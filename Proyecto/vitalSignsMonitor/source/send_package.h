/*
 * send_package.h
 *
 *  Created on: 17 ene. 2021
 *      Author: Gonzalo
 */

#ifndef SEND_PACKAGE_H_
#define SEND_PACKAGE_H_
#include<stdint.h>
#include<stdbool.h>

void send_temperature(uint8_t temperature);

void send_spo2(uint8_t spo2);

void send_hr(uint8_t hr);

void send_ecg(uint8_t ir, uint8_t * ecg);

#endif /* SEND_PACKAGE_H_ */
