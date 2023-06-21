/*
 * DAC8574.h
 *
 *  Created on: 23 juil. 2022
 *      Author: Pavel Orlov
 */

#ifndef DAC8574_LIB_H_
#define DAC8574_LIB_H_

#include <stdio.h>
#include <stdint.h>


#define DAC8574_ADD 0x98
#define DAC8574_CTR 0x34 // broadcast to all dac channels

void SetDAC(int channel, uint16_t value);  





#endif /* DAC8574_LIB_H_ */