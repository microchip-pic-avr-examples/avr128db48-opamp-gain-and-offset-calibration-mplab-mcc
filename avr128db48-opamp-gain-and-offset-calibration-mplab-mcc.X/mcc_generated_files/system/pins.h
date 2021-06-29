/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set OPAMP0_OUT aliases
#define OPAMP0_OUT_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define OPAMP0_OUT_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define OPAMP0_OUT_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define OPAMP0_OUT_GetValue() (VPORTD.IN & (0x1 << 2))
#define OPAMP0_OUT_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define OPAMP0_OUT_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define OPAMP0_OUT_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define OPAMP0_OUT_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define OPAMP0_OUT_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define OPAMP0_OUT_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define OPAMP0_OUT_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define OPAMP0_OUT_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define OPAMP0_OUT_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define OPAMP0_OUT_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define OPAMP0_OUT_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define OPAMP0_OUT_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DAC0_OUT aliases
#define DAC0_OUT_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define DAC0_OUT_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define DAC0_OUT_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define DAC0_OUT_GetValue() (VPORTD.IN & (0x1 << 6))
#define DAC0_OUT_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define DAC0_OUT_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define DAC0_OUT_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DAC0_OUT_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DAC0_OUT_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define DAC0_OUT_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DAC0_OUT_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DAC0_OUT_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DAC0_OUT_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DAC0_OUT_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DAC0_OUT_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DAC0_OUT_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PD2_DefaultInterruptHandler(void);
void PD2_SetInterruptHandler(void (* interruptHandler)(void)) ; 
void PD6_DefaultInterruptHandler(void);
void PD6_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
