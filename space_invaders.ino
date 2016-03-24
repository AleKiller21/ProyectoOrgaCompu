#include "VGA.h"     
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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

//menu
boolean start,about,showHighScores,menuAnimType, menuAlienDirection;
int menuAnim = 0, menuAlien_posx;

//nave
int spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship_lives;
int spaceship_speed, spaceship_shot_speed;

//disparo
int shot_posy, shot_posx;
boolean isShot;

//corazon
int heart_posx,heart_posy,heart_size;

//score
int currentScore,currentScore_posx,currentScore_posy;

//aliens
boolean alienAnimType, moveDirection, goDown, alienShooting;
int alienNum, animateAlien, alienCols, alienRows, alien_shot_speed;
int alien_speed, alien_width, alien_height;
unsigned char* current_alien1;
unsigned char* current_alien2;

//shields
int shield1_resistance, shield2_resistance, shield3_resistance, shield1_posx, shield2_posx, shield3_posx;
int shield_posy, shield_margin, shield_width, shield_height;

//general
boolean game_over;
int current_level;

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

//ARREGLOS

boolean alienLife[] = {1,1,1,1,1,1};

int alienType[] = {1,1,1,1,1,1};

int alienPos[][2] ={
{25,10},{50,10},{75,10},
{25,20},{50,20},{75,20}
};

int alienShots[][2] ={
{0,0},{0,0},{0,0},
{0,0},{0,0},{0,0}
};

int HighScores[3] = {0,0,0};

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

//FUNCIONES DE RENDERIZADO

void drawHighScores()
{
  VGA.clear();
  VGA.setColor(GREEN);
  VGA.printtext(50, 30, "HIGHSCORE");
  
  char* scorePtr;
  VGA.setColor(BLUE);
  for(int i=0; i < 3; i++)
  {
    scorePtr = "";
    itoa(HighScores[i],scorePtr,10);
    VGA.printtext(45, 50 + 10*i ,scorePtr);
  }
  
  VGA.setColor(RED);
  VGA.printtext(50, 107, "BUTTON 1(MAIN MENU)");
  
  while(true)
  {
    if(digitalRead(FPGA_BTN_0))
    {
      showHighScores = false;
      delay(150);
      return;
    }
  }
}

void drawMenu()
{
 
  if(menuAlien_posx == 100)
    menuAlienDirection = false;
  if(menuAlien_posx == 40)
    menuAlienDirection = true;
  
  if(menuAlienDirection)
    menuAlien_posx+= 2;
  else
    menuAlien_posx-= 2;
  
  menuAnim++;
  
  if(menuAnim == 10)
  {
    menuAnimType = !menuAnimType;
    menuAnim = 0;
  }
  
  if(menuAnimType){
    VGA.writeArea(menuAlien_posx, 10, 12, 8, enemy1);
  }else{
    VGA.writeArea(menuAlien_posx, 10, 12, 8, enemy2);
  }
  
  VGA.setColor(GREEN);
  VGA.printtext(25, 30, "SPACE INVADERS");
  
  VGA.setColor(BLUE);
  VGA.printtext(20, 60, "BUTTON 1(START)");
  VGA.printtext(20, 80, "BUTTON 2(ABOUT)");
  VGA.printtext(1, 100, "BUTTON 3(HIGHSCORES)");
}

void showControls()
{
  VGA.clear();
  while(true)
  {
    VGA.setColor(BLUE);
    VGA.printtext(5, 10, "BUTTON 1(RIGHT)");
    VGA.writeArea(138, 10, spaceship_width, spaceship_height, spaceship);
    VGA.printtext(5, 30, "BUTTON 2(LEFT)");
    VGA.writeArea(128, 30, spaceship_width, spaceship_height, spaceship);
    VGA.printtext(5, 53, "BUTTON 3(SHOOT)");
    VGA.writeArea(133 + spaceship_width/2, 49, 1, 3, shot);
    VGA.writeArea(133, 53, spaceship_width, spaceship_height, spaceship);
    VGA.printtext(5, 73, "SWITCH 1(PAUSE)");
    
    VGA.setColor(RED);
    VGA.printtext(3, 107, "BUTTON 1(MAIN MENU)");
    
    if(digitalRead(FPGA_BTN_0))
    {
      about = false;
      delay(150);
      return;
    }
  }
}

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
        VGA.writeArea(alienPos[i][0], alienPos[i][1], alien_width, alien_height, current_alien1);
      }else{
        VGA.writeArea(alienPos[i][0], alienPos[i][1], alien_width, alien_height, current_alien2);
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
      
      if(alienShots[i][1] >= 120)
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
    if(digitalRead(FPGA_BTN_3))
    {
      game_over = false;
      start = false;
      return;
    }
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

void showCurrentScore()
{
    char* scorePtr = "";
    itoa(currentScore,scorePtr,10);
    VGA.setColor(BLUE);
    VGA.printtext(currentScore_posx,currentScore_posy,scorePtr, true);
}

void showCurrentLevel()
{
  char* lvl = "";
  itoa(current_level,lvl,10);
  VGA.setColor(BLUE);
  VGA.printtext(150,1,lvl, true);
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
    if(shot_posx >= alienPos[i][0] && shot_posx <= alienPos[i][0] + alien_width)
      if(shot_posy >= alienPos[i][1] && shot_posy <= alienPos[i][1] + alien_height)
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
          alienShots[i][0] = alienPos[i][0] + (alien_width / 2);
          alienShots[i][1] = alienPos[i][1] + alien_height;
          break;
        }
      }
      
      else
      {
        if(!alienLife[i + alienCols])
        {
          if(alienShots[i][1] == 0)
          {
            alienShots[i][0] = alienPos[i][0] + (alien_width / 2);
            alienShots[i][1] = alienPos[i][1] + alien_height;
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

void checkMenuInput()
{
  if(digitalRead(FPGA_BTN_0))
  {
    start = true;
  }
  
  if(digitalRead(FPGA_BTN_1))
  {
    about = true;
  }
  
  if(digitalRead(FPGA_BTN_2))
  {
    showHighScores = true;
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
        if(alienPos[i][0] + alien_width >= 150)
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
        if(alienPos[i][0] <= 10)
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
    if(checkCollisionShield(shot_posx, shot_posy, shield1_posx, shield_posy, &shield1_resistance) ||
       checkCollisionShield(shot_posx, shot_posy, shield2_posx, shield_posy, &shield2_resistance) || 
       checkCollisionShield(shot_posx, shot_posy, shield3_posx, shield_posy, &shield3_resistance))    
         resetSpaceshipShot();
       
  }
  
  for(int i = 0; i < alienNum; i++)
  {
    if(alienShots[i][1] != 0)
    {
      if(checkCollisionShield(alienShots[i][0], alienShots[i][1], shield1_posx, shield_posy, &shield1_resistance) ||
         checkCollisionShield(alienShots[i][0], alienShots[i][1], shield2_posx, shield_posy, &shield2_resistance) ||
         checkCollisionShield(alienShots[i][0], alienShots[i][1], shield3_posx, shield_posy, &shield3_resistance))
           {
             resetAlienShot(i);
             continue;
           }
    }
  }
}

boolean checkCollisionShield(int shot_x, int shot_y, int shield_x, int shield_y, int* shield_resistance)
{
  if(*shield_resistance == 0)
    return false;
  
  if(shot_x >= shield_x && shot_x <= shield_x + shield_width)
    if(shot_y >= shield_y && shot_y <= shield_y + shield_height)
    {
      (*shield_resistance)--;
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
    currentScore += 10*alienType[alienShot];
    
    //alien shot animation
    VGA.writeArea(alienPos[alienShot][0], alienPos[alienShot][1], alien_width, alien_height, explosion);
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
      VGA.printtext(20,60,"BUTTON 4 TO EXIT");
      
      pauseAnim++;
      
      if(pauseAnim == 10)
      {
        pauseAnimType = !pauseAnimType;
        pauseAnim = 0;
      }
      
      if(pauseAnimType){
        VGA.writeArea(75, 75, alien_width, alien_height, current_alien1);
      }else{
        VGA.writeArea(75, 75, alien_width, alien_height, current_alien2);
      }
      
      //salir de pausa
      if(digitalRead(FPGA_SW_0))
      {
        break;
      }
      
      //regresar al menu
      if(digitalRead(FPGA_BTN_3))
      {
        VGA.clear();
        start = false;
        masterReset(false);
        return;
      }
      delay(100);
    }
  }
}

void checkGameOver()
{
  if(game_over)
  {
    if(currentScore > HighScores[2])
    {
      HighScores[2] = currentScore;
      sortScores();
    }
    
    masterReset(false);
    drawGameOver();
  }
}

void checkAliensArrival()
{
  for(int i = 0; i < alienNum; i++)
  {
    if(!alienLife[i])
      continue;
      
    if(alienPos[i][1] + alien_height >= shield_posy)
    {
      game_over = true;
      break;
    }
  }
}

boolean checkAliensLife()
{
  int contador = 0;
  
  for(int i = 0; i < alienNum; i++)
  {
    if(!alienLife[i])
      contador++;
  }
  
  return contador == 6 ? true : false;
}

void checkLevelFinished()
{
  if(checkAliensLife())
    nextLevel();
}

void checkLifeHit()
{
  if(!isShot)
    return;
    
  for(int i=0;i<spaceship_lives;i++)
  {    
    if(shot_posx >= heart_posx+(i*heart_size+i) && shot_posx <= heart_posx+(i*heart_size+i) + heart_size)
      if(shot_posy >= heart_posy && shot_posy <= heart_posy + heart_size)
      {
        spaceship_lives--;
        resetSpaceshipShot();
        return;
      }
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
      alienPos[i][1] += alien_speed;
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
  shot_posy = 0;
}

void resetAlienShot(int num)
{
  alienShots[num][0]= 0;
  alienShots[num][1]= 0;
}

void resetAliensPosition()
{
  int posx = 25;
  int posy = 10;
  int basex = 25;
  int iterator = 0;
  
  for(int alien = 0; alien < alienNum; alien++)
  {
    if(iterator == alienNum / 2)
    {
      iterator = 0;
      posy *= 2;
    }
      
    posx = basex * (iterator + 1);
    
    for(int pos = 0; pos < 2; pos++)
    {
      alienPos[alien][pos] = posx;
      posx = posy;
    }
    
    iterator++;
  }
}

void resetSpaceshipPosition()
{
  spaceship_posx = 70;
  spaceship_posy = 110;
}

void masterReset(boolean next_level)
{
  //Alien's life
  //Spaceship's life
  //Shots
  //Positions
  //Shields' resistance
  
  for(int i = 0; i < alienNum; i++)
  {
    alienLife[i] = 1;
  }
  
  for(int i = 0; i < alienNum; i++)
  {
    resetAlienShot(i);
  }
  
  resetSpaceshipShot();
  resetAliensPosition();
  resetSpaceshipPosition();
  
  if(!next_level)
  {
    spaceship_lives = 3;
    currentScore = 0;
    current_level = 1;
  }
    
  shield1_resistance = 12;
  shield2_resistance = 12;
  shield3_resistance = 12;
  
  alien_shot_speed = 2;
  alien_speed = 1;
  current_alien1 = alien1;
  current_alien2 = alien2;
  alien_width = 11;
  alien_height = 8;
}

//-----------------------------------------------------------------------------------------------------------

//OTHER LOGIC
  
void sortScores()
{
  int temp = 0;
  for(int i = 2; i > -1; i--)
  {
    if(HighScores[i] > HighScores[i-1])
    {
      temp = HighScores[i-1];
      HighScores[i-1] = HighScores[i];
      HighScores[i] = temp;
    }
  }
}

void startGame()
{
  while(true)
  {
    VGA.clear();
    VGA.writeArea(spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship);
    
    drawShield(shield1_posx, shield_posy, shield1_resistance);
    drawShield(shield2_posx, shield_posy, shield2_resistance);
    drawShield(shield3_posx, shield_posy, shield3_resistance);
    drawLives();
    drawShipBullet();  
    drawAliens();
    showCurrentScore();
    showCurrentLevel();
    
    fireAlienShot();
    moveAliens();  
    moveAlienShots();
    
    checkUserInput();
    
    checkCollisionAgainstPlayer();
    checkSpaceshipVitality();
           
    checkShieldCollision();  
    checkAlienHit();
    checkLifeHit();
    checkAliensArrival();
    checkLevelFinished();
    checkGameOver();
    
    if(!start)
      return;
    
    delay(100);
  }
}

void nextLevel()
{
  VGA.clear();
  VGA.setColor(GREEN);
  VGA.printtext(15, 50, "Ain't Over Yet!");
  masterReset(true); 
  
  ++current_level;
  alien_speed *= current_level; 
  if(current_level == 2)
  {
    current_alien1 = octopus1;
    current_alien2 = octopus2;
    alien_width = 8;
    alien_height = 8;
  }
  
  else if(current_level == 3)
  {
    current_alien1 = enemy1;
    current_alien2 = enemy2;
    alien_width = 12;
    alien_height = 8;
  }
  
  delay(1500);
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

void setup()
{
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  
  start = false;
  about = false;
  showHighScores = false;
  menuAnim = 0;
  menuAnimType = true;
  menuAlien_posx = 64;
  menuAlienDirection = true;
  
  currentScore_posx = 2;
  currentScore_posy = 1;
  currentScore = 0;
  
  spaceship_posx = 70;
  spaceship_posy = 110;
  spaceship_width = 11;
  spaceship_height = 6;
  spaceship_lives = 3;
  spaceship_speed = 4;
  spaceship_shot_speed = 3;
  current_alien1 = alien1;
  current_alien2 = alien2;
  
  alienNum = 6;
  animateAlien = 0;
  alienCols = 3;
  alienRows = 2;
  alien_shot_speed = 2;
  alien_speed = 1;
  alien_width = 11;
  alien_height = 8;
  
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
  current_level = 1;
}

void loop()
{
  VGA.clear();
  drawMenu();
  checkMenuInput();
  if(start)
    startGame();
  if(about)
    showControls();
  if(showHighScores)
    drawHighScores();
  
  delay(100);
}

