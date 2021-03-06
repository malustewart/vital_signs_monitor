/***************************************************************************//**
  @file     ecg_afe.c
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "ecg_afe.h"
//#include "dma.h"

#include "PIT.h"
#include "adc.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
uint16_t bufferA[ECG_AFE_BUFF_SIZE];
uint16_t bufferB[ECG_AFE_BUFF_SIZE];
bool messureReady=false;
bool bufferANoReady=false;
uint8_t sampleCount;
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
void ecg_afe_adcIrq(void);

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

void ecg_afe_init(void){
	PIT_init();
	PIT_set_timer(ECG_AFE_SAMPLING_FREC,1);
	adcInit(ADC_0, 0,ecg_afe_adcIrq,true,1);
}
bool ecg_afe_getSamples(uint8_t * ssamples){

	uint16_t * data2copy=bufferB;
	uint8_t tempData;

	if(bufferANoReady){
		data2copy=bufferA;
	}
	if(!messureReady){
		return false;
	}
	messureReady=false;
	for(int i=0; i<ECG_AFE_BUFF_SIZE;i++){
		tempData=(data2copy[i]/257.0);
		ssamples[i]=tempData;
	}

	return true;
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

void ecg_afe_adcIrq(void){
	if(!(sampleCount<ECG_AFE_BUFF_SIZE)){
		sampleCount=0;
		bufferANoReady=!bufferANoReady;
		messureReady=true;
	}
	if(!bufferANoReady){
		bufferA[sampleCount]=adcGetData(0);
	}else{
		bufferB[sampleCount]=adcGetData(0);
	}
	sampleCount++;
}

/******************************************************************************/


