/**
 * OPAMP Generated Driver API Header File
 * 
 * @file opamp.h
 * 
 * @defgroup opamp OPAMP
 * 
 * @brief This file contains API prototypes and other datatypes for the OPAMP module.
 *
 * @version OPAMP Driver Version 1.0.0
*/ 
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef OPAMP_H_INCLUDED
#define OPAMP_H_INCLUDED

#include "../system/utils/compiler.h"
#include <stdbool.h>

#define OPAMP_TIMEBASE_VALUE (3)

/**
 * @ingroup opamp
 * @brief This routine initializes the OPAMP and must be called before any other OPAMP routine is called.
 * This routine should only be called once during system initialization.
 * @param void
 * @return void
 */
void OPAMP_Initialize(void);

/**
 * @ingroup opamp
 * @brief This routine enables the OPAMP System
 * @param void
 * @return void
 */
void OPAMP_EnableSystem(void);

/**
 * @ingroup opamp
 * @brief This routine disables the OPAMP System
 * @param void
 * @return void
 */
void OPAMP_DisableSystem(void);
        
//OP0 Non-Inverting Programmable Gain Amplifier APIs

/**
 * @ingroup opamp
 * @brief This routine sets OP0's positive input as per user selection
 * @param value - desired positive input. For the available positive inputs, refer to OPAMP_MUXPOS_t enum from the device header file
 * @return void
 */
void OPAMP_SetOP0PositiveInMux(OPAMP_OP0INMUX_MUXPOS_t value);

/**
 * @ingroup opamp
 * @brief This routine sets the R1 and R2 values of OP0's internal resistor ladder as per user selection
 * @param value - esired resistor selection. For the available resistor values, refer to OPAMP_MUXWIP_t enum from the device header file
 * @return void
 */
void OPAMP_SetOP0WiperResMux(OPAMP_OP0RESMUX_MUXWIP_t value);

/**
 * @ingroup opamp
 * @brief This routine sets OP0's settle time
 * @param settleTime - desired settle time of 0 to 127 in us
 * @return void
 */
void OPAMP_SetOP0SettleTime(uint8_t settleTime);

/**
 * @ingroup opamp
 * @brief This routine checks if OP0's settling time is finished
 * @param void
 * @retval true - if the allowed settling time is finished
 * @retval false - if the OP0 is waiting for settling, related to enabling or configuration changes
 */
bool OPAMP_IsOP0Settled(void);

/**
 * @ingroup opamp
 * @brief This routine sets OP0's offset calibration
 * @param calValue - desired offset
 * @return void
 */
void OPAMP_SetOP0OffsetCalibration(uint8_t calValue);
        
#endif /* OPAMP_H_INCLUDED */
