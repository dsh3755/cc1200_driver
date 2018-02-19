#ifndef __CC1200_REGCFG__
#define __CC1200_REGCFG__
// RF settings for CC1200
#include "stm32f4xx_hal.h"

#define CC1200_IOCFG3                   0x0000
#define CC1200_IOCFG2                   0x0001
#define CC1200_IOCFG1                   0x0002
#define CC1200_IOCFG0                   0x0003
#define CC1200_SYNC3                    0x0004
#define CC1200_SYNC2                    0x0005
#define CC1200_SYNC1                    0x0006
#define CC1200_SYNC0                    0x0007
#define CC1200_SYNC_CFG1                0x0008
#define CC1200_SYNC_CFG0                0x0009
#define CC1200_DEVIATION_M              0x000A
#define CC1200_MODCFG_DEV_E             0x000B
#define CC1200_DCFILT_CFG               0x000C
#define CC1200_PREAMBLE_CFG1            0x000D
#define CC1200_PREAMBLE_CFG0            0x000E
#define CC1200_IQIC                     0x000F
#define CC1200_CHAN_BW                  0x0010
#define CC1200_MDMCFG1                  0x0011
#define CC1200_MDMCFG0                  0x0012
#define CC1200_SYMBOL_RATE2             0x0013
#define CC1200_SYMBOL_RATE1             0x0014
#define CC1200_SYMBOL_RATE0             0x0015
#define CC1200_AGC_REF                  0x0016
#define CC1200_AGC_CS_THR               0x0017
#define CC1200_AGC_GAIN_ADJUST          0x0018
#define CC1200_AGC_CFG3                 0x0019
#define CC1200_AGC_CFG2                 0x001A
#define CC1200_AGC_CFG1                 0x001B
#define CC1200_AGC_CFG0                 0x001C
#define CC1200_FIFO_CFG                 0x001D
#define CC1200_DEV_ADDR                 0x001E
#define CC1200_SETTLING_CFG             0x001F
#define CC1200_FS_CFG                   0x0020
#define CC1200_WOR_CFG1                 0x0021
#define CC1200_WOR_CFG0                 0x0022
#define CC1200_WOR_EVENT0_MSB           0x0023
#define CC1200_WOR_EVENT0_LSB           0x0024
#define CC1200_RXDCM_TIME               0x0025
#define CC1200_PKT_CFG2                 0x0026
#define CC1200_PKT_CFG1                 0x0027
#define CC1200_PKT_CFG0                 0x0028
#define CC1200_RFEND_CFG1               0x0029
#define CC1200_RFEND_CFG0               0x002A
#define CC1200_PA_CFG1                  0x002B
#define CC1200_PA_CFG0                  0x002C
#define CC1200_ASK_CFG                  0x002D
#define CC1200_PKT_LEN                  0x002E
  
/* Extended Configuration Registers */
#define CC1200_IF_MIX_CFG               0x2F00
#define CC1200_FREQOFF_CFG              0x2F01
#define CC1200_TOC_CFG                  0x2F02
#define CC1200_MARC_SPARE               0x2F03
#define CC1200_ECG_CFG                  0x2F04
#define CC1200_MDMCFG2                  0x2F05
#define CC1200_EXT_CTRL                 0x2F06
#define CC1200_RCCAL_FINE               0x2F07
#define CC1200_RCCAL_COARSE             0x2F08
#define CC1200_RCCAL_OFFSET             0x2F09
#define CC1200_FREQOFF1                 0x2F0A
#define CC1200_FREQOFF0                 0x2F0B
#define CC1200_FREQ2                    0x2F0C
#define CC1200_FREQ1                    0x2F0D
#define CC1200_FREQ0                    0x2F0E
#define CC1200_IF_ADC2                  0x2F0F
#define CC1200_IF_ADC1                  0x2F10
#define CC1200_IF_ADC0                  0x2F11
#define CC1200_FS_DIG1                  0x2F12
#define CC1200_FS_DIG0                  0x2F13
#define CC1200_FS_CAL3                  0x2F14
#define CC1200_FS_CAL2                  0x2F15
#define CC1200_FS_CAL1                  0x2F16
#define CC1200_FS_CAL0                  0x2F17
#define CC1200_FS_CHP                   0x2F18
#define CC1200_FS_DIVTWO                0x2F19
#define CC1200_FS_DSM1                  0x2F1A
#define CC1200_FS_DSM0                  0x2F1B
#define CC1200_FS_DVC1                  0x2F1C
#define CC1200_FS_DVC0                  0x2F1D
#define CC1200_FS_LBI                   0x2F1E
#define CC1200_FS_PFD                   0x2F1F
#define CC1200_FS_PRE                   0x2F20
#define CC1200_FS_REG_DIV_CML           0x2F21
#define CC1200_FS_SPARE                 0x2F22
#define CC1200_FS_VCO4                  0x2F23
#define CC1200_FS_VCO3                  0x2F24
#define CC1200_FS_VCO2                  0x2F25
#define CC1200_FS_VCO1                  0x2F26
#define CC1200_FS_VCO0                  0x2F27
#define CC1200_GBIAS6                   0x2F28
#define CC1200_GBIAS5                   0x2F29
#define CC1200_GBIAS4                   0x2F2A
#define CC1200_GBIAS3                   0x2F2B
#define CC1200_GBIAS2                   0x2F2C
#define CC1200_GBIAS1                   0x2F2D
#define CC1200_GBIAS0                   0x2F2E
#define CC1200_IFAMP                    0x2F2F
#define CC1200_LNA                      0x2F30
#define CC1200_RXMIX                    0x2F31
#define CC1200_XOSC5                    0x2F32
#define CC1200_XOSC4                    0x2F33
#define CC1200_XOSC3                    0x2F34
#define CC1200_XOSC2                    0x2F35
#define CC1200_XOSC1                    0x2F36
#define CC1200_XOSC0                    0x2F37
#define CC1200_ANALOG_SPARE             0x2F38
#define CC1200_PA_CFG3                  0x2F39
#define CC1200_IRQ0M                    0x2F3F
#define CC1200_IRQ0F                    0x2F40  
  
/* Status Registers */
#define CC1200_WOR_TIME1                0x2F64
#define CC1200_WOR_TIME0                0x2F65
#define CC1200_WOR_CAPTURE1             0x2F66
#define CC1200_WOR_CAPTURE0             0x2F67
#define CC1200_BIST                     0x2F68
#define CC1200_DCFILTOFFSET_I1          0x2F69
#define CC1200_DCFILTOFFSET_I0          0x2F6A
#define CC1200_DCFILTOFFSET_Q1          0x2F6B
#define CC1200_DCFILTOFFSET_Q0          0x2F6C
#define CC1200_IQIE_I1                  0x2F6D
#define CC1200_IQIE_I0                  0x2F6E
#define CC1200_IQIE_Q1                  0x2F6F
#define CC1200_IQIE_Q0                  0x2F70
#define CC1200_RSSI1                    0x2F71
#define CC1200_RSSI0                    0x2F72
#define CC1200_MARCSTATE                0x2F73
#define CC1200_LQI_VAL                  0x2F74
#define CC1200_PQT_SYNC_ERR             0x2F75
#define CC1200_DEM_STATUS               0x2F76
#define CC1200_FREQOFF_EST1             0x2F77
#define CC1200_FREQOFF_EST0             0x2F78
#define CC1200_AGC_GAIN3                0x2F79
#define CC1200_AGC_GAIN2                0x2F7A
#define CC1200_AGC_GAIN1                0x2F7B
#define CC1200_AGC_GAIN0                0x2F7C
#define CC1200_CFM_RX_DATA_OUT         0x2F7D
#define CC1200_CFM_TX_DATA_IN          0x2F7E
#define CC1200_ASK_SOFT_RX_DATA         0x2F7F
#define CC1200_RNDGEN                   0x2F80
#define CC1200_MAGN2                    0x2F81
#define CC1200_MAGN1                    0x2F82
#define CC1200_MAGN0                    0x2F83
#define CC1200_ANG1                     0x2F84
#define CC1200_ANG0                     0x2F85
#define CC1200_CHFILT_I2                0x2F86
#define CC1200_CHFILT_I1                0x2F87
#define CC1200_CHFILT_I0                0x2F88
#define CC1200_CHFILT_Q2                0x2F89
#define CC1200_CHFILT_Q1                0x2F8A
#define CC1200_CHFILT_Q0                0x2F8B
#define CC1200_GPIO_STATUS              0x2F8C
#define CC1200_FSCAL_CTRL               0x2F8D
#define CC1200_PHASE_ADJUST             0x2F8E
#define CC1200_PARTNUMBER               0x2F8F
#define CC1200_PARTVERSION              0x2F90
#define CC1200_SERIAL_STATUS            0x2F91
#define CC1200_MODEM_STATUS1            0x2F92
#define CC1200_MODEM_STATUS0            0x2F93
#define CC1200_MARC_STATUS1             0x2F94
#define CC1200_MARC_STATUS0             0x2F95
#define CC1200_PA_IFAMP_TEST            0x2F96
#define CC1200_FSRF_TEST                0x2F97
#define CC1200_PRE_TEST                 0x2F98
#define CC1200_PRE_OVR                  0x2F99
#define CC1200_ADC_TEST                 0x2F9A
#define CC1200_DVC_TEST                 0x2F9B
#define CC1200_ATEST                    0x2F9C
#define CC1200_ATEST_LVDS               0x2F9D
#define CC1200_ATEST_MODE               0x2F9E
#define CC1200_XOSC_TEST1               0x2F9F
#define CC1200_XOSC_TEST0               0x2FA0
#define CC1200_AES                      0x2FA1
#define CC1200_MDM_TEST                 0x2FA2  

#define CC1200_RXFIRST                  0x2FD2   
#define CC1200_TXFIRST                  0x2FD3   
#define CC1200_RXLAST                   0x2FD4 
#define CC1200_TXLAST                   0x2FD5 
#define CC1200_NUM_TXBYTES              0x2FD6  /* Number of bytes in TXFIFO */ 
#define CC1200_NUM_RXBYTES              0x2FD7  /* Number of bytes in RXFIFO */
#define CC1200_FIFO_NUM_TXBYTES         0x2FD8  
#define CC1200_FIFO_NUM_RXBYTES         0x2FD9  
#define CC1200_RXFIFO_PRE_BUF           0x2FDA
  
/* DATA FIFO Access */
#define CC1200_SINGLE_TXFIFO            0x003F     /*  TXFIFO  - Single accecss to Transmit FIFO */
#define CC1200_BURST_TXFIFO             0x007F     /*  TXFIFO  - Burst accecss to Transmit FIFO  */
#define CC1200_SINGLE_RXFIFO            0x00BF     /*  RXFIFO  - Single accecss to Receive FIFO  */
#define CC1200_BURST_RXFIFO             0x00FF     /*  RXFIFO  - Busrrst ccecss to Receive FIFO  */
  
/* AES Workspace */
/* AES Key */
#define CC1200_AES_KEY                  0x2FE0     /*  AES_KEY    - Address for AES key input  */
#define CC1200_AES_KEY15	        0x2FE0
#define CC1200_AES_KEY14	        0x2FE1
#define CC1200_AES_KEY13	        0x2FE2
#define CC1200_AES_KEY12	        0x2FE3
#define CC1200_AES_KEY11	        0x2FE4
#define CC1200_AES_KEY10	        0x2FE5
#define CC1200_AES_KEY9	                0x2FE6
#define CC1200_AES_KEY8	                0x2FE7
#define CC1200_AES_KEY7	                0x2FE8
#define CC1200_AES_KEY6	                0x2FE9
#define CC1200_AES_KEY5	                0x2FE10
#define CC1200_AES_KEY4	                0x2FE11
#define CC1200_AES_KEY3	                0x2FE12
#define CC1200_AES_KEY2	                0x2FE13
#define CC1200_AES_KEY1	                0x2FE14
#define CC1200_AES_KEY0	                0x2FE15

/* AES Buffer */
#define CC1200_AES_BUFFER               0x2FF0     /*  AES_BUFFER - Address for AES Buffer     */ 
#define CC1200_AES_BUFFER15		0x2FF0
#define CC1200_AES_BUFFER14		0x2FF1
#define CC1200_AES_BUFFER13		0x2FF2
#define CC1200_AES_BUFFER12		0x2FF3
#define CC1200_AES_BUFFER11		0x2FF4
#define CC1200_AES_BUFFER10		0x2FF5
#define CC1200_AES_BUFFER9		0x2FF6
#define CC1200_AES_BUFFER8		0x2FF7
#define CC1200_AES_BUFFER7		0x2FF8
#define CC1200_AES_BUFFER6		0x2FF9
#define CC1200_AES_BUFFER5		0x2FF10
#define CC1200_AES_BUFFER4		0x2FF11
#define CC1200_AES_BUFFER3		0x2FF12
#define CC1200_AES_BUFFER2		0x2FF13
#define CC1200_AES_BUFFER1		0x2FF14
#define CC1200_AES_BUFFER0		0x2FF15

#define CC1200_LQI_CRC_OK_BM            0x80
#define CC1200_LQI_EST_BM               0x7F

/* Command strobe registers */
#define CC1200_SRES                     0x30      /*  SRES    - Reset chip. */
#define CC1200_SFSTXON                  0x31      /*  SFSTXON - Enable and calibrate frequency synthesizer. */
#define CC1200_SXOFF                    0x32      /*  SXOFF   - Turn off crystal oscillator. */
#define CC1200_SCAL                     0x33      /*  SCAL    - Calibrate frequency synthesizer and turn it off. */
#define CC1200_SRX                      0x34      /*  SRX     - Enable RX. Perform calibration if enabled. */
#define CC1200_STX                      0x35      /*  STX     - Enable TX. If in RX state, only enable TX if CCA passes. */
#define CC1200_SIDLE                    0x36      /*  SIDLE   - Exit RX / TX, turn off frequency synthesizer. */
#define CC1200_SAFC                     0x37      /*  AFC     - Automatic Frequency Correction */    
#define CC1200_SWOR                     0x38      /*  SWOR    - Start automatic RX polling sequence (Wake-on-Radio) */
#define CC1200_SPWD                     0x39      /*  SPWD    - Enter power down mode when CSn goes high. */
#define CC1200_SFRX                     0x3A      /*  SFRX    - Flush the RX FIFO buffer. */
#define CC1200_SFTX                     0x3B      /*  SFTX    - Flush the TX FIFO buffer. */
#define CC1200_SWORRST                  0x3C      /*  SWORRST - Reset real time clock. */
#define CC1200_SNOP                     0x3D      /*  SNOP    - No operation. Returns status byte. */
  
/* Chip states returned in status byte */
#define CC1200_STATE_IDLE               0x00
#define CC1200_STATE_RX                 0x10
#define CC1200_STATE_TX                 0x20
#define CC1200_STATE_FSTXON             0x30
#define CC1200_STATE_CALIBRATE          0x40
#define CC1200_STATE_SETTLING           0x50
#define CC1200_STATE_RXFIFO_ERROR       0x60
#define CC1200_STATE_TXFIFO_ERROR       0x70


static const uint16_t __CC1200_PreSettings[][2]= 
{
  {CC1200_IOCFG2,            0x06},
  {CC1200_SYNC_CFG1,         0xA8},
  {CC1200_SYNC_CFG0,         0x23},
  {CC1200_DEVIATION_M,       0x47},
  {CC1200_MODCFG_DEV_E,      0x0C},
  {CC1200_DCFILT_CFG,        0x4B},
  {CC1200_PREAMBLE_CFG0,     0x8A},
  {CC1200_IQIC,              0xD8},
  {CC1200_CHAN_BW,           0x08},
  {CC1200_MDMCFG1,           0x42},
  {CC1200_MDMCFG0,           0x05},
  {CC1200_SYMBOL_RATE2,      0xA4},
  {CC1200_SYMBOL_RATE1,      0x7A},
  {CC1200_SYMBOL_RATE0,      0xE1},
  {CC1200_AGC_REF,           0x2A},
  {CC1200_AGC_CS_THR,        0xF6},
  {CC1200_AGC_CFG1,          0x12},
  {CC1200_AGC_CFG0,          0x80},
  {CC1200_FIFO_CFG,          0x00},
  {CC1200_FS_CFG,            0x12},
  {CC1200_PKT_CFG2,          0x00},
  {CC1200_PKT_CFG0,          0x20},
  {CC1200_PKT_LEN,           0xFF},
  {CC1200_IF_MIX_CFG,        0x1C},
  {CC1200_TOC_CFG,           0x03},
  {CC1200_MDMCFG2,           0x02},
  {CC1200_FREQ2,             0x56},
  {CC1200_FREQ1,             0xCC},
  {CC1200_FREQ0,             0xCC},
  {CC1200_IF_ADC1,           0xEE},
  {CC1200_IF_ADC0,           0x10},
  {CC1200_FS_DIG1,           0x04},
  {CC1200_FS_DIG0,           0x50},
  {CC1200_FS_CAL1,           0x40},
  {CC1200_FS_CAL0,           0x0E},
  {CC1200_FS_DIVTWO,         0x03},
  {CC1200_FS_DSM0,           0x33},
  {CC1200_FS_DVC1,           0xF7},
  {CC1200_FS_DVC0,           0x0F},
  {CC1200_FS_PFD,            0x00},
  {CC1200_FS_PRE,            0x6E},
  {CC1200_FS_REG_DIV_CML,    0x1C},
  {CC1200_FS_SPARE,          0xAC},
  {CC1200_FS_VCO0,           0xB5},
  {CC1200_IFAMP,             0x09},
  {CC1200_XOSC5,             0x0E},
  {CC1200_XOSC1,             0x03}
};

#endif
