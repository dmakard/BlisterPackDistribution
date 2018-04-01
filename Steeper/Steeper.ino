#include <avr/io.h>
#include <stdint.h>
#include <time.h>

time_t start = time(NULL);

/* Clockwise order */
#define RED      _BV(PC0)
#define BLUE     _BV(PC1)
#define GREEN    _BV(PC2)
#define BLACK    _BV(PC3)
#define RED_Y    _BV(PC4)
#define BLUE_Y   _BV(PC5)
#define GREEN_Y  _BV(PC6)  
#define BLACK_Y  _BV(PC7)
#define CM       345

#define DELAY 1.5/* milliseconds between steps */

int main(void){  
  DDRC = 0xff;    /* Enable output on all of the B pins */  
  PORTC = 0x00;            /* Set them all to 0v */  
  
  
  for(int i=0;i<5*CM;i++){/* main loop hddddere */    
      PORTC = RED;
      _delay_ms(DELAY);  
      PORTC = GREEN;    
      _delay_ms(DELAY); 
      PORTC = BLUE;  
      _delay_ms(DELAY);    
      PORTC = BLACK;    
      _delay_ms(DELAY);
  }
  for(int i=0;i<5*CM;i++){/* main loop hddddere */    
      PORTC = RED_Y;
      _delay_ms(DELAY);  
      PORTC = GREEN_Y;    
      _delay_ms(DELAY); 
      PORTC = BLUE_Y;  
      _delay_ms(DELAY);    
      PORTC = BLACK_Y;    
      _delay_ms(DELAY);
  }    
}

