#pragma once
#include "template.h"
#include <vector>
using namespace std;
struct sound;
extern vector <sound> soundS;
int loadsound(string name);
struct color;
extern vector <color> colorS;
int createcolor(int r, int g, int b);
struct font;
extern vector <font> fontS;
int createfont(vector <char> symbols, vector<vector <string> >names, vector<bool>coloraf);
void loadfont(int id, string name);
struct text; 
extern vector <text> textS;
int createtext(int x, int y, string message, int fontid, vector <int> colorsid, vector <int> soundsid, int interval, int shaking, float sizing, bool animate);
struct textproc;
extern vector <textproc> textprocS;
int showtext(int textid, int delay);
void setspritecolor(int sprite, int id);
void updatetexts();
void instanttext(int textprocid);