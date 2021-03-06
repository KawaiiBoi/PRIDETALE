#pragma once
#include "template.h"
#include <vector>
using namespace std;

extern int touched;
extern int text_page;
extern string edges;
extern vector<string> resolutions;

extern string state;
extern string firstkeypressed;
extern string secondkeypressed;
extern string thirdkeypressed;
extern string fourthkeypressed;
extern string narrastorage;
extern int narrasound;

extern double firstpointX;
extern double firstpointY;
extern double secondpointX;
extern double secondpointY;
extern double X1;
extern double Y1;
extern double X2;
extern double Y2;
extern double result;
extern double sinus;
extern double cosine;
extern double myangle;
extern double bias;
extern double move;
extern int objcol;

extern int wave_timer;

int createdialogcolor(string get_name, int get_r, int get_g, int get_b);
void colorsInitiate();
string toUpper(string str);
int getdialogcolor(string get_name);
int creategameWorldObject(double get_x, double get_y, int get_direction, int get_snd, int get_sndtype, int get_sndactive, int get_animationtype, int get_underobject, int get_bonetype, int get_gotoroom, double get_fps, double get_angle, double get_speed, double get_radius, double get_scalex, double get_scaley, vector <int> get_sprites, vector <int> get_sprite_actives, string get_info, vector <vector <string>> get_flavor_texts, bool get_info_count, bool get_solid, bool get_controllable, bool get_sndloop, bool get_spriteloop, bool get_underplayer, bool get_isportal);
void DeleteGameWorldObjects();
int HowManyGameWorldObjects();
void directionDetect(int objectid, int ghostid);
void setObjectGroupLocationAndUpdate(vector <int> objects, int startx, int starty, vector<vector<int>> coordinates);
void switchAnimation(int objectid, int flag);
void switchSound(int objectid, int flag);
int getStateCount(int objectid);
void stateUpdate(int objectid);
void narraInitiate();
string initiateDialog(string text);
int randomBetweenTwoNumbers(int n1, int n2);
int arrowButtonsPressedCount();
int directionStringToInt(string direction);
bool directionsAreOpposite(int d1, int d2);
int resultDirection(int d1, int d2, int d3);
int oppositeDirection(int direction);
void ghostGoHome(int ghostid);
void moveGhost(int ghostid, int direction);
void moveGhost(int ghostid, double x, double y);
int objectWeCollidedWith(int ghostid);
bool moveIsPossible(int ghostid);
bool moveIsPossible(int ghostid, int direction);
bool moveIsPossible(int ghostid, double x, double y);
void moveCharacter(int objectid, int ghostid, int direction);
void moveCharacter(int objectid, int ghostid, double x, double y);
string frontAndBack(int objectid, int objectToCheck);
double getAngle(int objectid, int objectToCheck);
bool isNecessaryForGlidingToBeReversed(int objectid, double angle, int direction);
double getBias(int objectid, double angle, int direction);
bool isPossibleToGlide(int objectid, int ghostid, int direction);
void glideCharacter(int objectid, int ghostid, int direction);
int compensatingDirection(int direction, string position, double angle);
int getQuarter(int objectid, int objectToCheck);
bool isCircle(int objectid, int ghostid, int direction);
void GlideCircle(int objectid, int ghostid, int direction);
void GlideCircleDefined(int objectid, int ghostid, int circleid, int direction);
int compensatingDirectionCircle(int direction, int quarter);
void manageCharacterMove(int objectid, int ghostid, int direction);
void manageCharacterMove(int objectid, int ghostid, int direction1, int direction2);
double getDistanceBetweenSpriteCenters(int sprite1, int sprite2);
bool isFarEnoughFromTheOtherWaves(int wave_sprite, int x, int y, vector <int> other_visible_waves, int M);
bool isFarEnoughFromTheOtherWavesInTheGroup(int wave_sprite, int x, int y, vector <int> waves_to_create, int index_to_stop, int N);
void startNewGroup(vector <int> waves_to_create, vector <int> other_visible_waves, int x1, int x2, int y1, int y2, int M, int N);
void setWaveTimer(int timer);
int manageWaves(vector <vector<int>> waves, int x1, int x2, int y1, int y2, int timer, int M, int N);
double getDistanceBetweenSpriteCenters(int sprite1, int sprite2);
void startNewGroup(vector <int> waves_to_create, vector <int> other_visible_waves, int x1, int x2, int y1, int y2, int M, int N);
void moveObjects(vector <vector<int>> objects, int x1, int x2, int y1, int y2, int direction);
bool buttonPressedIsTrue(string button);
void gameObjectUpdate(int objectid, int ghostid);