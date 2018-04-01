#include <avr/io.h>
#include <stdint.h>
#include <time.h>

// commit?
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
#define DISX     CM*5.55; // equates to length of dispil in X
#define DISY     CM*3; // equates to height of dispil in Y

#define DELAY 1.5/* milliseconds between steps */

// defines current position in x,y
int currentPos[2] = {1,1}; //

/* Logic is defined by two functionalities, picking up a pill and dropping pill.
   Odd is pick up pill Order, Even is a drop order.
*/

// Defining orders
int pickUpPill = 1;
int dropPill = 0;
int order  = pickUpPill + dropPill;

// init pickUp and drop pill distances.
int pickupdist[2] = {0,0};
int dropdist[2] = {0,0};

/*Define Position XY of Containers, 
need to setup them up in terms of rows and columns.
*/
int container1[2] = {3,4};
int container2[2] = {3,5};
int container3[2] = {3,6};
int container4[2] = {3,7};


// Defines which columns it needs to moveleft.
int moveLeft[12] = {5,6,7,8,13,14,15,16,21,22,23,24};

int main(void){  
  DDRC = 0xff;    /* Enable output on all of the B pins */  
  PORTC = 0x00;            /* Set them all to 0v */  
   
}
  
// Move in X direction
void moveX(column) // Row ranges from 1-4
{
 distanceX = DISX*column; // Defines the distance to move in.

 if (column % 4 == 0 )
  {
  moveY(1,true); // If multiple of 4, move down 1 in Y
  }
  
  for (int i = 0; i < 11; i++ )
    {
      if (column != moveLeft[i]) //move in Right direction
       {
         for(int i=0;i<distanceX;i++)
          {  
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
  }
    
 else  // move in Left direction
  {
   for(int i=0;i<distanceX;i++)
    {     
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
} 

// Move in the Y Direction
void moveY(row,moveDown)
 {
  distanceY = DISY*row; 
  if (moveDown)  // If true, moves down
    {
    for(int i=0;i<distanceY;i++)
      {      
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
 else // if false, moves up
 { 
   for(int i=0;i<distanceY;i++) 
    {
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

void mainLogic()
{
  if(order % 2 == 0) 
   {
    dropPill();
    pickUpPill++;
   }
  else 
  {
   pickPill();
   dropPill++;
  }
 order = pickUpPill + dropPill;
}

/* Convention will be move in Y then in X
 *  Reverse for drop Pill 
 */
void pickUpPill(containerNum,currentPos) 
{
 pickupDist =  ContainerNum + currentPos; // gives total distance to get pill {x,y}
 moveXY() // Forward direction 
}

void dropPill() 
{
  moveXY(); // Reverse Direction  
}

