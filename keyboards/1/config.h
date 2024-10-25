#pragma once

#define ENABLE_COMPILE_KEYCODE
#define FORCE_NKRO 
#define DEBOUNCE_TYPE DEBOUNCE_EAGER
#define DEBOUNCE 1
#define USB_POLLING_LATE_INTERVAL 0.125
#define KEYS_PER_SCAN 12

/* DIP switch */
#define DIP_SWITCH_PINS { D2 }

/* Indication led */
#define LED_MAC_OS_PIN C10
#define LED_WIN_OS_PIN C11
#define LED_OS_PIN_ON_STATE 1

/* The I2C Driver Configuration */
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

/* The SPI Driver Configuration */
// #define SPI_DRIVER SPID1
// #define SPI_SCK_PIN A5
// #define SPI_MOSI_PIN A7
// #define SPI_MISO_PIN A6
// #define CKLED2001_SPI_DIVISOR 21

/* EEPROM Driver Configuration */
#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)
