/*
 * Config_HW.h
 *
 * Created on: 30 March 2017
 * author:    Andras Kun (kun.andras@yahoo.de)
 * Source :   https://github.com/neskweek/LightSaberOS
 * This tab contains all settings necessary to define your saber board's electronic hardware configuration
 */


#if not defined CONFIG_HW_H_
#define CONFIG_HW_H_

/* Board definitions
 *  Define what kind of Arduino compatible board you have in your saber.
 *  DIYino Prime and Stardust are both dedicated, fully integrated
 *  saber boards manufactured by ProtoWerkstatt.
 *  For more information on DIYino products, see:
 *  https://github.com/Protonerd/DIYino
 *  https://www.facebook.com/ProtoWerkstatt-740015792832712/
 *  If you have a home-brew solution using the Arduino Nano, choose DIYINO_PRIME below
 */

#define DIYINO_PRIME
//#define DIYINO_STARDUST

/***** BOARD PINOUT DEFINITIONS ******/

/*
 * Definition of the MAIN and AUX buttons of your saber.
 * These 2 buttons are used to interact with the saber electronics in the hilt
 * With the SINGLEBUTTON compile directive you can configure your saber electronics
 * to use only a single button to interact with your board.
 */

// If your saber has only a single button to interact with the electronics, uncomment the next line
// in case you have 2 buttons (referred to as main and aux buttons) leave this line commented out

//#define SINGLEBUTTON
 
#ifdef DIYINO_PRIME 
  #define MAIN_BUTTON     12
  #ifndef SINGLEBUTTON
    #define AUX_BUTTON   4
  #endif
#else if DIYINO_STARDUST
  #define MAIN_BUTTON      12
  #ifndef SINGLEBUTTON
    #define AUX_BUTTON   11 // 2
  #endif
#endif


/*
 * BLADE TYPE
 *
 * RGB LED OR PIXELBLADE users:
 * Comment the following line will
 * disable and remove all LEDSTRINGS
 * blocks from compile
 *************************************/
//#define LEDSTRINGS
//#define STAR_LED
#define PIXELBLADE

/*
 * POWER SAVING CIRCUITRY
 * Definition of the power switches (DIYino Prime v1.5 or greater, STARDUST
 * The MP3 power switch will cut power to the MP3 chipset as well as disable the audio amp
 * The FTDI power switch will cut power to the Serial-to-UART FTDI chipset, saving power and
 * allowing a PC to access the SD-card or SPI flash via the MP3 chipset over USB.
 * Enable DEEP_SLEEP in software config to make use of the power saving options.
 */
#ifdef DIYINO_PRIME 
  #define MP3_PSWITCH 15 // A1
  #define FTDI_PSWITCH 16 // A2
#else if DIYINO_STARDUST 
  #define MP3_PSWITCH 17 // A3
  #define FTDI_PSWITCH 16 // A2
#endif
/*
 * General configuration for the main saber blade illumination types
 * STAR_LED refers to an in-hilt high-power LED module, usually of type RGB for color mixing, but can be a single LED type or any combination
 * of colors and LED dice up to 3 (more can be configured on demand, up to 6 with DIYino Prime
 * PIXELBLADE defines a neopixel stripe running the length of the blade. For more information on neopixels, see: https://www.adafruit.com/category/168
 * Currently supported chip set: WS2812B
 * LEDSTRINGS are commonly known as segmented LED strings and represent a blade type where thru-hole LEDs of a single color are connected in parallel
 * along the length of the blade. Currently supported number of segments: 6 (like Hasbro high-end and Plecter boards among others)
 */



  #ifdef DIYINO_PRIME 
    #define LED_RED       3
    #define LED_GREEN       5
    #define LED_BLUE      6
  #else if DIYINO_STARDUST
    #define LED_RED       5
    #define LED_GREEN       6
    #define LED_BLUE      9
  #endif

  // How many leds in one strip?
  #define NUMPIXELS 60  // can go up to 120, could lead to memory overflow if further increased, causing instability

  
  // For led chips like NEOPIXELs, which have a data line, ground, and power, you just
  // need to define DATA_PIN.
  #define DATA_PIN       13 // D13
  
  #ifdef CROSSGUARDSABER
    // define how many pixels are used for the crossguard and how many for the main blade
    #define CG_STRIPE 10 // cross guard stripe length
    #define MN_STRIPE 50 // main blade stripe length
  #endif


  #ifdef DIYINO_PRIME
    #define LS1       3
    #define LS2       5
    #define LS3       6
    #define LS4       9
    #define LS5       10
    #define LS6       11
  #else if DIYINO_STARDUST
    #define LS1       5
    #define LS2       6
    #define LS3      9
  #endif
  /*
   * FoCSTRING
   * Enable/disable management of
   * single Flash On Clash ledstring
   *************************************/
  //#define FoCSTRING      14

/*
 * BUTTON ACCENT_LED
 * Enable/disable management of
 * a button accent led
 *************************************/
#define ACCENT_LED  14 //A0

//#define MULTICOLOR_ACCENT_LED
#if defined MULTICOLOR_ACCENT_LED
#define RED_ACCENT_LED  16 //A2
#define GREEN_ACCENT_LED  17 //A3
#define BLUE_ACCENT_LED  A7  //.... A7 is input only ...
#endif



#define DFPLAYER_RX      8
#define DFPLAYER_TX     7
#define SPK1        20 //A6
#define SPK2        21 //A7




#define BUTTONLEDPIN 16 //A2

#define BATTERY_CHECK // comment to disable
#ifdef BATTERY_CHECK
  #ifdef DIYINO_PRIME
    #define BATTERY_READPIN 17 //A3 - read battery level
  #endif
  #ifdef DIYINO_STARDUST
    #define BATTERY_READPIN 15
  #endif
#endif


/************************************/
/*
 * SABER TYPE
 * currently in v1.3 only the CROSSGUARDSABER
 * will have any effect on the code
 * due to the fire blade effect
 *************************************/
#define SINGLEBLADE  // i.e. Graflex
//#define SABERSTAFF  // i.e. Darth Maul saber with dual blades
//#define CROSSGUARDSABER  // i.e. Kylo Ren saber




/*!!!!!IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT!!!
 *
 * MPU6050 device ORIENTATION
 * Choose which MPU's axis is parallel
 * to your blade axis
 *************************************/
//#define BLADE_X
#define BLADE_Y
//#define BLADE_Z
/************************************/

/*
 * MPU6050 calibrated offset values
 * If defined, calibration values will be retrieved from EEPROM
 * use this option if the MPU6050_calibration sketch wrote the calibrated offsets
 * into the EEPROM (default address is 96)
 * If not defined, you have to note down the calibrated offset values
 * and assign them to the respective variables in the code.
 *************************************/
#define MPUCALOFFSETEEPROM
#ifdef MPUCALOFFSETEEPROM
  #define MEMORYBASEMPUCALIBOFFSET 200 // 96 -> increased to 200 due to storing RGB PWM values in EEPROM takes a lot of space (3 x 1byte x 3 color types x nr of sound fonts i.e. for 5 sound fonts 45 bytes
#endif

#endif /* CONFIG_HW_H_ */

