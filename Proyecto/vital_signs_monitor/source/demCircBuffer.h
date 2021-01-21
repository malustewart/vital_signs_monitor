//
// Created by Matias Pierdominici on 10/24/2019.
//

#ifndef DEMODULADORFSK_DEMCIRCBUFFER_H
#define DEMODULADORFSK_DEMCIRCBUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include"i2c_sdk_structure.h"

typedef struct demCircBufferBuff {
	i2c_sdk_st * data;
    uint16_t dataSize;
    uint16_t head;
    uint16_t read;
    uint8_t off;
    uint16_t offPtr;
} demCircBufferBuff;

void demCircBufferInit(demCircBufferBuff * dataS, i2c_sdk_st * buffer,uint16_t buffSize,uint8_t ofestPtr);

void demCircBufferApend(demCircBufferBuff * dataS,i2c_sdk_st data2apend);

uint16_t demCircBufferAmauntData(demCircBufferBuff * dataS);

bool demCircBufferGetData(demCircBufferBuff * dataS,i2c_sdk_st * dato,i2c_sdk_st * datoOff);

void demCircBufferGetDataBetweenPtr(demCircBufferBuff * dataS,i2c_sdk_st * dato);

void demCircBufferGetDataBetweenPtrSinInc(demCircBufferBuff *dataS, i2c_sdk_st *dato);

#endif //DEMODULADORFSK_DEMCIRCBUFFER_H
