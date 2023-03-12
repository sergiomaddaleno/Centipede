
void InitPlayer(TPlayer *player){
    
    (*player).position.x = (kWindowWidth/2)-35;
    (*player).position.y = kWindowHeight-150;
    (*player).size = {esat::SpriteWidth(g_player_sprite)/2,esat::SpriteHeight(g_player_sprite)/2};
    (*player).sprite = g_player_sprite;
    (*player).bullet.position.x = (*player).position.x;
    (*player).bullet.position.y = (*player).position.y;
    (*player).bullet.size.x = 4;
    (*player).bullet.size.y = 24; 
    (*player).bullet.speed = 40;
    (*player).bullet.active=false;
    (*player).bullet.sprite = g_bullet_sprite;
    (*player).alive = true;
}

void DrawPlayer(TPlayer *player){
    
   if ((*player).alive == true){
    esat::DrawSprite((*player).sprite,(*player).position.x,(*player).position.y);
    } else {
        ++animation%=30; 
        if (animation<10)                    {(*player).sprite = g_player_sprite_death1;} 
        if (animation>=10 && animation<20)  {(*player).sprite = g_player_sprite_death2;}
        if (animation>=20 && animation<30)  {(*player).sprite = g_player_sprite_death4;}
        esat::DrawSprite((*player).sprite,(*player).position.x,(*player).position.y);
    }

    if ((*player).bullet.active == true) {
        esat::DrawSprite((*player).bullet.sprite, ((*player).bullet.position.x)+29, ((*player).bullet.position.y)+50);
        
    }
}

void MovePlayer(TPlayer *player){

    for (int j=0; j<11; j++){
        if (g_player.alive == true) {CollisionPlayerCentipede(&g_player, &g_centipede[j]); }
    }

    //mover player sprite
    int posx = esat::MousePositionX();
    int posy = esat::MousePositionY();

    (*player).position.x = posx-13;
    (*player).position.y = posy-15;
  
    //limite para que no suba el player de la fila 250 desde abajo
    if( (*player).position.y < kWindowHeight-250 ){
        (*player).position.y = kWindowHeight-250;
    }

    //activar bullet para dibujarla
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
        (*player).bullet.active=true;
    }

    //Controla si el bullet sube o para
    if ((*player).bullet.active == true) { //cuando ha disparado sube el bullet
    (*player).bullet.position.y -= (*player).bullet.speed;
    } else { //cuando no ha disparado recupera la posicion 
      (*player).bullet.position.x = posx-30;
      (*player).bullet.position.y = posy-50;
    }

   //borra el sprite de bullet cuando llega arriba
    if ((*player).bullet.position.y<0) {
      (*player).bullet.active = false;
      (*player).bullet.position.x = posx-30;
      (*player).bullet.position.y = posy-50;
    }
}
