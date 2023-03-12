
void InitSprites(){

    //sprites player
    g_player_sprite=esat::SpriteFromFile("./resources/img/player1.png");
    g_player_sprite2=esat::SpriteFromFile("./resources/img/player2.png");
    g_player_sprite3=esat::SpriteFromFile("./resources/img/player2.png");
    g_player_sprite_death1=esat::SpriteFromFile("./resources/img/playerdeath1.png");
    g_player_sprite_death2=esat::SpriteFromFile("./resources/img/playerdeath2.png");
    g_player_sprite_death3=esat::SpriteFromFile("./resources/img/playerdeath3.png");
    g_player_sprite_death4=esat::SpriteFromFile("./resources/img/playerdeath4.png");
    g_player_sprite_death5=esat::SpriteFromFile("./resources/img/playerdeath5.png");
    g_player_sprite_death6=esat::SpriteFromFile("./resources/img/playerdeath6.png");
    g_player_sprite_death7=esat::SpriteFromFile("./resources/img/playerdeath7.png");
    g_player_sprite_death8=esat::SpriteFromFile("./resources/img/playerdeath8.png");

    //sprite bullet
    g_bullet_sprite=esat::SpriteFromFile("./resources/img/bullet.png");
   
   //sprites mushrooms
    g_mushroom_sprite_complete=esat::SpriteFromFile("./resources/img/mushroomcomplete.png");
    g_mushroom_sprite_broken1=esat::SpriteFromFile("./resources/img/mushroombroken1.png");
    g_mushroom_sprite_broken2=esat::SpriteFromFile("./resources/img/mushroombroken2.png");
    g_mushroom_sprite_broken3=esat::SpriteFromFile("./resources/img/mushroombroken3.png");

    g_poisonmushroom_sprite_complete=esat::SpriteFromFile("./resources/img/poisonmushroomcomplete.png");
    g_poisonmushroom_sprite_broken1=esat::SpriteFromFile("./resources/img/poisonmushroombroken1.png");
    g_poisonmushroom_sprite_broken2=esat::SpriteFromFile("./resources/img/poisonmushroombroken2.png");
    g_poisonmushroom_sprite_broken3=esat::SpriteFromFile("./resources/img/poisonmushroombroken3.png");

    //sprite extra
    g_blacksprite=esat::SpriteFromFile("./resources/img/blacksprite.png");

    //sprites centipede head
    g_centipedehead_sprite_left=esat::SpriteFromFile("./resources/img/centipedehead_left.png");
    g_centipedehead_sprite_left2=esat::SpriteFromFile("./resources/img/centipedehead_left2.png");
    g_centipedehead_sprite_left3=esat::SpriteFromFile("./resources/img/centipedehead_left3.png");
    g_centipedehead_sprite_left4=esat::SpriteFromFile("./resources/img/centipedehead_left4.png");
    g_centipedehead_sprite_left5=esat::SpriteFromFile("./resources/img/centipedehead_left5.png");

    g_centipedehead_sprite_right=esat::SpriteFromFile("./resources/img/centipedehead_right.png");
    g_centipedehead_sprite_right2=esat::SpriteFromFile("./resources/img/centipedehead_right2.png");
    g_centipedehead_sprite_right3=esat::SpriteFromFile("./resources/img/centipedehead_right3.png");
    g_centipedehead_sprite_right4=esat::SpriteFromFile("./resources/img/centipedehead_right4.png");
    g_centipedehead_sprite_right5=esat::SpriteFromFile("./resources/img/centipedehead_right5.png");

    g_centipedehead_sprite_up=esat::SpriteFromFile("./resources/img/centipedehead_up.png");
    g_centipedehead_sprite_up2=esat::SpriteFromFile("./resources/img/centipedehead_up2.png");
    g_centipedehead_sprite_down=esat::SpriteFromFile("./resources/img/centipedehead_down.png");


    //sprites centipede body
    g_centipedebody_sprite_left=esat::SpriteFromFile("./resources/img/centipedebody_left.png");
    g_centipedebody_sprite_left2=esat::SpriteFromFile("./resources/img/centipedebody_left2.png");
    g_centipedebody_sprite_left3=esat::SpriteFromFile("./resources/img/centipedebody_left3.png");
    g_centipedebody_sprite_left4=esat::SpriteFromFile("./resources/img/centipedebody_left4.png");
    g_centipedebody_sprite_left5=esat::SpriteFromFile("./resources/img/centipedebody_left5.png");
    
    g_centipedebody_sprite_right=esat::SpriteFromFile("./resources/img/centipedebody_right.png");
    g_centipedebody_sprite_right2=esat::SpriteFromFile("./resources/img/centipedebody_right2.png");
    g_centipedebody_sprite_right3=esat::SpriteFromFile("./resources/img/centipedebody_right3.png");
    g_centipedebody_sprite_right4=esat::SpriteFromFile("./resources/img/centipedebody_right4.png");
    g_centipedebody_sprite_right5=esat::SpriteFromFile("./resources/img/centipedebody_right5.png");

    g_centipedebody_sprite_up=esat::SpriteFromFile("./resources/img/centipedebody_up.png");
    g_centipedebody_sprite_up2=esat::SpriteFromFile("./resources/img/centipedebody_up2.png");
    g_centipedebody_sprite_down=esat::SpriteFromFile("./resources/img/centipedebody_down.png");

    //sprites scorpion
    g_scorpion_sprite1=esat::SpriteFromFile("./resources/img/scorpion1.png");
    g_scorpion_sprite2=esat::SpriteFromFile("./resources/img/scorpion2.png");
    g_scorpion_sprite3=esat::SpriteFromFile("./resources/img/scorpion3.png");
    g_scorpion_sprite4=esat::SpriteFromFile("./resources/img/scorpion4.png");

    //sprites explosion
    g_explosion_sprite_1=esat::SpriteFromFile("./resources/img/explosion1.png");
    g_explosion_sprite_2=esat::SpriteFromFile("./resources/img/explosion2.png");
    g_explosion_sprite_3=esat::SpriteFromFile("./resources/img/explosion3.png");
    g_explosion_sprite_4=esat::SpriteFromFile("./resources/img/explosion4.png");
    g_explosion_sprite_5=esat::SpriteFromFile("./resources/img/explosion5.png");
    g_explosion_sprite_6=esat::SpriteFromFile("./resources/img/explosion6.png");

    //sprites spider
    g_spider_sprite1=esat::SpriteFromFile("./resources/img/spider1.png");
    g_spider_sprite2=esat::SpriteFromFile("./resources/img/spider2.png");
    g_spider_sprite3=esat::SpriteFromFile("./resources/img/spider3.png");
    g_spider_sprite4=esat::SpriteFromFile("./resources/img/spider4.png");
    g_spider_sprite5=esat::SpriteFromFile("./resources/img/spider5.png");

    //sprites flea
    g_flea_sprite1=esat::SpriteFromFile("./resources/img/flea1.png");
    g_flea_sprite2=esat::SpriteFromFile("./resources/img/flea2.png");
    g_flea_sprite3=esat::SpriteFromFile("./resources/img/flea3.png");
    g_flea_sprite4=esat::SpriteFromFile("./resources/img/flea4.png");
    
    g_loading_screen_1=esat::SpriteFromFile("./resources/img/centipedeart.png");
}

void ReleaseSprites(){

    esat::SpriteRelease(g_player_sprite);
    esat::SpriteRelease(g_player_sprite2);
     esat::SpriteRelease(g_player_sprite3);
    esat::SpriteRelease(g_player_sprite_death1);
    esat::SpriteRelease(g_player_sprite_death2);
    esat::SpriteRelease(g_player_sprite_death3);
    esat::SpriteRelease(g_player_sprite_death4);
    esat::SpriteRelease(g_player_sprite_death5);
    esat::SpriteRelease(g_player_sprite_death6);
    esat::SpriteRelease(g_player_sprite_death7);
    esat::SpriteRelease(g_player_sprite_death8);

    esat::SpriteRelease(g_bullet_sprite);

    esat::SpriteRelease(g_mushroom_sprite_complete);
    esat::SpriteRelease(g_mushroom_sprite_broken1);
    esat::SpriteRelease(g_mushroom_sprite_broken2);
    esat::SpriteRelease(g_mushroom_sprite_broken3);

    esat::SpriteRelease(g_poisonmushroom_sprite_complete);
    esat::SpriteRelease(g_poisonmushroom_sprite_broken1);
    esat::SpriteRelease(g_poisonmushroom_sprite_broken2);
    esat::SpriteRelease(g_poisonmushroom_sprite_broken3);

    esat::SpriteRelease(g_blacksprite);

    esat::SpriteRelease(g_centipedehead_sprite_left);
    esat::SpriteRelease(g_centipedehead_sprite_left2);
    esat::SpriteRelease(g_centipedehead_sprite_left3);
    esat::SpriteRelease(g_centipedehead_sprite_left4);
    esat::SpriteRelease(g_centipedehead_sprite_left5);

    esat::SpriteRelease(g_centipedehead_sprite_right);
    esat::SpriteRelease(g_centipedehead_sprite_right2);
    esat::SpriteRelease(g_centipedehead_sprite_right3);
    esat::SpriteRelease(g_centipedehead_sprite_right4);
    esat::SpriteRelease(g_centipedehead_sprite_right5);

    esat::SpriteRelease(g_centipedehead_sprite_up);
    esat::SpriteRelease(g_centipedehead_sprite_up2);
    esat::SpriteRelease(g_centipedehead_sprite_down);
    
    esat::SpriteRelease(g_centipedebody_sprite_left);
    esat::SpriteRelease(g_centipedebody_sprite_left2);
    esat::SpriteRelease(g_centipedebody_sprite_left3);
    esat::SpriteRelease(g_centipedebody_sprite_left4);
    esat::SpriteRelease(g_centipedebody_sprite_left5);

    esat::SpriteRelease(g_centipedebody_sprite_right);
    esat::SpriteRelease(g_centipedebody_sprite_right2);
    esat::SpriteRelease(g_centipedebody_sprite_right3);
    esat::SpriteRelease(g_centipedebody_sprite_right4);
    esat::SpriteRelease(g_centipedebody_sprite_right5);

    esat::SpriteRelease(g_centipedebody_sprite_up);
    esat::SpriteRelease(g_centipedebody_sprite_up2);
    esat::SpriteRelease(g_centipedebody_sprite_down);

    esat::SpriteRelease(g_scorpion_sprite1);
    esat::SpriteRelease(g_scorpion_sprite2);
    esat::SpriteRelease(g_scorpion_sprite3);
    esat::SpriteRelease(g_scorpion_sprite4);

    esat::SpriteRelease(g_explosion_sprite_1);
    esat::SpriteRelease(g_explosion_sprite_2);
    esat::SpriteRelease(g_explosion_sprite_3);
    esat::SpriteRelease(g_explosion_sprite_4);
    esat::SpriteRelease(g_explosion_sprite_5);
    esat::SpriteRelease(g_explosion_sprite_6);

    esat::SpriteRelease(g_spider_sprite1);
    esat::SpriteRelease(g_spider_sprite2);
    esat::SpriteRelease(g_spider_sprite3);
    esat::SpriteRelease(g_spider_sprite4);
    esat::SpriteRelease(g_spider_sprite5);

    esat::SpriteRelease(g_flea_sprite1);
    esat::SpriteRelease(g_flea_sprite2);
    esat::SpriteRelease(g_flea_sprite3);
    esat::SpriteRelease(g_flea_sprite4);

    esat::SpriteRelease(g_loading_screen_1);
}

