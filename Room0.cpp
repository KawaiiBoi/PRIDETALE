#include "Rooms.h"
#include "template.h"
#include <fstream>
#include "world.h"
#include "dialog.h"
#include "user.h"
using namespace std;

int music_rm0;
int frisk;
int ghost;
int room;
int room_over;
int bridge;
int bridge011;
int bridge012;
int bridge021;
int bridge022;
int water;
int wave1;
int wave2;
int wave3;
int wave4;
int wave5;
int wave6;
int wave7;
int wave8;
int crystal_main;
int crystal_big1;
int crystal_big2;
int crystal_big3;
int crystal_big4;
int shine_main;
int shine_big1;
int shine_big2;
int shine_big3;
int shine_big4;
int mountain;
int circle;
int portal;
double mountain_angle;
double circle_radius;
double speed;
int room_timer;

vector<int> sprites_frisk;
vector<int> sprite_actives_frisk;
vector<int> sprites_ghost;
vector<int> sprite_actives_ghost;
vector<int> images_frisk;

vector<int> sprites_room;
vector<int> sprite_actives_room;
vector<int> images_room;

vector<int> sprites_room_over;
vector<int> sprite_actives_room_over;
vector<int> images_room_over;

vector<int> sprites_bridge;
vector<int> sprite_actives_bridge;
vector<int> images_bridge;
int bridge_snd;

vector<int> sprites_bridge011;
vector<int> sprite_actives_bridge011;
vector<int> images_bridge011;

vector<int> sprites_bridge012;
vector<int> sprite_actives_bridge012;
vector<int> images_bridge012;

vector<int> sprites_bridge021;
vector<int> sprite_actives_bridge021;
vector<int> images_bridge021;

vector<int> sprites_bridge022;
vector<int> sprite_actives_bridge022;
vector<int> images_bridge022;

vector<int> sprites_water;
vector<int> sprite_actives_water;
vector<int> images_water;
int water_snd;

vector<int> sprites_wave1;
vector<int> sprite_actives_wave1;

vector<int> sprites_wave2;
vector<int> sprite_actives_wave2;

vector<int> sprites_wave3;
vector<int> sprite_actives_wave3;

vector<int> sprites_wave4;
vector<int> sprite_actives_wave4;

vector<int> sprites_wave5;
vector<int> sprite_actives_wave5;

vector<int> sprites_wave6;
vector<int> sprite_actives_wave6;

vector<int> sprites_wave7;
vector<int> sprite_actives_wave7;

vector<int> sprites_wave8;
vector<int> sprite_actives_wave8;

vector<int> images_wave;

vector<int> sprites_crystal_main;
vector<int> sprite_actives_crystal_main;
vector<int> images_crystal_main;

vector<int> sprites_crystal_big1;
vector<int> sprite_actives_crystal_big1;
vector<int> images_crystal_big1;

vector<int> sprites_crystal_big2;
vector<int> sprite_actives_crystal_big2;
vector<int> images_crystal_big2;

vector<int> sprites_crystal_big3;
vector<int> sprite_actives_crystal_big3;
vector<int> images_crystal_big3;

vector<int> sprites_crystal_big4;
vector<int> sprite_actives_crystal_big4;
vector<int> images_crystal_big4;

vector<int> sprites_shine_main;
vector<int> sprite_actives_shine_main;
vector<int> images_shine_main;

vector<int> sprites_shine_big1;
vector<int> sprite_actives_shine_big1;

vector<int> sprites_shine_big2;
vector<int> sprite_actives_shine_big2;

vector<int> sprites_shine_big3;
vector<int> sprite_actives_shine_big3;

vector<int> sprites_shine_big4;
vector<int> sprite_actives_shine_big4;

vector<int> images_shine_big;

vector<int> sprites_mountain;
vector<int> sprite_actives_mountain;
vector<int> images_mountain;

vector<int> sprites_circle;
vector<int> sprite_actives_circle;
vector<int> images_circle;

vector<int> sprites_portal;
vector<int> sprite_actives_portal;
vector<int> images_portal;

ofstream timerfile;

void RunRoom0()
{
	room_timer = 0; //таймер
	setWaveTimer(randomBetweenTwoNumbers(20,30));

	timerfile.open("timerfile.txt");

	ifstream myfileangle;
	myfileangle.open("angle.txt");
	myfileangle >> mountain_angle;
	myfileangle.close();

	ifstream myfileradius;
	myfileradius.open("radius.txt");
	myfileradius >> circle_radius;
	myfileradius.close();

	ifstream myfilespeed;
	myfilespeed.open("speed.txt");
	myfilespeed >> speed;
	myfilespeed.close();

	music_rm0 = agk::LoadMusic("resources/cave_theme.mp3");//тест музона Тайлера
	agk::PlayMusic(music_rm0,1);
	water_snd = agk::LoadSound("resources/SE/amio_sma-Aftermat-7396_hifi.wav");
	bridge_snd = agk::LoadSound("resources/SE/Wood Hull On Boat Creaking-SoundBible.com-867026276.wav");

	//Создание первого спрайта (Фриск идет вниз)
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
	sprites_frisk.push_back(agk::CreateSprite(0));
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
	}

	images_room.push_back(agk::LoadImage("resources/Cave/Rooms/1-1.png"));
	sprites_room.push_back(agk::CreateSprite(images_room[images_room.size() - 1]));
	sprite_actives_room.push_back(0);

	images_room_over.push_back(agk::LoadImage("resources/Cave/Rooms/1-1 (over).png"));
	sprites_room_over.push_back(agk::CreateSprite(images_room_over[images_room_over.size() - 1]));
	sprite_actives_room_over.push_back(0);

	images_bridge.push_back(agk::LoadImage("resources/Cave/Bridge1.png"));
	sprites_bridge.push_back(agk::CreateSprite(images_bridge[images_bridge.size() - 1]));
	sprite_actives_bridge.push_back(0);

	images_bridge011.push_back(agk::LoadImage("resources/Cave/Bridge0_1_1.png"));
	sprites_bridge011.push_back(agk::CreateSprite(images_bridge011[images_bridge011.size() - 1]));
	sprite_actives_bridge011.push_back(0);

	images_bridge012.push_back(agk::LoadImage("resources/Cave/Bridge0_1_2.png"));
	sprites_bridge012.push_back(agk::CreateSprite(images_bridge012[images_bridge012.size() - 1]));
	sprite_actives_bridge012.push_back(0);

	images_bridge021.push_back(agk::LoadImage("resources/Cave/Bridge0_2_1.png"));
	sprites_bridge021.push_back(agk::CreateSprite(images_bridge021[images_bridge021.size() - 1]));
	sprite_actives_bridge021.push_back(0);

	images_bridge022.push_back(agk::LoadImage("resources/Cave/Bridge0_2_2.png"));
	sprites_bridge022.push_back(agk::CreateSprite(images_bridge022[images_bridge022.size() - 1]));
	sprite_actives_bridge022.push_back(0);

	images_water.push_back(agk::LoadImage("resources/Cave/Water1.png"));
	images_water.push_back(agk::LoadImage("resources/Cave/Water2.png"));
	images_water.push_back(agk::LoadImage("resources/Cave/Water3.png"));
	sprites_water.push_back(agk::CreateSprite(0));
	agk::AddSpriteAnimationFrame(sprites_water[0], images_water[0]);
	agk::AddSpriteAnimationFrame(sprites_water[0], images_water[1]);
	agk::AddSpriteAnimationFrame(sprites_water[0], images_water[2]);
	sprite_actives_water.push_back(1);

	images_mountain.push_back(agk::LoadImage("resources/Sprites/b72.png"));
	sprites_mountain.push_back(agk::CreateSprite(images_mountain[images_mountain.size() - 1]));
	sprite_actives_mountain.push_back(0);

	images_circle.push_back(agk::LoadImage("resources/a circle (transparent).png"));
	sprites_circle.push_back(agk::CreateSprite(images_circle[images_circle.size() - 1]));
	sprite_actives_circle.push_back(0);

	images_portal.push_back(agk::LoadImage("resources/Itsaportal.png"));
	sprites_portal.push_back(agk::CreateSprite(images_portal[images_portal.size() - 1]));
	sprite_actives_portal.push_back(0);

	images_crystal_main.push_back(agk::LoadImage("resources/Cave/Crystals/Crystal_Main.png"));
	sprites_crystal_main.push_back(agk::CreateSprite(images_crystal_main[images_crystal_main.size() - 1]));
	sprite_actives_crystal_main.push_back(0);

	images_crystal_big1.push_back(agk::LoadImage("resources/Cave/Crystals/CrystalBig1.png"));
	sprites_crystal_big1.push_back(agk::CreateSprite(images_crystal_big1[images_crystal_big1.size() - 1]));
	sprite_actives_crystal_big1.push_back(0);

	images_crystal_big2.push_back(agk::LoadImage("resources/Cave/Crystals/CrystalBig2.png"));
	sprites_crystal_big2.push_back(agk::CreateSprite(images_crystal_big2[images_crystal_big2.size() - 1]));
	sprite_actives_crystal_big2.push_back(0);

	images_crystal_big3.push_back(agk::LoadImage("resources/Cave/Crystals/CrystalBig3.png"));
	sprites_crystal_big3.push_back(agk::CreateSprite(images_crystal_big3[images_crystal_big3.size() - 1]));
	sprite_actives_crystal_big3.push_back(0);

	images_crystal_big4.push_back(agk::LoadImage("resources/Cave/Crystals/CrystalBig4.png"));
	sprites_crystal_big4.push_back(agk::CreateSprite(images_crystal_big4[images_crystal_big4.size() - 1]));
	sprite_actives_crystal_big4.push_back(0);

	images_shine_main.push_back(agk::LoadImage("resources/Cave/Crystals/Shine_Main_1.png"));
	images_shine_main.push_back(agk::LoadImage("resources/Cave/Crystals/Shine_Main_2.png"));
	images_shine_main.push_back(agk::LoadImage("resources/Cave/Crystals/Shine_Main_3.png"));
	sprites_shine_main.push_back(agk::CreateSprite(0));
	agk::AddSpriteAnimationFrame(sprites_shine_main[0], images_shine_main[0]);
	agk::AddSpriteAnimationFrame(sprites_shine_main[0], images_shine_main[1]);
	agk::AddSpriteAnimationFrame(sprites_shine_main[0], images_shine_main[2]);
	agk::AddSpriteAnimationFrame(sprites_shine_main[0], images_shine_main[1]);
	sprite_actives_shine_main.push_back(1);

	images_shine_big.push_back(agk::LoadImage("resources/Cave/Crystals/Shine_Big_1.png"));
	images_shine_big.push_back(agk::LoadImage("resources/Cave/Crystals/Shine_Big_2.png"));

	sprites_shine_big1.push_back(agk::CreateSprite(0));
	sprites_shine_big2.push_back(agk::CreateSprite(0));
	sprites_shine_big3.push_back(agk::CreateSprite(0));
	sprites_shine_big4.push_back(agk::CreateSprite(0));

	agk::AddSpriteAnimationFrame(sprites_shine_big1[0], images_shine_big[0]);
	agk::AddSpriteAnimationFrame(sprites_shine_big1[0], images_shine_big[1]);

	agk::AddSpriteAnimationFrame(sprites_shine_big2[0], images_shine_big[0]);
	agk::AddSpriteAnimationFrame(sprites_shine_big2[0], images_shine_big[1]);

	agk::AddSpriteAnimationFrame(sprites_shine_big3[0], images_shine_big[0]);
	agk::AddSpriteAnimationFrame(sprites_shine_big3[0], images_shine_big[1]);

	agk::AddSpriteAnimationFrame(sprites_shine_big4[0], images_shine_big[0]);
	agk::AddSpriteAnimationFrame(sprites_shine_big4[0], images_shine_big[1]);

	sprite_actives_shine_big1.push_back(1);
	sprite_actives_shine_big2.push_back(1);
	sprite_actives_shine_big3.push_back(1);
	sprite_actives_shine_big4.push_back(1);

	images_wave.push_back(agk::LoadImage("resources/Cave/Wave0.png"));
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

	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[0]);//1
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[1]);//2
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[2]);//3
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[3]);//4
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[4]);//5
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[3]);//4
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[2]);//3
	agk::AddSpriteAnimationFrame(sprites_wave1[0], images_wave[1]);//2

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

	sprite_actives_wave1.push_back(0);
	sprite_actives_wave2.push_back(0);
	sprite_actives_wave3.push_back(0);
	sprite_actives_wave4.push_back(0);
	sprite_actives_wave5.push_back(0);
	sprite_actives_wave6.push_back(0);
	sprite_actives_wave7.push_back(0);
	sprite_actives_wave8.push_back(0);

	//Создаем объекты

	//DeleteGameWorldObjects();

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
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
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
		true, //underplayer
		false //isportal
	);

	room_over = creategameWorldObject(
		5006, //x
		6158, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_room_over, //sprites
		sprite_actives_room_over, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		false, //underplayer
		false //isportal
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
		-1, //gotoroom
		0, //fps
		mountain_angle, //angle
		0, //speed
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
		false, //underplayer
		false //isportal
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
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
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
		false, //underplayer
		false //isportal
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
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
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
		false, //underplayer
		false //isportal
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
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
		1, //fps
		0, //angle
		0, //speed
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
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
		-1, //gotoroom
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
		true, //underplayer
		false //isportal
	);

	crystal_main = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_crystal_main, //sprites
		sprite_actives_crystal_main, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		false //isportal
	);
	crystal_big1 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_crystal_big1, //sprites
		sprite_actives_crystal_big1, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		false //isportal
	);
	crystal_big2 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_crystal_big2, //sprites
		sprite_actives_crystal_big2, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		false //isportal
	);
	crystal_big3 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_crystal_big3, //sprites
		sprite_actives_crystal_big3, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		false //isportal
	);
	crystal_big4 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_crystal_big4, //sprites
		sprite_actives_crystal_big4, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		false //isportal
	);

	shine_main = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		crystal_main, //underobject
		0, //bonetype
		-1, //gotoroom
		1, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_shine_main, //sprites
		sprite_actives_shine_main, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true, //underplayer
		false //isportal
	);
	shine_big1 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		crystal_big1, //underobject
		0, //bonetype
		-1, //gotoroom
		1, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_shine_big1, //sprites
		sprite_actives_shine_big1, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true, //underplayer
		false //isportal
	);
	shine_big2 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		crystal_big2, //underobject
		0, //bonetype
		-1, //gotoroom
		1, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_shine_big2, //sprites
		sprite_actives_shine_big2, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true, //underplayer
		false //isportal
	);
	shine_big3 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		crystal_big3, //underobject
		0, //bonetype
		-1, //gotoroom
		1, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_shine_big3, //sprites
		sprite_actives_shine_big3, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true, //underplayer
		false //isportal
	);
	shine_big4 = creategameWorldObject(
		0, //x
		0, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		crystal_big4, //underobject
		0, //bonetype
		-1, //gotoroom
		1, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_shine_big4, //sprites
		sprite_actives_shine_big4, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		true, //spriteloop
		true, //underplayer
		false //isportal
	);

	frisk = creategameWorldObject(
		5100, //x
		5950, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		8, //fps
		0, //angle
		speed, //speed
		0, //radius
		2, //scalex
		2, //scaley
		sprites_frisk, //sprites
		sprite_actives_frisk, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		true, //controllable
		false, //soundloop
		true, //spriteloop
		false, //underplayer
		false //isportal
	);
	ghost = creategameWorldObject(
		5100, //x
		5950, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		-1, //gotoroom
		8, //fps
		0, //angle
		speed, //speed
		0, //radius
		2, //scalex
		2, //scaley
		sprites_ghost, //sprites
		sprite_actives_ghost, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		true, //controllable
		false, //soundloop
		true, //spriteloop
		false, //underplayer
		false //isportal
	);

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
		1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		circle_radius, //radius
		1, //scalex
		1, //scaley
		sprites_circle, //sprites
		sprite_actives_circle, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		true //isportal
	);

	portal = creategameWorldObject(
		6770, //x
		5340, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		0, //bonetype
		1, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		0, //radius
		1, //scalex
		1, //scaley
		sprites_portal, //sprites
		sprite_actives_portal, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		false, //solid
		false, //controllable
		false, //soundloop
		false, //spriteloop
		true, //underplayer
		true //isportal
	);

	for (int i = 0; i < 4; i++)
	{
		agk::SetSpriteVisible(sprites_ghost[i], false);
		agk::SetSpritePhysicsOn(sprites_ghost[i]);
		agk::SetSpriteShape(sprites_ghost[i], 0);
		agk::ClearSpriteShapes(sprites_ghost[i]);
		agk::AddSpriteShapeBox(sprites_ghost[i], -20, 15, 18, 30, 0);
		agk::SetSpritePhysicsIsSensor(sprites_ghost[i], 1);
	}

	agk::SetSpritePhysicsOn(sprites_room[0]);
	agk::SetSpriteShape(sprites_room[0], 0);
	agk::ClearSpriteShapes(sprites_room[0]);
	agk::AddSpriteShapeBox(sprites_room[0], -869, 254, 459, 253, 0); //вторая горизонтальная от низа, лево от моста
	agk::AddSpriteShapeBox(sprites_room[0], 644, 254, 715, 253, 0); //вторая горизонтальная от низа, право от моста
	agk::AddSpriteShapeBox(sprites_room[0], -864, -47, 459, -46, 0); //третья горизонтальная от низа, лево от моста
	agk::AddSpriteShapeBox(sprites_room[0], 644, -47, 886, -46, 0); //третья горизонтальная от низа, право от моста
	agk::AddSpriteShapeBox(sprites_room[0], 625, 234, 624, -27, 0); //правая вертикальная моста
	agk::AddSpriteShapeBox(sprites_room[0], 478, 234, 479, -27, 0); //левая вертикальная моста
	agk::AddSpriteShapeCircle(sprites_room[0], 459, 234, 20); //левый нижний круг моста
	agk::AddSpriteShapeCircle(sprites_room[0], 644, 234, 20); //правый нижний круг моста
	agk::AddSpriteShapeCircle(sprites_room[0], 459, -27, 20); //левый верхний круг моста
	agk::AddSpriteShapeCircle(sprites_room[0], 644, -27, 20); //правый верхний круг моста
	//agk::AddSpriteShapeBox(sprites_room[0], -854, 566, 716, 567, 0); //нижняя горизонтальная
	agk::AddSpriteShapeBox(sprites_room[0], -863, -370, -864, -46, 0); //левая вертикальная, верхняя часть
	agk::AddSpriteShapeBox(sprites_room[0], -868, 253, -869, 556, 0); //левая вертикальная, нижняя часть
	agk::AddSpriteShapeBox(sprites_room[0], -864, -369, 716, -370, 0); //четвертая горизонтальная от низа
	agk::AddSpriteShapeBox(sprites_room[0], 715, -370, 716, -210, 0); //правая вертикальная, верхняя часть
	agk::AddSpriteShapeBox(sprites_room[0], 715, -211, 886, -210, 0); //правая горизонтальная, верхняя часть, верхний правый гориз. отрезок
	agk::AddSpriteShapeBox(sprites_room[0], 715, 253, 716, 567, 0); //правая вертикальная, нижняя часть
	agk::SetSpritePhysicsIsSensor(sprites_room[0], 1);

	agk::SetSpritePhysicsOn(sprites_room_over[0]);
	agk::SetSpriteShape(sprites_room_over[0], 0);
	agk::ClearSpriteShapes(sprites_room_over[0]);
	agk::AddSpriteShapeBox(sprites_room_over[0], -800, 109, 800, 110, 0);
	agk::SetSpritePhysicsIsSensor(sprites_room_over[0], 1);
	
	agk::SetSpritePhysicsOn(sprites_bridge[0]);
	agk::SetSpriteShape(sprites_bridge[0], 0);
	agk::ClearSpriteShapes(sprites_bridge[0]);
	//agk::AddSpriteShapeBox(sprites_bridge[0], -77, -160, 77, 148, 0);
	agk::SetSpritePhysicsIsSensor(sprites_bridge[0], 1);

	agk::SetSpritePhysicsOn(sprites_portal[0]);
	agk::SetSpriteShape(sprites_portal[0], 0);
	agk::ClearSpriteShapes(sprites_portal[0]);
	agk::AddSpriteShapeBox(sprites_portal[0], -78, -122.5, 78, 122.5, 0);
	agk::SetSpritePhysicsIsSensor(sprites_portal[0], 1);

	agk::SetSpritePhysicsOn(sprites_mountain[0]);
	agk::SetSpriteShape(sprites_mountain[0], 0);
	agk::ClearSpriteShapes(sprites_mountain[0]);
	agk::AddSpriteShapeBox(sprites_mountain[0], -320, -15, 320, 15, 0);
	agk::SetSpritePhysicsIsSensor(sprites_mountain[0], 1);

	agk::SetSpritePhysicsOn(sprites_circle[0]);
	agk::SetSpriteShape(sprites_circle[0], 0);
	agk::ClearSpriteShapes(sprites_circle[0]);
	agk::AddSpriteShapeCircle(sprites_circle[0], 0, 0, circle_radius);
	agk::SetSpritePhysicsIsSensor(sprites_circle[0], 1);

	agk::SetPhysicsGravity(0, 0);

	gameObjectUpdate(room, -1);
	gameObjectUpdate(room_over, -1);

	setObjectGroupLocationAndUpdate(
	{
		bridge, //список объектов
		bridge011, bridge012,//, bridge013, 
		bridge021, bridge022//, bridge023
	},
		6361, //x группы
		5520, //y группы
		{ //список относительных координат для каждого из объектов
			{ 0,0 },
			{ -36,-77 },
			{ -14,-1 },
			//	{-40,-47},
			{ -38,161 },
			{ -16,338 },
			//	{-59,295}
		});

	setObjectGroupLocationAndUpdate(
	{
		crystal_main, shine_main //список объектов
	},
		5125, //x группы
		6000, //y группы
		{ //список относительных координат для каждого из объектов
			{ 0,0 },
			{ -8,18 }
		});

	setObjectGroupLocationAndUpdate(
	{
		crystal_big1, shine_big1 //список объектов
	},
		5105, //x группы
		5920, //y группы
		{ //список относительных координат для каждого из объектов
			{ 0,0 },
			{ -8,4 }
		});

	setObjectGroupLocationAndUpdate(
	{
		crystal_big2, shine_big2 //список объектов
	},
		5205, //x группы
		5960, //y группы
		{ //список относительных координат для каждого из объектов
			{ 0,0 },
			{ -8,2 }
		});

	setObjectGroupLocationAndUpdate(
	{
		crystal_big3, shine_big3 //список объектов
	},
		5100, //x группы
		6060, //y группы
		{ //список относительных координат для каждого из объектов
			{ 0,0 },
			{ -10,4 }
		});

	setObjectGroupLocationAndUpdate(
	{
		crystal_big4, shine_big4 //список объектов
	},
		5150, //x группы
		6125, //y группы
		{ //список относительных координат для каждого из объектов
			{ 0,0 },
			{ -9,1 }
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
	gameObjectUpdate(wave8, -1);
	gameObjectUpdate(portal, -1);
	gameObjectUpdate(crystal_main, -1);
	gameObjectUpdate(shine_main, -1);
	agk::SetSpriteVisible(sprites_portal[0], false);
}


int when_earth_stopped = -1;
void UpdateRoom0()
{

	/*
	room_timer = manageWaves({ {wave1, wave2}, {wave3, wave4}, {wave5, wave6}, {wave7, wave8} }, 5025, 5650, 6000, 5810, room_timer, 10, 10);
	if (agk::GetSpritePlaying(sprites_wave1[0]) == 0 && room_timer > 100 && when_earth_stopped == -1)
	{
		when_earth_stopped = room_timer;
	}
	if (room_timer == 100)
	{
		agk::PlaySprite(sprites_wave1[0], 3, 0);
	}
	agk::Print(room_timer);
	agk::Print(when_earth_stopped);
	timerfile << room_timer<<endl;
	room_timer++;
	//moveObjects({ {wave1, wave2, wave3, wave4, wave5, wave6, wave7, wave8} }, 5025, 6600, 5650, 5810, 2);

	*/ //Какая-то страшная функция, тобой же написанная ранее. Будь заей, перечитай потом, что она делает. <3
	gameObjectUpdate(frisk, ghost);
}

void CloseRoom0()
{
	sprites_frisk.clear();
	sprite_actives_frisk.clear();
	sprites_ghost.clear();
	sprite_actives_ghost.clear();
	images_frisk.clear();

	sprites_room.clear();
	sprite_actives_room.clear();
	images_room.clear();

	sprites_room_over.clear();
	sprite_actives_room_over.clear();
	images_room_over.clear();

	sprites_bridge.clear();
	sprite_actives_bridge.clear();
	images_bridge.clear();

	sprites_bridge011.clear();
	sprite_actives_bridge011.clear();
	images_bridge011.clear();

	sprites_bridge012.clear();
	sprite_actives_bridge012.clear();
	images_bridge012.clear();

	sprites_bridge021.clear();
	sprite_actives_bridge021.clear();
	images_bridge021.clear();

	sprites_bridge022.clear();
	sprite_actives_bridge022.clear();
	images_bridge022.clear();

	sprites_water.clear();
	sprite_actives_water.clear();
	images_water.clear();

	sprites_wave1.clear();
	sprite_actives_wave1.clear();

	sprites_wave2.clear();
	sprite_actives_wave2.clear();

	sprites_wave3.clear();
	sprite_actives_wave3.clear();

	sprites_wave4.clear();
	sprite_actives_wave4.clear();

	sprites_wave5.clear();
	sprite_actives_wave5.clear();

	sprites_wave6.clear();
	sprite_actives_wave6.clear();

	sprites_wave7.clear();
	sprite_actives_wave7.clear();

	sprites_wave8.clear();
	sprite_actives_wave8.clear();

	images_wave.clear();

	sprites_mountain.clear();
	sprite_actives_mountain.clear();
	images_mountain.clear();

	sprites_circle.clear();
	sprite_actives_circle.clear();
	images_circle.clear();

	sprites_portal.clear();
	sprite_actives_portal.clear();
	images_portal.clear();

	sprites_crystal_main.clear();
	sprite_actives_crystal_main.clear();
	images_crystal_main.clear();

	sprites_shine_main.clear();
	sprite_actives_shine_main.clear();
	images_shine_main.clear();
	
	agk::DeleteAllImages();
	agk::DeleteAllSprites();
	agk::DeleteSound(water_snd);
	agk::DeleteSound(bridge_snd);
	DeleteGameWorldObjects();
}