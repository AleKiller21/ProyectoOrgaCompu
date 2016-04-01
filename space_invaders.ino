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

unsigned char shieldPoweup[]={
BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,
WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,
WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,
WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE
};

unsigned char powerUp[]={
BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,
BLUE,BLACK,BLACK,BLACK,BLACK,BLACK,BLUE,
BLUE,BLACK,BLACK,BLUE,BLACK,BLACK,BLUE,
BLUE,BLACK,BLUE,BLUE,BLUE,BLACK,BLUE,
BLUE,BLACK,BLACK,BLUE,BLACK,BLACK,BLUE,
BLACK,BLUE,BLACK,BLACK,BLACK,BLUE,BLACK,
BLACK,BLACK,BLUE,BLUE,BLUE,BLACK,BLACK
};

unsigned char powerUpShot[]={
BLACK,BLACK,BLACK,RED,BLACK,BLACK,BLACK,
BLACK,RED,RED,RED,RED,RED,BLACK,
BLACK,RED,BLACK,RED,BLACK,RED,BLACK,
RED,RED,RED,RED,RED,RED,RED,
BLACK,RED,BLACK,RED,BLACK,RED,BLACK,
BLACK,RED,RED,RED,RED,RED,BLACK,
BLACK,BLACK,BLACK,RED,BLACK,BLACK,BLACK
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

unsigned char power_shot[]={
RED,
RED,
RED,
RED
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

unsigned char scoreTaker1[]={
BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK
};

unsigned char scoreTaker2[]={
BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,BLACK,BLACK
};

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

//DECLARACION DE VARIABLES

//menu
boolean showMenu,menuAnimType, menuAlienDirection;
int menuAnim = 0, menuAlien_posx, menu_selection;

//nave
int spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship_lives;
int spaceship_speed, spaceship_shot_speed;

//power-up
int shield_resistance, contador_shield, power_shield_posX, power_shield_posY, shot_counter, power_shotX, power_shotY, shot_time;
boolean shield_active, power_onScreen, shot_power, shot_onSreen;

//disparo
int shot_posy, shot_posx;
boolean isShot;

//corazon
int heart_posx,heart_posy,heart_size;

//score
boolean showNewHighScore;
int currentScore,currentScore_posx,currentScore_posy;

//aliens
boolean alienAnimType, moveDirection, goDown, alienShooting, taker_Destroyed, takerAnimationType, scoreTaken, takerAppears, takerConditions, minScore;
int alienNum, animateAlien, alienCols, alienRows, alien_shot_speed, animateTaker, takerX, takerSpeed, probabilidadTaker;
int alien_speed, alien_width, alien_height;
unsigned char* current_alien1;
unsigned char* current_alien2;
unsigned char* taker1;
unsigned char* taker2;

//shields
int shield1_resistance, shield2_resistance, shield3_resistance, shield1_posx, shield2_posx, shield3_posx;
int shield_posy, shield_margin, shield_width, shield_height;

//general
boolean game_over;
int current_level, current_message;

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

char* messages[] = {"Ignore", "Ain't Over Yet", "Foolish Earthling!", "Still here?!", "This is the End!", "Impossible!!!", "Error! Error! Error!"};

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
      showMenu = true;
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
  
  if(menu_selection == 0)
    VGA.setColor(CYAN);
  else
    VGA.setColor(BLUE);
  VGA.printtext(60, 60, "START");
  
  if(menu_selection == 1)
  {
    VGA.setColor(CYAN);
  }else
  {
    VGA.setColor(BLUE);
  }
  VGA.printtext(60, 80, "ABOUT");
  
  if(menu_selection == 2)
    VGA.setColor(CYAN);
  else
    VGA.setColor(BLUE);
  VGA.printtext(45, 100, "HIGHSCORES");
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
      showMenu = true;
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

void drawTaker()
{
    if(takerConditions)
    {
      animateTaker++;
      if(animateTaker == 10)
      {
        takerAnimationType = !takerAnimationType;
        animateTaker = 0;
      }
      
      if(takerAnimationType){
        VGA.writeArea(takerX, 1, 16, 7, taker1);
      }else{
        VGA.writeArea(takerX, 1, 16, 7, taker2);
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
    
    if(showNewHighScore)
    {
      VGA.setColor(YELLOW);
      VGA.printtext(35, 75, "NEW HIGHSCORE");
    }
    
    if(digitalRead(FPGA_BTN_3))
    {
      showNewHighScore = false;
      game_over = false;
      showMenu = true;
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

void drawShieldCapacity()
{
  if(shield_active)
  {
    for(int i=0;i<shield_resistance;i++)
  {
    VGA.writeArea(0+(i*7+i), 90, 7, 7, powerUp);
  }
  }
}

void drawShotActive()
{
  if(shot_power)
  {
    VGA.writeArea(0, 80, 7, 7, powerUpShot);
  }
}

void drawPowerUp()
{
  if(power_onScreen)
    VGA.writeArea(power_shield_posX, power_shield_posY, 7, 7, powerUp);
}

void drawShotPowerUp()
{
  if(shot_onSreen)
    VGA.writeArea(power_shotX, power_shotY, 7, 7, powerUpShot);
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
    if(shot_power)
    {
      VGA.writeArea(shot_posx, shot_posy, 1, 3, power_shot);
    }else
    {
      VGA.writeArea(shot_posx, shot_posy, 1, 3, shot);
    }
  }
}

void showCurrentScore()
{
    char* scorePtr = "";
    itoa(currentScore,scorePtr,10);
    VGA.setColor(BLUE);
    if(scoreTaken == false){
      VGA.printtext(currentScore_posx,currentScore_posy,scorePtr, true);
    }else{
      VGA.printtext(takerX,6,scorePtr, true);
    }
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
    if(shot_posx >= alienPos[i][0] - 3 && shot_posx <= alienPos[i][0] + alien_width + 3)
      if(shot_posy >= alienPos[i][1] && shot_posy <= alienPos[i][1] + alien_height + 3)
        if(alienLife[i])
          return i;
  }
  return -1;
}

int shootingTaken()
{
    if(shot_posx >= takerX - 3 && shot_posx <= takerX + 19)
      if(shot_posy >= 1 && shot_posy <= 11)
         return 1;
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

//Calcula si el taker aparecera en la ronda actual
void takerAppear()
{
  if(taker_Destroyed == false){
    int desicion = rand() % 50;
    int resta = 7 * current_level;
    if(desicion >= (probabilidadTaker - resta)){
      takerAppears = true;
    }
  }
}

void powerUpAppear()
{
  contador_shield++;
  if(contador_shield >= 30 && power_onScreen == false)
  {
    int desicion = rand() % 100;
    int resta = 15 * current_level;
    if(desicion >= (100 - resta))
    {
      power_onScreen = true;
      int posX = rand() % 145;
      power_shield_posX = posX + 2;
      power_shield_posY = 50;
    }
    contador_shield = 0;
  }
}

void ShotpowerUpAppear()
{
  shot_counter++;
  if(shot_counter >= 30 && shot_onSreen == false && shot_power == false)
  {
    int desicion = rand() % 100;
    int resta = 10 * current_level;
    if(desicion >= (100 - resta))
    {
      shot_onSreen = true;
      int posX = rand() % 145;
      power_shotX = posX + 2;
      power_shotY = 50;
    }
    shot_counter = 0;
  }
}

//----------------------------------------------------------------------------------------------------

//CHECK ACTIONS

void checkMenuInput()
{
  if(digitalRead(FPGA_BTN_0))
  {
    menu_selection--;
    if(menu_selection < 0)
    {
      menu_selection = 2;
    }
  }
  
  if(digitalRead(FPGA_BTN_1))
  {
    menu_selection++;
    if(menu_selection > 2)
    {
      menu_selection = 0;
    }
  }
  
  if(digitalRead(FPGA_BTN_2))
  {
    showMenu = false;
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
          if(shield_active)
          {
            shield_resistance--;
          }else
          {
            spaceship_lives--;
          }
          resetAlienShot(i);
          break;
        }
    }
  }
}
  
void checkPowerUpColiision()
{
  if(power_onScreen)
  {
    if(((power_shield_posX >= spaceship_posx && power_shield_posX <= spaceship_posx + spaceship_width) || (power_shield_posX + 7 >= spaceship_posx && power_shield_posX + 7 <= spaceship_posx + spaceship_width)) && (power_shield_posX <= spaceship_posx + spaceship_width))
    {
      if(power_shield_posY >=105)
        {
          power_onScreen = false;
          shield_resistance = 3;
          shield_active = true;
        }
    }
  }
}

void checkShotPowerUpColiision()
{
  if(shot_onSreen)
  {
    if(((power_shotX >= spaceship_posx && power_shotX <= spaceship_posx + spaceship_width) || (power_shotX + 7 >= spaceship_posx && power_shotX + 7 <= spaceship_posx + spaceship_width)) && (power_shotX <= spaceship_posx + spaceship_width))
    {
      if(power_shotY >=105)
        {
          shot_onSreen = false;
          shot_power = true;
        }
    }
  }
}

void checkShotPowerDuration()
{
  if(shot_power == true)
  {
    shot_time++;
    if(shot_time == 50)
    {
      shot_time = 0;
      shot_power = false;
    }
  }
}

void checkShield()
{
  if(shield_active)
  {
    if(shield_resistance <= 0)
      shield_active = false;
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
    minScore = true;
    
    //alien shot animation
    VGA.writeArea(alienPos[alienShot][0], alienPos[alienShot][1], alien_width, alien_height, explosion);
    alien_shot_speed++;
    alien_speed++;
    delay(30);
  }
}

void checkTakerHit()
{
  if(!taker_Destroyed)
  {
  int alienShot = shootingTaken();
  if(alienShot != -1)
  {
    taker_Destroyed = true;
    scoreTaken = false;
    takerAppears = false;
    takerConditions = false;
    resetSpaceshipShot();
    currentScore += 100;
    
    //alien shot animation
    VGA.writeArea(takerX, 1, 16, 7, explosion);
    delay(30);
  }
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
        showMenu = true;
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
      showNewHighScore = true;
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

void checkTakerCondit()
{
  if(taker_Destroyed == false)
  {
    if(takerAppears == true)
    {
      if(minScore == true){
        takerConditions = true;
     }
    }
  }
}

void checkTakerDirection()
{
    if(takerConditions == true)
    {
      if(scoreTaken == false){
        if(takerX <= 2){
          scoreTaken = true;
       }else{
          takerX -= takerSpeed;
       }
        }else{
         if(takerX >= 140){
           currentScore = 0;
           taker_Destroyed = true;
           takerConditions = false;
           scoreTaken = false;
         }else{
           takerX += takerSpeed;;
         }
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

void moveTaker()
{
  checkTakerCondit();
  checkTakerDirection();
}

void movePowerUp()
{
  if(power_onScreen)
  {
    power_shield_posY++;
    if(power_shield_posY >= 120)
      power_onScreen = false;
  }
}

void moveShotPowerUp()
{
  if(shot_onSreen)
  {
    power_shotY++;
    if(power_shotY >= 120)
      shot_onSreen = false;
  }
}

//-----------------------------------------------------------------------------------------------------------

//RESET

void resetSpaceshipShot()
{
  if(!shot_power)
  {
    isShot = false;
    shot_posx = 0;
    shot_posy = 0;
  }
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
  //Taker stats
  
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
    spaceship_shot_speed = 3;
    changeAlienType(1);
    taker_Destroyed = false;
    scoreTaken = false;
    takerAppears = false;
    takerConditions = false;
    takerX = 145;
    takerAnimationType = false;
    animateTaker = 0;
    minScore = false;
    takerSpeed = 1;
    probabilidadTaker = 50;
  }
  
  shield_resistance = 0;
  shield_active = false;
  power_shield_posY = 50;
  power_shield_posX = 50;
  contador_shield = 0;
  power_onScreen = false;
  
  shot_counter = 0;
  power_shotX = 50;
  power_shotY = 50;
  shot_time = 0;
  shot_power = false;
  shot_onSreen = false;
    
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
    if(shield_active)
      {
        VGA.writeArea(spaceship_posx-2, spaceship_posy-2, spaceship_width+4, spaceship_height+2, shieldPoweup);
      }
    VGA.writeArea(spaceship_posx, spaceship_posy, spaceship_width, spaceship_height, spaceship);
    
    checkCollisionAgainstPlayer();
    checkPowerUpColiision();
    checkShotPowerUpColiision();
    checkShield();
    checkSpaceshipVitality();
    checkShotPowerDuration();
    
    drawShield(shield1_posx, shield_posy, shield1_resistance);
    drawShield(shield2_posx, shield_posy, shield2_resistance);
    drawShield(shield3_posx, shield_posy, shield3_resistance);
    drawLives();
    drawShieldCapacity();
    drawShotActive();
    drawShipBullet();  
    drawAliens();
    drawTaker();
    showCurrentScore();
    showCurrentLevel();
    powerUpAppear();
    ShotpowerUpAppear();
    drawPowerUp();
    drawShotPowerUp();
    
    fireAlienShot();
    moveAliens();
    moveTaker();  
    moveAlienShots();
    movePowerUp();
    moveShotPowerUp();
    
    checkUserInput();
           
    checkShieldCollision();  
    checkAlienHit();
    checkTakerHit();
    checkLifeHit();
    checkAliensArrival();
    checkLevelFinished();
    checkGameOver();
    
    if(showMenu)
      return;
    
    delay(100);
  }
}

void nextLevel()
{
  VGA.clear();
  VGA.setColor(GREEN);
  ++current_level;
  if(current_level > 3)
  {
    current_message = (current_message == 6?3:current_message+1);
    VGA.printtext(15, 50, messages[current_message]);
  }
  else
    VGA.printtext(15, 50, messages[current_level - 1]);
  masterReset(true); 
  
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
  
  changeAlienType(current_level);
  
  spaceship_shot_speed++;
  
  minScore = false;
  takerSpeed += 1;
  takerAppear();
  
  delay(1500);
}

void changeAlienType(int lvl)
{
  for(int i = 0; i < alienNum; i++)
    alienType[i] = lvl;
    
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

void setup()
{
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  
  showMenu = true;
  menu_selection = 0;
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
  current_message = 2;
  
  taker_Destroyed = false;
  scoreTaken = false;
  takerAppears = false;
  takerConditions = false;
  takerX = 145;
  takerAnimationType = false;
  animateTaker = 0;
  taker1 = scoreTaker1;
  taker2 = scoreTaker2;
  minScore = false;
  takerSpeed = 1;
  probabilidadTaker = 50;
  takerAppear();
  
  shield_resistance = 0;
  shield_active = false;
  power_shield_posY = 50;
  power_shield_posX = 50;
  contador_shield = 0;
  power_onScreen = false;
  
  shot_counter = 0;
  power_shotX = 50;
  power_shotY = 50;
  shot_time = 0;
  shot_power = false;
  shot_onSreen = false;
}

void loop()
{
  VGA.clear();
  drawMenu();
  checkMenuInput();
  if(!showMenu)
  {
    if(menu_selection == 0)
      startGame();
    if(menu_selection == 1)
      showControls();
    if(menu_selection == 2)
      drawHighScores();
  }
  delay(100);
}

