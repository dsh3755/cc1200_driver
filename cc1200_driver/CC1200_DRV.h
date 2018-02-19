#ifndef __CC1200_DRV__
#define __CC1200_DRV__

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#define sysDelay(ms) osDelay(ms)

#include "CC1200_RegCfg.h"
#define CC1200_CSon HAL_GPIO_WritePin(__CC1200_csPort,__CC1200_csPin,GPIO_PIN_RESET)
#define CC1200_CSoff HAL_GPIO_WritePin(__CC1200_csPort,__CC1200_csPin,GPIO_PIN_SET)
#define CC1200_TranReceData(td,rd) (HAL_SPI_TransmitReceive(__CC1200_spiPORT,td,rd,1,500))
#define CC1200_TranThenReceData(td,rd) 	HAL_SPI_Transmit(__CC1200_spiPORT,td,1,500);\
																				HAL_SPI_Receive(__CC1200_spiPORT,rd,1,500)
#define CC1200_TransData(td,len) (HAL_SPI_Transmit(__CC1200_spiPORT,td,len,500))
#define CC1200_ReciveData(rd,len) (HAL_SPI_Receive(__CC1200_spiPORT,rd,len,500))

#define CC1200_sendCommand(cmd) CC1200_changeMode(cmd)
#define CC1200_enterRxMode() CC1200_sendCommand(SRX)
#define CC1200_enterTxMode() CC1200_sendCommand(STX)
#define CC1200_flushRxFIFO() CC1200_sendCommand(SFRX)
#define CC1200_flushTxFIFO() CC1200_sendCommand(SFTX)
#define CC1200_enterSleepMode() CC1200_sendCommand(SPWD)
#define CC1200_enterIDLEMode() CC1200_sendCommand(SIDLE)
#define CC1200_softReset() CC1200_sendCommand(SRES)

typedef enum{SRES=0x30,SFSTXON,SXOFF,SCAL,SRX,STX,SIDLE,SAFC,SWOR,SPWD,SFRX,SFTX,SWORRST,SNOP} CC1200_COMMANDS;
typedef enum{IDLE=0x00,RX,TX,FSTXON,CALIBRATE,SETTLING,RFIFOERR,TFIFOERR} CC1200_STATUS;
typedef enum{CC1200_Failt=0,CC1200_OK} CC1200_RET_STATUS;
/*	initial section	*/
void __CC1200_InitRegs(void);
void CC1200_SetUpSPI(SPI_HandleTypeDef* port,GPIO_TypeDef* csPort,uint16_t pin);

/*	Register sction */
void CC1200_writeReg(uint16_t regAddr,uint8_t data);
uint8_t CC1200_readReg(uint16_t regAddr);

/*	brust access sction */
void CC1200_burstWriteReg(uint16_t startRegAddr,uint8_t *data,uint8_t cnt);

/*	FIFO sction */
uint8_t* CC1200_getRxFIFOInfo(void);

void CC1200_writeTxFIFO(uint8_t data);
uint8_t CC1200_readRxFIFO(void);

CC1200_RET_STATUS CC1200_transData(uint8_t len, uint8_t *datas);
CC1200_RET_STATUS CC1200_receiveDataUntil(uint8_t *datas,uint8_t *linkQual);
void CC1200_burstReadRxFIFO(uint8_t cnt,uint8_t* retDatas);
void CC1200_burstWriteTxFIFO(uint8_t cnt,uint8_t* txDatas);

/*	control sction */
CC1200_STATUS CC1200_getStatus(void);
void CC1200_changeMode(CC1200_COMMANDS cmd);
#endif
