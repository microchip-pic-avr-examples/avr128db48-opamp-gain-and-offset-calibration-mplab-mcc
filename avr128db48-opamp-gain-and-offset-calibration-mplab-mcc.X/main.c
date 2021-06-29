/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/
#include "mcc_generated_files/system/system.h"
#include <util/delay.h>

/* The DAC (Digital-to-Analog Converter) has 10-bit resolution and 2^10 = 1024
 * possible input values. DAC outputs of approximately 60 mV and 120 mV will be 
 * used to perform a two-point gain and offset measurement/calibration of the 
 * op amp gain stage. The calculation of the two DAC data values needed to 
 * generate the two output voltages are thus: 
 * (60 mV / 2500 mV) * 1024 = 25
 * (120 mV / 2500 mV) * 1024 = 49
 */
#define DAC_60_MV ((60 * 1024UL) / 2500UL)
#define DAC_120_MV ((120 * 1024UL) / 2500UL)

//Pins do to the ADC measurements on
#define DAC0_OUTPUT_PIN ADC_MUXPOS_AIN6_gc 
#define OPAMP0_OUTPUT_PIN ADC_MUXPOS_AIN2_gc

/* 
 * Floating-point value of the reference voltage (VREF) in mV for converting the
 * measured offset to mV. Set this value to the corresponding VREF output for 
 * DAC0 and ADC0. 
 */
#define VREF_MV 2500.0 

/* 
 * The AVR-DB ADC (Analog-to-Digital Converter) has 12-bit resolution and
 * 2^12 = 4096 possible output values. If using the 10-bit resolution, set to
 * 2^10 = 1024.
 */
#define ADC_MAX_VAL 4096

//The number of mV equivalent to one LSB change in the ADC output
#define MV_PER_ADC_LSB (VREF_MV/ADC_MAX_VAL)

//Number of measurements to average
#define N_AVERAGE 100

/* Number of microseconds to delay to allow the DAC0 and OPAMP0 output signal to
 * settle before doing the N_AVERAGE measurements with each DAC0 value. 
 * The value should be adjusted depending on the resulting settling time of the 
 * DAC0 and OPAMP0 when affected by external circuitry connected to their 
 * respective output pins (PD6 and PD2). The settle time can be significantly 
 * reduced if no external circuitry is connected to the output pins.
 */
#define SETTLE_TIME_US 1000

volatile struct PGA_calib_data {
    float gain; // Measured gain
    float offset; // Measured input offset in ADC units
    float offset_mv; // Measured input offset in mV
}calib_data;

/*
 * Perform N_AVERAGE measurements to calculate the PGA calibration data and 
 * store the results in the global 'calib_data' struct. 
 */
void PGA_Calibrate(void) 
{
    uint8_t n;
	int32_t accum_xa = 0, accum_ya = 0, accum_xb = 0, accum_yb = 0;
	float avg_xa, avg_ya, avg_xb, avg_yb ; 
 
    DAC0_SetOutput(DAC_60_MV);
    _delay_us(SETTLE_TIME_US);
    
    //Measure the PGA input and output values
    for(n = 0; n < N_AVERAGE; n++) {
        accum_xa += ADC0_GetConversion(DAC0_OUTPUT_PIN); 
        accum_ya += ADC0_GetConversion(OPAMP0_OUTPUT_PIN); 
    }
    
    DAC0_SetOutput(DAC_120_MV);
    _delay_us(SETTLE_TIME_US);
    
     //Measure the PGA input and output values
    for(n = 0; n < N_AVERAGE; n++) {
        accum_xb += ADC0_GetConversion(DAC0_OUTPUT_PIN); 
        accum_yb += ADC0_GetConversion(OPAMP0_OUTPUT_PIN); 
    }
      
    avg_xa = ((float) accum_xa)/((float) N_AVERAGE);
	avg_ya = ((float) accum_ya)/((float) N_AVERAGE);
	avg_xb = ((float) accum_xb)/((float) N_AVERAGE);
	avg_yb = ((float) accum_yb)/((float) N_AVERAGE);
    
    calib_data.gain = (avg_yb - avg_ya)/(avg_xb - avg_xa); 
	calib_data.offset = (avg_ya/calib_data.gain) - avg_xa; 
	calib_data.offset_mv = calib_data.offset * MV_PER_ADC_LSB;
    
    return; 
}



/*
    Main application
*/

int main(void)
{
    // Initializes MCU, drivers and middleware
    SYSTEM_Initialize();
    
    PGA_Calibrate(); 

    while(1)
    {
    }    
}