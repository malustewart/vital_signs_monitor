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
#include "demCircBuffer.h"
//#include "PIT.h"
#include"adc.h"
#include "send_package.h"

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


uart_cfg_t uart_config;
void App_Init (void)
{
	uart_config.baudrate = 9600;
	uart_config.parity = no_parity;
	uart_config.stopBit = 1;

//	uart_config.baudrate = 9600;
//	uart_config.parity = odd_parity;
//	uart_config.stopBit = 0;



	i2c_sdk_init();
	//uartInit(3,uart_config);
	uartInit(3,uart_config);
	gpioMode(PORTNUM2PIN(GPIO_PB,23), INPUT);
	ecg_afe_init();




}

/* Función que se llama constantemente en un ciclo infinito */


void App_Run (void)
{

	uint32_t ir; // almaceno las nueva muestras de ir
	uint32_t red;// almaceno las nueva muestra de red

	float spo22; // valor de spo2
	int32_t hr; // valor de hr
	int8_t isValidSpo2; // flag validez spo2
	int8_t isValidHr;//flag validez hr
	float irmedia=0; //valor medio de las muestras ir
	float redmedia=0; ////valor medio de las muestras red
	uint32_t bir[500];// buffer para las muestras ir
	uint32_t bred[500];// buffer para las muestras red
	float r; // ratio of ratios
	float cor;// correlacion entre la seal red y ir

	bool haySampleIr=false;
	bool hayEcg=false;
	uint8_t ecg2send[4];



	uint32_t temp;
	uint32_t acumulator=10;




	maxim_max30102_reset();//inicializo el maxim xq requiere que las interrupciones de i2c
	maxim_max30102_init();//
	bool readingMax=false;//

	while(!maxim_max30102_read_fifoNB(&red, &ir));//realizo la primera lectura de la fifio para liniciar la converion
	//ojo la linea es bloqueante

	//A partir de aca el codigo es no bloqueante
	while(1){//loop de sampleo
		for(uint16_t i=0;i<100;i){

			if(!readingMax){
				readingMax=!gpioRead(PORTNUM2PIN(GPIO_PB,23));
			}else{
				if(maxim_max30102_read_fifoNB(&red, &ir)){
					readingMax=false;
					bred[i]=red;
					bir[i]=ir;
					i++;
					haySampleIr=true;
					//acumulator=(acumulator+red)/2;
					//temp=(red-120000-210)*(250./(14600.0-12800.0))*(250/2200.0)*(250/320.0)*(250.0/270.0);
					temp=(red-120000-210)*0.011417;
					//acumulator=(acumulator+red)/2;

				}
			}
			if(ecg_afe_getSamples(ecg2send)){
				//send_ecg(ir,ecg2send);
				hayEcg=true;

			}
			if(hayEcg&&haySampleIr){
				haySampleIr=false;
				hayEcg=false;

				send_ecg(temp,ecg2send);
			}
		}// aca termina el for de las 100 muestras del max30102


		rf_heart_rate_and_oxygen_saturation(bred, 100,bir,&spo22,&isValidSpo2, &hr, &isValidHr, &r, &cor,&irmedia,&redmedia);
		//calculo el hr y spo2 a partir de 100 muestras

		if(isValidHr==1){ // si la medicion de hr es valida la envio
			send_hr(hr);
		}
		if(isValidSpo2==1){ // si la medicion de spo2 es valida la envio
			send_spo2(spo22);
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
