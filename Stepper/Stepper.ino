#include <avr/io.h>
#include <stdint.h>
#include <time.h>

time_t start = time(NULL);

/* Clockwise order */
#define RED_X      _BV(PC0)
#define BLUE_X     _BV(PC1)
#define GREEN_X    _BV(PC2)
#define BLACK_X    _BV(PC3)
#define RED_Y    _BV(PC4)
#define BLUE_Y   _BV(PC5)
#define GREEN_Y  _BV(PC6)  
#define BLACK_Y  _BV(PC7)
#define CM       345 // equates to 1 cm
#define DisX     CM*5.55; // equates to length of dispil in X
#define DisY     CM*3; // equates to height of dispil in Y

#define DELAY 1.5/* milliseconds between steps */

int main(void){  
  DDRC = 0xff;    /* Enable output on all of the B pins */  
  PORTC = 0x00;            /* Set them all to 0v */  
  


  // This is for clockwise in X
  for(int i=0;i<Column*CM;i++){  
      PORTC = RED_X;
      _delay_ms(DELAY);  
      PORTC = GREEN_X;    
      _delay_ms(DELAY); 
      PORTC = BLUE_X;  
      _delay_ms(DELAY);    
      PORTC = BLACK_X;    
      _delay_ms(DELAY);
  }
  // This is for clockwise in Y
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

// This is for counter clockwise in X
for(int i=0;i<CM;i++){    
      
      PORTC = BLACK_X;
      _delay_ms(DELAY);  
      PORTC = BLUE_X;
      _delay_ms(DELAY);  
      PORTC = GREEN_X; 
      _delay_ms(DELAY);  
      PORTC = RED_X;   
      _delay_ms(DELAY);
  }

// This is for counter clockwise in Y
for(int i=0;i<5*CM;i++){/* main loop hddddere */    
     
      PORTC = BLACK_Y;
      _delay_ms(DELAY);  
      PORTC = BLUE_Y;
      _delay_ms(DELAY);  
      PORTC = GREEN_Y; 
      _delay_ms(DELAY);  
      PORTC = RED_Y;   
      _delay_ms(DELAY);
  }   
}

   
}

void moveX(row) 
{
  
  
  
}
void moveY(column)
{
  
 
  
} 
