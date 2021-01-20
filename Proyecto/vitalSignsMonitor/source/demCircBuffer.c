//
// Created by Matias Pierdominici on 10/24/2019.
//

#include "demCircBuffer.h"

void demCircBufferInit(demCircBufferBuff * dataS, i2c_sdk_st * buffer,uint16_t buffSize,uint8_t ofestPtr){
    dataS->data=buffer;
    dataS->dataSize=buffSize;
    dataS->head=0;
    dataS->read=0;
    dataS->off=ofestPtr;
    dataS->offPtr=dataS->dataSize - dataS->off;
}

void demCircBufferApend(demCircBufferBuff * dataS,i2c_sdk_st data2apend){
    (dataS->data)[dataS->head]=data2apend;//agrego el dato al buffer
    dataS->head++;
    dataS->head%=dataS->dataSize; //reinicio el buffer
}

uint16_t demCircBufferAmauntData(demCircBufferBuff * dataS){
    if(dataS->head >= dataS->read){
        return dataS->head - dataS->read;
    }else{
        return dataS->dataSize - dataS->read + dataS->head;
    }
}

bool demCircBufferGetData(demCircBufferBuff * dataS,i2c_sdk_st * dato,i2c_sdk_st * datoOff){
    *dato=(dataS->data)[dataS->read];
    *datoOff=(dataS->data)[dataS->offPtr];
    dataS->read++;
    dataS->offPtr++;
    dataS->read%=dataS->dataSize;
    dataS->offPtr%=dataS->dataSize;
}

void demCircBufferGetDataBetweenPtr(demCircBufferBuff *dataS, i2c_sdk_st *dato) {
    uint16_t offT=0;
    offT=dataS->offPtr;

    for(int i=0;i<dataS->off+1;i++){
        dato[dataS->off-i]=dataS->data[offT];
        offT++;
        offT%=dataS->dataSize;
    }

    i2c_sdk_st t1;
    i2c_sdk_st t2;
    demCircBufferGetData(dataS,&t1,&t2);

}

void demCircBufferGetDataBetweenPtrSinInc(demCircBufferBuff *dataS, i2c_sdk_st *dato) {
    uint16_t offT=0;
    offT=dataS->offPtr;

    for(int i=0;i<dataS->off+1;i++){
        dato[dataS->off-i]=dataS->data[offT];
        offT++;
        offT%=dataS->dataSize;
    }


}

