#include "FT6206_driver.h"
#include "FT6206_regs.h"
#include "FT6206_types.h"
#include "assert.h"
#include "utility.h"
#include <stdint.h>

static void FT62062_configRegisterWrite(const FT6206_t *FT6206_handle)
{
    //Determine data/transaction size based on reg if necessary
    //Begin I2C transaction w/ address and write bit
    //send target register
    //write data
    //End I2C transaction
}

static void FT62062_configRegisterRead(const FT6206_t *FT6206_handle)
{
    //Determine data/transaction size based on reg if necessary
    //Begin I2C transaction w/ address and write bit
    //send target register
    //read data
    //End I2C transaction    
}

static void FT62062_dataRegisterWrite(const FT6206_t *FT6206_handle)
{
    //Determine data/transaction size based on reg if necessary
    //Begin I2C transaction w/ address and write bit
    //send target register
    //write data
    //End I2C transaction
}

static void FT62062_dataRegisterRead(const FT6206_t *FT6206_handle)
{
    //Determine data/transaction size based on reg if necessary
    //Begin I2C transaction w/ address and write bit
    //send target register
    //read data
    //End I2C transaction    
}

static void FT6202Init(const FT6206_t *FT6206_handle)
{
    //Do some initialization stuff here of the configuration registers
    //May need to do a check to see if IC is in hibernate mode. Could potentially just issue reset to begin with. 
}

