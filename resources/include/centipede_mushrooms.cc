
void InitMushroom(){

    int mushroom_width=32, mushroom_height=32, posx, posy;
    srand (time(NULL));
    for(int i=0;i<50;++i){
        posx = rand()%(kWindowWidth-mushroom_width);
        posy = rand()%(kWindowWidth-mushroom_height/*-150*/)+(mushroom_height+10) ;
        g_mushrooms[i].position.x = posx-posx%32; // para que sean multiplos de 32
        g_mushrooms[i].position.y = posy-posy%32; // para que sean multiplos de 32
        g_mushrooms[i].size.x = mushroom_width;
        g_mushrooms[i].size.y = mushroom_height;
        g_mushrooms[i].type = 1;
        g_mushrooms[i].score = 0;
        g_mushrooms[i].counter = 5;
        g_mushrooms[i].alive = true;
        g_mushrooms[i].sprite = g_mushroom_sprite_complete;       
    }

    //Inicializar los mushrooms que luego aparecen 
    for(int i=50; i<62; ++i){
        g_mushrooms[i].position.x = 0;
        g_mushrooms[i].position.y = 0;
        g_mushrooms[i].size.x = mushroom_width;
        g_mushrooms[i].size.y = mushroom_height;
        g_mushrooms[i].type = 1;
        g_mushrooms[i].score = 0;
        g_mushrooms[i].counter = 5;
        g_mushrooms[i].alive = false;
        g_mushrooms[i].sprite = g_mushroom_sprite_complete;       
    }

}

void DrawMushrooms(){
    
	for (int i=0; i<62; i++){
        
        //cuando la bala choca con la seta para borrarla
        CollisionMushroomBullet(&g_mushrooms[i], &g_player);
        CollisionPlayerMushroom(&g_player, &g_mushrooms[i]);

        //si el mushroom esta vivo, lo dibuja
	    if (g_mushrooms[i].alive){ 
            esat::DrawSprite(g_mushrooms[i].sprite, g_mushrooms[i].position.x, g_mushrooms[i].position.y);
        }      
    }
}