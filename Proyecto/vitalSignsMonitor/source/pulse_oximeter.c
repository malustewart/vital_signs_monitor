/***************************************************************************//**
  @file     pulse_oximeter.c
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "pulse_oximeter.h"
#include"MAX30102.h"
#include"algorithm_by_RF.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

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

/** @ brief realiza la inicializacion del MAX30102,
 * previamente deve estar inicializado el driver de i2c
 */
void pulse_oximeter_init(void){
	maxim_max30102_init(); //inicializo el MAX30102. frecuencia de sampleo 25HZ
}

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
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/*******************************************************************************
 *******************************************************************************
						            INTERRUPT SERVICE ROUTINES
 *******************************************************************************
 ******************************************************************************/

/******************************************************************************/


