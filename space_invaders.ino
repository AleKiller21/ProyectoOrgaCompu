#include "VGA.h"     
#include <time.h>

//ARREGLOS DE DIBUJOS

unsigned char spaceship[]={
BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN
};

unsigned char shot[]={
GREEN,
GREEN,
GREEN,
GREEN
};

unsigned char shotAlien[]={
GREEN,
GREEN,
GREEN,
GREEN
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

//-------------------------------------------------------------------------------------

//VARIABLES

//nave
int spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship_lives, spaceship_shot_speed;

//disparo
int shot_posy, shot_posx;
boolean isShot;

//aliens
boolean alienAnimType, moveDirection, goDown, alienShooting;
int alienNum, animateAlien, alienCols, alienRows, alien_shot_speed, fire_next_shot, delay_next_shot, alien_speed;

boolean game_over;

//-----------------------------------------------------------------------------------------------------

//ARREGLOS DE POSICION

boolean alienLife[] = {1,1,1,1,1,1};

int alienPos[][2] ={
{25,10},{50,10},{75,10},
{25,20},{50,20},{75,20}
};

int alienShots[][2] ={
{0,0},{0,0},{0,0},
{0,0},{0,0},{0,0}
};

//------------------------------------------------------------------------------------------------------

//FUNCIONES DE RENDERIZADO

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

void moveAlienShots()
{
  for(int i = 0; i < alienNum; i++)
  {
    if(alienShots[i][1] != 0)
    {
      VGA.writeArea(alienShots[i][0], alienShots[i][1], 1, 3, shotAlien);
      alienShots[i][1] += alien_shot_speed;
      
      if(alienShots[i][1] >= VGA.getVSize())
      {
        alienShots[i][0]= 0;
        alienShots[i][1]= 0;
      }
    }
  }
}

void drawGameOver()
{
  VGA.clear();
  while(game_over)
  {
    VGA.setColor(GREEN);
    VGA.printtext(80, 60, "GAME OVER");
  }
}

//-----------------------------------------------------------------------------------------------------

//LOGICA

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

void fireAlienShot()
{
  for(int i = 0; i < alienNum; i++)
  {
    if(alienLife[i])
    {
      if(i >= alienNum - alienCols && i < alienNum)
      {
        if(alienShots[i][1] == 0)
        {
          alienShots[i][0] = alienPos[i][0]+5;
          alienShots[i][1] = alienPos[i][1]+8;
          break;
        }
      }
      
      else
      {
        if(!alienLife[i + alienCols])
        {
          if(alienShots[i][1] == 0)
          {
            alienShots[i][0] = alienPos[i][0]+5;
            alienShots[i][1] = alienPos[i][1]+8;
            break;
          }
        }
      }
    }
  }
}

void checkCollisionAgainstPlayer()
{
  for(int i = 0; i < alienNum; i++)
  {
    if(alienShots[i][1] != 0)
    {
      if(alienShots[i][0] >= spaceship_posx && alienShots[i][0] <= spaceship_posx + spaceship_width)
        if(alienShots[i][1] >= spaceship_posy && alienShots[i][1] <= spaceship_posy + spaceship_height)
        {
          spaceship_lives--;
          alienShots[i][0]= 0;
          alienShots[i][1]= 0;
          break;
        }
    }
  }
}

void checkSpaceshipVitality()
{
  if(spaceship_lives <= 0)
    game_over = true;
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
//revisar columnas muertas
int checkOffsetLeft()
{
  int offset = 0;
  for(int i = 0; i < alienCols; i++)
  {  
    for(int j = 0; j < alienRows; j++)
    {
      if(alienLife[i+(j*alienCols)])
        return offset;
    }
    offset++;
  }
  return offset;
}

int checkOffsetRight()
{
  int offset = 0;
  for(int i = alienCols-1; i > 0; i--)
  {  
    for(int j = 0; j < alienRows; j++)
    {
      if(alienLife[i+(j*alienCols)])
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
  //cambiar a la izquierda
  if(moveDirection)
  {
    offset = checkOffsetRight();
    int i = alienCols-1-offset;
    //for(int i = alienCols-1-offset; i<=alienNum;i = i + alienCols - offset)
    //{
      if(alienLife[i] || alienLife[i + alienCols])
      {
        if(alienPos[i][0] >= 145)
        {
          moveDirection = false;
          goDown = true;
          return;
        }
      }
    //}
  }
  else{
    //cambiar a la derecha
    offset = checkOffsetLeft();
    int i = offset; i<alienNum;
    //for(int i = offset; i<alienNum;i = i + alienCols + offset)
    //{
      if(alienLife[i] || alienLife[i + alienCols])
      {
        if(alienPos[i][0] <= 15)
        {
          moveDirection = true;
          goDown = true;
          return;
        }
      }
    //}
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
      alienPos[i][0] += alien_speed;
    else
      alienPos[i][0] -= alien_speed;
    if(goDown)
      alienPos[i][1] += 1;
  }
  if(goDown)
    goDown = false;
}

//---------------------------------------------------------------------------------------------------------

void setup() {
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  
  spaceship_posx = 70;
  spaceship_posy = 110;
  spaceship_width = 11;
  spaceship_height = 6;
  spaceship_lives = 3;
  spaceship_shot_speed = 3;
  
  alienNum = 6;
  animateAlien = 0;
  alienCols = 3;
  alienRows = 2;
  alien_shot_speed = 2;
  alien_speed = 1;
  
  fire_next_shot = 15;
  delay_next_shot = 15;
  
  isShot = false;
  alienShooting = false;
  alienAnimType = true;
  moveDirection = true;
  
  game_over = false;
}

void loop(){
  VGA.clear();
  VGA.writeArea(spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship);
  drawAliens();
  moveAliens();
  
  //if(fire_next_shot >= delay_next_shot)
  //{
    fireAlienShot();
    fire_next_shot = 0;
  //}
  
  moveAlienShots();
  checkCollisionAgainstPlayer();
  checkSpaceshipVitality();
  
  //fire_next_shot++;
  
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
    shot_posx = spaceship_posx+5;
  }
  
  if(isShot)
  {
    shot_posy-= spaceship_shot_speed;
    VGA.writeArea(shot_posx, shot_posy, 1, 3, shot);
    int alienShot = shooting();
    if(alienShot != -1)
    {
      alienLife[alienShot] = 0;
      isShot = false;
      shot_posx = 0;
      
      //alien shot animation
      VGA.writeArea(alienPos[alienShot][0], alienPos[alienShot][1], 11, 8, explosion);
      alien_shot_speed++;
      alien_speed++;
      delay(30);
    }
  }
  
  //GameOver
  if(game_over)
  {
    drawGameOver();
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

