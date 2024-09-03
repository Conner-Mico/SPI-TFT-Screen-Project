#ifndef FT6206_DRIVER_H
#define FT6206_DRIVER_H

#include "FT6206_types.h"

// Device Register Addresses
const uint8_t DEV_MODE = 0x00; //Congifures operating mode of chip. We want "WORKING MODE" which is value 0x00
const uint8_t GEST_ID = 0x01; //Describes gesture from a valid touch event
const uint8_t TD_STATUS = 0x02; //Provides number of active touch points
const uint8_t P1_XH = 0x03; //MSB of Touch Point 1's X coordinate and Event Flag
const uint8_t P1_XL = 0x04; //LSB of Touch Point 1's X coordinate
const uint8_t P1_YH = 0x05; //MSB of Touch Point 1's Y coordinate and Touch ID
const uint8_t P1_YL = 0x06; //LSB of Touch Point 1's Y coordinate
const uint8_t P1_WEIGHT = 0x07; //Touch Point 1's pressure value
const uint8_t P1_MISC = 0x08; //Touch Pont 1's Touch Area value
const uint8_t P2_XH = 0x09; //MSB of Touch Point 2's X coordinate and Event Flag
const uint8_t P2_XL = 0x0A; //LSB of Touch Point 2's X coordinate
const uint8_t P2_YH = 0x0B; //MSB of Touch Point 2's Y coordinate and Touch ID
const uint8_t P2_YL = 0x0C; //LSB of Touch Point 2's Y coordinate
const uint8_t P2_WEIGHT = 0x0D; //Touch Point 2's pressure value
const uint8_t P2_MISC = 0x0E; //Touch Pont 2's Touch Area value

const uint8_t TH_GROUP = 0x80; //Threshold for touch detection

const uint8_t TH_DIFF = 0x85; //Filter function coefficient
const uint8_t CTRL = 0x86; //Enables/disables ability to move from Active Mode to Monitor Mode automatically 
const uint8_t TIME_ENTER_MONITOR = 0x87; //Time period for switching from Active Mode to Monitor Mode after no touch
const uint8_t PERIOD_ACTIVE = 0x88; //Report rate in Active Mode (seems like a more appropriate name would include "RATE" over "PERIOD", but folloed datasheet)
const uint8_t PERIOD_MONITOR = 0x89; //Report rate in Monitor Mode (seems like a more appropriate name would include "RATE" over "PERIOD", but folloed datasheet)

const uint8_t RADIAN_VALUE = 0x91; //Minimum allwed angle in rotating gesture
const uint8_t OFFSET_LEFT_RIGHT = 0x92; //Maximum offset for moving left or right gestures
const uint8_t OFFSET_UP_DOWN = 0x93; //Maximum offset for moving up or down gestures
const uint8_t DISTANCE_LEFT_RIGHT = 0x94; //Minimum distance for moving left or right gestures
const uint8_t DISTANCE_UP_DOWN = 0x95; //Minimum distance for moving up or down gestures
const uint8_t DISTANCE_ZOOM = 0x96; //Minimum distance for zoom in or out gestures

const uint8_t LIB_VER_H = 0xA1; //LIB version info upper byte
const uint8_t LIB_VER_L = 0xA2; //LIB version info lower byte
const uint8_t CIPHER = 0xA3; //Chip selecting? Need to read more
const uint8_t G_MODE = 0xA4; //Sets interrup mode (polling vs trigger)
const uint8_t PWR_MODE = 0xA5; //Current power mode the system is in
const uint8_t FIRMID = 0xA6; //Firmware version

const uint8_t FOCALTECH_ID = 0xA8; //FocalTech's Panel ID (irrelevant?)

const uint8_t RELEASE_CODE_ID = 0xAF; //Release code version

const uint8_t STATE = 0xBC; //Current operating mode

//Device ID's
const uint8_t FT6206_VENDID = 0x11;
const uint8_t FT6206_CHIPID = 0x06;

//I2C Bus Addresses
const uint8_t FT6206_BASE_ADDRESS = 0x38; //Pulled from Adafruit's circuit python library. Needs confirmation. Could not find address in FT6206 datasheet. 
const uint8_t FT6206_READ_ADDRESS = (FT6206_BASE_ADDRESS << 1) | 0x01;
const uint8_t FT6206_WRITE_ADDRESS = FT6206_BASE_ADDRESS << 1;

//Function Prototypes
void FT6206Init(const FT6206_t *FT6206_handle);
void FT6202_configRegisterWrite(const FT6206_t *FT6206_handle);
void FT6202_configRegisterRead(const FT6206_t *FT6206_handle);
void FT6202_dataRegisterWrite(const FT6206_t *FT6206_handle);
void FT6202_dataRegisterRead(const FT6206_t *FT6206_handle);


#endif