

//los puntos cuando hay colisión
bool PointCollision(int x1,int y1, int x2,int y2, int w2,int h2){
  return x1>=x2 && x1<=x2+w2 && y1>=y2 && y1<=y2+h2;
}

bool BoxCollision(int x1,int y1, int w1,int h1, int x2,int y2, int w2,int h2) {

  return PointCollision(x1,y1,x2,y2,w2,h2) ||
         PointCollision(x1+w1,y1,x2,y2,w2,h2) ||
         PointCollision(x1+w1,y1+h1,x2,y2,w2,h2) ||
         PointCollision(x1,y1+h1,x2,y2,w2,h2);
}

void CollisionMushroomBullet(TMushroom *mushroom, TPlayer *player){
  
  //comprueba si hay colisión
  if(BoxCollision(((*player).bullet.position.x)+32,((*player).bullet.position.y),
                  (*player).bullet.size.x,(*player).bullet.size.y,
                  (*mushroom).position.x,(*mushroom).position.y,
                  (*mushroom).size.x,(*mushroom).size.y) && (*player).bullet.active){


    //si hay colision borra el bullet y va cambiando de sprite y sumo score
    (*mushroom).counter = (*mushroom).counter-1;
    switch ((*mushroom).counter){
      case 4: (*mushroom).sprite = g_mushroom_sprite_broken1; (*player).bullet.active=false; break;
      case 3: (*mushroom).sprite = g_mushroom_sprite_broken2; (*player).bullet.active=false; break;
      case 2: (*mushroom).sprite = g_mushroom_sprite_broken3; (*player).bullet.active=false; break;
      case 1: (*mushroom).sprite = g_blacksprite; (*player).bullet.active=false; (*mushroom).alive = false; score1 = score1 + 4; break;
      case 0: (*player).bullet.active=true; break;
    
    
    }
  }
}

bool CollisionCentipedeBullet(TCentipede *centipede, TPlayer *player){
  

  //Comprueba si hay colision  
  if(BoxCollision(

                  ((*player).bullet.position.x)+32,((*player).bullet.position.y),
                  (*player).bullet.size.x,(*player).bullet.size.y,
                  (*centipede).position.x,(*centipede).position.y,
                  (*centipede).size.x,(*centipede).size.y) && (*player).bullet.active){
   

        for(int j=1; j<8; ++j){
          switch(j){
            case 1: (*centipede).sprite = g_explosion_sprite_1; break;
            case 2: (*centipede).sprite = g_explosion_sprite_2; break;
            case 3: (*centipede).sprite = g_explosion_sprite_3; break;
            case 4: (*centipede).sprite = g_explosion_sprite_4; break;
            case 5: (*centipede).sprite = g_explosion_sprite_5; break;
            case 6: (*centipede).sprite = g_explosion_sprite_6; break;
            case 7: (*centipede).sprite = g_blacksprite; score1 = score1 + 10; break;
            //case 7: esat::DrawSprite(g_mushrooms.sprite, g_mushrooms.position.x, g_mushrooms.position.y) 
          }
        }
    return true;}
    else {return false;}
}

void CollisionCentipedeMushroom(TCentipede *centipede, TMushroom *mushroom){

  //Comprueba si hay colision 
  if ((((*mushroom).alive) && (BoxCollision)(
                  (*centipede).position.x, (*centipede).position.y,
                  (*centipede).size.x,(*centipede).size.y,
                  (*mushroom).position.x,(*mushroom).position.y,
                  (*mushroom).size.x, (*mushroom).size.y))) {

    //cambia direccion si colisiona con el mushroom
    for(int i=0; i<12; ++i){

      //Cambia la direccion cuando va hacia la derecha, baja 32 y gira a la izquierda
      if (((((g_centipede[i].position.x)+32)==(*mushroom).position.x) && ((g_centipede[i].position.y)==(*mushroom).position.y)) && g_centipede[i].direction == 1) {
      
        g_centipede[i].direction = 3;
        g_centipede[i].position.y += 32;
     
      if ((i==0) && (g_centipede[i].alive)){g_centipede[i].type = 1;}
      if ((i>0) && (g_centipede[i].alive) && (g_centipede[i].type == 4)) {g_centipede[i].type = 3;}
      }

      //Cambia la direccion cuando va hacia la izquierda, baja 32 y gira a la derecha
      if (((((g_centipede[i].position.x)-32)==(*mushroom).position.x) && ((g_centipede[i].position.y)==(*mushroom).position.y)) && g_centipede[i].direction == 3) {
      
        g_centipede[i].direction = 1;
        g_centipede[i].position.y += 32;

      if ((i==0) && (g_centipede[i].alive)) {g_centipede[i].type = 2;}
      if ((i>0) && (g_centipede[i].alive) && (g_centipede[i].type == 3)) {g_centipede[i].type = 4;}
      }

    }
  }
}

bool CollisionPlayerCentipede(TPlayer *player, TCentipede *centipede){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*centipede).position.x,(*centipede).position.y,
                  (*centipede).size.x, (*centipede).size.y)) {


    if (lifeNum > 0){ lifeNum = lifeNum - 1;} 
    (*player).bullet.active=false;
    (*centipede).alive = false;

    return true;}
  else {return false;}
}

void CollisionPlayerMushroom(TPlayer *player, TMushroom *mushroom){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*mushroom).position.x,(*mushroom).position.y,
                  (*mushroom).size.x, (*mushroom).size.y)) {
      
       if ((*player).position.x > (*mushroom).position.x){ (*player).position.x = (*player).position.x +32;}
       if ((*player).position.x < (*mushroom).position.x){ (*player).position.x = (*player).position.x -32;}

       //if ((*player).position.y <  (*mushroom).position.y){ (*player).position.y = (*player).position.x -32;}
       //if ((*player).position.y >  (*mushroom).position.y){ (*player).position.y = (*player).position.x +32;}
    
  }
}

void CollisionScorpionMushroom(TScorpion *scorpion, TMushroom *mushroom){

  if(BoxCollision(

                  ((*scorpion).position.x), ((*scorpion).position.y),
                  (*scorpion).size.x-30, (*scorpion).size.y-17,
                  (*mushroom).position.x, (*mushroom).position.y,
                  (*mushroom).size.x-30, (*mushroom).size.y-17)){

   
    (*mushroom).sprite = g_poisonmushroom_sprite_complete;
    
  }
}

void CollisionScorpionBullet(TScorpion *scorpion, TPlayer *player){

  //Comprueba si hay colision  
  if(BoxCollision(

                  ((*player).bullet.position.x)+32,((*player).bullet.position.y),
                  (*player).bullet.size.x,(*player).bullet.size.y,
                  (*scorpion).position.x,(*scorpion).position.y,
                  (*scorpion).size.x,(*scorpion).size.y) && (*player).bullet.active){
                                
        g_scorpion.alive = false;

        for(int j=1; j<8; ++j){
          switch(j){
            case 1: (*scorpion).sprite = g_explosion_sprite_1; break;
            case 2: (*scorpion).sprite = g_explosion_sprite_2; break;
            case 3: (*scorpion).sprite = g_explosion_sprite_3; break;
            case 4: (*scorpion).sprite = g_explosion_sprite_4; break;
            case 5: (*scorpion).sprite = g_explosion_sprite_5; break;
            case 6: (*scorpion).sprite = g_explosion_sprite_6; break;
            case 7: (*scorpion).sprite = g_blacksprite; g_scorpion.alive = false; score1 = score1 + 1000; break;


          }
        }
      }
}

void CollisionFleaBullet(TFlea *flea, TPlayer *player){

  //Comprueba si hay colision  
  if(BoxCollision(

                  ((*player).bullet.position.x)+32,((*player).bullet.position.y),
                  (*player).bullet.size.x,(*player).bullet.size.y,
                  (*flea).position.x,(*flea).position.y,
                  (*flea).size.x,(*flea).size.y) && (*player).bullet.active){
   
        g_flea.alive = false;
        for(int j=1; j<8; ++j){
          switch(j){
            case 1: (*flea).sprite = g_explosion_sprite_1; break;
            case 2: (*flea).sprite = g_explosion_sprite_2; break;
            case 3: (*flea).sprite = g_explosion_sprite_3; break;
            case 4: (*flea).sprite = g_explosion_sprite_4; break;
            case 5: (*flea).sprite = g_explosion_sprite_5; break;
            case 6: (*flea).sprite = g_explosion_sprite_6; break;
            case 7: (*flea).sprite = g_blacksprite; score1 = score1 + 200; break;
            
          }
        }
      }
}

void CollisionSpiderBullet(TSpider *spider, TPlayer *player){

  //Comprueba si hay colision  
  if(BoxCollision(

                  ((*player).bullet.position.x)+32,((*player).bullet.position.y),
                  (*player).bullet.size.x,(*player).bullet.size.y,
                  (*spider).position.x,(*spider).position.y,
                  (*spider).size.x,(*spider).size.y) && (*player).bullet.active){
   
        g_spider.alive = false;

        for(int j=1; j<8; ++j){
          switch(j){
            case 1: (*spider).sprite = g_explosion_sprite_1; break;
            case 2: (*spider).sprite = g_explosion_sprite_2; break;
            case 3: (*spider).sprite = g_explosion_sprite_3; break;
            case 4: (*spider).sprite = g_explosion_sprite_4; break;
            case 5: (*spider).sprite = g_explosion_sprite_5; break;
            case 6: (*spider).sprite = g_explosion_sprite_6; break;
            case 7: (*spider).sprite = g_blacksprite; score1 = score1 + 500; break;
            
          }
        }
      }
}

bool CollisionPlayerFlea(TFlea *flea, TPlayer *player){

   if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*flea).position.x,(*flea).position.y,
                  (*flea).size.x, (*flea).size.y)) {

    if (lifeNum > 0){ lifeNum = lifeNum - 1;} 
    (*player).bullet.active=false;
    g_flea.alive = false;
      
     return true;}
  else {return false;}
}

bool CollisionPlayerSpider(TPlayer *player, TSpider *spider){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*spider).position.x,(*spider).position.y,
                  (*spider).size.x, (*spider).size.y)) {

    if (lifeNum > 0){ lifeNum = lifeNum - 1;} 
    (*player).bullet.active=false;
      
    g_spider.alive = false;
      
    return true;}
  else {return false;}
}