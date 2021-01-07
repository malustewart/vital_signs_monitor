/***************************************************************************//**
  @file     idc_sdk.c
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
 ******************************************************************************/

#ifndef I2C_SDK_H_
#define I2C_SDK_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "MK64F12.h"
#include <stdint.h>
#include <stddef.h>
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef enum
{
	i2c_sdk_EN_PROCESO, //el perifierio se encuentra en uso
	i2c_sdk_REPOSO, //el periferio no esta realizando ninguna accion
	i2c_sdk_ERROR  //hubo un error en la transaccion
} i2c_sdk_status_t;


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Inicializa el i2c0, con sda(PTE25) y scl(PTE24)
 *
 * @param void
 * @return void
 */
 void i2c_sdk_init(void);

 /**
  * @brief Escrive en un registro de un dispositivo conectado al i2c
  *
  * @param adress: direccion del dispositivo
  * @param reg: registro al cual se le realiza la escritura
  * @param data:  arreglo con la informacion a enviar
  * @param sizeData: cantidad de bytes en data
  * @return void
  */
 void i2c_sdk_readReg(uint8_t adress,uint8_t reg, uint8_t * volatile data,uint8_t sizeData);

 /**
  * @brief Leo el contenido de un registro de un periferico
  *
  * @param adress: direccion del dispositivo
  * @param reg: registro al cual se le realiza la lectura
  * @param data:  arreglo con la informacion a recivir
  * @param sizeData: cantidad de bytes en data
  */
 void i2c_sdk_writeReg(uint8_t adress,uint8_t reg, uint8_t * volatile data,uint8_t sizeData);

 /**
  * @brief Devuelve en que estado se encuentra el periferico
  */
 i2c_sdk_status_t i2c_sdk_status(void);


/*******************************************************************************
 ******************************************************************************/

#endif /* I2C_SDK_H_ */
