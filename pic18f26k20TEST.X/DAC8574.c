/*
 * DAC8574
 *
 *  Created on: 23 juil. 2022
 *      Author: Pavel Orlov
 */
 
#include "DAC8574.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
 
 void SetDAC(int channel, uint16_t value)  
{
  uint8_t DACCmd = 0;
  switch (channel)
  {
   case 0:  DACCmd=  0x10; break;
   case 1:  DACCmd=  0x12; break;   
   case 2:  DACCmd=  0x14; break;   
   case 3:  DACCmd=  0x16; break;  
   default: break;
  }
  //I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len);
  uint8_t DAC8574_Data[3];
  
  DAC8574_Data[0] = DACCmd;
  DAC8574_Data[1] = (value & 0xFF00)>>8;
  DAC8574_Data[2] = (value & 0x00FF);
  I2C_WriteNBytes(DAC8574_ADD,DAC8574_Data,3);

 
  /*i2c_start();
  i2c_write(DAC8574_ADD);      // Device address 
  i2c_write(DACCmd); 
  i2c_write(value >> 8);     // Send MSB
  i2c_write(value);         // Send LSB
  i2c_stop();           // Stop condition
   */
}