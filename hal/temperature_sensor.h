/***************************************************************************//**
  @file     temperature_sensor.h
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
 ******************************************************************************/

#ifndef TEMPERATURE_SENSOR
#define TEMPERATURE_SENSOR

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef enum { CELSIUS,
               FAHRENHEIT,
               UNITS_N
             } temp_unit_t;

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/**
 * CUIDADO!!!!!!!!!!!!!!!!!!!!!
 * Previo a la utilizacion de la biblioteca, llamar a la
 * funacion i2c_sdk_init de i2c_sdk.h
 */

/**
* @brief Inicio la medicion de temperatura
*
*/
void temp_initMeasure(void);

/**
* @brief Devuelve el estado del sensor de temperatura
*@return:si devuelve false, el sensor esta realizando la medicion
*en el caso contrario(true), la medicion esta lista
*/
bool temp_status(void);

/**
 * @brief Returns current temp
 * 
 * @param uni 
 * @return int: temp in  of degree
 * Example: if current temp = 37.5, returns 37.5
 */
float temp_get_temp(temp_unit_t unit);





/*******************************************************************************
 ******************************************************************************/


#endif /* TEMPERATURE_SENSOR */
