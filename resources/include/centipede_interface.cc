
void InitInterface(){

    char cadena[10];

    esat::DrawSetTextFont("./resources/font/Centipede.ttf");
    esat::DrawSetTextSize(35.0f);

}

void DrawScores(){
  
   char cadena[10];
   int i=score1;
   itoa(i,cadena,10);
   
   esat::DrawSetFillColor(255,0,0);
   esat::DrawText(20, 32, "POINTS:");
   esat::DrawText(160, 32, cadena);
   
    //Cuando matan al player, inicializa todos los valores y borra un sprite del marcador
    for (int j=0; j<12; j++){
        if (((CollisionPlayerCentipede(&g_player, &g_centipede[j])) || (CollisionPlayerFlea(&g_flea, &g_player)) || (CollisionPlayerSpider(&g_player, &g_spider)))== true){
           
            if (lifeNum == 0) {g_player.alive = false;} //Cuando ya no le quedan vidas
            else {InitCentipede(); InitSpider(); InitFlea(); InitScorpion(); InitPlayer(&g_player);}
            
        }
    }

    //DIbujan los players en el marcador
   switch (lifeNum){
        case 3: esat::DrawSprite(g_player_sprite3,256,0);  esat::DrawSprite(g_player_sprite2,288,0); break;
        case 2: esat::DrawSprite(g_player_sprite3,256,0); break;
    }


    if (g_player.alive == false){ //(g_player_sprite2 == g_blacksprite){

      esat::DrawText(kWindowWidth * 0.4f, kWindowHeight * 0.4f, "GAME OVER");
    }
    
}

void LoadingScreen(){
    
    if(gamestart==false){
        esat::DrawSprite(g_loading_screen_1, 190, 100);
        //esat::DrawSprite(g_pp_sprite, 20, kWindowHeight-120);
        esat::DrawText(180, kWindowHeight-60, "Recreated   by   Sergio   Madaleno");

        esat::DrawText(240, 80, "press  'enter'  to  start");
    }
    
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
        gamestart=true;
    }
}