#include <avr/io.h>
#include <stdint.h>

/* Clockwise order */
#define RED_X     _BV(PC0)
#define BLUE_X    _BV(PC1)
#define GREEN_X   _BV(PC2)
#define BLACK_X   _BV(PC3)
#define RED_Y     _BV(PC4)
#define BLUE_Y    _BV(PC5)
#define GREEN_Y   _BV(PC6)  
#define BLACK_Y   _BV(PC7)
#define CM       345 // equates to 1 cm
#define DISX     CM*5.55; // equates to length of dispil in X
#define DISY     CM*3; // equates to height of dispil in Y
#define DELAY 1.5/* milliseconds between steps */

// defines current position in x,y
int currentX = NULL; //
int currentY = NULL;

//Move X-
void moveLeft (int steps){
  if(currentX-steps > 0){
    currentX = currentX-steps;
    for(int i = 0; i < (DISX*(steps-1)); i++){
      PORTC = RED_X;
      _delay_ms(DELAY);  
      PORTC = GREEN_X;    
      _delay_ms(DELAY); 
      PORTC = BLUE_X;  
      _delay_ms(DELAY);    
      PORTC = BLACK_X;    
      _delay_ms(DELAY);
    }
  }
};

//Move X+
void moveRight (int steps){
  if(currentX+steps < 5){
    currentX = currentX+steps;
    for(int i = 0; i < (DISX*(steps-1)); i++){
      PORTC = BLACK_X;
      _delay_ms(DELAY);  
      PORTC = BLUE_X;    
      _delay_ms(DELAY); 
      PORTC = GREEN_X;  
      _delay_ms(DELAY);    
      PORTC = RED_X;    
      _delay_ms(DELAY);
    }
  }
};

void moveUP (int steps){
  if(currentY-steps < 0){
    currentY = currentY-steps;
    for(int i = 0; i < (DISY*(steps-1)); i++){
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
};

void moveDown (int steps){
  if(currentY+steps < 0){
    currentY = currentY+steps;
    for(int i = 0; i < (DISY*(steps-1)); i++){
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
};

//posX and posY defined where the hatch should go to
void moveHatch(int posX, int posY){
  if(currentX < posX ){
    moveRight(posX);
  }
  if(currentX > posX){
    moveLeft(posX);
  }
  if(currentY > posY ){
    moveDown(posY);
  }
  if(currentY < posY){
    moveUP(posY);
  }
}

void setup(){
  DDRC = 0xFF;
  PORTC = 0X00;
}

int main(){
  setup();
  moveHatch(3,2);
}
