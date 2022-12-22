/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F26K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "Modbas_RTU.h"

#define test1bit(var, bit) ((var) & (1 <<(bit)))
#define setbit(var, bit) ((var) |= (1 << (bit)))
#define clrbit(var, bit) ((var) &= ~(1 << (bit)))


//volatile uint8_t rxData[5];
//void my_rx_sartISR(void);
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
   
   EUSART_SetRxInterruptHandler(USART_RXC_vect);
   EUSART_SetTxInterruptHandler(USART_TXC_vect);
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
   INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
   INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
  struct {
           unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
         } bitt;
   char toggle=0;
   uint8_t address = (0XE6)>>1;
   uint8_t dat[3]={0X30,0X64,0XC0};
   uint8_t red[3]={0x1C};
   uint8_t red2[3];
   
   
    while (1)
    {
        
        //
         if(IO_RA2_GetValue() && !bitt.b0 )
         {
             IO_RA0_SetHigh();
             
             
              //I2C_Write2ByteRegister((0XE6)>>1,0X30,0X64C0);
              I2C_WriteNBytes(address,dat,3);
              //I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len);
              I2C_WriteNBytes((0xD0)>>1,red,1);
              //I2C_ReadNBytes(0xD0,0x1C,2);
              I2C_ReadNBytes((0xD1)>>1, red2 , 3);
              
              bitt.b0=1;
              
         }
         else if(!IO_RA2_GetValue() && bitt.b0)
         {
             IO_RA0_SetLow();
             bitt.b0=0;
         }
         if(TXSTAbits.TRMT && USART_UDR_vect)
         {
             USART_UDRE_vect (); 
             
         }
           modbasRtu_Slave();
        // Add your application code
    }
   
}
//void my_rx_sartISR(void)
//   {
//         static uint8_t cnt;
//
//         if(cnt==2)cnt=0;
//         rxData[cnt] = RCREG;
//         cnt++;
//
//         if (rxData[0]==0xD && rxData[1]==0xD) 
//             {
//                 IO_RA1_Toggle();
//                 rxData[0]=0;
//                 rxData[1]=0;
//                 cnt=0;
//             }
//        
//   }
/**
 End of File
*/