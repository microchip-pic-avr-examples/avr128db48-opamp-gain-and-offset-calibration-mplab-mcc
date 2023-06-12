/**
 * ADC0 Generated Driver API Header File
 * 
 * @file adc0.h
 * 
 * @defgroup adc0 ADC0
 * 
 * @brief API prototypes and other datatypes for the ADC0 module driver.
 *
 * @version ADC0 Driver Version 1.0.0
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


#ifndef ADC0_H_INCLUDED
#define ADC0_H_INCLUDED

#include "../system/utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup adc0
 * @enum ADC0_window_mode_t
 * @brief Window Comparator Modes
 */
typedef enum {
    ADC0_window_disabled,  /**<Window Comparison is Disabled*/
    ADC0_window_below,     /**<Result is below a threshold*/
    ADC0_window_above,     /**<Result is above a threshold*/
    ADC0_window_inside,    /**<Result is inside a window*/
    ADC0_window_outside    /**<Result is outside a window*/
} ADC0_window_mode_t;

/**
 * @ingroup adc0
 * @typedef void adc_irq_cb_t
 * @brief Function pointer to callback function called by IRQ. NULL=default value: No callback function is to be used.
 */
typedef void (*adc_irq_cb_t)(void);

/**
 * @ingroup adc0
 * @typedef uint32_t adc_result_t
 * @brief Datatype for the result of non-differential ADC conversion.
 */
typedef uint16_t adc_result_t;

/**
 * @ingroup adc0
 * @typedef int32_t diff_adc_result_t
 * @brief Datatype for the result of differential ADC conversion.
 */
typedef int16_t diff_adc_result_t;

/**
 * @ingroup adc0
 * @typedef ADC_MUXPOS_t adc_0_channel_t
 * @brief Datatype for the ADC Positive Input Selection
 */
typedef ADC_MUXPOS_t adc_0_channel_t;

/**
 * @ingroup adc0
 * @typedef ADC_MUXNEG_t adc_0_muxneg_channel_t
 * @brief Datatype for the ADC Negative Input Selection
 */
typedef ADC_MUXNEG_t adc_0_muxneg_channel_t;

/**
 * @ingroup adc0
 * @brief Initializes ADC interface. If module is configured to disabled state, the clock to the ADC is disabled if this is supported by the device's clock system.
 * @param none
 * @retval 0 - the ADC init was successful
 * @retval 1 - the ADC init was not successful
 */
int8_t ADC0_Initialize(void);

/**
 * @ingroup adc0
 * @brief Enables ADC0. If supported by the clock system, enables the clock to the ADC. Enables the ADC module by setting the enable-bit in the ADC control register.
 * @param none
 * @return none
 */
void ADC0_Enable(void);

/**
 * @ingroup adc0
 * @brief Disables ADC0. Disables the ADC module by clearing the enable-bit in the ADC control register. If supported by the clock system, disables the clock to the ADC.
 * @param none
 * @return none
 */
void ADC0_Disable(void);

/**
 * @ingroup adc0
 * @brief Enables conversion auto-trigger
 * @param none
 * @return none
 */
void ADC0_EnableAutoTrigger(void);

/**
 * @ingroup adc0
 * @brief Disables conversion auto-trigger
 * @param none
 * @return none
 */
void ADC0_DisableAutoTrigger(void);

/**
 * @ingroup adc0
 * @brief Sets conversion window comparator high threshold
 * @param adc_result_t high - desired window comparator high threshold register value
 * @return none
 */
void ADC0_SetWindowHigh(adc_result_t high);

/**
 * @ingroup adc0
 * @brief Sets conversion window comparator low threshold
 * @param adc_result_t low - desired window comparator low threshold register value
 * @return none
 */
void ADC0_SetWindowLow(adc_result_t low);

/**
 * @ingroup adc0
 * @brief Sets conversion window mode
 * @param ADC0_window_mode_t mode - window mode
 * @return none
 */
void ADC0_SetWindowMode(ADC0_window_mode_t mode);

/**
 * @ingroup adc0
 * @brief Sets ADC channel to be used for windowed conversion mode
 * @param adc_0_channel_t channel - The ADC channel to start conversion on
 * @return none
 */
void ADC0_SetWindowChannel(adc_0_channel_t channel);

/**
 * @ingroup adc0
 * @brief Starts a conversion on ADC0
 * @param adc_0_channel_t channel - The ADC channel to start conversion on
 * @return none
 */
void ADC0_StartConversion(adc_0_channel_t channel);

 /**
 * @ingroup adc0
 * @brief Starts a differential conversion on ADC0
 * @param adc_0_channel_t channel - The ADC positive input channel to start conversion on
 * @param adc_0_muxneg_channel_t channel1 - The ADC negative input channel to start conversion on
 * @return none
 */
void ADC0_StartDiffConversion(adc_0_channel_t channel, adc_0_muxneg_channel_t channel1);

 /**
 * @ingroup adc0
 * @brief Stops a conversion on ADC0
 * @param none
 * @return none
 */
void ADC0_StopConversion(void);

/**
 * @ingroup adc0
 * @brief Checks if the ADC conversion is done
 * @param none
 * @retval 1 (true) - The ADC conversion is done
 * @retval 0 (false) - The ADC converison is not done
 */
bool ADC0_IsConversionDone(void);

/**
 * @ingroup adc0
 * @brief Reads a conversion result from ADC0
 * @param none
 * @return adc_result_t - Conversion result read from the ADC0 module
 */
adc_result_t ADC0_GetConversionResult(void);

/**
 * @ingroup adc0
 * @brief Reads the conversion window result from ADC0
 * @param none
 * @retval 1 (true) - a comparison results in a trigger condition
 * @retval 0 (false) - a comparison does not result in a trigger condition.
 */
bool ADC0_GetWindowResult(void);

/**
 * @ingroup adc0
 * @brief Starts a conversion, wait until ready, and return the conversion result
 * @param adc_0_channel_t channel - The ADC channel to get the conversion result
 * @return adc_result_t - Conversion result read from the ADC0 ADC module
 */
adc_result_t ADC0_GetConversion(adc_0_channel_t channel);

 /**
 * @ingroup adc0
 * @brief Starts a differential conversion, wait until ready, and return the conversion result
 * @param adc_0_channel_t channel - The ADC positive input channel to get the conversion result
 * @param adc_0_muxneg_channel_t channel1 - The ADC negative input channel to get the conversion result
 * @return diff_adc_result_t - Conversion result read from the ADC0 ADC module
 */
diff_adc_result_t ADC0_GetDiffConversion(adc_0_channel_t channel, adc_0_muxneg_channel_t channel1);

/**
 * @ingroup adc0
 * @brief Returns the number of bits in the ADC conversion result
 * @param none
 * @return uint8_t - The number of bits in the ADC conversion result
 */
uint8_t ADC0_GetResolution(void);

/**
 * @ingroup adc0
 * @brief Registers a callback function to be called if conversion satisfies window criteria.
 * @param adc_irq_cb_t f - Pointer to function to be called
 * @return none
 */
void ADC0_RegisterWindowCallback(adc_irq_cb_t f);

/**
 * @ingroup adc0
 * @brief Registers a callback function to be called when measurement is complete and a new result is ready.
 * @param adc_irq_cb_t f - Pointer to function to be called
 * @return none
 */
void ADC0_RegisterResrdyCallback(adc_irq_cb_t f);

#ifdef __cplusplus
}
#endif

#endif /* ADC0_H_INCLUDED */