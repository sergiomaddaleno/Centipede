
struct TCoords{
    int x,y;
};

struct TBullet{
  TCoords position, size;
  bool active;
  int speed;
  esat::SpriteHandle sprite;
};

struct TPlayer{
  TCoords position,size;
  TBullet bullet;
  bool alive;
  esat::SpriteHandle sprite;
};

struct TMushroom{
  TCoords position,size;
  int type;
  int score;
  int counter;
  bool alive;
  esat::SpriteHandle sprite;
};

struct TCentipede{
  TCoords position,size;
  int direction;
  int speed;
  int type;
  int score;
  int counter;
  bool alive;
  TBullet bullet;
  int limite;
  esat::SpriteHandle sprite;
};

struct TScorpion{
  TCoords position,size;
  int direction;
  int speed;
  int type;
  int score;
  int counter;
  bool alive;
  int limite;
  esat::SpriteHandle sprite;
};

struct TSpider{
  TCoords position,size;
  int direction;
  int speed;
  int type;
  int score;
  int counter;
  bool alive;
  int limite;
  esat::SpriteHandle sprite;
};

struct TFlea{
  TCoords position,size;
  int direction;
  int speed;
  int type;
  int score;
  int counter;
  bool alive;
  int limite;
  esat::SpriteHandle sprite;
};


const int kWindowWidth=224*4, kWindowHeight=256*4-32;
int lastMushroom = 50;
int score1=0;
int animation;
int lifeNum=3;
unsigned char fps=60;
double current_time,last_time;
int Loading;
bool gamestart=false;
bool gameselection=false;


esat::SpriteHandle g_player_sprite, g_player_sprite2, g_player_sprite3, g_bullet_sprite, g_blacksprite, 

                  g_mushroom_sprite_complete, g_mushroom_sprite_broken1, 
                  g_mushroom_sprite_broken2, g_mushroom_sprite_broken3,

                  g_poisonmushroom_sprite_complete, g_poisonmushroom_sprite_broken1, 
                  g_poisonmushroom_sprite_broken2, g_poisonmushroom_sprite_broken3,

                  g_centipedehead_sprite_up, g_centipedebody_sprite_up, g_centipedehead_sprite_down, g_centipedebody_sprite_down, g_centipedehead_sprite_up2, g_centipedebody_sprite_up2,
                  
                  g_centipedehead_sprite_left, g_centipedehead_sprite_left2, g_centipedehead_sprite_left3, g_centipedehead_sprite_left4, g_centipedehead_sprite_left5,

                  g_centipedehead_sprite_right, g_centipedehead_sprite_right2, g_centipedehead_sprite_right3, g_centipedehead_sprite_right4, g_centipedehead_sprite_right5, 
                  
                  g_centipedebody_sprite_left, g_centipedebody_sprite_left2, g_centipedebody_sprite_left3, g_centipedebody_sprite_left4, g_centipedebody_sprite_left5, 
                  
                  g_centipedebody_sprite_right, g_centipedebody_sprite_right2, g_centipedebody_sprite_right3, g_centipedebody_sprite_right4, g_centipedebody_sprite_right5,

                  g_scorpion_sprite1,  g_scorpion_sprite2,  g_scorpion_sprite3,  g_scorpion_sprite4,

                  g_flea_sprite1, g_flea_sprite2, g_flea_sprite3, g_flea_sprite4, 

                  g_player_sprite_death1, g_player_sprite_death2, g_player_sprite_death3, g_player_sprite_death4, 
                  g_player_sprite_death5, g_player_sprite_death6, g_player_sprite_death7, g_player_sprite_death8,

                  g_spider_sprite1, g_spider_sprite2, g_spider_sprite3, g_spider_sprite4, g_spider_sprite5, g_loading_screen_1,

                  g_explosion_sprite_1, g_explosion_sprite_2, g_explosion_sprite_3, g_explosion_sprite_4, g_explosion_sprite_5, g_explosion_sprite_6; 

TPlayer g_player;
TMushroom g_mushrooms[62];
TBullet g_bullet;
TCentipede g_centipede[12];
TScorpion g_scorpion;
TSpider g_spider;
TFlea g_flea;






