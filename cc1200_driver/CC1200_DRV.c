#include "CC1200_DRV.h"
#define CC1200_ReadOp 0x80
#define CC1200_WriteOp 0x3F
#define __CC1200_BurstBitSet(addr) (addr|0x40)
#define __CC1200_ReadBitSet(addr) (addr|0x80)

#define __cc1200_RXFIRST 0
#define __cc1200_TXFIRST 1
#define __cc1200_RXLAST	2
#define __cc1200_TXLAST 3
#define __cc1200_TXBYTES 4
#define __cc1200_RXBYTES 5

static SPI_HandleTypeDef* __CC1200_spiPORT;
static GPIO_TypeDef*	__CC1200_csPort;
static uint16_t __CC1200_csPin;

static uint8_t __CC1200_FIFOInfo[6]={0};

static inline void directFIFOAccess(uint8_t addr)
{
	uint8_t Cmd=0x3E,regAddr=0xD2;
	Cmd = __CC1200_BurstBitSet(Cmd);
	CC1200_CSon;
	CC1200_TransData(&Cmd,1);
	CC1200_TransData(&regAddr,1);
	CC1200_ReciveData(__CC1200_FIFOInfo,6);
	CC1200_CSoff;
}

void CC1200_changeMode(CC1200_COMMANDS cmd)
{
	uint8_t status,command=cmd;
	
	CC1200_CSon;
	CC1200_TranReceData(&command,&status);
	CC1200_CSoff;
}

void __CC1200_InitRegs(void)
{
	//printf("sizof:%d",sizeof(__CC1200_PreSettings));
	uint16_t *tempPtr = (uint16_t*)__CC1200_PreSettings;
	for(uint8_t i=0;i<(sizeof(__CC1200_PreSettings)/2);i+=2)
	{
		CC1200_writeReg(*(tempPtr+i),*(tempPtr+i+1));
	}
}

void CC1200_SetUpSPI(SPI_HandleTypeDef* port,GPIO_TypeDef* csPort,uint16_t pin)
{
	__CC1200_spiPORT = port;
	__CC1200_csPort = csPort;
	__CC1200_csPin = pin;
	__CC1200_InitRegs();
}

CC1200_STATUS CC1200_getStatus(void)
{
	uint8_t cmd = (uint8_t)SNOP,status;
	CC1200_CSon;
	CC1200_TranReceData(&cmd,&status);
	CC1200_CSoff;
	status &= 0x7F; // ignored bit 7: CHIP_RDYn
	status >>= 4;		// reversed 0:3 bits
	return (CC1200_STATUS)status;
}

void CC1200_burstWriteReg(uint16_t startRegAddr,uint8_t *data,uint8_t cnt)
{
	
	if(startRegAddr < 0x2F)	// stander burst rugister access
	{
		startRegAddr =__CC1200_BurstBitSet(startRegAddr);
		CC1200_CSon;
		CC1200_TransData((uint8_t*)&startRegAddr,1);
		for(uint8_t i=0;i<cnt;++i)
			{
				CC1200_TransData(data+i,1);
			}
		CC1200_CSoff;
	}
	else	// extended burst rugister access
	{
		startRegAddr &= 0xFF;
		uint8_t extenBrustCom = __CC1200_BurstBitSet(0x2F);
		
		CC1200_CSon;
		CC1200_TransData(&extenBrustCom,1);
		CC1200_TransData((uint8_t*)&startRegAddr,1);
		for(uint8_t i=0;i<cnt;++i)
			{
				CC1200_TransData(data+i,1);
			}
		CC1200_CSoff;
	}
}

uint8_t CC1200_readReg(uint16_t regAddr)
{
	uint8_t rd;
	if(regAddr < 0x2F)
	{
		uint8_t cmd = regAddr;
		cmd |= CC1200_ReadOp;
		CC1200_CSon;
		CC1200_TranThenReceData(&cmd,&rd);
		CC1200_CSoff;
	}
	else
	{
		uint8_t LSB = regAddr;
		uint8_t MSB = (regAddr >> 8)| CC1200_ReadOp;
		CC1200_CSon;
		CC1200_TransData(&MSB,1);
		CC1200_TranThenReceData(&LSB,&rd);
		CC1200_CSoff;
	}
	return rd;
}

void CC1200_writeReg(uint16_t regAddr,uint8_t data)
{
	if(regAddr < 0x2F)
	{
		uint8_t cmd = regAddr;
		CC1200_CSon;
		CC1200_TransData(&cmd,1);
		CC1200_TransData(&data,1);
		CC1200_CSoff;
	}
	else
	{
		CC1200_CSon;
		uint8_t LSB = regAddr;
		uint8_t MSB = (regAddr >> 8);
		CC1200_TransData(&MSB,1);
		CC1200_TransData(&LSB,1);
		CC1200_TransData(&data,1);
		CC1200_CSoff;
	}
}

void CC1200_writeTxFIFO(uint8_t data)
{
	uint8_t status;
	uint8_t FIFOAcessCmd = 0x3F;
	CC1200_CSon;
	CC1200_TransData(&FIFOAcessCmd,1);
	CC1200_TranReceData(&data,&status);
	CC1200_CSoff;
}
uint8_t CC1200_readRxFIFO(void)
{
	//uint8_t status;
	uint8_t getVal = 0;
	uint8_t FIFOAcessCmd = __CC1200_ReadBitSet(0x3F);
	CC1200_CSon;
	CC1200_TransData(&FIFOAcessCmd,1);
	CC1200_ReciveData(&getVal,1);
	CC1200_CSoff;
	return getVal;
}
CC1200_RET_STATUS CC1200_transData(uint8_t len, uint8_t *datas)
{
	if(CC1200_getStatus() ==IDLE)
	{
		CC1200_writeTxFIFO(len);
		for(uint8_t i=0;i<len;++i)
			CC1200_writeTxFIFO(datas[i]);
		CC1200_enterTxMode();
		return CC1200_OK;
	}
	return CC1200_Failt;
}

CC1200_RET_STATUS CC1200_receiveDataUntil(uint8_t *datas,uint8_t *linkQual)
{
	uint8_t rxbytes =0;
	if(CC1200_getStatus() == IDLE)
	{
		CC1200_enterRxMode();
		sysDelay(1);
		while(CC1200_getStatus() != IDLE)
			sysDelay(1);
		rxbytes = CC1200_readRxFIFO();
		if(rxbytes == 0)
			return CC1200_Failt;
		CC1200_burstReadRxFIFO(rxbytes,datas);  //two status Bytes will be append ! CRC,LQI,RSSI
		CC1200_readRxFIFO(); // RSSI Byte ,not used
		*linkQual = CC1200_readRxFIFO() & 0x7F ;
		return CC1200_OK;
	}
	else
		return CC1200_Failt;
}

void CC1200_burstReadRxFIFO(uint8_t cnt,uint8_t* retDatas)
{
	uint8_t FIFOAcessCmd = __CC1200_ReadBitSet(0x3F);	//read switch on
	FIFOAcessCmd = __CC1200_BurstBitSet(FIFOAcessCmd);	//burst switch on
	CC1200_CSon;
	CC1200_TransData(&FIFOAcessCmd,1);
	CC1200_ReciveData(retDatas,cnt);
	CC1200_CSoff;
}

uint8_t* CC1200_getRxFIFOInfo(void)
{
	directFIFOAccess(CC1200_NUM_RXBYTES && 0xff);
	return __CC1200_FIFOInfo;
}

void CC1200_burstWriteTxFIFO(uint8_t cnt,uint8_t* txDatas)
{
	uint8_t FIFOAcessCmd = __CC1200_BurstBitSet(0x3F);
	CC1200_CSon;
	CC1200_TransData(&FIFOAcessCmd,1);
	CC1200_TransData(txDatas,cnt);
	CC1200_CSoff;
}
