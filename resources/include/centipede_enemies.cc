
//centipede
void InitCentipede(){

    int centipede_width=32, centipede_height=32;
    //srand (time(NULL));
    for(int i=0; i<12; ++i){
        g_centipede[i].position.x = (kWindowWidth)-512 - (i*32);
        g_centipede[i].position.y = -64;
        g_centipede[i].size.x = centipede_width;
        g_centipede[i].size.y = centipede_height;
        g_centipede[i].direction = 1;
        g_centipede[i].speed = 4;

        if (i==0){g_centipede[i].type = 1;} //Cabeza centipede == 1
          else   {g_centipede[i].type = 2;} //Resto centipede == 2

        g_centipede[i].counter = 2;
        g_centipede[i].alive = true;
        g_centipede[i].limite = kWindowHeight;

        if (i==0){g_centipede[i].sprite = g_centipedehead_sprite_right;}
        else{g_centipede[i].sprite =  g_centipedebody_sprite_right;}       
    }
}

void DrawCentipede(){
    
    //Tipo de sprite segun el movimiento 
    for (int i=11; i>=0; --i){
      switch(g_centipede[i].type){
        case 1: ++animation%=50;
              if (animation<5)                   {g_centipede[i].sprite = g_centipedehead_sprite_left;}             
              if (animation>=40 && animation<45)  {g_centipede[i].sprite = g_centipedehead_sprite_left5;}
              break;

        case 2: ++animation%=50;
              if (animation<5)                   {g_centipede[i].sprite = g_centipedehead_sprite_right;}             
              if (animation>=40 && animation<45)  {g_centipede[i].sprite = g_centipedehead_sprite_right5;}
              break;

        case 3:  ++animation%=50;
              if (animation<5)                   {g_centipede[i].sprite = g_centipedebody_sprite_left;}             
              if (animation>=40 && animation<45)  {g_centipede[i].sprite = g_centipedebody_sprite_left5;}
              break;

        case 4: ++animation%=50;
              if (animation<5)                   {g_centipede[i].sprite = g_centipedebody_sprite_right;}             
              if (animation>=40 && animation<45)  {g_centipede[i].sprite = g_centipedebody_sprite_right5;}
              break;

        case 5:  ++animation%=50;
              if (animation<5)                   {g_centipede[i].sprite = g_centipedehead_sprite_up;}             
              if (animation>=40 && animation<45)  {g_centipede[i].sprite = g_centipedehead_sprite_up2;}
              break;


        case 6: g_centipede[i].sprite = g_centipedehead_sprite_down; break;

        case 7: ++animation%=50;
              if (animation<5)                   {g_centipede[i].sprite = g_centipedebody_sprite_up;}             
              if (animation>=40 && animation<45)  {g_centipede[i].sprite = g_centipedebody_sprite_up2;}
              break;

        case 8: g_centipede[i].sprite = g_centipedebody_sprite_down; break;
      }

	    if (g_centipede[i].alive == true){ 
        esat::DrawSprite(g_centipede[i].sprite, g_centipede[i].position.x, g_centipede[i].position.y);
      }
    }
}

void MoveCentipede(){
  
  int i, j;

  //Mueve el centipede
  for(i=0; i<12; ++i){

    //movimiento inicial para que baje recto hacia abajo, y luego gira a la derecha
    if ((g_centipede[i].position.y == -64 ) && (g_centipede[i].position.x == kWindowWidth/2)){
      g_centipede[i].direction = 2; 

      if ((i==0) && (g_centipede[i].alive)){g_centipede[i].type = 6;}
      if ((i>0) && (g_centipede[i].alive)){g_centipede[i].type = 8;}}

    if (g_centipede[i].position.y == 32){
      g_centipede[i].direction = 1;
      if ((i==0) && (g_centipede[i].alive)){g_centipede[i].type = 2;}
      if ((i>0) && (g_centipede[i].alive)) {g_centipede[i].type = 4;}
    }

    // Cuando choca la bala con el Centipede:
    if ((g_centipede[i].alive) && (CollisionCentipedeBullet(&g_centipede[i], &g_player))){
      g_centipede[i].alive = false;
      g_player.bullet.active = false;

      //dibuja los mushrooms cuando mata al centipede
        if (lastMushroom<62){  
            for (int j=50; j<=lastMushroom; j++){
                g_mushrooms[j].alive = true;
                g_mushrooms[lastMushroom].position.x = g_centipede[i].position.x ;
                g_mushrooms[lastMushroom].position.y = g_centipede[i].position.y;
                esat::DrawSprite(g_mushrooms[j].sprite, g_mushrooms[j].position.x, g_mushrooms[j].position.y);
            }
            lastMushroom++;
         }

        //Cambia la dirección de la cola del bicho (los que están detrás del choque)  
        j=i+1;
        while (j<12 && g_centipede[j].alive == true){
          
          if ((g_centipede[j].direction == 3) && (j==i+1)){ g_centipede[j].type = 2;}
            
          if (g_centipede[j].direction == 3){ g_centipede[j].direction = 1;}          
            
          if ((g_centipede[j].direction == 1) && (j==i+1)) { g_centipede[j].type = 1;}
           
          if (g_centipede[j].direction == 1){g_centipede[j].direction = 3;}       

          j++;
        }  
    }


    for (int j=0; j<62; j++){
       (CollisionCentipedeMushroom(&g_centipede[i], &g_mushrooms[j]));
     }

    switch (g_centipede[i].direction){
      case 0: g_centipede[i].position.y -= g_centipede[i].speed; break;
      case 1: g_centipede[i].position.x += g_centipede[i].speed; break;
      case 2: g_centipede[i].position.y += g_centipede[i].speed; break;
      case 3: g_centipede[i].position.x -= g_centipede[i].speed; break;
      
    }

    //Cambia la direccion cuando va hacia la derecha y choca con el lateral, baja 32 y gira a la izquierda
    if ((g_centipede[i].position.x)>=kWindowWidth-32){
      
      g_centipede[i].position.x = kWindowWidth-32;
      g_centipede[i].direction = 3;
      g_centipede[i].position.y += 32;

      if ((i==0) && (g_centipede[i].alive)){g_centipede[i].type = 1;}
      if ((i>0) && (g_centipede[i].alive) && (g_centipede[i].type==4)) {g_centipede[i].type = 3;}
      if ((i>0) && (g_centipede[i].alive) && (g_centipede[i].type==2)) {g_centipede[i].type = 1;}
    }

    //Cambia la direccion cuando va hacia la izquierda y choca con el lateral, baja 32 y gira a la derecha
    if ((g_centipede[i].position.x)<=0){
      g_centipede[i].direction = 1;
      g_centipede[i].position.y += 32;

      if ((i==0) && (g_centipede[i].alive)){g_centipede[i].type = 2;}
      if ((i>0) && (g_centipede[i].alive) && (g_centipede[i].type==3)) {g_centipede[i].type = 4;}
      if ((i>0) && (g_centipede[i].alive) && (g_centipede[i].type==1)) {g_centipede[i].type = 2;}
    }

    //Una vez llega el centipede abajo, sube y cambia de sprites 
    if ((g_centipede[i].position.y == kWindowHeight-32) && (g_centipede[i].position.x == kWindowWidth/2)){
      
        g_centipede[i].direction = 0;
        if(g_centipede[i].direction == 0){
          if ((i==0) && (g_centipede[i].alive)){g_centipede[i].type = 5;}
          if ((i>0) && (g_centipede[i].alive)){g_centipede[i].type = 7;}
        }  
    } 
  }
}


//scorpion
void InitScorpion(){

    int scorpion_width=64, scorpion_height=32, posx, posy;
    srand (time(NULL));
  
        posy = rand()%(kWindowWidth-scorpion_height-150)+(scorpion_height+10);
        
        g_scorpion.position.x = -3000; 
        g_scorpion.position.y = posy-posy%32; // para que sean multiplos de 32
        g_scorpion.size.x = scorpion_width;
        g_scorpion.size.y = scorpion_height;

        g_scorpion.direction = 1;

        g_scorpion.speed = 4;
        g_scorpion.type = 1;

        g_scorpion.counter = 0;
        g_scorpion.alive = true;
        g_scorpion.limite = kWindowHeight;

        g_scorpion.sprite = g_scorpion_sprite1;  
}

void DrawScorpion(){

  ++animation%=60;
 
  if (g_scorpion.alive == true){
    if (animation<15)                  {g_scorpion.sprite = g_scorpion_sprite1;}
    if (animation>=45 && animation<60) {g_scorpion.sprite = g_scorpion_sprite4;} 
  }

  esat::DrawSprite(g_scorpion.sprite, g_scorpion.position.x, g_scorpion.position.y);
}

void MoveScorpion(){

  //int randirection = srand (time(NULL));

  for (int j=0; j<50; j++){
        CollisionScorpionMushroom(&g_scorpion, &g_mushrooms[j]);
  }
  CollisionScorpionBullet(&g_scorpion, &g_player);
 

  //dos posibles direcciones, de derech a izq o viceversa
  switch (g_scorpion.direction){
      case 1: g_scorpion.position.x += g_scorpion.speed; break;
      case 2: g_scorpion.position.x -= g_scorpion.speed; break;
    }

    //para parar al scorpion
    if (g_scorpion.position.x == kWindowWidth+500){
      
       g_scorpion.alive = false;
       g_scorpion.speed = 0;
    }
}


//spider
void InitSpider(){

    int spider_width=64, spider_height=32, posx, posy;
    srand (time(NULL));
  
        //posx = rand()%(kWindowWidth-spider_width);
        //posy = rand()%(kWindowWidth-spider_height-150)+(spider_height+10);
        
        g_spider.position.x = 11000;
        g_spider.position.y = -10300; 
        g_spider.size.x = spider_width;
        g_spider.size.y = spider_height;

        g_spider.direction = 4;

        g_spider.speed = 4;
        g_spider.type = 1;

        g_spider.counter = 1;
        g_spider.alive = true;
        g_spider.limite = kWindowHeight;

        g_spider.sprite = g_spider_sprite1;  
}

void DrawSpider(){
  
   ++animation%=75;

  if (g_spider.alive == true){
    if (animation<15)                  {g_spider.sprite = g_spider_sprite1;}
    if (animation>=15 && animation<40) { g_spider.sprite = g_spider_sprite2;} 
    if (animation>=40 && animation<75) { g_spider.sprite = g_spider_sprite5;} 
  }  

	esat::DrawSprite(g_spider.sprite, g_spider.position.x, g_spider.position.y);

}

void MoveSpider(){

  //srand (time(NULL));
   CollisionSpiderBullet(&g_spider, &g_player); // borra el sprite de la araña cuando colisiona con la bala del jugador
   if (g_spider.alive == true) { CollisionPlayerSpider(&g_player, &g_spider);} // para matar al jugador.


  //posibles direcciones de la araña
  switch (g_spider.direction){
      //diagonal derecha, abajo
      case 1: (g_spider.position.x = ((g_spider.position.x) + g_spider.speed)) && (g_spider.position.y = ((g_spider.position.y) + g_spider.speed)); break;
      //diagonal izq, arriba
      case 2: (g_spider.position.x = ((g_spider.position.x) - g_spider.speed)) && (g_spider.position.y = ((g_spider.position.y) - g_spider.speed)); break;
      //diagonal derecha, arriba
      case 3: (g_spider.position.x = ((g_spider.position.x) + g_spider.speed)) && (g_spider.position.y = ((g_spider.position.y) - g_spider.speed)); break;
      //diagonal izq, abajo
      case 4: (g_spider.position.x = ((g_spider.position.x) - g_spider.speed)) && (g_spider.position.y = ((g_spider.position.y) + g_spider.speed)); break;
      //izqo derecha
      case 5: g_spider.position.x += g_spider.speed; break;
      case 6: g_spider.position.x -= g_spider.speed; break;
      //arriba o abajo
      case 7: g_spider.position.y -= g_spider.speed; break;
      case 8: g_spider.position.y += g_spider.speed; break;
    }

    //para que rebote por la pantalla
    if (g_spider.position.x == 0 ){
        g_spider.direction = 1;}

    if (g_spider.position.y == kWindowHeight-32){
        g_spider.direction = 3;}

}


//flea
void InitFlea(){

    int flea_width=64, flea_height=32, posx, posy;
    //srand (time(NULL));
  
        posx = rand()%(kWindowWidth-flea_width);
       
        g_flea.position.x = posx;
        g_flea.position.y = -6000;
        g_flea.size.x = flea_width;
        g_flea.size.y = flea_height;

        g_flea.direction = 2;

        g_flea.speed = 4;
        g_flea.type = 1;

        g_flea.counter = 1;
        g_flea.alive = true;
        g_flea.limite = kWindowHeight;

        g_flea.sprite = g_flea_sprite1;  
    
}

void DrawFlea(){

  ++animation%=60;

  if (g_flea.alive == true){
    if (animation<15)                  {g_flea.sprite =  g_flea_sprite1;}
    if (animation>=15 && animation<30) { g_flea.sprite =  g_flea_sprite2;}
    if (animation>=30 && animation<45) { g_flea.sprite =  g_flea_sprite3;}
    if (animation>=45 && animation<60) { g_flea.sprite =  g_flea_sprite4;} 
  }

	esat::DrawSprite(g_flea.sprite, g_flea.position.x, g_flea.position.y);

}

void MoveFlea(){

  //int randirection;
  srand (time(NULL));
  CollisionFleaBullet(&g_flea, &g_player);
  if (g_flea.alive == true) {CollisionPlayerFlea(&g_flea, &g_player);}
  
  switch (g_flea.direction){
      case 2: g_flea.position.y += g_flea.speed; break;
    }
}