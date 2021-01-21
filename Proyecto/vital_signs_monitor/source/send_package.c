/*
 * send_package.c
 *
 *  Created on: 17 ene. 2021
 *      Author: Gonzalo
 */
#include "send_package.h"

#define SEND_PACKAGE_TEMP_SIZE 1 //no incluye el byte de sincronismo
#define SEND_PACKAGE_TEMP_HEAD 252

#define SEND_PACKAGE_SPO2_SIZE 1
#define SEND_PACKAGE_SPO2_HEAD 253

#define SEND_PACKAGE_HR_SIZE 1
#define SEND_PACKAGE_HR_HEAD 254

#define SEND_PACKAGE_IR_ECG_SIZE 5
#define SEND_PACKAGE_IR_ECG_HEAD 255

void send_temperature(uint8_t temperature){
	uint8_t array[SEND_PACKAGE_TEMP_SIZE+1];
	array[0]=SEND_PACKAGE_TEMP_HEAD;
	array[1]=temperature;
	uartWriteMsg(3, array, SEND_PACKAGE_TEMP_SIZE+1);
}

void send_spo2(uint8_t spo2){
	uint8_t array[SEND_PACKAGE_SPO2_SIZE+1];
	array[0]=SEND_PACKAGE_SPO2_HEAD;
	array[1]=spo2;
	uartWriteMsg(3, array, SEND_PACKAGE_SPO2_SIZE+1);
}

void send_hr(uint8_t hr){
	uint8_t array[SEND_PACKAGE_HR_SIZE+1];
	array[0]=SEND_PACKAGE_HR_HEAD;
	array[1]=hr;
	uartWriteMsg(3, array, SEND_PACKAGE_HR_SIZE+1);
}

void send_ecg(uint8_t ir, uint8_t * ecg){
	uint8_t array[SEND_PACKAGE_IR_ECG_SIZE+1];
	array[0]=SEND_PACKAGE_IR_ECG_HEAD;
	array[1]=ir;

	for (int i = 2; i < SEND_PACKAGE_IR_ECG_SIZE+1; i++){
		array[i] = ecg[i-2];
	}

	uartWriteMsg(3, array, SEND_PACKAGE_IR_ECG_SIZE+1);
}

