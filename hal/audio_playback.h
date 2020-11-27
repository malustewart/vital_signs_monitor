/***************************************************************************//**
  @file     audio_playback.h
  @brief    ...
  @author   Maria Luz Stewart Harris, Matias Pierdominici, Gonzalo Silva
 ******************************************************************************/

#ifndef AUDIO_PLAYBACK
#define AUDIO_PLAYBACK

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/


/**
 * @brief Identifies pre-stored recordings. 
 * Recordings cannot be added or modified in runtime.
 */
typedef enum { LOW_BPM, 
               HIGH_BPM, 
               LOW_SPO2, 
               HIGH_SPO2, 
               LOW_TEMP,
               HIGH_TEMP, 
               AUDIO_RECORDING_N
             } ap_recording_t;

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Play a recording
 * 
 * @param recording: identifies recording to be played
 * @return int: 1 if recording was and played, 0 otherwise.
 */
int ap_play_recording(ap_recording_t recording);

/*******************************************************************************
 ******************************************************************************/


#endif /* AUDIO_PLAYBACK */