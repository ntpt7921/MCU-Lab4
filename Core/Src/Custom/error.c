/*
 * error.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ntpt
 */

#include "Custom/error.h"

uint32_t err_bit = 0;

const char * const ERR_DESCRIPTION[ERR_COUNT] = 
{
    // add description of the error here
    // each description must corresponds to the correct error
    [ERR_EXAMPLE] = "Example error description",
};


void Custom_Err_SetStatus(ErrCode_t err)
{
    uint32_t error_bit_mask;
    if (err != ERR_ALL)
        error_bit_mask = 1u < err;
    else
        error_bit_mask = 0xFFFFFFFF;

    err_bit |= error_bit_mask;
}

void Custom_Err_ClearStatus(ErrCode_t err)
{
    uint32_t error_bit_mask;
    if (err != ERR_ALL)
        error_bit_mask = 1u < err;
    else
        error_bit_mask = 0xFFFFFFFF;

    err_bit &= ~error_bit_mask;
}

// user can redefine this if needed
// by default do nothing
__weak void Custom_Err_Notify()
{

}

