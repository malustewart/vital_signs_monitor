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
#include <uart_micros.h>
#include"temperature_sensor.h"
//#include"I2C.h"
#include"i2c_sdk.h"
#include"MAX30102.h"
#include "gpio.h"
#include "algorithm_by_RF.h"
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
uart_cfg_t uart_config;
void App_Init (void)
{
	uart_config.baudrate = 9600;
	uart_config.parity = odd_parity;
	uart_config.stopBit = 0;
	//test.data=datas;
	//test.data_size=1;
	//test.error=I2C_NO_ERROR;
	///test.callback=llegoalgo;
	// gpioMode(PIN_LED_BLUE, OUTPUT);
	//    I2C_init(I2C_0);
	//    //I2C_init_r(I2C_CH0,PORTNUM2PIN(PE,25),PORTNUM2PIN(PE,24));
	//    temp_init();
	i2c_sdk_init();
	uartInit(0,uart_config);
	gpioMode(PORTNUM2PIN(GPIO_PB,23), INPUT);

}

/* Función que se llama constantemente en un ciclo infinito */


void App_Run (void)
{
	uint8_t dataRx;
	uint32_t ir;
	uint32_t red;

	float spo22;
	int8_t isvalid1;
	int8_t isvalid2;
	int32_t hr;
	float r;
	float cor;
	int ii;
	char printD[6];
	uint32_t bir[500];
	uint32_t bred[500];
	maxim_max30102_reset();
	maxim_max30102_init();
	maxim_max30102_read_fifo(&red,&ir);
	while(1){
		for(uint16_t i=0;i<100;i++){
			while(gpioRead(PORTNUM2PIN(GPIO_PB,23)));
			maxim_max30102_read_fifo(&red,&ir);
			bir[i]=ir;
			bred[i]=red;
			itoa(red, printD,10);
			uartWriteMsg(0,printD, 6);
			uartWriteMsg(0,",",1);
			itoa(ir, printD,10);
			uartWriteMsg(0,printD, 6);
			uartWriteMsg(0,"\n", 1);
		}
		//		if(!gpioRead(PORTNUM2PIN(GPIO_PB,23))){
		//			maxim_max30102_read_fifo(&red,&ir);
		//		}
	//	maxim_heart_rate_and_oxygen_saturation(bir,  125, bred,  &spo22,&isvalid1 ,&hr , &isvalid2);
		rf_heart_rate_and_oxygen_saturation(bir, 100, bred,&spo22,&isvalid1, &hr, &isvalid2, &r, &cor);

		if(isvalid2==1){
			ii++;
//			itoa(hr, printD,10);
//			uartWriteMsg(0,printD, 4);
//			uartWriteMsg(0,"\n", 1);
		}
		if(isvalid1==1){
					ii++;
		//			itoa(hr, printD,10);
		//			uartWriteMsg(0,printD, 4);
		//			uartWriteMsg(0,"\n", 1);
				}

}
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
