/*
 * i2c_sdk_structure.h
 *
 *  Created on: Jan 15, 2021
 *      Author: mpier
 */
#include<stdbool.h>
#include<stdint.h>

#ifndef I2C_SDK_STRUCTURE_H_
#define I2C_SDK_STRUCTURE_H_

typedef struct i2c_sdk_st {
    uint8_t st_adress;
    uint8_t st_reg;
	uint8_t * volatile st_data;
	uint8_t st_dataSize;
	uint32_t * st_ready;
	bool st_read;
}i2c_sdk_st;


#endif /* I2C_SDK_STRUCTURE_H_ */
