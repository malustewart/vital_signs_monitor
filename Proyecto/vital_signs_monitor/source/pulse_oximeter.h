/***************************************************************************//**
  @file     pulse_oximeter.h
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
 ******************************************************************************/

#ifndef PULSE_OXIMETER
#define PULSE_OXIMETER

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include<stdint.h>
#include<stdbool.h>
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define PULSE_OXIMETER_ONE_SAMPLE 1
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/** @ brief realiza la inicializacion del MAX30102,
 * previamente deve estar inicializado el driver de i2c
 */
void pulse_oximeter_init(void);

/**@brief devuelve la medicion de ritmo caridaco en ppm
 * @param devuele en hr[] las pulsaciones en ppm
 * @return si es true el contenido de hr[] es valido
 */
bool pulse_oximeter_hrReady(uint32_t hr[PULSE_OXIMETER_ONE_SAMPLE]);

/**@brief devuelve la medicion de spo2 en %
 * @param devuele en spo2[] la concentracion de oxigeno en sangre
 * @return si es true el contenido de spo2[] es valido
 */
bool pulse_oximeter_spo2Ready(float spo2[PULSE_OXIMETER_ONE_SAMPLE]);

/**@brief cada vez que se acumulen las 100 muestras de la lectura del ir y red
 * se aplica el algoritmo para obtener el pulso y spo2. Despues de llamar a esta funcion, ejecutar
 * pulse_oximeter_xxReady
 * @param redData[] valor de la ultima lecura del sensor red
 * @param irData[] valor de la ultima lecura del sensor red
 * @return true, el valor de redData y irData es valido
 */
bool pulse_oximeter_update(uint32_t redData[PULSE_OXIMETER_ONE_SAMPLE],uint32_t irData[PULSE_OXIMETER_ONE_SAMPLE]);


/*******************************************************************************
 ******************************************************************************/


#endif /* PULSE_OXIMETER */
