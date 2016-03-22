#include "VGA.h"     
#include <time.h>

unsigned char spaceship[]={
BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN
};

unsigned char shot[]={
WHITE,
WHITE,
WHITE,
WHITE
};

unsigned char alien1[]={
BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,
WHITE,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,WHITE,
BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK
};

unsigned char alien2[]={
BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,
WHITE,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,WHITE,
WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,
WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,WHITE,
BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,
BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK
};

unsigned char octopus1[]={
BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
BLACK,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,BLACK,
WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,
BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK
};

unsigned char octopus2[]={
BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
BLACK,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,BLACK,
BLACK,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,BLACK,
WHITE,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,WHITE
};

unsigned char enemy1[]={
BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,
BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,
BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK
};

unsigned char enemy2[]={
BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,
BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,BLACK,
WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE
};

unsigned char explosion[]={
BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,
BLACK,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,
WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,
BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,WHITE,BLACK,BLACK,WHITE,BLACK,BLACK,
BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK
};

//nave
int spaceship_posx;

//disparo
int shot_posy, shot_posx;
boolean isShot;

//aliens
boolean alienAnimType, moveDirection, goDown;
int alienNum, animateAlien, alienCols, alienRows;
boolean alienLife[] = {1,1,1,1,1,1};
int alienPos[][2] ={
{25,10},{50,10},{75,10},
{25,20},{50,20},{75,20}
};

//dibujar alien con vida del arreglo(animado)
void drawAliens()
{
  animateAlien++;
  for(int i=0;i<alienNum;i++)
  {
    if(alienLife[i])
    {
      if(animateAlien == 10)
      {
        alienAnimType = !alienAnimType;
        animateAlien = 0;
      }
      
      if(alienAnimType){
        VGA.writeArea(alienPos[i][0], alienPos[i][1], 11, 8, alien1);
      }else{
        VGA.writeArea(alienPos[i][0], alienPos[i][1], 11, 8, alien2);
      }
    }
  }
}

//revisar si el disparo pego en un alien
int shooting()
{
  for(int i=0;i<alienNum;i++)
  {
    if(shot_posx >= alienPos[i][0] && shot_posx <= alienPos[i][0]+11)
      if(shot_posy >= alienPos[i][1] && shot_posy <= alienPos[i][1]+8)
        if(alienLife[i])
          return i;
  }
  return -1;
}



//revisar columnas muertas
int checkOffset(int init, int condition)
{
  int offset = 0;
  for(int i = init*-1; i < condition; i++)
  {  
    for(int j = 0; j < alienRows; j++)
    {
      int temp = (i<0?i*-1:i);
      if(alienLife[temp+(j*alienCols)])
        return offset;
    }
    offset++;
  }
  return offset;
}

//revisar la direccion para moverse
void checkDirection()
{
  int offset;
  //cambiar a la derecha
  offset = checkOffset(0,alienCols);
  for(int i = offset; i < alienNum;i = i + alienCols + offset)
  {
    if(alienPos[i][0] == 1)
    {
      moveDirection = !moveDirection;
      goDown = true;
      return;
    }
  }
  
  //cambiar a la izquierda
  offset = checkOffset(alienCols-1, 1);
  for(int i = alienCols - 1 - offset; i<=alienNum;i = i + alienCols - offset)
  {
    if(alienPos[i][0] == 148)
    {
      moveDirection = !moveDirection;
      goDown = true;
      return;
    }
  }
}

//mover alien
void moveAliens()
{
  checkDirection();
  moveAliensHelper();
}

void moveAliensHelper()
{
  for(int i = 0; i<alienNum; i++)
  {
    if(moveDirection)
      alienPos[i][0] += 1;
    else
      alienPos[i][0] -= 1;
    if(goDown)
      alienPos[i][1] += 1;
  }
  if(goDown)
    goDown = false;
}

void setup() {
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  spaceship_posx=70;
  isShot = false;
  alienNum=6;
  animateAlien = 0;
  alienAnimType = true;
  alienCols = 3;
  alienRows = 2;
  moveDirection = true;
}

void loop(){
  VGA.clear();
  VGA.writeArea(spaceship_posx, 110, 11, 6, spaceship);
  drawAliens();
  moveAliens();
  
  //mover nave
  if(digitalRead(FPGA_BTN_0))
  {
    if(spaceship_posx > 1)
      spaceship_posx-= 3;
  }
  if(digitalRead(FPGA_BTN_1))
  {
    if(spaceship_posx < 149)
      spaceship_posx+= 3;
  }
  
  //disparar
  if(digitalRead(FPGA_BTN_2))
  {
    isShot = true;
    shot_posy = 107;
    shot_posx = spaceship_posx+5;;
  }
  if(isShot)
  {
    shot_posy--;
    VGA.writeArea(shot_posx, shot_posy, 1, 3, shot);
    int alienShot = shooting();
    if(alienShot != -1)
    {
      alienLife[alienShot] = 0;
      isShot = false;
      shot_posx = 0;
      
      //alien shot animation
      VGA.writeArea(alienPos[alienShot][0], alienPos[alienShot][1], 11, 8, explosion);
      delay(30);
    }
  }
  
  //pausa
  if(!digitalRead(FPGA_SW_0))
  {
    //animacion de alien en pausa
    int pauseAnim = 0;
    boolean pauseAnimType = true;
    while(true)
    {
      VGA.setColor(227, 38, 54);
      VGA.printtext(60,45,"PAUSED");
      VGA.printtext(20,60,"BUTTON 1 TO EXIT");
      pauseAnim++;
      if(pauseAnim == 10)
      {
        pauseAnimType = !pauseAnimType;
        pauseAnim = 0;
      }
      
      if(pauseAnimType){
        VGA.writeArea(75, 75, 11, 8, alien1);
      }else{
        VGA.writeArea(75, 75, 11, 8, alien2);
      }
      
      //salir de pausa
      if(digitalRead(FPGA_SW_0))
      {
        break;
      }
      
      //regresar al menu (como no tenemos menu solo va a clear por ahora)  
      if(digitalRead(FPGA_BTN_0))
      {
        VGA.clear();
        while(true){}
      }
      delay(100);
    }
  }
  delay(100);
}

