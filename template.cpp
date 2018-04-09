#include "template.h"
#include "font.h"
#include "dialog.h"
#include "user.h"
#include "world.h"
#include "Rooms.h"
#include "string"
#include <fstream>

using namespace std;
int choc;

app App;

int fontid;
int englishfont;

string contain;
vector <int> floweyvoice;
vector <int> narratorvoice;
vector <int> papyrusvoice;
vector <int> sansvoice;
vector <int> whitecolor;
vector <int> characolor;
vector <int> asrielcolor;
vector <int> stopcolor;


vector <int> rednicecolor;
vector <int> bluenicecolor;
vector <int> greennicecolor;
vector <vector <int> >possiblecolors;
vector <int> englishvoice;

bool first_screen = false;
int iteration = 0;
int background = -1;
//int frisk;
//int ghost;
int wall;
int wall2;
int wall3;
int hoodini1;
int hoodini2;
int hoodini3;
int hoodini4;
int hoodini5;
int hoodini6;
int hoodini7;
//int room;
int room2;
//int bridge;
//int bridge011;
//int bridge012;
int bridge013;
//int bridge021;
//int bridge022;
int bridge023;
//int water;
//int wave1;
//int wave2;
//int wave3;
//int wave4;
//int wave5;
//int wave6;
//int wave7;
//int wave8;
//int mountain;
//int circle;
//double mountain_angle;
//double circle_radius;
//double speed;
int music;
//vector<int> sprites_frisk;
//vector<int> sprite_actives_frisk;
//vector<int> sprites_ghost;
//vector<int> sprite_actives_ghost;
//vector<int> images_frisk;
vector<int> sprites_wall;
vector<int> sprite_actives_wall;
vector<int> sprites_wall2;
vector<int> sprite_actives_wall2;
vector<int> sprites_wall3;
vector<int> sprite_actives_wall3;
vector<int> images_wall;
vector<int> sprites_hoodini1;
vector<int> sprite_actives_hoodini1;
vector<int> images_hoodini1;
vector<int> sprites_hoodini2;
vector<int> sprite_actives_hoodini2;
vector<int> images_hoodini2;
vector<int> sprites_hoodini3;
vector<int> sprite_actives_hoodini3;
vector<int> images_hoodini3;
vector<int> sprites_hoodini4;
vector<int> sprite_actives_hoodini4;
vector<int> images_hoodini4;
vector<int> sprites_hoodini5;
vector<int> sprite_actives_hoodini5;
vector<int> images_hoodini5;
vector<int> sprites_hoodini6;
vector<int> sprite_actives_hoodini6;
vector<int> images_hoodini6;
vector<int> sprites_hoodini7;
vector<int> sprite_actives_hoodini7;
vector<int> images_hoodini7;

//vector<int> sprites_room;
//vector<int> sprite_actives_room;
//vector<int> images_room;

vector<int> sprites_room2;
vector<int> sprite_actives_room2;
vector<int> images_room2;

//vector<int> sprites_bridge;
//vector<int> sprite_actives_bridge;
//vector<int> images_bridge;
//int bridge_snd;

//vector<int> sprites_bridge011;
//vector<int> sprite_actives_bridge011;
//vector<int> images_bridge011;

//vector<int> sprites_bridge012;
//vector<int> sprite_actives_bridge012;
//vector<int> images_bridge012;

vector<int> sprites_bridge013;
vector<int> sprite_actives_bridge013;
vector<int> images_bridge013;

//vector<int> sprites_bridge021;
//vector<int> sprite_actives_bridge021;
//vector<int> images_bridge021;

//vector<int> sprites_bridge022;
//vector<int> sprite_actives_bridge022;
//vector<int> images_bridge022;

vector<int> sprites_bridge023;
vector<int> sprite_actives_bridge023;
vector<int> images_bridge023;

//vector<int> sprites_water;
//vector<int> sprite_actives_water;
//vector<int> images_water;
//int water_snd;

//vector<int> sprites_wave1;
//vector<int> sprite_actives_wave1;

//vector<int> sprites_wave2;
//vector<int> sprite_actives_wave2;

//vector<int> sprites_wave3;
//vector<int> sprite_actives_wave3;

//vector<int> sprites_wave4;
//vector<int> sprite_actives_wave4;

//vector<int> sprites_wave5;
//vector<int> sprite_actives_wave5;

//vector<int> sprites_wave6;
//vector<int> sprite_actives_wave6;

//vector<int> sprites_wave7;
//vector<int> sprite_actives_wave7;

//vector<int> sprites_wave8;
//vector<int> sprite_actives_wave8;

//vector<int> sprites_mountain;
//vector<int> sprite_actives_mountain;
//vector<int> images_mountain;

//vector<int> sprites_circle;
//vector<int> sprite_actives_circle;
//vector<int> images_circle;

//vector<int> images_wave;

vector<int> sounds;
int voice;
int showT;
int resX = 1366;
int resY = 768;

void mapshape(int sprite, vector <vector <bool> > map) {

	agk::SetSpritePhysicsOn(sprite);
	agk::SetSpriteShape(sprite, 0);

	agk::SetSpriteOffset(sprite, 0, 0);

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x]) agk::AddSpriteShapeBox(sprite, x, y, x + 1, y + 1, 0);
		}
	}

	agk::SetSpritePhysicsOff(sprite);

}

int u;

void app::Begin(void)
{
	agk::SetWindowTitle("O_O");
	srand(time(NULL));
	
	agk::SetVirtualResolution(1920, 1080);
	agk::SetWindowSize(1280, 720, 0);
	//agk::SetGenerateMipmaps(1);
	agk::SetClearColor(0, 0, 0);
	agk::SetSyncRate(60, 0);
	//agk::SetVSync(0);
	//agk::SetSyncRate(0, 1);
	agk::SetScissor(0, 0, 0, 0);
	
	//agk::SetViewZoom(1.2);

	//ifstream myfileangle;
	//myfileangle.open("angle.txt");
	//myfileangle >> mountain_angle;
	//myfileangle.close();

	//ifstream myfileradius;
	//myfileradius.open("radius.txt");
	//myfileradius >> circle_radius;
	//myfileradius.close();

	//ifstream myfilespeed;
	//myfilespeed.open("speed.txt");
	//myfilespeed >> speed;
	//myfilespeed.close();

	//mountain_angle
	agk::SetPhysicsDebugOn();

	//music = agk::LoadMusic("resources/Cave/Beginning of a New Journey (genocide version).mp3");
	//agk::PlayMusic(music, 1);

	//text stuff
	
	narraInitiate();
	colorsInitiate();
	
	//text stuff finished

	//int wallsound1 = agk::LoadSound("resources/wallsnd.wav");
	//sounds.push_back(wallsound1);
	//int wallsound2 = agk::LoadSound("resources/wallsnd.wav");
	//sounds.push_back(wallsound2);
	//int wallsound3 = agk::LoadSound("resources/wallsnd.wav");
	//sounds.push_back(wallsound3);
	//int clod = agk::LoadSound("resources/clod1.wav");
	//water_snd = agk::LoadSound("resources/SE/amio_sma-Aftermat-7396_hifi.wav");
	//bridge_snd = agk::LoadSound("resources/SE/Wood Hull On Boat Creaking-SoundBible.com-867026276.wav");
	//agk::PlayMusic(sound, true);
	
	//voice = createtext(10, 10, "Test", englishfont, characolor, narratorvoice, 1, 1, 1, false);
	//showT = showtext(voice, 0);

	//Создание первого спрайта (Фриск идет вниз)
	/*
	sprites_frisk.push_back(agk::CreateSprite(0));
	sprite_actives_frisk.push_back(0);
	sprites_ghost.push_back(agk::CreateSprite(0));
	sprite_actives_ghost.push_back(0);

	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_0.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_1.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_2.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_3.png"));

	for (int i = 0; i < 4; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk[0], images_frisk[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost[0], images_frisk[i]);
	}
		
	//Создание второго спрайта (Фриск идет влево)
	/*sprites_frisk.push_back(agk::CreateSprite(0));
	sprite_actives_frisk.push_back(0);
	sprites_ghost.push_back(agk::CreateSprite(0));
	sprite_actives_ghost.push_back(0);

	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharal_0.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharal_1.png"));

	for (int i = 4; i < 6; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk[1], images_frisk[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost[1], images_frisk[i]);
	}
		

	//Создание третьего спрайта (Фриск идет вправо)
	sprites_frisk.push_back(agk::CreateSprite(0));
	sprite_actives_frisk.push_back(0);
	sprites_ghost.push_back(agk::CreateSprite(0));
	sprite_actives_ghost.push_back(0);

	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharar_0.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharar_1.png"));

	for (int i = 6; i < 8; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk[2], images_frisk[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost[2], images_frisk[i]);
	}
		
	

	//Создание четвертого спрайта (Фриск идет вверх)
	sprites_frisk.push_back(agk::CreateSprite(0));
	sprite_actives_frisk.push_back(0);
	sprites_ghost.push_back(agk::CreateSprite(0));
	sprite_actives_ghost.push_back(0);

	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_0.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_1.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_2.png"));
	images_frisk.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_3.png"));

	for (int i = 8; i < 12; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk[3], images_frisk[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost[3], images_frisk[i]);
	}*/

	//Создаем спрайт стены
	/*images_wall.push_back(agk::LoadImage("resources/wall.png"));
	sprites_wall.push_back(agk::CreateSprite(images_wall[images_wall.size() - 1]));
	sprites_wall2.push_back(agk::CreateSprite(images_wall[images_wall.size() - 1]));
	sprites_wall3.push_back(agk::CreateSprite(images_wall[images_wall.size() - 1]));
	sprite_actives_wall.push_back(0);
	sprite_actives_wall2.push_back(0);
	sprite_actives_wall3.push_back(0);

	//Создаем спрайт Худини
	sprites_hoodini1.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini1.push_back(1);
	sprites_hoodini2.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini2.push_back(0);
	sprites_hoodini3.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini3.push_back(1);
	sprites_hoodini4.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini4.push_back(0);
	sprites_hoodini5.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini5.push_back(1);
	sprites_hoodini6.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini6.push_back(0);
	sprites_hoodini7.push_back(agk::CreateSprite(0));
	sprite_actives_hoodini7.push_back(0);
	
	for (int i = 1; i <= 35; i++)
	{
			string filepath = "resources/Sprites/" + to_string(i) + ".png";
			const char *cstr = filepath.c_str();
			images_hoodini1.push_back(agk::LoadImage(cstr));
			images_hoodini2.push_back(agk::LoadImage(cstr));
			images_hoodini3.push_back(agk::LoadImage(cstr));
			images_hoodini4.push_back(agk::LoadImage(cstr));
			images_hoodini5.push_back(agk::LoadImage(cstr));
			images_hoodini6.push_back(agk::LoadImage(cstr));
			images_hoodini7.push_back(agk::LoadImage(cstr));
	}
	for (int i = 0; i < 35; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_hoodini1[0], images_hoodini1[i]);
		agk::AddSpriteAnimationFrame(sprites_hoodini2[0], images_hoodini2[i]);
		agk::AddSpriteAnimationFrame(sprites_hoodini3[0], images_hoodini3[i]);
		agk::AddSpriteAnimationFrame(sprites_hoodini4[0], images_hoodini4[i]);
		agk::AddSpriteAnimationFrame(sprites_hoodini5[0], images_hoodini5[i]);
		agk::AddSpriteAnimationFrame(sprites_hoodini6[0], images_hoodini6[i]);
		agk::AddSpriteAnimationFrame(sprites_hoodini7[0], images_hoodini7[i]);
	}*/

	//images_room.push_back(agk::LoadImage("resources/Cave/r0.png"));
	//sprites_room.push_back(agk::CreateSprite(images_room[images_room.size() - 1]));
	//sprite_actives_room.push_back(0);

	//images_room2.push_back(agk::LoadImage("resources/Cave/1.png"));
	//sprites_room2.push_back(agk::CreateSprite(images_room2[images_room2.size() - 1]));
	//sprite_actives_room2.push_back(0);
	
	//images_bridge.push_back(agk::LoadImage("resources/Cave/Bridge1.png"));
	//sprites_bridge.push_back(agk::CreateSprite(images_bridge[images_bridge.size() - 1]));
	//sprite_actives_bridge.push_back(0);

	//images_bridge011.push_back(agk::LoadImage("resources/Cave/Bridge0_1_1.png"));
	//sprites_bridge011.push_back(agk::CreateSprite(images_bridge011[images_bridge011.size() - 1]));
	//sprite_actives_bridge011.push_back(0);

	//images_bridge012.push_back(agk::LoadImage("resources/Cave/Bridge0_1_2.png"));
	//sprites_bridge012.push_back(agk::CreateSprite(images_bridge012[images_bridge012.size() - 1]));
	//sprite_actives_bridge012.push_back(0);

	//images_bridge013.push_back(agk::LoadImage("resources/Cave/Bridge0_1_3.png"));
	//sprites_bridge013.push_back(agk::CreateSprite(images_bridge013[images_bridge013.size() - 1]));
	//sprite_actives_bridge013.push_back(0);

	//images_bridge021.push_back(agk::LoadImage("resources/Cave/Bridge0_2_1.png"));
	//sprites_bridge021.push_back(agk::CreateSprite(images_bridge021[images_bridge021.size() - 1]));
	//sprite_actives_bridge021.push_back(0);

	//images_bridge022.push_back(agk::LoadImage("resources/Cave/Bridge0_2_2.png"));
	//sprites_bridge022.push_back(agk::CreateSprite(images_bridge022[images_bridge022.size() - 1]));
	//sprite_actives_bridge022.push_back(0);

	//images_bridge023.push_back(agk::LoadImage("resources/Cave/Bridge0_2_3.png"));
	//sprites_bridge023.push_back(agk::CreateSprite(images_bridge023[images_bridge023.size() - 1]));
	//sprite_actives_bridge023.push_back(0);
	
	//images_water.push_back(agk::LoadImage("resources/Cave/Water1.png"));
	//images_water.push_back(agk::LoadImage("resources/Cave/Water2.png"));
	//images_water.push_back(agk::LoadImage("resources/Cave/Water3.png"));
	//agk::SetImageMagFilter(sprites_bridge[0], 0);
	//agk::SetImageMinFilter(sprites_bridge[0], 0);
	//agk::SetImageMagFilter(sprites_bridge[0], 0);
	//agk::SetImageMinFilter(sprites_bridge[0], 0);
	//agk::SetImageMagFilter(sprites_bridge[0], 0);
	//agk::SetImageMinFilter(sprites_bridge[0], 0);
	//sprites_water.push_back(agk::CreateSprite(0));
	//agk::AddSpriteAnimationFrame(sprites_water[0], images_water[0]);
	//agk::AddSpriteAnimationFrame(sprites_water[0], images_water[1]);
	//agk::AddSpriteAnimationFrame(sprites_water[0], images_water[2]);
	//sprite_actives_water.push_back(1);

	//images_mountain.push_back(agk::LoadImage("resources/Sprites/b72.png"));
	//sprites_mountain.push_back(agk::CreateSprite(images_mountain[images_mountain.size() - 1]));
	//sprite_actives_mountain.push_back(0);

	//images_circle.push_back(agk::LoadImage("resources/a circle (transparent).png"));
	//sprites_circle.push_back(agk::CreateSprite(images_circle[images_circle.size() - 1]));
	//sprite_actives_circle.push_back(0);

	/*images_wave.push_back(agk::LoadImage("resources/Cave/Wave0.png"));
	images_wave.push_back(agk::LoadImage("resources/Cave/Wave1.png"));
	images_wave.push_back(agk::LoadImage("resources/Cave/Wave2.png"));
	images_wave.push_back(agk::LoadImage("resources/Cave/Wave3.png"));
	images_wave.push_back(agk::LoadImage("resources/Cave/Wave4.png"));

	sprites_wave1.push_back(agk::CreateSprite(0));
	sprites_wave2.push_back(agk::CreateSprite(0));
	sprites_wave3.push_back(agk::CreateSprite(0));
	sprites_wave4.push_back(agk::CreateSprite(0));
	sprites_wave5.push_back(agk::CreateSprite(0));
	sprites_wave6.push_back(agk::CreateSprite(0));
	sprites_wave7.push_back(agk::CreateSprite(0));
	sprites_wave8.push_back(agk::CreateSprite(0));

	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[1]);
	
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave2[0], images_wave[1]);

	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave3[0], images_wave[1]);

	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave4[0], images_wave[1]);

	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave5[0], images_wave[1]);

	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave6[0], images_wave[1]);

	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave7[0], images_wave[1]);

	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[0]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[1]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[4]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[3]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[2]);
	agk::AddSpriteAnimationFrame(sprites_wave8[0], images_wave[1]);

	sprite_actives_wave1.push_back(1);
	sprite_actives_wave2.push_back(1);
	sprite_actives_wave3.push_back(1);
	sprite_actives_wave4.push_back(1);
	sprite_actives_wave5.push_back(1);
	sprite_actives_wave6.push_back(1);
	sprite_actives_wave7.push_back(1);
	sprite_actives_wave8.push_back(1);*/

	//Создаем объекты
	/*
	circle = creategameWorldObject(
		6000, //x
		5900, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		2, //bonetype
		6, //fps
		0, //angle
		1, //speed
		circle_radius, //radius
		1, //scalex
		1, //scaley
		sprites_circle, //sprites
		sprite_actives_circle, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true //underplayer
	);
	room = creategameWorldObject(
		5000, //x
		5000, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		0, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_room, //sprites
		sprite_actives_room, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true //underplayer
	);/*
	room2 = creategameWorldObject(
		5000, //x
		5650, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		0, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_room2, //sprites
		sprite_actives_room2, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true //underplayer
	);
	mountain = creategameWorldObject(
		5550, //x
		5785, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		1, //bonetype
		6, //fps
		mountain_angle, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_mountain, //sprites
		sprite_actives_mountain, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		false //underplayer
	);
	bridge = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		bridge_snd, //sound
		3, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge, //sprites
		sprite_actives_bridge, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true //underplayer
	);
	bridge011 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge011, //sprites
		sprite_actives_bridge011, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		false //underplayer
	);
	bridge012 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge012, //sprites
		sprite_actives_bridge012, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true //underplayer
	);
	bridge013 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge013, //sprites
		sprite_actives_bridge013, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		false //underplayer
	);
	bridge021 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge021, //sprites
		sprite_actives_bridge021, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		false //underplayer
	);
	bridge022 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge022, //sprites
		sprite_actives_bridge022, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true //underplayer
	);
	bridge023 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		4, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_bridge023, //sprites
		sprite_actives_bridge023, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		false //underplayer
	);
	water = creategameWorldObject(
		4998, //x
		5600, //y
		0, //direction
		water_snd, //sound
		0, //soundtype
		1, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		1, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_water, //sprites
		sprite_actives_water, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		true, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave1 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave1, //sprites
		sprite_actives_wave1, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave2 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave2, //sprites
		sprite_actives_wave2, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave3 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave3, //sprites
		sprite_actives_wave3, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave4 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave4, //sprites
		sprite_actives_wave4, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave5 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave5, //sprites
		sprite_actives_wave5, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave6 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave6, //sprites
		sprite_actives_wave6, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave7 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave7, //sprites
		sprite_actives_wave7, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	wave8 = creategameWorldObject(
		randomBetweenTwoNumbers(5025, 6000), //x
		randomBetweenTwoNumbers(5650, 5810), //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		bridge, //underobject
		0, //bonetype
		3, //fps
		0, //angle
		1, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_wave8, //sprites
		sprite_actives_wave8, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);
	hoodini7 = creategameWorldObject(
		6350, //x
		5700, //y
		0, //direction
		clod, //sound
		3, //soundtype
		0, //soundactive
		3, //animationtype
		-1, //underobject
		0, //bonetype
		10, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_hoodini7, //sprites
		sprite_actives_hoodini7, //sprite_actives
		"hoodini", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true //underplayer
	);*/
	
	//frisk = creategameWorldObject(6300, 6050, 0, 0, 0, 0, 0, -1, 0, 8, 0, speed, 0, 2, 2, sprites_frisk, sprite_actives_frisk, "", {}, false, true, true, false, true, false);
	//ghost = creategameWorldObject(6300, 6050, 0, 0, 0, 0, 0, -1, 0, 8, 0, speed, 0, 2, 2, sprites_ghost, sprite_actives_ghost, "", {}, false, true, true, false, true, false);
	//wall = creategameWorldObject(600, 100, 0, wallsound1, 2, 0, 0, 0, 0, 1, 1, sprites_wall, sprite_actives_wall, "wall1", {}, false, true, false, true, false, false);
	//wall2 = creategameWorldObject(500, 400, 0, wallsound2, 3, 0, 0, 0, 0, 1, 1, sprites_wall2, sprite_actives_wall2, "wall2", {}, false, false, false, true, false, false);
	//wall3 = creategameWorldObject(-1000, 00, 0, wallsound3, 1, 1, 0, 0, 0, 1, 1, sprites_wall3, sprite_actives_wall3, "qwerty", { {"* Smells <timewait='20'><textcolor='red'>wally."},{"<textcolor='red'>* No chocolate."}, { "* You look so happy... like a wall was everything you ever wished." },{ "* Hey, I'm not judging. Walls are not that bad at all!" } }, true, true, false, true, false, false);
	//hoodini1 = creategameWorldObject(800, 800, 0, 0, 0, 0, 0, 10, 0, 1, 1, sprites_hoodini1, sprite_actives_hoodini1, "hoodini", { { "* It's Hoodini, the angel of death.", "* Kinda pretty, is he not?" },{ "* Feel free to stay here as long as you wish." }, { "* Okay, I'll help you with formating. Let it be a line break.<linebreak>* Hope it's working well! I really hope <timewait='5 sec'>so!<linebreak>* It's time for some <textcolor='yellow'>bloomy blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah blah</textcolor> text!" } }, true, true, false, false, true, false);
	//hoodini2 = creategameWorldObject(800, 1000, 0, 0, 0, 0, 0, 10, 0, 1, 1, sprites_hoodini2, sprite_actives_hoodini2, "hoodini", {}, false, true, false, false, true, false);
	//hoodini3 = creategameWorldObject(1000, 800, 0, 0, 0, 0, 1, 10, 0, 1, 1, sprites_hoodini3, sprite_actives_hoodini3, "hoodini", {}, false, true, false, false, true, false);
	//hoodini4 = creategameWorldObject(1000, 1000, 0, 0, 0, 0, 1, 10, 0, 1, 1, sprites_hoodini4, sprite_actives_hoodini4, "hoodini", {}, false, true, false, false, true, false);
	//hoodini5 = creategameWorldObject(1200, 800, 0, 0, 0, 0, 2, 10, 0, 1, 1, sprites_hoodini5, sprite_actives_hoodini5, "hoodini", {}, false, true, false, false, true, false);
	//hoodini6 = creategameWorldObject(1200, 1000, 0, 0, 0, 0, 2, 10, 0, 1, 1, sprites_hoodini6, sprite_actives_hoodini6, "hoodini", {}, false, true, false, false, true, false);
	
	/*for (int i = 0; i < 4; i++)
	{
		agk::SetSpriteVisible(sprites_ghost[i], false);
		agk::SetSpritePhysicsOn(sprites_ghost[i]);
		agk::SetSpriteShape(sprites_ghost[i], 0);
		agk::ClearSpriteShapes(sprites_ghost[i]);
		
		agk::AddSpriteShapeBox(sprites_ghost[i], -20, 15, 18, 30, 0);
		
		agk::SetSpritePhysicsIsSensor(sprites_ghost[i], 1);
	}*/
	/*
	agk::SetSpritePhysicsOn(sprites_wall[0]);
	agk::SetSpriteShape(sprites_wall[0], 0);
	agk::ClearSpriteShapes(sprites_wall[0]);
	agk::AddSpriteShapeBox(sprites_wall[0], -252.5, 15, 252.5, 158.5, 0);
	agk::SetSpritePhysicsIsSensor(sprites_wall[0], 1);

	agk::SetSpritePhysicsOn(sprites_wall2[0]);
	agk::SetSpriteShape(sprites_wall2[0], 0);
	agk::ClearSpriteShapes(sprites_wall2[0]);
	agk::AddSpriteShapeBox(sprites_wall2[0], -252.5, 15, 252.5, 158.5, 0);
	agk::SetSpritePhysicsIsSensor(sprites_wall2[0], 1);

	
	agk::SetSpritePhysicsOn(sprites_wall3[0]);
	agk::SetSpriteShape(sprites_wall3[0], 0);
	agk::ClearSpriteShapes(sprites_wall3[0]);
	agk::AddSpriteShapeBox(sprites_wall3[0], -252.5, 15, 252.5, 158.5, 0);
	agk::SetSpritePhysicsIsSensor(sprites_wall3[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini1[0]);
	agk::SetSpriteShape(sprites_hoodini1[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini1[0]);
	agk::AddSpriteShapeBox(sprites_hoodini1[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini1[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini2[0]);
	agk::SetSpriteShape(sprites_hoodini2[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini2[0]);
	agk::AddSpriteShapeBox(sprites_hoodini2[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini2[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini3[0]);
	agk::SetSpriteShape(sprites_hoodini3[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini3[0]);
	agk::AddSpriteShapeBox(sprites_hoodini3[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini3[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini4[0]);
	agk::SetSpriteShape(sprites_hoodini4[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini4[0]);
	agk::AddSpriteShapeBox(sprites_hoodini4[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini4[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini5[0]);
	agk::SetSpriteShape(sprites_hoodini5[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini5[0]);
	agk::AddSpriteShapeBox(sprites_hoodini5[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini5[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini6[0]);
	agk::SetSpriteShape(sprites_hoodini6[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini6[0]);
	agk::AddSpriteShapeBox(sprites_hoodini6[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini6[0], 1);

	agk::SetSpritePhysicsOn(sprites_hoodini7[0]);
	agk::SetSpriteShape(sprites_hoodini7[0], 0);
	agk::ClearSpriteShapes(sprites_hoodini7[0]);
	agk::AddSpriteShapeBox(sprites_hoodini7[0], -30, 0, 30, 115, 0);
	agk::SetSpritePhysicsIsSensor(sprites_hoodini7[0], 1);*/
	
	/*agk::SetSpritePhysicsOn(sprites_room[0]);
	agk::SetSpriteShape(sprites_room[0], 0);
	agk::ClearSpriteShapes(sprites_room[0]);
	agk::AddSpriteShapeBox(sprites_room[0], -784, 254, 544, 253, 0); //вторая горизонтальная от низа, лево от моста
	agk::AddSpriteShapeBox(sprites_room[0], 729, 254, 800, 253, 0); //вторая горизонтальная от низа, право от моста
	agk::AddSpriteShapeBox(sprites_room[0], -779, -47, 544, -46, 0); //третья горизонтальная от низа, лево от моста
	agk::AddSpriteShapeBox(sprites_room[0], 729, -47, 801, -46, 0); //третья горизонтальная от низа, право от моста
	agk::AddSpriteShapeBox(sprites_room[0], 710, 234, 709, -27, 0); //правая вертикальная моста
	agk::AddSpriteShapeBox(sprites_room[0], 563, 234, 564, -27, 0); //левая вертикальная моста
	//agk::AddSpriteShapeCircle(sprites_room[0], 544, 234, 20); //левый нижний круг моста
	agk::AddSpriteShapeCircle(sprites_room[0], 729, 234, 20); //правый нижний круг моста
	//agk::AddSpriteShapeCircle(sprites_room[0], 544, -27, 20); //левый верхний круг моста
	//agk::AddSpriteShapeCircle(sprites_room[0], 729, -27, 20); //правый верхний круг моста
	agk::AddSpriteShapeBox(sprites_room[0], -769, 566, 801, 567, 0); //нижняя горизонтальная
	agk::AddSpriteShapeBox(sprites_room[0], -778, -370, -779, -46, 0); //левая вертикальная, верхняя часть
	agk::AddSpriteShapeBox(sprites_room[0], -783, 253, -784, 556, 0); //левая вертикальная, нижняя часть
	agk::AddSpriteShapeBox(sprites_room[0], -779, -369, 801, -370, 0); //четвертая горизонтальная от низа
	agk::AddSpriteShapeBox(sprites_room[0], 800, -370, 801, -46, 0); //правая вертикальная, верхняя часть
	agk::AddSpriteShapeBox(sprites_room[0], 800, 253, 801, 567, 0); //правая вертикальная, нижняя часть
	agk::SetSpritePhysicsIsSensor(sprites_room[0], 1);*/
	

	/*agk::SetSpritePhysicsOn(sprites_bridge[0]);
	agk::SetSpriteShape(sprites_bridge[0], 0);
	agk::ClearSpriteShapes(sprites_bridge[0]);
	agk::AddSpriteShapeBox(sprites_bridge[0], -77, -160, 77, 148, 0);
	agk::SetSpritePhysicsIsSensor(sprites_bridge[0], 1);*/

	/*
	agk::SetSpritePhysicsOn(sprites_bridge011[0]);
	agk::SetSpriteShape(sprites_bridge011[0], 0);
	agk::ClearSpriteShapes(sprites_bridge011[0]);
	agk::AddSpriteShapeBox(sprites_bridge011[0], -94, -29, -70, -49, 0);
	agk::AddSpriteShapeBox(sprites_bridge011[0], 70, -47, 94, -29, 0);
	agk::SetSpritePhysicsIsSensor(sprites_bridge011[0], 1);

	agk::SetSpritePhysicsOn(sprites_bridge021[0]);
	agk::SetSpriteShape(sprites_bridge021[0], 0);
	agk::ClearSpriteShapes(sprites_bridge021[0]);
	agk::AddSpriteShapeBox(sprites_bridge021[0], -100, 98, -76, 83, 0);
	agk::AddSpriteShapeBox(sprites_bridge021[0], 77, 98, 101, 83, 0);
	agk::SetSpritePhysicsIsSensor(sprites_bridge021[0], 1);*/
	
	/*agk::SetSpritePhysicsOn(sprites_mountain[0]);
	agk::SetSpriteShape(sprites_mountain[0], 0);
	agk::ClearSpriteShapes(sprites_mountain[0]);
	agk::AddSpriteShapeBox(sprites_mountain[0], -320, -15, 320, 15, 0);
	agk::SetSpritePhysicsIsSensor(sprites_mountain[0], 1);
	
	agk::SetSpritePhysicsOn(sprites_circle[0]);
	agk::SetSpriteShape(sprites_circle[0], 0);
	agk::ClearSpriteShapes(sprites_circle[0]);
	agk::AddSpriteShapeCircle(sprites_circle[0], 0, 0, circle_radius);*/
	

	//agk::SetPhysicsDebugOn();
	

	
	/*gameObjectUpdate(wall, -1);
	gameObjectUpdate(wall2, -1);
	gameObjectUpdate(wall3, -1);
	gameObjectUpdate(hoodini1, -1);
	gameObjectUpdate(hoodini2, -1);
	gameObjectUpdate(hoodini3, -1);
	gameObjectUpdate(hoodini4, -1);
	gameObjectUpdate(hoodini5, -1);
	gameObjectUpdate(hoodini6, -1);
	gameObjectUpdate(hoodini7, -1);
	*/
	//gameObjectUpdate(room, -1);
	//gameObjectUpdate(room2, -1);
	/*setObjectGroupLocationAndUpdate(
	{ 
		bridge, //список объектов
		bridge011, bridge012,//, bridge013, 
		bridge021, bridge022//, bridge023
	}, 
		6361, //x группы
		5520, //y группы
		{ //список относительных координат для каждого из объектов
			{0,0},
			{-36,-77},
			{-14,-1},
		//	{-40,-47},
			{-38,161},
			{-16,338},
		//	{-59,295}
		});
	gameObjectUpdate(mountain, -1);
	gameObjectUpdate(circle, -1);
	gameObjectUpdate(water, -1);
	gameObjectUpdate(wave1, -1);
	gameObjectUpdate(wave2, -1);
	gameObjectUpdate(wave3, -1);
	gameObjectUpdate(wave4, -1);
	gameObjectUpdate(wave5, -1);
	gameObjectUpdate(wave6, -1);
	gameObjectUpdate(wave7, -1);
	gameObjectUpdate(wave8, -1);*/
	//
	//agk::SetSpritePhysicsOff(wall);
	//gameObjectUpdate(frisk);
	//for (int i = 0; agk::GetImageExists(i); i++)
	//{
	//	agk::SetImageMagFilter(i, 0);
	//	agk::SetImageMinFilter(i, 0);

	//}
	
	fontid = createfont
	(

	{
		'д', 'к', 'а', '/', 'б',  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T', 'U','V', 'W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t', 'u','v', 'w','x','y','z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		'%', '#', '&', '$', '*', '@', '?', '+','>','}','{','<', '_','~','=' ,'-',']',')','[','(','!','^' ,';', ',', '.','|', '`' 
	
	},

	{
		{ "д" },{ "к" },{ "а" },{ "/" },{ "б" },{ "A" },{ "B" },{ "C" },{ "D" },{ "E" },{ "F" },{ "G" },{ "H" },{ "I" },{ "J" },{ "K" },{ "L" },{ "M" },{ "N" },{ "O" },{ "P" },{ "Q" },{ "R" },{ "S" },{ "T" },{ "U" },{ "V" },{ "W" },{ "X" },{ "Y" },{ "Z" },{ "a" },{ "b" },{ "c" },{ "d" },{ "e" },{ "f" },{ "g" },{ "h" },{ "i" },{ "j" },{ "k" },{ "l" },{ "m" },{ "n" },{ "o" },{ "p" },{ "q" },{ "r" },{ "s" },{ "t" },{ "u" },{ "v" },{ "w" },{ "x" },
		
		{ "y"},
		
		{ "z" },{ "1" },{ "2" },{ "3" },{ "4" },{ "5" },{ "6" },{ "7" },{ "8" },{ "9" },{ "0" },
		{ "%" },{ "#" },{ "&" },{ "$" },{ "*" },{ "@" },{ "?" },{ "+" },{ ">" },{ "}" },{ "{" },{ "<" },{ "_" },{ "~" },{ "=" } ,{ "-" },{ "]" },{ ")" },{ "[" },{ "(" },{ "!" },{ "^" } ,{ ";" },{ "," },{ "." },{ "|" },{ "`" }
	},
	
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	);

	
	






	vector <char> allowed = {
		'д', 'к', 'а', '/', 'б',  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T', 'U','V', 'W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t', 'u','v', 'w','x','y','z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		'%', '#', '&', '$', '*', '@', '?', '+','>','}','{','<', '_','~','=' ,'-',']',')','[','(','!','^' ,';', ',', '.','|', '`'

	};


	vector <string> special;

	for (int i = 1; i < 15; i++) {
		string download = "o";
		if (i > 9) download += '1';
		download += char(int('0') + i % 10);
		for (int z = 0; z < 3; z++) special.push_back(download);
	}


	vector <vector <string> > names = { { "д" },{ "к" },{ "а" },{ "/" },{ "б" },{ "A" },{ "B" },{ "C" },{ "D" },{ "E" },{ "F" },{ "G" },{ "H" },{ "I" },{ "J" },{ "K" },{ "L" },{ "M" },{ "N" },{ "O" },{ "P" },{ "Q" },{ "R" },{ "S" },{ "T" },{ "U" },{ "V" },{ "W" },{ "X" },{ "Y" },{ "Z" },{ "a" },{ "b" },{ "c" },{ "d" },{ "e" },{ "f" },{ "g" },{ "h" },{ "i" },{ "j" },{ "k" },{ "l" },{ "m" },{ "n" },
	special,
	
	{ "p" },{ "q" },{ "r" },{ "s" },{ "t" },{ "u" },{ "v" },{ "w" },{ "x" },{ "y" },{ "z" },{ "1" },{ "2" },{ "3" },{ "4" },{ "5" },{ "6" },{ "7" },{ "8" },{ "9" },{ "0" },{ "%" },{ "#" },{ "&" },{ "$" },{ "*" },{ "@" },{ "?" },{ "+" },{ ">" },{ "}" },{ "{" },{ "<" },{ "_" },{ "~" },{ "=" } ,{ "-" },{ "]" },{ ")" },{ "[" },{ "(" },{ "!" },{ "^" } ,{ ";" },{ "," },{ "." },{ "|" },{ "`" } };

	vector <bool> color(allowed.size(), 1);

	for (int i = 0; i < allowed.size(); i++) if (allowed[i] == 'o') color[i] = 0;

	englishfont = createfont
	(allowed, names, color);




	//д = :
	//к = "
	//а = '
	//б = \
	

	
	
	loadfont(fontid, "atlas");

	

	loadfont(englishfont, "englishatlas");

	 contain = "дка/б%#&$*@?+>}{<_~=-])[(!^;,.|`ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
	 floweyvoice = { loadsound("flowey1"), loadsound("flowey2") };
	narratorvoice = { loadsound("narrator") };
	papyrusvoice = { loadsound("papyrus") };
sansvoice = { loadsound("sans") };
englishvoice = { loadsound("honk") };
	whitecolor = { createcolor(255,255,255) };
	 characolor = { createcolor(255,0,0) };
	
	 
	for (float a = 0; a < 180; a+=0.1) {
		int r = sin(a) * 127 + 128;
		int g = sin(a+2) * 127 + 128;
		int b = sin(a+4) * 127 + 128;
		asrielcolor.push_back(createcolor(r, g, b));
	}

	 
	for (int a = 0; a < 50; a++) stopcolor.push_back(createcolor(255, 0, 0));
	for (int a = 0; a < 50; a++) stopcolor.push_back(createcolor(0, 0, 255));


	for (int i = 0; i < 100; i++) {
		greennicecolor.push_back(createcolor(0, 150 + i, 0));
	}
	for (int i = 0; i < 100; i++) {
		greennicecolor.push_back(createcolor(0, 250 - i, 0));
	}

	for (int i = 0; i < 100; i++) {
		rednicecolor.push_back(createcolor(150+i, 0, 0));
	}
	for (int i = 0; i < 100; i++) {
		rednicecolor.push_back(createcolor(250 - i, 0, 0));
	}

	for (int i = 0; i < 100; i++) {
		bluenicecolor.push_back(createcolor(0, 0, 150 + i));
	}
	for (int i = 0; i < 100; i++) {
		bluenicecolor.push_back(createcolor(0, 0, 250 - i));
	}

	possiblecolors.push_back(rednicecolor);
	possiblecolors.push_back(bluenicecolor);
	possiblecolors.push_back(greennicecolor);

	DebugRun();
	current_room = 0;
	RunRoom(0);

	choc= agk::CreateText("sweet chocolate");
}

//int timer = 0;
int holder;
int resolution = 0;
bool closed = false;
int app::Loop(void)
{
	
	agk::FixTextToScreen(choc, 1);
	agk::SetTextColor(choc, 255, 0, 0, 255);
	agk::SetTextPosition(choc, agk::GetVirtualWidth()*0.5, agk::GetVirtualHeight()*0.75);
	agk::SetTextSize(choc, 50);
	agk::SetTextDepth(choc, 0);
	


	if (pressed("lkm"))
	{
		CloseRoom(0); closed = true;
	}
	if (pressed("z"))
	{
		if (edges == "agk::Round is used")
			edges = "agk::Floor is used";
		else if (edges == "agk::Floor is used")
			edges = "agk::Nothing is used";
		else if (edges == "agk::Nothing is used")
			edges = "agk::Round is used";
	}
	if (pressed("x"))
	{
		if (resolution != 3)
			resolution++;
		else
			resolution = 0;
		switch (resolution)
		{
		case 0:
			agk::SetVirtualResolution(1280, 720); break;
		case 1:
			agk::SetVirtualResolution(1366, 768); break;
		case 2:
			agk::SetVirtualResolution(1600, 900); break;
		case 3:
			agk::SetVirtualResolution(1920, 1080); break;
		}
	}
	agk::Print((edges + " (Z to switch)").c_str());
	agk::Print((resolutions[resolution] + " (X to switch)").c_str());
	agk::Print(agk::GetViewOffsetX());
	agk::Print(agk::GetViewOffsetY());

	//agk::Print(state.c_str());
	//	getBias(frisk, getAngle(frisk, mountain), 0);
	//getBias(frisk, getAngle(frisk, mountain), 1);
	//agk::Print(firstkeypressed.c_str());
	//agk::Print(secondkeypressed.c_str());
	//agk::Print(thirdkeypressed.c_str());
	//agk::Print(fourthkeypressed.c_str());
	//agk::Print(arrowButtonsPressedCount());
	//agk::Print(frontAndBack(frisk, mountain).c_str());
	//agk::Print(getQuarter(frisk, circle)); //uncomment later
	//agk::Print(objcol);//uncomment later
	//agk::Print(firstpointX);
	//agk::Print(firstpointY);
	//agk::Print(secondpointX);
	//agk::Print(secondpointY);
	//agk::Print((float)sinus);
	//agk::Print((float)cosine);
	//agk::Print((float)myangle);
	//	agk::Print(bias);
	//	agk::Print(move);
	//agk::Print(X1);
	//agk::Print(Y1);
	//agk::Print(X2);
	//agk::Print(Y2);
	//agk::Print(result);
	//agk::Print((float)getAngle(frisk, mountain));
	//agk::Print(agk::ScreenFPS());
	//directionDetect(frisk, ghost);

	//if (closed==false)
	agk::Print(current_room);
	UpdateRoom();
	//agk::Print(HowManySounds());
	//agk::Print(HowManyImages());
	//agk::Print(HowManySprites());
	//agk::Print(HowManyGameWorldObjects());
	//updatedialogs();
	agk::Sync();
	return 0;
}

void app::End (void) 
{

}
