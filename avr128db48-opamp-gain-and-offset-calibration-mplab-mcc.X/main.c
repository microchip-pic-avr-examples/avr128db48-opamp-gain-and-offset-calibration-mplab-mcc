 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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


int main(void)
{
    SYSTEM_Initialize();
    
    PGA_Calibrate();
    
    while(1)
    {
    }    
}