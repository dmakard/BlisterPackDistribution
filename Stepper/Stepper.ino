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
#define CM        11 // equates to 1 cm
#define DISX      CM*5.55 // equates to length of dispil in X
#define DISY      CM*3.2 // equates to height of dispil in Y
#define DELAY     1.5
/* milliseconds between steps */

// defines current position in x,y
int currentX= 1;
int currentY=1;

//Move X- 
void moveLeft (int posX){
  if(currentX-posX > 0){
    sleepX(false);
    int steps = currentX - posX;
    currentX = posX;// update current position
    for(int i = 0; i < (DISX*steps); i++){
         PORTC = BLACK_X;
      _delay_ms(DELAY);  
      PORTC = BLUE_X;    
      _delay_ms(DELAY); 
      PORTC = GREEN_X;  
      _delay_ms(DELAY);    
      PORTC = RED_X;    
      _delay_ms(DELAY);
    }
    sleepX(true);
  }
};

//Move X+
void moveRight (int posX){
  if(currentX+posX < 6){
    sleepX(false);
    int steps =posX-currentX;
    currentX = posX;
    for(int i = 0; i < (DISX*steps); i++){
      PORTC = RED_X;
      _delay_ms(DELAY);  
      PORTC = GREEN_X;    
      _delay_ms(DELAY); 
      PORTC = BLUE_X;  
      _delay_ms(DELAY);    
      PORTC = BLACK_X;    
      _delay_ms(DELAY);
    }
    sleepX(true);
  }
};

void moveUP (int posY){
  if(currentY-posY > 0){
    sleepY(false);
    int steps = currentY-posY;
    currentY = posY;
    for(int i = 0; i < (DISY*steps); i++){
      PORTC = BLACK_Y;
      _delay_ms(DELAY);  
      PORTC = BLUE_Y;    
      _delay_ms(DELAY); 
      PORTC = GREEN_Y;  
      _delay_ms(DELAY);    
      PORTC = RED_Y;    
      _delay_ms(DELAY);
    }
    sleepY(true);
  }
};

void moveDown (int posY){
  if(currentY+posY < 9){
    sleepY(false);
    int steps = posY-currentY;
    currentY = posY;
    for(int i = 0; i < (DISY*steps); i++){
      PORTC = RED_Y;
      _delay_ms(DELAY);  
      PORTC = GREEN_Y;   
      _delay_ms(DELAY); 
      PORTC = BLUE_Y;  
      _delay_ms(DELAY);    
      PORTC = BLACK_Y;    
      _delay_ms(DELAY);
    }
    sleepY(true);
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
  if(currentY < posY ){
    moveDown(posY);
  }
  if(currentY > posY){
    moveUP(posY);
  }
}

void sleepX(bool val){
  if(val == true){
    PORTD = _BV(PD2);
    PORTB = _BV(PB2);
  }
  else{
    PORTD = 0x00;
    PORTB = 0x00;
  }
}


void sleepY(bool val){
  if(val == true){
    PORTB = _BV(PB0) && _BV(PB1);
  }
  else{
    PORTB = 0x00;
  }
}
void setup(){
  DDRC = 0xFF;
  PORTC = 0X00;
}

int main(){
  setup();
  moveHatch(4,7);
  _delay_ms(1000);
  moveHatch(1,1);
}
