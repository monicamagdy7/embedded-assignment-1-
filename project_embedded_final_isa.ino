#include <avr/io.h>
#include <util/delay.h> // library to be able to use delay

//add the libraries we created to be able to call their functions and use them
#include "ADC.h"
#include "UART.h"
#include "Dio.h"
///////////////////////////////////////////////////////////////////////////////////////// 

int main(void){
  init();
  unsigned char buffer [4];



 while (1) //infinite loop
  {
  int a = Adc_ReadChannel(0);  //reads the value from the LDR and stores it in variable 'a'
  Uart_SendString("LDR Reading : "); // sends this message before each reading
  itoa(a, buffer, 10); // itoa converts integer to string so that it can be read on the serial monitor and it takes the value we want to convert then buffer then 10(which stands for decimal)
  Uart_SendString(buffer);
    Uart_SendString("  ");
     _delay_ms(500);
    Uart_SendChar('\r'); 
   Uart_SendChar('\n'); //new line
   
    if((PINB & (1 << 3))!= 0)  // if switch not pressed
    {
      PORTB = PORTB & ~(1 << 5);    // Switch OFF lED
      //_delay_ms(1000); 
    }  
    else // if key is pressed
    {
      PORTB = PORTB | (1 << 5);  //switch on led
      //to send a message on  the serial monitor that the button is pressed
      Uart_SendChar ('k');
      Uart_SendChar ('e');
      Uart_SendChar ('y');
      Uart_SendChar (' ');
      Uart_SendChar ('i');
      Uart_SendChar ('s');
      Uart_SendChar (' ');
      Uart_SendChar ('p');
      Uart_SendChar ('r');
      Uart_SendChar ('e');
      Uart_SendChar ('s');
      Uart_SendChar ('s');
      Uart_SendChar ('e');
      Uart_SendChar ('d');
      Uart_SendChar ('\n');
      
      _delay_ms(5000); //to make the led on for 5 seconds 
    }
    ////////////////////////////////////////////////////the ldr///////////////////////////////////////////
    if(a > 600){ //if ldr reading value is higher than 200
     PORTB = PORTB  &!(1 << 0); //switch off led 
     
     //sends a warning message
     Uart_SendChar('M');
     Uart_SendChar('o');
     Uart_SendChar('r');
     Uart_SendChar('n');
     Uart_SendChar('i');
     Uart_SendChar('n');
     Uart_SendChar('g');
     Uart_SendChar(' ');}
     
  else{ //if ldr reading value is lower than 200

    //sends a warning 
     PORTB = PORTB | (1 << 0);
     Uart_SendChar('N');
     Uart_SendChar('i');
     Uart_SendChar('g');
     Uart_SendChar('h');
     Uart_SendChar('t');
     Uart_SendChar(' '); }
  }
  return 0;
}



void init(){
  DDRB = DDRB | (1 << 5);     // Make PB5 output
Uart_Init();

 DDRB = DDRB & ~(1 << 3);    // Make PB3 input
  PORTB = PORTB | (1 << 3);   // Activate pull up resistance


  Adc_Init(); //setup the adc
Uart_Init();  // setup the uart

  // direction led1, switch
  DDRC &= ~(1 << 0); // make it input
  DDRB = DDRB | (1 << 0); // make it output
  //it can be written using Dio
  
  // pull up resistace
  PORTB = PORTB | (1 << 3);


}
