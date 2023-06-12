/**
 * DAC0 Generated Driver File
 * 
 * @file dac0.c
 * 
 * @ingroup dac0
 * 
 * @brief Contains the API implementations for the DAC0 driver.
 *
 * @version DAC0 Driver Version 1.0.0
*/
/*
� [2023] Microchip Technology Inc. and its subsidiaries.

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



#include "../dac0.h"

int8_t DAC0_Initialize(void)
{
    // DATA Register 
	DAC0.DATA = 0x0;
    // ENABLE enabled; OUTEN enabled; RUNSTDBY disabled; 
	DAC0.CTRLA = 0x41;

    return 0;
}

void DAC0_Enable(void)
{
    DAC0.CTRLA |= DAC_ENABLE_bm;
}

void DAC0_Disable(void)
{
    DAC0.CTRLA &= ~DAC_ENABLE_bm;
}

void DAC0_SetOutput(dac_resolution_t value)
{
    value     = value << DAC_DATA_gp;
	value     = value & 0xFFC0;
    DAC0.DATA = value;
}

uint8_t DAC0_GetResolution(void)
{
    return 10;
}