#include "VGA.h"     
#include <time.h>

unsigned char spaceship[]={
BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
};

unsigned char shot[]={
WHITE,
WHITE,
WHITE,
WHITE,
};

unsigned char alien[]={
BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,
WHITE,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,WHITE,
BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
};

//spaceship
int spaceship_posx;

//shot
int shot_posy;
boolean isShot;

void setup() {
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  spaceship_posx=70;
  isShot = false;
}

void loop(){
  VGA.clear();
  VGA.writeArea(spaceship_posx, 110, 11, 6, spaceship);
  VGA.writeArea(25, 6, 11, 8, alien);
  VGA.writeArea(50, 6, 11, 8, alien);
  VGA.writeArea(75, 6, 11, 8, alien);
  delay(100);
  
  //moverse
  if(digitalRead(FPGA_BTN_0))
  {
    spaceship_posx--;
  }
  if(digitalRead(FPGA_BTN_1))
  {
    spaceship_posx++;
  }
  
  //disparar
  if(digitalRead(FPGA_BTN_2))
  {
    isShot = true;
    shot_posy = 107;
  }
  if(isShot)
  {
    shot_posy--;
    VGA.writeArea(spaceship_posx+5, shot_posy, 1, 3, shot);
  }
  
  //pausa
  if(digitalRead(FPGA_BTN_3))
  {
    while(true)
    {
      delay(1000);
      if(digitalRead(FPGA_BTN_3))
      {
        break;
      }
    }
  }
}
