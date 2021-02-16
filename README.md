<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Gain and Offset Calibration of the Analog Signal Conditioning (OPAMP) Peripheral

A new feature introduced in the AVR® DB MCU is the Analog Signal Conditioning (OPAMP) peripheral. The OPAMP peripheral can be configured as a PGA and in this example, the internal DAC and ADC are used to calibrate the gain and offset for the PGA. For more information on the calibration procedure, see the [application note](https://microchip.com/DS00003633).   

## Related Documentation

* [AN3633 - Gain and Offset Calibration of the Analog Signal Conditioning (OPAMP) Peripheral](https://microchip.com/DS00003633)
* [AVR128DB48 Curiosity Nano User Guide](https://www.microchip.com/DS50003037)
* [AVR128DB48 Device Page](https://www.microchip.com/wwwproducts/en/AVR128DB48)

## Software Used
* [MPLAB® X](https://www.microchip.com/mplab/mplab-x-ide) v5.45 or later
* [MPLAB® XC8 Compiler](https://www.microchip.com/mplab/compilers) v2.31 or later
* MPLABX AVR-Dx_DFP version 1.6.88 or later
* For the START based Microchip Studio version of this project, please go to [this repository](https://github.com/microchip-pic-avr-examples/avr128db48-opamp-gain-and-offset-calibration-studio-start)

## Hardware Used

* [AVR128DB48 Curiosity Nano](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV35L43A)

## Setup

* No external hardware setup needed

## Demo Configuration
* Connect the AVR128DB48 Curiosity Nano to a computer using a USB cable
* Download the *.zip file or clone the example to get the source code
* Open `avr128db48-opamp-gain-and-offset-calibration-mplab-mcc.X` in MPLAB X
* Press the make and program button to program the device
* If no tool has been chosen, a window will open, select the AVR128DB48 Curiosity Nano. The tool can also be choosen in the project settings. 

## Conclusion
After going through this example you should be able to calibrate the gain and offset of the OPAMP configured as a PGA.
