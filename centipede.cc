
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "resources/include/centipede_variables.cc"
#include "resources/include/sprites.cc"
#include "resources/include/centipede_collisions.cc"
#include "resources/include/centipede_player.cc"
#include "resources/include/centipede_mushrooms.cc"
#include "resources/include/centipede_enemies.cc"
#include "resources/include/centipede_interface.cc"


void Game(){
  DrawPlayer(&g_player);
  if (g_player.alive == true) {MovePlayer(&g_player);}
  DrawMushrooms();
  DrawCentipede();
  MoveCentipede();
  DrawScorpion();
  MoveScorpion();
  DrawSpider();
  MoveSpider();
  DrawFlea();
  MoveFlea();
  DrawScores();

}

void InitParts(){
  InitSprites();
  InitPlayer(&g_player);
  InitMushroom();
  InitCentipede();
  InitScorpion();
  InitSpider();
  InitFlea();

  InitInterface();
}

void GameStart(){

  LoadingScreen();
  if(Loading==200){ //200
   gameselection=true;
  }
  if(gamestart){
    Game();
  }
}

int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindowWidth,kWindowHeight);
  WindowSetMouseVisibility(true);

  InitParts();
  
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
  
  	last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
   
    GameStart();
    esat::DrawEnd();

   do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
   esat::WindowFrame();
  }

  ReleaseSprites();
  esat::WindowDestroy();

  return 0;
}

