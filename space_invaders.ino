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

unsigned char shield1[]={
BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,
BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN
};

unsigned char shield2[]={
BLACK,BLACK,BLACK,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,GREEN,GREEN,GREEN,BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,GREEN,GREEN,BLACK,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN
};

unsigned char shield3[]={
BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,GREEN,BLACK,BLACK,BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,
BLACK,GREEN,GREEN,GREEN,BLACK,BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,
BLACK,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,
BLACK,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN
};

unsigned char heart[]={
BLACK,BLACK,RED,RED,BLACK,BLACK,
BLACK,BLACK,RED,RED,BLACK,BLACK,
RED,RED,RED,RED,RED,RED,
RED,RED,RED,RED,RED,RED,
BLACK,BLACK,RED,RED,BLACK,BLACK,
BLACK,BLACK,RED,RED,BLACK,BLACK
};

unsigned char shot[]={
GREEN,
GREEN,
GREEN,
GREEN
};

unsigned char shotAlien[]={
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

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

//DECLARACION DE VARIABLES

//nave
int spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship_lives;
int spaceship_speed, spaceship_shot_speed;

//disparo
int shot_posy, shot_posx;
boolean isShot;

//corazon
int heart_posx,heart_posy,heart_size;

//aliens
boolean alienAnimType, moveDirection, goDown, alienShooting;
int alienNum, animateAlien, alienCols, alienRows, alien_shot_speed, alien_speed;

//shields
int shield1_resistance, shield2_resistance, shield3_resistance, shield1_posx, shield2_posx, shield3_posx;
int shield_posy, shield_margin, shield_width, shield_height;

boolean game_over;

//-----------------------------------------------------------------------------------------------------
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

void drawLives()
{
  for(int i=0;i<spaceship_lives;i++)
  {
    VGA.writeArea(heart_posx+(i*heart_size+i), heart_posy, heart_size, heart_size, heart);
  }
}

void drawShield(int shield_x, int shield_y, int shield_resistance)
{
  if(shield_resistance > 0)
  {
    if(shield_resistance <= 4)
      VGA.writeArea(shield_x, shield_y, shield_width, shield_height, shield3);
    
    else if(shield_resistance <= 8)
      VGA.writeArea(shield_x, shield_y, shield_width, shield_height, shield2);
    
    else if(shield_resistance <= 12)
      VGA.writeArea(shield_x, shield_y, shield_width, shield_height, shield1);
  }
}

void drawShipBullet()
{
  if(isShot)
  {
    shot_posy-= spaceship_shot_speed;
    VGA.writeArea(shot_posx, shot_posy, 1, 3, shot);
  }
}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

//LOGICA

//SHOOTING

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

void fireShipBullets()
{
  if(digitalRead(FPGA_BTN_2))
  {
    isShot = true;
    shot_posy = 107;
    shot_posx = spaceship_posx+5;
  }
}

//----------------------------------------------------------------------------------------------------

//CHECK ACTIONS

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
          resetAlienShot(i);
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
  else
  {
    //cambiar a la derecha
    offset = checkOffsetLeft();
    int i = offset;
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

void checkShieldCollision()
{
  if(isShot)
  {
    if(checkCollisionShield(shot_posx, shot_posy, shield1_posx, shield_posy, 1) || 
       checkCollisionShield(shot_posx, shot_posy, shield2_posx, shield_posy, 2) ||
       checkCollisionShield(shot_posx, shot_posy, shield3_posx, shield_posy, 3))
         resetSpaceshipShot(); 
       
  }
  
  for(int i = 0; i < alienNum; i++)
  {
    if(alienShots[i][1] != 0)
    {
      if(checkCollisionShield(alienShots[i][0], alienShots[i][1], shield1_posx, shield_posy, 1) ||
         checkCollisionShield(alienShots[i][0], alienShots[i][1], shield2_posx, shield_posy, 2) ||
         checkCollisionShield(alienShots[i][0], alienShots[i][1], shield3_posx, shield_posy, 3))
           {
             resetAlienShot(i);
             continue;
           }
    }
  }
}

boolean checkCollisionShield(int shot_x, int shot_y, int shield_x, int shield_y, int num_shield)
{
  if(shot_x >= shield_x && shot_x <= shield_x + shield_width)
    if(shot_y >= shield_y && shot_y <= shield_y + shield_height)
      switch(num_shield)
      {
        case 1:
          shield1_resistance--;
          return true;
        
        case 2:
          shield2_resistance--;
          return true;
        
        case 3:
          shield3_resistance--;
          return true;
      }
      
  return false;
}

void checkAlienHit()
{
  int alienShot = shooting();
  if(alienShot != -1)
  {
    alienLife[alienShot] = 0;
    resetSpaceshipShot();
    currentScore += 10 * alienType[alienShot];
    
    //alien shot animation
    VGA.writeArea(alienPos[alienShot][0], alienPos[alienShot][1], 11, 8, explosion);
    alien_shot_speed++;
    alien_speed++;
    delay(30);
  }
}

void checkUserInput()
{
  moveShip();
  fireShipBullets();
  checkPause();
}

void checkPause()
{
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
}

void checkGameOver()
{
  if(game_over)
  {
    drawGameOver();
  }
}

//----------------------------------------------------------------------------------------------------------

//MOVE CHARACTERS

//mover alien
void moveAliens()
{
  checkDirection();
  moveAliensHelper();
}

void moveAliensHelper()
{
  for(int i = 0; i < alienNum; i++)
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

void moveShip()
{
  if(digitalRead(FPGA_BTN_0))
  {
    if(spaceship_posx > 1)
      spaceship_posx-= spaceship_speed;
  }
  if(digitalRead(FPGA_BTN_1))
  {
    if(spaceship_posx < 149)
      spaceship_posx+= spaceship_speed;
  }
}

//-----------------------------------------------------------------------------------------------------------

//RESET

void resetSpaceshipShot()
{
  isShot = false;
  shot_posx = 0;
}

void resetAlienShot(int num)
{
  alienShots[num][0]= 0;
  alienShots[num][1]= 0;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

void setup()
{
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  
  spaceship_posx = 70;
  spaceship_posy = 110;
  spaceship_width = 11;
  spaceship_height = 6;
  spaceship_lives = 3;
  spaceship_speed = 4;
  spaceship_shot_speed = 3;
  
  alienNum = 6;
  animateAlien = 0;
  alienCols = 3;
  alienRows = 2;
  alien_shot_speed = 2;
  alien_speed = 1;
  
  isShot = false;
  alienShooting = false;
  alienAnimType = true;
  moveDirection = true;
  
  heart_size = 6;
  heart_posx = 0;
  heart_posy = 100;
  
  shield1_resistance = 12;
  shield2_resistance = 12;
  shield3_resistance = 12;
  shield_margin = VGA.getHSize() / 4;
  shield1_posx = shield_margin - 10;
  shield2_posx = shield_margin * 2 - 5;
  shield3_posx = shield_margin * 3;
  shield_posy = 97;
  shield_width = 11;
  shield_height = 8;
  
  game_over = false;
}

void loop()
{
  VGA.clear();
  
  VGA.writeArea(spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship);
  
  drawShield(shield1_posx, shield_posy, shield1_resistance);
  drawShield(shield2_posx, shield_posy, shield2_resistance);
  drawShield(shield3_posx, shield_posy, shield3_resistance);
  drawLives();
  drawShipBullet();  
  drawAliens();
  
  fireAlienShot();
  moveAliens();  
  moveAlienShots();
  
  checkUserInput();
  checkCollisionAgainstPlayer();
  checkSpaceshipVitality();
  checkShieldCollision();  
  checkAlienHit();
  checkGameOver();
  
  delay(100);
}

