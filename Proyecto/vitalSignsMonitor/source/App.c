/***************************************************************************//**
  @file     App.c
  @brief    Application functions
  @author   Nicolás Magliola
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

//#include "board.h"
//#include "gpio.h"
//#include "I2C.h"
#include"temperature_sensor.h"
//#include"I2C.h"
#include"i2c_sdk.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static void delayLoop(uint32_t veces);


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/* Función que se llama 1 vez, al comienzo del programa */
//I2C_transcieve_t test;
//uint8_t datas[5];
//
//void llegoalgo(void){
//	static uint8_t i;
//	i++;
//}

void App_Init (void)
{
	//test.data=datas;
	//test.data_size=1;
	//test.error=I2C_NO_ERROR;
	///test.callback=llegoalgo;
   // gpioMode(PIN_LED_BLUE, OUTPUT);
//    I2C_init(I2C_0);
//    //I2C_init_r(I2C_CH0,PORTNUM2PIN(PE,25),PORTNUM2PIN(PE,24));
//    temp_init();
    i2c_sdk_init();
}

/* Función que se llama constantemente en un ciclo infinito */


void App_Run (void)
{

	float ctemp=0;
	temp_initMeasure();
	while(!temp_status());
	ctemp=temp_get_temp(CELSIUS);
	delayLoop(100000);

}


/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static void delayLoop(uint32_t veces)
{
    while (veces--);
}


/*******************************************************************************
 ******************************************************************************/
