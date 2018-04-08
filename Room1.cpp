#include "Rooms.h"
#include "template.h"
#include <fstream>
#include "world.h"
#include "dialog.h"
#include "user.h"

using namespace std;

int frisk1;
int ghost1;
int room1;
int circle1;

vector<int> sprites_frisk1;
vector<int> sprite_actives_frisk1;
vector<int> sprites_ghost1;
vector<int> sprite_actives_ghost1;
vector<int> images_frisk1;

vector<int> sprites_room1;
vector<int> sprite_actives_room1;
vector<int> images_room1;

vector<int> sprites_circle1;
vector<int> sprite_actives_circle1;
vector<int> images_circle1;

void RunRoom1()
{

	//Создание первого спрайта (Фриск идет вниз)
	sprites_frisk1.push_back(agk::CreateSprite(0));
	sprite_actives_frisk1.push_back(0);
	sprites_ghost1.push_back(agk::CreateSprite(0));
	sprite_actives_ghost1.push_back(0);

	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_0.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_1.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_2.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharad_3.png"));

	for (int i = 0; i < 4; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk1[0], images_frisk1[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost1[0], images_frisk1[i]);
	}

	//Создание второго спрайта (Фриск идет влево)
	sprites_frisk1.push_back(agk::CreateSprite(0));
	sprite_actives_frisk1.push_back(0);
	sprites_ghost1.push_back(agk::CreateSprite(0));
	sprite_actives_ghost1.push_back(0);

	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharal_0.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharal_1.png"));

	for (int i = 4; i < 6; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk1[1], images_frisk1[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost1[1], images_frisk1[i]);
	}

	//Создание третьего спрайта (Фриск идет вправо)
	sprites_frisk1.push_back(agk::CreateSprite(0));
	sprite_actives_frisk1.push_back(0);
	sprites_ghost1.push_back(agk::CreateSprite(0));
	sprite_actives_ghost1.push_back(0);

	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharar_0.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharar_1.png"));

	for (int i = 6; i < 8; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk1[2], images_frisk1[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost1[2], images_frisk1[i]);
	}

	//Создание четвертого спрайта (Фриск идет вверх)
	sprites_frisk1.push_back(agk::CreateSprite(0));
	sprite_actives_frisk1.push_back(0);
	sprites_ghost1.push_back(agk::CreateSprite(0));
	sprite_actives_ghost1.push_back(0);

	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_0.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_1.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_2.png"));
	images_frisk1.push_back(agk::LoadImage("resources/Frisk/spr_f_maincharau_3.png"));

	for (int i = 8; i < 12; i++)
	{
		agk::AddSpriteAnimationFrame(sprites_frisk1[3], images_frisk1[i]);
		agk::AddSpriteAnimationFrame(sprites_ghost1[3], images_frisk1[i]);
	}

	images_room1.push_back(agk::LoadImage("resources/Cave/r0.png"));
	sprites_room1.push_back(agk::CreateSprite(images_room1[images_room1.size() - 1]));
	sprite_actives_room1.push_back(0);

	images_circle1.push_back(agk::LoadImage("resources/a circle (transparent).png"));
	sprites_circle1.push_back(agk::CreateSprite(images_circle1[images_circle1.size() - 1]));
	sprite_actives_circle1.push_back(0);

	//DeleteGameWorldObjects();

	circle1 = creategameWorldObject(
		6170, //x
		5300, //y
		0, //direction
		0, //sound
		0, //soundtype
		0, //soundactive
		0, //animationtype
		-1, //underobject
		2, //bonetype
		0, //gotoroom
		0, //fps
		0, //angle
		0, //speed
		85, //radius
		1, //scalex
		1, //scaley
		sprites_circle1, //sprites
		sprite_actives_circle1, //sprite_actives
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

	room1 = creategameWorldObject(
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
		sprites_room1, //sprites
		sprite_actives_room1, //sprite_actives
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

	frisk1 = creategameWorldObject(
		5300, //x
		5300, //y
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
		2, //speed
		0, //radius
		2, //scalex
		2, //scaley
		sprites_frisk1, //sprites
		sprite_actives_frisk1, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		true, //controllable
		false, //soundloop
		true, //spriteloop
		false, //underplayer
		false //isportal
	);
	ghost1 = creategameWorldObject(
		5300, //x
		5300, //y
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
		2, //speed
		0, //radius
		2, //scalex
		2, //scaley
		sprites_ghost1, //sprites
		sprite_actives_ghost1, //sprite_actives
		"", //info
		{}, //flavor_texts
		false, //info_count
		true, //solid
		true, //controllable
		false, //soundloop
		true, //spriteloop
		false, //underplayer
		false //isportal
	);

	for (int i = 0; i < 4; i++)
	{
		agk::SetSpriteVisible(sprites_ghost1[i], false);
		agk::SetSpritePhysicsOn(sprites_ghost1[i]);
		agk::SetSpriteShape(sprites_ghost1[i], 0);
		agk::ClearSpriteShapes(sprites_ghost1[i]);
		agk::AddSpriteShapeBox(sprites_ghost1[i], -20, 15, 18, 30, 0);
		agk::SetSpritePhysicsIsSensor(sprites_ghost1[i], 1);
	}

	agk::SetSpritePhysicsOn(sprites_room1[0]);
	agk::SetSpriteShape(sprites_room1[0], 0);
	agk::ClearSpriteShapes(sprites_room1[0]);
	agk::AddSpriteShapeBox(sprites_room1[0], -784, 254, 544, 253, 0); //вторая горизонтальная от низа, лево от моста
	agk::AddSpriteShapeBox(sprites_room1[0], 729, 254, 800, 253, 0); //вторая горизонтальная от низа, право от моста
	agk::AddSpriteShapeBox(sprites_room1[0], -779, -47, 544, -46, 0); //третья горизонтальная от низа, лево от моста
	agk::AddSpriteShapeBox(sprites_room1[0], 729, -47, 801, -46, 0); //третья горизонтальная от низа, право от моста
	agk::AddSpriteShapeBox(sprites_room1[0], 710, 234, 709, -27, 0); //правая вертикальная моста
	agk::AddSpriteShapeBox(sprites_room1[0], 563, 234, 564, -27, 0); //левая вертикальная моста
	agk::AddSpriteShapeCircle(sprites_room1[0], 544, 234, 20); //левый нижний круг моста
	agk::AddSpriteShapeCircle(sprites_room1[0], 729, 234, 20); //правый нижний круг моста
	agk::AddSpriteShapeCircle(sprites_room1[0], 544, -27, 20); //левый верхний круг моста
	agk::AddSpriteShapeCircle(sprites_room1[0], 729, -27, 20); //правый верхний круг моста
	agk::AddSpriteShapeBox(sprites_room1[0], -769, 566, 801, 567, 0); //нижняя горизонтальная
	agk::AddSpriteShapeBox(sprites_room1[0], -778, -370, -779, -46, 0); //левая вертикальная, верхняя часть
	agk::AddSpriteShapeBox(sprites_room1[0], -783, 253, -784, 556, 0); //левая вертикальная, нижняя часть
	agk::AddSpriteShapeBox(sprites_room1[0], -779, -369, 801, -370, 0); //четвертая горизонтальная от низа
	agk::AddSpriteShapeBox(sprites_room1[0], 800, -370, 801, -46, 0); //правая вертикальная, верхняя часть
	agk::AddSpriteShapeBox(sprites_room1[0], 800, 253, 801, 567, 0); //правая вертикальная, нижняя часть
	agk::SetSpritePhysicsIsSensor(sprites_room1[0], 1);

	agk::SetSpritePhysicsOn(sprites_circle1[0]);
	agk::SetSpriteShape(sprites_circle1[0], 0);
	agk::ClearSpriteShapes(sprites_circle1[0]);
	agk::AddSpriteShapeCircle(sprites_circle1[0], 0, 0, 85);
	agk::SetSpritePhysicsIsSensor(sprites_circle1[0], 1);

	agk::SetPhysicsGravity(0, 0);

	gameObjectUpdate(room1, -1);
	gameObjectUpdate(circle1, -1);

}

void UpdateRoom1()
{
	gameObjectUpdate(frisk1, ghost1);
}

void CloseRoom1()
{
	sprites_frisk1.clear();
	sprite_actives_frisk1.clear();
	sprites_ghost1.clear();
	sprite_actives_ghost1.clear();
	images_frisk1.clear();

	sprites_room1.clear();
	sprite_actives_room1.clear();
	images_room1.clear();

	sprites_circle1.clear();
	sprite_actives_circle1.clear();
	images_circle1.clear();

	agk::DeleteAllImages();
	agk::DeleteAllSprites();
	DeleteGameWorldObjects();
}