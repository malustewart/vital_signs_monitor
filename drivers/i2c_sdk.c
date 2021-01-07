/***************************************************************************//**
  @file     idc_sdk.c
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
  @source: https://mcuoneclipse.com/2020/06/29/mcuxpresso-sdk-tutorial-using-i2c-driver-on-okdo-e1-board/
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "i2c_sdk.h"
#include "fsl_i2c.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include"MK64F12.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define I2C_SDK_BAUDRATE 100000U
#define I2C_SDK_BUFFER 20
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
i2c_master_config_t masterConfig;// variable que contiene la configuracion del periferico
volatile bool completionFlag = true;
volatile bool nakFlag        = false;
volatile uint8_t bufferRXTX[I2C_SDK_BUFFER];
i2c_master_handle_t g_m_handle;
i2c_master_transfer_t masterXfer;
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static void i2c_master_callback(I2C_Type *base, i2c_master_handle_t *handle,status_t status, void *userData);
/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void i2c_sdk_init(void){
	CLOCK_EnableClock(kCLOCK_PortE);
	const port_pin_config_t porte24_pin31_config = {
			kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
			kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
			kPORT_OpenDrainEnable,                                   /* Open drain is enabled */
			kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
			kPORT_MuxAlt5,                                           /* Pin is configured as I2C0_SCL */
			kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	};
	PORT_SetPinConfig(PORTE, 24u, &porte24_pin31_config); /* PORTE24 (pin 31) is configured as I2C0_SCL */
	const port_pin_config_t porte25_pin32_config = {
			kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
			kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
			kPORT_OpenDrainEnable,                                   /* Open drain is enabled */
			kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
			kPORT_MuxAlt5,                                           /* Pin is configured as I2C0_SDA */
			kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	};
	PORT_SetPinConfig(PORTE, 25u, &porte25_pin32_config); /* PORTE25 (pin 32) is configured as I2C0_SDA */

	I2C_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate_Bps = I2C_SDK_BAUDRATE;
	I2C_MasterInit(I2C0, &masterConfig, CLOCK_GetFreq(I2C0_CLK_SRC));
	I2C_MasterTransferCreateHandle(I2C0, &g_m_handle,i2c_master_callback, NULL);
}

 void i2c_sdk_readReg(uint8_t adress,uint8_t reg, uint8_t * volatile data,uint8_t sizeData){


	     completionFlag = false;
	     nakFlag=false;
	     memset(&masterXfer, 0, sizeof(masterXfer));

	     // Read the result registers
	     memset(data, 0,sizeData);
	     masterXfer.slaveAddress   = adress;
	     masterXfer.direction      = kI2C_Read;
	     masterXfer.subaddress     = reg;		// They start from 0xF7
	     masterXfer.subaddressSize = 1;
	     masterXfer.data           = data;
	     masterXfer.dataSize       = sizeData;
	     masterXfer.flags          = kI2C_TransferDefaultFlag;

	 	I2C_MasterTransferNonBlocking(I2C0, &g_m_handle, &masterXfer);
 }

 void i2c_sdk_writeReg(uint8_t adress,uint8_t reg, uint8_t *  volatile data,uint8_t sizeData){
	 completionFlag = false;
	 nakFlag=false;
	 memset(&masterXfer, 0, sizeof(masterXfer));
	 masterXfer.slaveAddress   = adress;
	 masterXfer.direction      = kI2C_Write;
	 masterXfer.subaddress     = reg;		// They start from 0xF7
	 masterXfer.subaddressSize = 1;
	 masterXfer.data           = data;
	 masterXfer.dataSize       = sizeData;
	 masterXfer.flags          = kI2C_TransferDefaultFlag;

	 I2C_MasterTransferNonBlocking(I2C0, &g_m_handle, &masterXfer);

 }

 i2c_sdk_status_t i2c_sdk_status(void){
	 i2c_sdk_status_t temp=i2c_sdk_ERROR;
	 if(completionFlag==true && nakFlag==false){
		 temp=i2c_sdk_REPOSO;
	 }else if(completionFlag==false && nakFlag==false){
		 temp=i2c_sdk_EN_PROCESO;
	 }

	 return temp;
 }



/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/*******************************************************************************
 *******************************************************************************
						            INTERRUPT SERVICE ROUTINES
 *******************************************************************************
 ******************************************************************************/
 static void i2c_master_callback(I2C_Type *base, i2c_master_handle_t *handle,status_t status, void *userData){
     /* Signal transfer success when received success status. */
     if (status == kStatus_Success)
     {
         completionFlag = true;
     }
     /* Signal transfer success when received success status. */
     if ((status == kStatus_I2C_Nak) || (status == kStatus_I2C_Addr_Nak))
     {
         nakFlag = true;
     }
 }

/******************************************************************************/
