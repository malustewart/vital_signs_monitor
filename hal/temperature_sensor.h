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
 * @brief Returns current temp
 * 
 * @param uni 
 * @return int: temp in tenths of degree 
 * >= 0 if current temp is available.
 * -1 if current temp is not available
 * Example: if current temp = 37.5, returns 375. 
 */
int temp_get_temp(ap_unit_t unit);

/*******************************************************************************
 ******************************************************************************/


#endif /* TEMPERATURE_SENSOR */