/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */




/*************************************************************************************/
#define On 1
#define Off 0
#define Change_output 10
#define discrete_output_reading 11
#define address_Device 0x31
    
#define NUMBER_ANALOG_INPUT 10
#define NUMBER_ANALOG_Output 10 
#define NUMBER_Binary_inputs 10
#define NUMBER_Binary_Output  10 
    
 unsigned char Danie_Rx_ModbasRtu[30] = {},quantity_Data_ModbasRtu;
//volatile unsigned char Bit_action_ModbasRtu,DD;
 unsigned int  Danie_ModbasRtu_analog_input  [ NUMBER_ANALOG_INPUT ];
 unsigned int  Danie_ModbasRtu_analog_Output [ NUMBER_ANALOG_Output ];
 unsigned char Danie_ModbasRtu_Binary_input  [ (NUMBER_Binary_inputs / 8)+ 1 ];
 unsigned char Danie_ModbasRtu_Binary_Output [ (NUMBER_Binary_Output/ 8)+ 1 ];
 unsigned char Temp_ModbasRtu;
    struct 
    {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
    } Bit_action_ModbasRtu = {0,0,0},D;
unsigned char  USART_UDR_vect = 0;

/**************************************************************************************/
void TIMER0_COMP_vect(void);     //прерывание таймера T0
void USART_RXC_vect(void);        // прерывание по завершению приема байта данных
void USART_TXC_vect (void);         // прерывание по завершению отправки байта данных
void USART_UDRE_vect(void);        // прерывание регистр данных на передачю пуст

/*************************************************************************************/
    
    int crc_chk( unsigned char* data, unsigned char length );
    unsigned int ModbasRtu_Register_address(unsigned char Li);
    char Data_integrity();
    char _Bin_input_Output( register unsigned char NUMBER, register unsigned char state,volatile unsigned char *Masiv, volatile unsigned char Sd );
    void Changing_Discrete_Output(void);
    void Reading_Discrete_Output(unsigned char *Massiv, register unsigned char Number_);
    void Read_analog_input(unsigned char *Massiv, register unsigned char Number_, unsigned char Vt);
    void analog_output_recording(void);
    void Error_modbasRtu (volatile unsigned char Temp_Error);
    void check_sum ( register unsigned char Adress);
    void modbasRtu_Answer();
    char read_digital_inputs( volatile unsigned char Temp1 ); // прочитать бит входов
    void change_digital_inputs( volatile unsigned char Temp1,volatile unsigned char Temp2 ); // изменить бит входов
    char read_digital_Output( volatile unsigned char Temp1 ); // прочитать бит выходов
    void change_digital_Output( volatile unsigned char Temp1,volatile unsigned char Temp2 ); // изменить бит выходов
    void change_analogue_Output (volatile unsigned char nomer, int Danie); // записать значение аналоговые выходов
    void change_analogue_input (volatile unsigned char nomer, int Danie);  // записать значение аналоговых входов
    int read_analogue_Output (volatile unsigned char nomer); // считать значение аналоговые выходов
    int read_analogue_input (volatile unsigned char nomer);  // считать значение аналоговых входов
    void modbasRtu_Slave( void );

	     /*

           change_digital_inputs(23,On);  // изменить дискретный вход пина 23 на 1 (On-1,Off-0)
	       BV = read_digital_inputs(23);  // считать состояние дискретного входа 23 (возвращает char)

	       change_digital_Output(20,On);  // изменить дискретный выход пина 20 на 1 (On-1,Off-0)
	       BV = read_digital_Output(20);  // считать состояние дискретного выхода 20 (возвращает char)

		   change_analogue_Output(1,567); // записать значение 567, первого аналогового выхода, (ячейка массива 1)
		   change_analogue_input (2,300); // записать значение 300, врторого аналогового входа,( ячейка массива 2)

		   BV = read_analogue_Output (1); // считать значение первого аналогового выхода (возвращает int)
		   BV = read_analogue_input (2);  // считать значение первого аналогового входа (возвращает int)

	    */
    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

