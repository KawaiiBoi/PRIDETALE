#include "world.h"
#include "user.h"
#include "dialog.h"
#include "template.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "Rooms.h"
#define PI 3.14159265
using namespace std;

int touched = 0;
int text_page = 0;
string edges = "agk::Round is used";
vector<string> resolutions = {"1280 x 720", "1366 x 768", "1600 x 900", "1920 x 1080"};

string state = "state: ";
string firstkeypressed = "none"; //для возни с движением героя
string secondkeypressed = "none";
string thirdkeypressed = "none";
string fourthkeypressed = "none";
string narrastorage;
int narrasound;

double firstpointX;
double firstpointY;
double secondpointX;
double secondpointY;
double X1;
double Y1;
double X2;
double Y2;
double result;
double sinus;
double cosine;
double myangle;
double bias;
double move;
int objcol = -2;

int wave_timer;

//remove later
ofstream motion_log;
ofstream wave_log;

struct dialogcolor
{
	string name;
	int r, g, b;
};

vector <dialogcolor> dialogcolorS;

int createdialogcolor(string get_name, int get_r, int get_g, int get_b)
{
	dialogcolor sample;
	sample.name = get_name;
	sample.r = get_r;
	sample.g = get_g;
	sample.b = get_b;
	dialogcolorS.push_back(sample);
	return dialogcolorS.size() - 1;
}

void colorsInitiate()
{
	createdialogcolor("Snow", 255, 250, 250);
	createdialogcolor("GhostWhite", 248, 248, 255);
	createdialogcolor("WhiteSmoke", 245, 245, 245);
	createdialogcolor("Gainsboro", 220, 220, 220);
	createdialogcolor("FloralWhite", 255, 250, 240);
	createdialogcolor("OldLace", 253, 245, 230);
	createdialogcolor("Linen", 250, 240, 230);
	createdialogcolor("AntiqueWhite", 250, 235, 215);
	createdialogcolor("PapayaWhip", 255, 239, 213);
	createdialogcolor("BlanchedAlmond", 255, 235, 205);
	createdialogcolor("Bisque", 255, 228, 196);
	createdialogcolor("PeachPuff", 255, 218, 185);
	createdialogcolor("NavajoWhite", 255, 222, 173);
	createdialogcolor("Moccasin", 255, 228, 181);
	createdialogcolor("Cornsilk", 255, 248, 220);
	createdialogcolor("Ivory", 255, 255, 240);
	createdialogcolor("LemonChiffon", 255, 250, 205);
	createdialogcolor("Seashell", 255, 245, 238);
	createdialogcolor("Honeydew", 240, 255, 240);
	createdialogcolor("MintCream", 245, 255, 250);
	createdialogcolor("Azure", 240, 255, 255);
	createdialogcolor("AliceBlue", 240, 248, 255);
	createdialogcolor("lavender", 230, 230, 250);
	createdialogcolor("LavenderBlush", 255, 240, 245);
	createdialogcolor("MistyRose", 255, 228, 225);
	createdialogcolor("White", 255, 255, 255);
	createdialogcolor("Black", 0, 0, 0);
	createdialogcolor("DarkSlateGray", 47, 79, 79);
	createdialogcolor("DimGrey", 105, 105, 105);
	createdialogcolor("SlateGrey", 112, 128, 144);
	createdialogcolor("LightSlateGray", 119, 136, 153);
	createdialogcolor("Grey", 190, 190, 190);
	createdialogcolor("LightGray", 211, 211, 211);
	createdialogcolor("MidnightBlue", 25, 25, 112);
	createdialogcolor("NavyBlue", 0, 0, 128);
	createdialogcolor("CornflowerBlue", 100, 149, 237);
	createdialogcolor("DarkSlateBlue", 72, 61, 139);
	createdialogcolor("SlateBlue", 106, 90, 205);
	createdialogcolor("MediumSlateBlue", 123, 104, 238);
	createdialogcolor("LightSlateBlue", 132, 112, 255);
	createdialogcolor("MediumBlue", 0, 0, 205);
	createdialogcolor("RoyalBlue", 65, 105, 225);
	createdialogcolor("Blue", 0, 0, 255);
	createdialogcolor("DodgerBlue", 30, 144, 255);
	createdialogcolor("DeepSkyBlue", 0, 191, 255);
	createdialogcolor("SkyBlue", 135, 206, 235);
	createdialogcolor("LightSkyBlue", 135, 206, 250);
	createdialogcolor("SteelBlue", 70, 130, 180);
	createdialogcolor("LightSteelBlue", 176, 196, 222);
	createdialogcolor("LightBlue", 173, 216, 230);
	createdialogcolor("PowderBlue", 176, 224, 230);
	createdialogcolor("PaleTurquoise", 175, 238, 238);
	createdialogcolor("DarkTurquoise", 0, 206, 209);
	createdialogcolor("MediumTurquoise", 72, 209, 204);
	createdialogcolor("Turquoise", 64, 224, 208);
	createdialogcolor("Cyan", 0, 255, 255);
	createdialogcolor("LightCyan", 224, 255, 255);
	createdialogcolor("CadetBlue", 95, 158, 160);
	createdialogcolor("MediumAquamarine", 102, 205, 170);
	createdialogcolor("Aquamarine", 127, 255, 212);
	createdialogcolor("DarkGreen", 0, 100, 0);
	createdialogcolor("DarkOliveGreen", 85, 107, 47);
	createdialogcolor("DarkSeaGreen", 143, 188, 143);
	createdialogcolor("SeaGreen", 46, 139, 87); 
	createdialogcolor("MediumSeaGreen", 60, 179, 113);
	createdialogcolor("LightSeaGreen", 32, 178, 170);
	createdialogcolor("PaleGreen", 152, 251, 152);
	createdialogcolor("SpringGreen", 0, 255, 127);
	createdialogcolor("LawnGreen", 124, 252, 0);
	createdialogcolor("Green", 0, 255, 0);
	createdialogcolor("Chartreuse", 127, 255, 0);
	createdialogcolor("MedSpringGreen", 0, 250, 154);
	createdialogcolor("GreenYellow", 173, 255, 47);
	createdialogcolor("LimeGreen", 50, 205, 50);
	createdialogcolor("YellowGreen", 154, 205, 50);
	createdialogcolor("ForestGreen", 34, 139, 34);
	createdialogcolor("OliveDrab", 107, 142, 35);
	createdialogcolor("DarkKhaki", 189, 183, 107);
	createdialogcolor("PaleGoldenrod", 238, 232, 170);
	createdialogcolor("LtGoldenrodYello", 250, 250, 210);
	createdialogcolor("LightYellow", 255, 255, 224);
	createdialogcolor("Yellow", 255, 255, 0);
	createdialogcolor("Gold", 255, 215, 0);
	createdialogcolor("LightGoldenrod", 238, 221, 130);
	createdialogcolor("goldenrod", 218, 165, 32);
	createdialogcolor("DarkGoldenrod", 184, 134, 11);
	createdialogcolor("RosyBrown", 188, 143, 143);
	createdialogcolor("IndianRed", 205, 92, 92);
	createdialogcolor("SaddleBrown", 139, 69, 19);
	createdialogcolor("Sienna", 160, 82, 45);
	createdialogcolor("Peru", 205, 133, 63);
	createdialogcolor("Burlywood", 222, 184, 135);
	createdialogcolor("Beige", 245, 245, 220);
	createdialogcolor("Wheat", 245, 222, 179);
	createdialogcolor("SandyBrown", 244, 164, 96);
	createdialogcolor("Tan", 210, 180, 140);
	createdialogcolor("Chocolate", 210, 105, 30);
	createdialogcolor("Firebrick", 178, 34, 34);
	createdialogcolor("Brown", 165, 42, 42);
	createdialogcolor("DarkSalmon", 233, 150, 122);
	createdialogcolor("Salmon", 250, 128, 114);
	createdialogcolor("LightSalmon", 255, 160, 122);
	createdialogcolor("Orange", 255, 165, 0);
	createdialogcolor("DarkOrange", 255, 140, 0);
	createdialogcolor("Coral", 255, 127, 80);
	createdialogcolor("LightCoral", 240, 128, 128);
	createdialogcolor("Tomato", 255, 99, 71);
	createdialogcolor("OrangeRed", 255, 69, 0);
	createdialogcolor("Red", 255, 0, 0);
	createdialogcolor("HotPink", 255, 105, 180);
	createdialogcolor("DeepPink", 255, 20, 147);
	createdialogcolor("Pink", 255, 192, 203);
	createdialogcolor("LightPink", 255, 182, 193);
	createdialogcolor("PaleVioletRed", 219, 112, 147);
	createdialogcolor("Maroon", 176, 48, 96);
	createdialogcolor("MediumVioletRed", 199, 21, 133);
	createdialogcolor("VioletRed", 208, 32, 144);
	createdialogcolor("Magenta", 255, 0, 255);
	createdialogcolor("Violet", 238, 130, 238);
	createdialogcolor("Plum", 221, 160, 221);
	createdialogcolor("Orchid", 218, 112, 214);
	createdialogcolor("MediumOrchid", 186, 85, 211);
	createdialogcolor("DarkOrchid", 153, 50, 204);
	createdialogcolor("DarkViolet", 148, 0, 211);
	createdialogcolor("BlueViolet", 138, 43, 226);
	createdialogcolor("Purple", 160, 32, 240);
	createdialogcolor("MediumPurple", 147, 112, 219);
	createdialogcolor("Thistle", 216, 191, 216);
	createdialogcolor("Snow1", 255, 250, 250);
	createdialogcolor("Snow2", 238, 233, 233);
	createdialogcolor("Snow3", 205, 201, 201);
	createdialogcolor("Snow4", 139, 137, 137);
	createdialogcolor("Seashell1", 255, 245, 238);
	createdialogcolor("Seashell2", 238, 229, 222);
	createdialogcolor("Seashell3", 205, 197, 191);
	createdialogcolor("Seashell4", 139, 134, 130);
	createdialogcolor("AntiqueWhite1", 255, 239, 219);
	createdialogcolor("AntiqueWhite2", 238, 223, 204);
	createdialogcolor("AntiqueWhite3", 205, 192, 176);
	createdialogcolor("AntiqueWhite4", 139, 131, 120);
	createdialogcolor("Bisque1", 255, 228, 196);
	createdialogcolor("Bisque2", 238, 213, 183);
	createdialogcolor("Bisque3", 205, 183, 158);
	createdialogcolor("Bisque4", 139, 125, 107);
	createdialogcolor("PeachPuff1", 255, 218, 185);
	createdialogcolor("PeachPuff2", 238, 203, 173);
	createdialogcolor("PeachPuff3", 205, 175, 149);
	createdialogcolor("PeachPuff4", 139, 119, 101);
	createdialogcolor("NavajoWhite1", 255, 222, 173);
	createdialogcolor("NavajoWhite2", 238, 207, 161);
	createdialogcolor("NavajoWhite3", 205, 179, 139);
	createdialogcolor("NavajoWhite4", 139, 121, 94);
	createdialogcolor("LemonChiffon1", 255, 250, 205);
	createdialogcolor("LemonChiffon2", 238, 233, 191);
	createdialogcolor("LemonChiffon3", 205, 201, 165);
	createdialogcolor("LemonChiffon4", 139, 137, 112);
	createdialogcolor("Cornsilk1", 255, 248, 220);
	createdialogcolor("Cornsilk2", 238, 232, 205);
	createdialogcolor("Cornsilk3", 205, 200, 177);
	createdialogcolor("Cornsilk4", 139, 136, 120);
	createdialogcolor("Ivory1", 255, 255, 240);
	createdialogcolor("Ivory2", 238, 238, 224);
	createdialogcolor("Ivory3", 205, 205, 193);
	createdialogcolor("Ivory4", 139, 139, 131);
	createdialogcolor("Honeydew1", 240, 255, 240);
	createdialogcolor("Honeydew2", 224, 238, 224);
	createdialogcolor("Honeydew3", 193, 205, 193);
	createdialogcolor("Honeydew4", 131, 139, 131);
	createdialogcolor("LavenderBlush1", 255, 240, 245);
	createdialogcolor("LavenderBlush2", 238, 224, 229);
	createdialogcolor("LavenderBlush3", 205, 193, 197);
	createdialogcolor("LavenderBlush4", 139, 131, 134);
	createdialogcolor("MistyRose1", 255, 228, 225);
	createdialogcolor("MistyRose2", 238, 213, 210);
	createdialogcolor("MistyRose3", 205, 183, 181);
	createdialogcolor("MistyRose4", 139, 125, 123);
	createdialogcolor("Azure1", 240, 255, 255);
	createdialogcolor("Azure2", 224, 238, 238);
	createdialogcolor("Azure3", 193, 205, 205);
	createdialogcolor("Azure4", 131, 139, 139);
	createdialogcolor("SlateBlue1", 131, 111, 255);
	createdialogcolor("SlateBlue2", 122, 103, 238);
	createdialogcolor("SlateBlue3", 105, 89, 205);
	createdialogcolor("SlateBlue4", 71, 60, 139);
	createdialogcolor("RoyalBlue1", 72, 118, 255);
	createdialogcolor("RoyalBlue2", 67, 110, 238);
	createdialogcolor("RoyalBlue3", 58, 95, 205);
	createdialogcolor("RoyalBlue4", 39, 64, 139);
	createdialogcolor("Blue1", 0, 0, 255);
	createdialogcolor("Blue2", 0, 0, 238);
	createdialogcolor("Blue3", 0, 0, 205);
	createdialogcolor("Blue4", 0, 0, 139);
	createdialogcolor("DodgerBlue1", 30, 144, 255);
	createdialogcolor("DodgerBlue2", 28, 134, 238);
	createdialogcolor("DodgerBlue3", 24, 116, 205);
	createdialogcolor("DodgerBlue4", 16, 78, 139);
	createdialogcolor("SteelBlue1", 99, 184, 255);
	createdialogcolor("SteelBlue2", 92, 172, 238);
	createdialogcolor("SteelBlue3", 79, 148, 205);
	createdialogcolor("SteelBlue4", 54, 100, 139);
	createdialogcolor("DeepSkyBlue1", 0, 191, 255);
	createdialogcolor("DeepSkyBlue2", 0, 178, 238);
	createdialogcolor("DeepSkyBlue3", 0, 154, 205);
	createdialogcolor("DeepSkyBlue4", 0, 104, 139);
	createdialogcolor("SkyBlue1", 135, 206, 255);
	createdialogcolor("SkyBlue2", 126, 192, 238);
	createdialogcolor("SkyBlue3", 108, 166, 205);
	createdialogcolor("SkyBlue4", 74, 112, 139);
	createdialogcolor("LightSkyBlue1", 176, 226, 255);
	createdialogcolor("LightSkyBlue2", 164, 211, 238);
	createdialogcolor("LightSkyBlue3", 141, 182, 205);
	createdialogcolor("LightSkyBlue4", 96, 123, 139);
	createdialogcolor("SlateGray1", 198, 226, 255);
	createdialogcolor("SlateGray2", 185, 211, 238);
	createdialogcolor("SlateGray3", 159, 182, 205);
	createdialogcolor("SlateGray4", 108, 123, 139);
	createdialogcolor("LightSteelBlue1", 202, 225, 255);
	createdialogcolor("LightSteelBlue2", 188, 210, 238);
	createdialogcolor("LightSteelBlue3", 162, 181, 205);
	createdialogcolor("LightSteelBlue4", 110, 123, 139);
	createdialogcolor("LightBlue1", 191, 239, 255);
	createdialogcolor("LightBlue2", 178, 223, 238);
	createdialogcolor("LightBlue3", 154, 192, 205);
	createdialogcolor("LightBlue4", 104, 131, 139);
	createdialogcolor("LightCyan1", 224, 255, 255);
	createdialogcolor("LightCyan2", 209, 238, 238);
	createdialogcolor("LightCyan3", 180, 205, 205);
	createdialogcolor("LightCyan4", 122, 139, 139);
	createdialogcolor("PaleTurquoise1", 187, 255, 255);
	createdialogcolor("PaleTurquoise2", 174, 238, 238);
	createdialogcolor("PaleTurquoise3", 150, 205, 205);
	createdialogcolor("PaleTurquoise4", 102, 139, 139);
	createdialogcolor("CadetBlue1", 152, 245, 255);
	createdialogcolor("CadetBlue2", 142, 229, 238);
	createdialogcolor("CadetBlue3", 122, 197, 205);
	createdialogcolor("CadetBlue4", 83, 134, 139);
	createdialogcolor("Turquoise1", 0, 245, 255);
	createdialogcolor("Turquoise2", 0, 229, 238);
	createdialogcolor("Turquoise3", 0, 197, 205);
	createdialogcolor("Turquoise4", 0, 134, 139);
	createdialogcolor("Cyan1", 0, 255, 255);
	createdialogcolor("Cyan2", 0, 238, 238);
	createdialogcolor("Cyan3", 0, 205, 205);
	createdialogcolor("Cyan4", 0, 139, 139);
	createdialogcolor("DarkSlateGray1", 151, 255, 255);
	createdialogcolor("DarkSlateGray2", 141, 238, 238);
	createdialogcolor("DarkSlateGray3", 121, 205, 205);
	createdialogcolor("DarkSlateGray4", 82, 139, 139);
	createdialogcolor("Aquamarine1", 127, 255, 212);
	createdialogcolor("Aquamarine2", 118, 238, 198);
	createdialogcolor("Aquamarine3", 102, 205, 170);
	createdialogcolor("Aquamarine4", 69, 139, 116);
	createdialogcolor("DarkSeaGreen1", 193, 255, 193);
	createdialogcolor("DarkSeaGreen2", 180, 238, 180);
	createdialogcolor("DarkSeaGreen3", 155, 205, 155);
	createdialogcolor("DarkSeaGreen4", 105, 139, 105);
	createdialogcolor("SeaGreen1", 84, 255, 159);
	createdialogcolor("SeaGreen2", 78, 238, 148);
	createdialogcolor("SeaGreen3", 67, 205, 128);
	createdialogcolor("SeaGreen4", 46, 139, 87);
	createdialogcolor("PaleGreen1", 154, 255, 154);
	createdialogcolor("PaleGreen2", 144, 238, 144);
	createdialogcolor("PaleGreen3", 124, 205, 124);
	createdialogcolor("PaleGreen4", 84, 139, 84);
	createdialogcolor("SpringGreen1", 0, 255, 127);
	createdialogcolor("SpringGreen2", 0, 238, 118);
	createdialogcolor("SpringGreen3", 0, 205, 102);
	createdialogcolor("SpringGreen4", 0, 139, 69);
	createdialogcolor("Green1", 0, 255, 0);
	createdialogcolor("Green2", 0, 238, 0);
	createdialogcolor("Green3", 0, 205, 0);
	createdialogcolor("Green4", 0, 139, 0);
	createdialogcolor("Chartreuse1", 127, 255, 0);
	createdialogcolor("Chartreuse2", 118, 238, 0);
	createdialogcolor("Chartreuse3", 102, 205, 0);
	createdialogcolor("Chartreuse4", 69, 139, 0);
	createdialogcolor("OliveDrab1", 192, 255, 62);
	createdialogcolor("OliveDrab2", 179, 238, 58);
	createdialogcolor("OliveDrab3", 154, 205, 50);
	createdialogcolor("OliveDrab4", 105, 139, 34);
	createdialogcolor("DarkOliveGreen1", 202, 255, 112);
	createdialogcolor("DarkOliveGreen2", 188, 238, 104);
	createdialogcolor("DarkOliveGreen3", 162, 205, 90);
	createdialogcolor("DarkOliveGreen4", 110, 139, 61);
	createdialogcolor("Khaki1", 255, 246, 143);
	createdialogcolor("Khaki2", 238, 230, 133);
	createdialogcolor("Khaki3", 205, 198, 115);
	createdialogcolor("Khaki4", 139, 134, 78);
	createdialogcolor("LightGoldenrod1", 255, 236, 139);
	createdialogcolor("LightGoldenrod2", 238, 220, 130);
	createdialogcolor("LightGoldenrod3", 205, 190, 112);
	createdialogcolor("LightGoldenrod4", 139, 129, 76);
	createdialogcolor("LightYellow1", 255, 255, 224);
	createdialogcolor("LightYellow2", 238, 238, 209);
	createdialogcolor("LightYellow3", 205, 205, 180);
	createdialogcolor("LightYellow4", 139, 139, 122);
	createdialogcolor("Yellow1", 255, 255, 0);
	createdialogcolor("Yellow2", 238, 238, 0);
	createdialogcolor("Yellow3", 205, 205, 0);
	createdialogcolor("Yellow4", 139, 139, 0);
	createdialogcolor("Gold1", 255, 215, 0);
	createdialogcolor("Gold2", 238, 201, 0);
	createdialogcolor("Gold3", 205, 173, 0);
	createdialogcolor("Gold4", 139, 117, 0);
	createdialogcolor("Goldenrod1", 255, 193, 37);
	createdialogcolor("Goldenrod2", 238, 180, 34);
	createdialogcolor("Goldenrod3", 205, 155, 29);
	createdialogcolor("Goldenrod4", 139, 105, 20);
	createdialogcolor("DarkGoldenrod1", 255, 185, 15);
	createdialogcolor("DarkGoldenrod2", 238, 173, 14);
	createdialogcolor("DarkGoldenrod3", 205, 149, 12);
	createdialogcolor("DarkGoldenrod4", 139, 101, 8);
	createdialogcolor("RosyBrown1", 255, 193, 193);
	createdialogcolor("RosyBrown2", 238, 180, 180);
	createdialogcolor("RosyBrown3", 205, 155, 155);
	createdialogcolor("RosyBrown4", 139, 105, 105);
	createdialogcolor("IndianRed1", 255, 106, 106);
	createdialogcolor("IndianRed2", 238, 99, 99);
	createdialogcolor("IndianRed3", 205, 85, 85);
	createdialogcolor("IndianRed4", 139, 58, 58);
	createdialogcolor("Sienna1", 255, 130, 71);
	createdialogcolor("Sienna2", 238, 121, 66);
	createdialogcolor("Sienna3", 205, 104, 57);
	createdialogcolor("Sienna4", 139, 71, 38);
	createdialogcolor("Burlywood1", 255, 211, 155);
	createdialogcolor("Burlywood2", 238, 197, 145);
	createdialogcolor("Burlywood3", 205, 170, 125);
	createdialogcolor("Burlywood4", 139, 115, 85);
	createdialogcolor("Wheat1", 255, 231, 186);
	createdialogcolor("Wheat2", 238, 216, 174);
	createdialogcolor("Wheat3", 205, 186, 150);
	createdialogcolor("Wheat4", 139, 126, 102);
	createdialogcolor("Tan1", 255, 165, 79);
	createdialogcolor("Tan2", 238, 154, 73);
	createdialogcolor("Tan3", 205, 133, 63);
	createdialogcolor("Tan4", 139, 90, 43);
	createdialogcolor("Chocolate1", 255, 127, 36);
	createdialogcolor("Chocolate2", 238, 118, 33);
	createdialogcolor("Chocolate3", 205, 102, 29);
	createdialogcolor("Chocolate4", 139, 69, 19);
	createdialogcolor("Firebrick1", 255, 48, 48);
	createdialogcolor("Firebrick2", 238, 44, 44);
	createdialogcolor("Firebrick3", 205, 38, 38);
	createdialogcolor("Firebrick4", 139, 26, 26);
	createdialogcolor("Brown1", 255, 64, 64);
	createdialogcolor("Brown2", 238, 59, 59);
	createdialogcolor("Brown3", 205, 51, 51);
	createdialogcolor("Brown4", 139, 35, 35);
	createdialogcolor("Salmon1", 255, 140, 105);
	createdialogcolor("Salmon2", 238, 130, 98);
	createdialogcolor("Salmon3", 205, 112, 84);
	createdialogcolor("Salmon4", 139, 76, 57);
	createdialogcolor("LightSalmon1", 255, 160, 122);
	createdialogcolor("LightSalmon2", 238, 149, 114);
	createdialogcolor("LightSalmon3", 205, 129, 98);
	createdialogcolor("LightSalmon4", 139, 87, 66);
	createdialogcolor("Orange1", 255, 165, 0);
	createdialogcolor("Orange2", 238, 154, 0);
	createdialogcolor("Orange3", 205, 133, 0);
	createdialogcolor("Orange4", 139, 90, 0);
	createdialogcolor("DarkOrange1", 255, 127, 0);
	createdialogcolor("DarkOrange2", 238, 118, 0);
	createdialogcolor("DarkOrange3", 205, 102, 0);
	createdialogcolor("DarkOrange4", 139, 69, 0);
	createdialogcolor("Coral1", 255, 114, 86);
	createdialogcolor("Coral2", 238, 106, 80);
	createdialogcolor("Coral3", 205, 91, 69);
	createdialogcolor("Coral4", 139, 62, 47);
	createdialogcolor("Tomato1", 255, 99, 71);
	createdialogcolor("Tomato2", 238, 92, 66);
	createdialogcolor("Tomato3", 205, 79, 57);
	createdialogcolor("Tomato4", 139, 54, 38);
	createdialogcolor("OrangeRed1", 255, 69, 0);
	createdialogcolor("OrangeRed2", 238, 64, 0);
	createdialogcolor("OrangeRed3", 205, 55, 0);
	createdialogcolor("OrangeRed4", 139, 37, 0);
	createdialogcolor("Red1", 255, 0, 0);
	createdialogcolor("Red2", 238, 0, 0);
	createdialogcolor("Red3", 205, 0, 0);
	createdialogcolor("Red4", 139, 0, 0);
	createdialogcolor("DeepPink1", 255, 20, 147);
	createdialogcolor("DeepPink2", 238, 18, 137);
	createdialogcolor("DeepPink3", 205, 16, 118);
	createdialogcolor("DeepPink4", 139, 10, 80);
	createdialogcolor("HotPink1", 255, 110, 180);
	createdialogcolor("HotPink2", 238, 106, 167);
	createdialogcolor("HotPink3", 205, 96, 144);
	createdialogcolor("HotPink4", 139, 58, 98);
	createdialogcolor("Pink1", 255, 181, 197);
	createdialogcolor("Pink2", 238, 169, 184);
	createdialogcolor("Pink3", 205, 145, 158);
	createdialogcolor("Pink4", 139, 99, 108);
	createdialogcolor("LightPink1", 255, 174, 185);
	createdialogcolor("LightPink2", 238, 162, 173);
	createdialogcolor("LightPink3", 205, 140, 149);
	createdialogcolor("LightPink4", 139, 95, 101);
	createdialogcolor("PaleVioletRed1", 255, 130, 171);
	createdialogcolor("PaleVioletRed2", 238, 121, 159);
	createdialogcolor("PaleVioletRed3", 205, 104, 137);
	createdialogcolor("PaleVioletRed4", 139, 71, 93);
	createdialogcolor("Maroon1", 255, 52, 179);
	createdialogcolor("Maroon2", 238, 48, 167);
	createdialogcolor("Maroon3", 205, 41, 144);
	createdialogcolor("Maroon4", 139, 28, 98);
	createdialogcolor("VioletRed1", 255, 62, 150);
	createdialogcolor("VioletRed2", 238, 58, 140);
	createdialogcolor("VioletRed3", 205, 50, 120);
	createdialogcolor("VioletRed4", 139, 34, 82);
	createdialogcolor("Magenta1", 255, 0, 255);
	createdialogcolor("Magenta2", 238, 0, 238);
	createdialogcolor("Magenta3", 205, 0, 205);
	createdialogcolor("Magenta4", 139, 0, 139);
	createdialogcolor("Orchid1", 255, 131, 250);
	createdialogcolor("Orchid2", 238, 122, 233);
	createdialogcolor("Orchid3", 205, 105, 201);
	createdialogcolor("Orchid4", 139, 71, 137);
	createdialogcolor("Plum1", 255, 187, 255);
	createdialogcolor("Plum2", 238, 174, 238);
	createdialogcolor("Plum3", 205, 150, 205);
	createdialogcolor("Plum4", 139, 102, 139);
	createdialogcolor("MediumOrchid1", 224, 102, 255);
	createdialogcolor("MediumOrchid2", 209, 95, 238);
	createdialogcolor("MediumOrchid3", 180, 82, 205);
	createdialogcolor("MediumOrchid4", 122, 55, 139);
	createdialogcolor("DarkOrchid1", 191, 62, 255);
	createdialogcolor("DarkOrchid2", 178, 58, 238);
	createdialogcolor("DarkOrchid3", 154, 50, 205);
	createdialogcolor("DarkOrchid4", 104, 34, 139);
	createdialogcolor("Purple1", 155, 48, 255);
	createdialogcolor("Purple2", 145, 44, 238);
	createdialogcolor("Purple3", 125, 38, 205);
	createdialogcolor("Purple4", 85, 26, 139);
	createdialogcolor("MediumPurple1", 171, 130, 255);
	createdialogcolor("MediumPurple2", 159, 121, 238);
	createdialogcolor("MediumPurple3", 137, 104, 205);
	createdialogcolor("MediumPurple4", 93, 71, 139);
	createdialogcolor("Thistle1", 255, 225, 255);
	createdialogcolor("Thistle2", 238, 210, 238);
	createdialogcolor("Thistle3", 205, 181, 205);
	createdialogcolor("Thistle4", 139, 123, 139);
	createdialogcolor("grey11", 28, 28, 28);
	createdialogcolor("grey21", 54, 54, 54);
	createdialogcolor("grey31", 79, 79, 79);
	createdialogcolor("grey41", 105, 105, 105);
	createdialogcolor("grey51", 130, 130, 130);
	createdialogcolor("grey61", 156, 156, 156);
	createdialogcolor("grey71", 181, 181, 181);
	createdialogcolor("gray81", 207, 207, 207);
	createdialogcolor("gray91", 232, 232, 232);
	createdialogcolor("DarkGrey", 169, 169, 169);
	createdialogcolor("DarkBlue", 0, 0, 139);
	createdialogcolor("DarkCyan", 0, 139, 139);
	createdialogcolor("DarkMagenta", 139, 0, 139);
	createdialogcolor("DarkRed", 139, 0, 0);
	createdialogcolor("LightGreen", 144, 238, 144);

	//remove later
	
	motion_log.open("motion_log.txt");
	wave_log.open("wave_log.txt");
}

string toUpper(string str)
{
	for (int i = 0; i<str.size(); i++) if (str[i] >= 'a' && str[i] <= 'z') str[i] += 'A' - 'a';
	return str;
}

int getdialogcolor(string get_name)
{
	for (int i = 0; i < dialogcolorS.size(); i++)
	{
		if (toUpper(dialogcolorS[i].name) == toUpper(get_name))
		{
			return i;
		}
	}
	return -1;
}

struct gameWorldObject
{
	double x, y, scalex, scaley, fps, angle, speed, radius;
	//sndtype: 0 - состояние звука никак не меняется, 1 - переключается при взаимодействии
	//2 - включается только один раз, 3 - привязан к коллизии 
	//animationtype - то же самое, но для спрайтов
	int direction, snd, sndtype, sndactive, playsnd, animationtype, underobject, bonetype, gotoroom;
	vector <int> sprites;
	vector <int> sprite_actives;
	string info;
	vector <vector <string>> flavor_texts;
	vector <vector <string>> dialogues;
	bool info_count, solid, controllable, sndloop, spriteloop, underplayer, isportal;
};

vector<gameWorldObject> gameWorldObjectS;

int creategameWorldObject(double get_x, double get_y, int get_direction, int get_snd, int get_sndtype, int get_sndactive, int get_animationtype, int get_underobject, int get_bonetype, int get_gotoroom, double get_fps, double get_angle, double get_speed, double get_radius, double get_scalex, double get_scaley, vector <int> get_sprites, vector <int> get_sprite_actives, string get_info, vector <vector <string>> get_flavor_texts, bool get_info_count, bool get_solid, bool get_controllable, bool get_sndloop, bool get_spriteloop, bool get_underplayer, bool get_isportal)
{
	gameWorldObject sample;
	sample.x = get_x;
	sample.y = get_y;
	sample.direction = get_direction;
	sample.snd = get_snd;
	sample.sndtype = get_sndtype;
	sample.sndactive = get_sndactive;
	sample.animationtype = get_animationtype;
	sample.underobject = get_underobject;
	sample.bonetype = get_bonetype;
	sample.gotoroom = get_gotoroom;
	sample.fps = get_fps;
	sample.angle = get_angle;
	sample.speed = get_speed;
	sample.radius = get_radius;
	sample.scalex = get_scalex;
	sample.scaley = get_scaley;
	sample.sprites = get_sprites;
	sample.sprite_actives = get_sprite_actives;
	sample.info = get_info;
	sample.flavor_texts = get_flavor_texts;
	if (sample.flavor_texts.size() != 0)
	{
		for (int i = 0; i < sample.flavor_texts.size(); i++)
		{
			vector <string> texts;
			if (sample.flavor_texts[i].size() != 0)
			{
				for (int j = 0; j < sample.flavor_texts[i].size(); j++)
				{
					texts.push_back(initiateDialog(sample.flavor_texts[i][j]));
				}
			}
			sample.dialogues.push_back(texts);
		}
	}
	sample.info_count = get_info_count;
	sample.solid = get_solid;
	sample.controllable = get_controllable;
	sample.sndloop = get_sndloop;
	sample.spriteloop = get_spriteloop;
	sample.underplayer = get_underplayer;
	sample.isportal = get_isportal;
	gameWorldObjectS.push_back(sample);
	return gameWorldObjectS.size() - 1;
}

int HowManyGameWorldObjects()
{
	return gameWorldObjectS.size();
}

void DeleteGameWorldObjects()
{
	gameWorldObjectS.clear();
}

void directionDetect(int objectid, int ghostid)
{
	for (int i = 0; i < gameWorldObjectS[objectid].sprites.size(); i++)
	{
		//agk::Print(agk::GetSpriteX(gameWorldObjectS[objectid].sprites[i]));
		//agk::Print(agk::GetSpriteY(gameWorldObjectS[objectid].sprites[i]));
		//agk::Print(agk::GetSpriteCurrentFrame(gameWorldObjectS[objectid].sprites[i]));
		//agk::Print(agk::GetSpritePlaying(gameWorldObjectS[objectid].sprites[i]));
	}
	for (int i = 0; i < gameWorldObjectS[ghostid].sprites.size(); i++)
	{
		//agk::Print(agk::GetSpriteX(gameWorldObjectS[ghostid].sprites[i]));
		//agk::Print(agk::GetSpriteY(gameWorldObjectS[ghostid].sprites[i]));
		//agk::Print(agk::GetSpriteCurrentFrame(gameWorldObjectS[ghostid].sprites[i]));
		//agk::Print(agk::GetSpritePlaying(gameWorldObjectS[ghostid].sprites[i]));
	
	}
	//agk::Print(gameWorldObjectS[objectid].direction);
}

void setObjectGroupLocationAndUpdate(vector <int> objects, int startx, int starty, vector<vector<int>> coordinates)
{
	if (objects.size() != coordinates.size())
		return;
	for (int i = 0; i < objects.size(); i++)
	{
		if (coordinates[i].size() != 2)
			return;
		gameWorldObjectS[objects[i]].x = startx + coordinates[i][0];
		gameWorldObjectS[objects[i]].y = starty + coordinates[i][1];
		gameObjectUpdate(objects[i], -1);
	}
}

void switchAnimation(int objectid, int flag)
{
	if (gameWorldObjectS[objectid].animationtype == 3)
	{
		if ((gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] == 0) && (flag == 1))
		{
			agk::PlaySprite(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], gameWorldObjectS[objectid].fps, 0);
			gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] = 1;
		}
		if (agk::GetSpriteCurrentFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]) == agk::GetSpriteFrameCount(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]))
		{
			agk::StopSprite(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]);
			agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
			gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] = 0;
		}
	}
	else
	{
		if ((gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] != flag) && (gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] != 2))
		{
			if (flag == 0)
			{
				agk::StopSprite(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]);
				gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] = 0;
			}
			else
			{
				if (agk::GetSpriteCurrentFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]) == 1)
					agk::PlaySprite(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], gameWorldObjectS[objectid].fps, gameWorldObjectS[objectid].spriteloop);
				else
					agk::ResumeSprite(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]);
				gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] = 1;
			}
		}
		if (gameWorldObjectS[objectid].animationtype == 2)
			gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] = 2;
	}
}

void switchSound(int objectid, int flag)
{
	if (gameWorldObjectS[objectid].sndtype == 3)
	{
		if ((gameWorldObjectS[objectid].sndactive == 0) && (flag == 1))
		{
			gameWorldObjectS[objectid].playsnd = agk::PlaySound(gameWorldObjectS[objectid].snd);
			gameWorldObjectS[objectid].sndactive = 1;
		}
		if (agk::GetSoundInstancePlaying(gameWorldObjectS[objectid].playsnd) == 0)
		{
			agk::StopSoundInstance(gameWorldObjectS[objectid].playsnd);
			gameWorldObjectS[objectid].sndactive = 0;
		}
	}
	else
	{
		if ((gameWorldObjectS[objectid].sndactive != flag) && (gameWorldObjectS[objectid].sndactive != 2))
		{
			if (flag == 0)
			{
				agk::StopSoundInstance(gameWorldObjectS[objectid].playsnd);
				gameWorldObjectS[objectid].sndactive = 0;
			}
			else
				if (flag == 1)
				{
					if(!agk::GetSoundInstancePlaying(gameWorldObjectS[objectid].playsnd))
					gameWorldObjectS[objectid].playsnd = agk::PlaySound(gameWorldObjectS[objectid].snd, 100, gameWorldObjectS[objectid].sndloop);
					gameWorldObjectS[objectid].sndactive = 1;
				}
		}
		if (gameWorldObjectS[objectid].sndtype == 2)
			gameWorldObjectS[objectid].sndactive = 2;
	}
}

int getStateCount(int objectid)
{
	size_t info_index = state.find(gameWorldObjectS[objectid].info);
	if (info_index != string::npos)
	{
		size_t delimeter_index = state.find(";", info_index);
		size_t number_index = info_index + gameWorldObjectS[objectid].info.length() + 1;
		return stoi(state.substr(number_index, delimeter_index - number_index));
	}
	else
		return -1;
}

void stateUpdate(int objectid)
{
	if (touched == 0)
		if (gameWorldObjectS[objectid].info_count == false)
		{
			size_t index = state.find(gameWorldObjectS[objectid].info);
			if (index != string::npos)
			{
				state.replace(index, gameWorldObjectS[objectid].info.length() + 1, "");
			}
			else
			{
				state += gameWorldObjectS[objectid].info + ";";
			}
		}
		else
		{
			size_t info_index = state.find(gameWorldObjectS[objectid].info);
			if (info_index != string::npos)
			{
				size_t delimeter_index = state.find(";", info_index);
				size_t number_index = info_index + gameWorldObjectS[objectid].info.length() + 1;
				int number = stoi(state.substr(number_index, delimeter_index - number_index)) + 1;
				state.replace(number_index, delimeter_index - number_index, to_string(number));
			}
			else
			{
				state += gameWorldObjectS[objectid].info + "_1;";
			}
		}
}

void narraInitiate()
{
	narrastorage = Astorage(); //создать хранилище 
	Lstorage( //загрузить изображения в хранилище
		narrastorage, //id хранилища
		{ 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
		50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
		72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,
		92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126 }, //коды ASCII символов, которые нужно загрузить
		"standard", //название шрифта
		1 //количество кадров, которое нужно загрузить
	);
	narrasound = agk::LoadSound("resources/narrator.wav");
}

string initiateDialog(string text)
{
	string narradialog;

	vector <string> tokens;

	vector<string> dialoglines;
	vector<int> dialogfragwaits;
	vector<bool> dialoglinebreaks;
	vector<int> dialogshakes;
	vector<int> dialogspritewaits;
	vector<int> dialogdistances;
	vector<int> dialogsounds;
	vector <vector <int> > dialog_r;
	vector <vector <int> > dialog_g;
	vector <vector <int> > dialog_b;
	vector <int> dialogcolorwaits;

	char * c_text = new char[text.size() + 1];
	strcpy(c_text, text.c_str());
	
	
	char *p = strtok(c_text,"<>");
	while (p != 0)
	{
		string token(p);
		tokens.push_back(token);
		p = strtok(NULL, "<>");
	}
	
	//ofstream output, debug;
	//output.open("resources/tagstest.txt");
	//debug.open("resources/what_the_hell_going_on_can_someone_tell_me_please.txt");
	
	//Инициализация значений цветов по умолчанию и оперативных
	int def_r = 255;
	int def_g = 255;
	int def_b = 255;
	int r = def_r;
	int g = def_g;
	int b = def_b;

	//Инициализация задержки вывода между фрагментами - по умолчанию и оперативной
	int def_fragwait = 5;
	int fragwait = def_fragwait;

	//Надо ли переносить строку - по умолчанию и оперативный
	bool def_linebreak = false;
	bool linebreak = def_linebreak;

	int index = -1;

	//Если токенов не 0 (хотя хз как их может быть 0, но лучше перестраховаться :3), то
	if (tokens.size() != 0)
	{
		for (int i = 0; i < tokens.size(); i++)
		{
			//Проверяем, является ли следующим токеном тег "wait". Ибо это играет роль для предыдущего токена.
			if (i < tokens.size() - 1)
			{
				size_t pos = tokens[i + 1].find("timewait=", 0);
				if (pos != string::npos)
				{
					size_t firstpart = tokens[i + 1].find("'", pos + 9);
					size_t secondpart = tokens[i + 1].find(" sec'", firstpart + 1);
					//Надо проверить, что все введено корректно (защита от дурака в бытовых условиях :3)
					if (firstpart != string::npos && secondpart != string::npos)
					{
						//Если мы пришли сюда, то тег "wait" оформлен корректно. Далее нам надо считать число шагов исходя из секунд
						fragwait = stoi(tokens[i + 1].substr(firstpart + 1, secondpart - firstpart - 1)) * 60;
					}
					else
					{
						if (firstpart != string::npos && secondpart == string::npos)
						{
							//Если мы пришли сюда, то, вероятно, значение задержки было введено в шагах
							secondpart = tokens[i + 1].find("'", firstpart + 1);
							fragwait = stoi(tokens[i + 1].substr(firstpart + 1, secondpart - firstpart - 1));
						}
					}
				}
				else
				{
					if (fragwait != def_fragwait)
						fragwait = def_fragwait;
				}
			}
			//Проверяем, не является ли токен тегом linebreak
			if (tokens[i] == "linebreak")
			{
				linebreak = true;
				index = i;
			}
			else
			{
				if(i != index + 1)
					linebreak = def_linebreak;
			}
			//Проверяем, вдруг у нас <textcolor> или </textcolor>
			size_t pos = tokens[i].find("textcolor");
			if (pos != string::npos)
			{
				//Проверяем в лоб - вдруг у нас </textcolor>?
				if (tokens[i] == "/textcolor")
				{
					r = def_r;
					g = def_g;
					b = def_b;
				}
				else
				{
					string colorstring = "nonecolor";
					size_t firstpart = tokens[i].find("='", pos + 9);
					size_t secondpart = tokens[i].find("'", firstpart + 2);
					if(firstpart != string::npos && secondpart != string::npos)
						colorstring = tokens[i].substr(firstpart + 2, secondpart - firstpart - 2);
					size_t firstcomma = colorstring.find(",");
					if (firstcomma == string::npos)
					{
						int color = getdialogcolor(colorstring);
						if (color != -1)
						{
							r = dialogcolorS[color].r;
							g = dialogcolorS[color].g;
							b = dialogcolorS[color].b;
						}
					}
					else
					{
						size_t secondcomma = colorstring.find(",", firstcomma + 1);
						if (secondcomma != string::npos)
						{
							r = stoi(colorstring.substr(0, firstcomma));
							g = stoi(colorstring.substr(firstcomma + 1, secondcomma - firstcomma - 1));
							b = stoi(colorstring.substr(secondcomma + 1, colorstring.size() - secondcomma - 1));
						}
					}
				}
			}
			if ((tokens[i].find("textcolor") == string::npos) && (tokens[i].find("linebreak") == string::npos) && (tokens[i].find("timewait") == string::npos))
			{				
				dialoglines.push_back(tokens[i]);
				dialogfragwaits.push_back(fragwait);
				dialoglinebreaks.push_back(linebreak);
				dialogshakes.push_back(0);
				dialogspritewaits.push_back(5);
				dialogdistances.push_back(5);
				dialogsounds.push_back(narrasound);
				dialog_r.push_back({ r });
				dialog_g.push_back({ g });
				dialog_b.push_back({ b });
				dialogcolorwaits.push_back({ 1 });
			}
		}
	}

	narradialog = lines(

	{ dialoglines },

	{ dialogfragwaits },						//задержка после отображения фрагмента

	{ dialoglinebreaks },		//фрагмент начинает параграф

	{ dialogshakes },						//дрожание фрагмента (5)
	{ dialogspritewaits },						//замедление фрагмента
	{ dialogdistances },						//разряженность фрагмента (1)
	{ dialogsounds },			//звук фрагмента (AGK)

	{ dialog_r },	//цикл r фрагмента
	{ dialog_g }, //цикл g фрагмента
	{ dialog_b }, //цикл b фрагмента
	{ dialogcolorwaits },						//задержка после изменения цвета фрагмента

		50,									//y первого фрагмента
		50,									//x первого фрагмента
		5 * 2 + 16 + 12,							//сдвиг остальных фрагментов (2)
		1000,								//критический x

		50,									//расстояние между строками (3)
		1,									//размер (4)
		true,								//изменение (1), (2) и (3) вместе с (4)

		1,									//задержка после смещения при дрожании
		50,									//количество смещений в одном цикле дрожания
		false,								//изменение (5) вместе с (4)

		narrastorage,							//хранилище
		1,									//количество кадров для загрузки из хранилища
		1,									//задержка после смены кадра

		{ 32 }								//ASCII коды символов без озвучки

	);

	return narradialog;
}

int randomBetweenTwoNumbers(int n1, int n2)
{
	int max, min;
	if (n1 > n2)
	{
		max = n1;
		min = n2;
	}
	else
	{
		max = n2;
		min = n1;
	}
	return rand() % (max - min + 1) + min;
}

int arrowButtonsPressedCount()
{
	int count = 0;
	if(hold("down"))
		count++;
	if (hold("left"))
		count++;
	if (hold("right"))
		count++;
	if (hold("up"))
		count++;
	return count;
}

int directionStringToInt(string direction)
{
	if (direction == "down") return 0;
	if (direction == "left") return 1;
	if (direction == "right") return 2;
	if (direction == "up") return 3;
	return -1;
}

bool directionsAreOpposite(int d1, int d2)
{
	if ((d1 == 0 && d2 == 3) || (d1 == 3 && d2 == 0) || (d1 == 1 && d2 == 2) || (d1 == 2 && d2 == 1))
		return true;
	return false;
}

int resultDirection(int d1, int d2, int d3)
{
	int result = -1;
	for (int i = 0; i < 4; i++)
	{
		if (i != d1 && i != d2 && i != d3)
			switch (i)
			{
				case 0:
					result = 3; break;
				case 1:
					result = 2; break;
				case 2:
					result = 1; break;
				case 3:
					result = 0; break;
			}
	}
	return result;
}

int oppositeDirection(int direction)
{
	int result = -1;
	switch (direction)
	{
		case 0:
			result = 3; break;
		case 1:
			result = 2; break;
		case 2:
			result = 1; break;
		case 3:
			result = 0; break;
	}
	return result;
}

void ghostGoHome(int ghostid)
{
	agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[ghostid].x, gameWorldObjectS[ghostid].y);
}

void moveGhost(int ghostid, int direction)
{
	switch (direction)
	{
		case 0:
		{
			agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], agk::GetSpriteX(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]), agk::GetSpriteY(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]) + gameWorldObjectS[ghostid].speed);
		} break;
		case 1:
		{
			agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], agk::GetSpriteX(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]) - gameWorldObjectS[ghostid].speed, agk::GetSpriteY(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]));
		} break;
		case 2:
		{
			agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], agk::GetSpriteX(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]) + gameWorldObjectS[ghostid].speed, agk::GetSpriteY(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]));
		} break;
		case 3:
		{
			agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], agk::GetSpriteX(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]), agk::GetSpriteY(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]) - gameWorldObjectS[ghostid].speed);
		} break;
	}
}

void moveGhost(int ghostid, double x, double y)
{
	agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], agk::GetSpriteX(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]) + x, agk::GetSpriteY(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction]) + y);
}

int objectWeCollidedWith(int ghostid)
{
	int resultobject = -1;
	agk::StepPhysics(0.0001);
	for (int i = 0; i < gameWorldObjectS.size(); i++)
	{
		if (agk::GetPhysicsCollision(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[i].sprites[gameWorldObjectS[i].direction]))
		{
			resultobject = i;
			break;
		}
	}
	objcol = resultobject;
	return resultobject;
}

bool moveIsPossible(int ghostid)
{
	bool solid = false;
	int collideobject = objectWeCollidedWith(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].solid == true)
			solid = true;
	}
	else
		return true;
	if (solid == false)
		return true;
	return false;
}

bool moveIsPossible(int ghostid, int direction)
{
	bool solid = false;
	moveGhost(ghostid, direction);
	int collideobject = objectWeCollidedWith(ghostid);
	ghostGoHome(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].solid == true)
			solid = true;
	}
	else
		return true;
	if (solid == false)
		return true;
	return false;
}

bool moveIsPossible(int ghostid, double x, double y) //изменить на оную с координатами
{
	bool solid = false;
	moveGhost(ghostid, x, y);
	int collideobject = objectWeCollidedWith(ghostid);
	ghostGoHome(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].solid == true)
			solid = true;
	}
	else
		return true;
	if (solid == false)
		return true;
	return false;
}

void moveCharacter(int objectid, int ghostid, int direction)
{
	switch (direction)
	{
		case 0: //down
		{
			gameWorldObjectS[ghostid].y += gameWorldObjectS[ghostid].speed;
			gameWorldObjectS[objectid].y += gameWorldObjectS[objectid].speed;
		} break;
		case 1: //left
		{
			gameWorldObjectS[ghostid].x -= gameWorldObjectS[ghostid].speed;
			gameWorldObjectS[objectid].x -= gameWorldObjectS[objectid].speed;
		} break;
		case 2: //right
		{
			gameWorldObjectS[ghostid].x += gameWorldObjectS[ghostid].speed;
			gameWorldObjectS[objectid].x += gameWorldObjectS[objectid].speed;
		} break;
		case 3: //up
		{
			gameWorldObjectS[ghostid].y -= gameWorldObjectS[ghostid].speed;
			gameWorldObjectS[objectid].y -= gameWorldObjectS[objectid].speed;
		} break;
	}

	int collideobject = objectWeCollidedWith(ghostid);
	if (collideobject != -1)
	{
		for (int i = 0; i < gameWorldObjectS.size(); i++)
		{
			if (i == collideobject)
			{
				if (gameWorldObjectS[i].sndtype == 3)
					switchSound(i, 1);
				if (gameWorldObjectS[i].animationtype == 3)
					switchAnimation(i, 1);
			}
			else
			{
				if (gameWorldObjectS[i].sndtype == 3)
					switchSound(i, 0);
				if (gameWorldObjectS[i].animationtype == 3)
					switchAnimation(i, 0);
			}
		}
	}
}

void moveCharacter(int objectid, int ghostid, double x, double y)
{
	gameWorldObjectS[ghostid].x += x;
	gameWorldObjectS[objectid].x += x;
	gameWorldObjectS[ghostid].y += y;
	gameWorldObjectS[objectid].y += y;

	int collideobject = objectWeCollidedWith(ghostid);
	if (collideobject != -1)
	{
		for (int i = 0; i < gameWorldObjectS.size(); i++)
		{
			if (i == collideobject)
			{
				if (gameWorldObjectS[i].sndtype == 3)
					switchSound(i, 1);
				if (gameWorldObjectS[i].animationtype == 3)
					switchAnimation(i, 1);
			}
			else
			{
				if (gameWorldObjectS[i].sndtype == 3)
					switchSound(i, 0);
				if (gameWorldObjectS[i].animationtype == 3)
					switchAnimation(i, 0);
			}
		}
	}
}

string frontAndBack(int objectid, int objectToCheck)
{
	
	firstpointX = agk::GetWorldXFromSprite(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction], -agk::GetSpriteWidth(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]) / 2, 0);
	firstpointY = agk::GetWorldYFromSprite(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction], -agk::GetSpriteWidth(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]) / 2, 0);
	secondpointX = agk::GetWorldXFromSprite(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction], agk::GetSpriteWidth(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]) / 2, 0);
	secondpointY = agk::GetWorldYFromSprite(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction], agk::GetSpriteWidth(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]) / 2, 0);
	
	X1 = secondpointX - firstpointX;
	Y1 = secondpointY - firstpointY;
	X2 = agk::GetSpriteXByOffset(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]) - firstpointX;
	Y2 = agk::GetSpriteYByOffset(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]) - firstpointY;
	result = X1*Y2 - X2*Y1;

	if (result > 0)
		return "front";
	else
		if (result < 0)
			return "back";
		else
			return "collinear";
}

double getAngle(int objectid, int objectToCheck)
{
	if (frontAndBack(objectid, objectToCheck) == "front")
		return gameWorldObjectS[objectToCheck].angle;
	else
		return 180 - gameWorldObjectS[objectToCheck].angle;
}

bool isNecessaryForGlidingToBeReversed(int objectid, double angle, int direction)
{
	if (angle > 90)
		angle = 180 - angle;

	double step = gameWorldObjectS[objectid].speed;

	double angleSinus = sin(angle * PI / 180);
	double angleCosine = cos(angle * PI / 180);

	double displacementSinus = step / angleSinus;
	double displacementCosine = step / angleCosine;

	if (displacementSinus < displacementCosine)
	{
		if (direction == 0 || direction == 3)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (direction == 1 || direction == 2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

double getBias(int objectid, double angle, int direction)
{
	if (angle > 90)
		angle = 180 - angle;
	double step = gameWorldObjectS[objectid].speed;
	if (direction == 0 || direction == 3)
	{
		double angleSinus = sin(angle * PI / 180);
		double displacement = step / angleSinus;
		return sqrt(displacement * displacement - step * step);
	}
	else
		if (direction == 1 || direction == 2)
		{
			double angleCosine = cos(angle * PI / 180);
			double displacement = step / angleCosine;
			return sqrt(displacement * displacement - step * step);
		}
}

bool isPossibleToGlide(int objectid, int ghostid, int direction)
{
	moveGhost(ghostid, direction);
	int collideobject = objectWeCollidedWith(ghostid);
	ghostGoHome(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].bonetype == 1)
		{
			double angle = getAngle(objectid, collideobject);
			switch (direction)
			{
				case 0:
				{
					if (getAngle(objectid, collideobject) > 90 && getAngle(objectid, collideobject) < 180)
					{
						if (frontAndBack(objectid, collideobject) == "front")
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, -getBias(objectid, angle, direction), gameWorldObjectS[objectid].speed))
									return true;
							}
							else
							{
								if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, getBias(objectid, angle, 1)))
									return true;
							}
						}
						else
							if (frontAndBack(objectid, collideobject) == "back")
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, getBias(objectid, angle, direction), gameWorldObjectS[objectid].speed))
										return true;
								}
								else
								{
									if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, getBias(objectid, angle, 2)))
										return true;
								}
							}
					}
				} break;
				case 1:
				{
					if (frontAndBack(objectid, collideobject) == "back")
					{
						if (getAngle(objectid, collideobject) > 0 && getAngle(objectid, collideobject) < 90)
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, getBias(objectid, angle, direction)))
									return true;
							}
							else
							{
								if (moveIsPossible(ghostid, -getBias(objectid, angle, 0), gameWorldObjectS[objectid].speed))
									return true;
							}
						}
						else
						{
							if (getAngle(objectid, collideobject) > 90 && getAngle(objectid, collideobject) < 180)
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, -getBias(objectid, angle, direction)))
										return true;
								}
								else
								{
									if (moveIsPossible(ghostid, -getBias(objectid, angle, 3), -gameWorldObjectS[objectid].speed))
										return true;
								}
							}
						}
					}
				} break;
				case 2:
				{
					if (frontAndBack(objectid, collideobject) == "front")
					{
						if (getAngle(objectid, collideobject) > 0 && getAngle(objectid, collideobject) < 90)
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, getBias(objectid, angle, direction)))
									return true;
							}
							else
							{
								if (moveIsPossible(ghostid, getBias(objectid, angle, 0), gameWorldObjectS[objectid].speed))
									return true;
							}
						}
						else
						{
							if (getAngle(objectid, collideobject) > 90 && getAngle(objectid, collideobject) < 180)
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, -getBias(objectid, angle, direction)))
										return true;
								}
								else
								{
									if (moveIsPossible(ghostid, getBias(objectid, angle, 3), -gameWorldObjectS[objectid].speed))
										return true;
								}
							}
						}
					}
				} break;
				case 3:
				{
					if (getAngle(objectid, collideobject) > 0 && getAngle(objectid, collideobject) < 90)
					{
						if (frontAndBack(objectid, collideobject) == "front")
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, -getBias(objectid, angle, direction), -gameWorldObjectS[objectid].speed))
									return true;
							}
							else
							{
								if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, -getBias(objectid, angle, 1)))
									return true;
							}
						}
						else
							if (frontAndBack(objectid, collideobject) == "back")
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, getBias(objectid, angle, direction), -gameWorldObjectS[objectid].speed))
										return true;
								}
								else
								{
									if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, -getBias(objectid, angle, 2)))
										return true;
								}
							}
					}
				} break;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void glideCharacter(int objectid, int ghostid, int direction)
{
	moveGhost(ghostid, direction);
	int collideobject = objectWeCollidedWith(ghostid);
	ghostGoHome(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].bonetype == 1)
		{
			double angle = getAngle(objectid, collideobject);
			switch (direction)
			{
				case 0:
				{
					if (getAngle(objectid, collideobject) > 90 && getAngle(objectid, collideobject) < 180)
					{
						if (frontAndBack(objectid, collideobject) == "front")
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, -getBias(objectid, angle, direction), gameWorldObjectS[objectid].speed))
									moveCharacter(objectid, ghostid, -getBias(objectid, angle, direction), gameWorldObjectS[objectid].speed);
							}
							else
							{
								if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, getBias(objectid, angle, 1)))
									moveCharacter(objectid, ghostid, -gameWorldObjectS[objectid].speed, getBias(objectid, angle, 1));
							}
						}
						else
							if (frontAndBack(objectid, collideobject) == "back")
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, getBias(objectid, angle, direction), gameWorldObjectS[objectid].speed))
										moveCharacter(objectid, ghostid, getBias(objectid, angle, direction), gameWorldObjectS[objectid].speed);
								}
								else
								{
									if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, getBias(objectid, angle, 2)))
										moveCharacter(objectid, ghostid, gameWorldObjectS[objectid].speed, getBias(objectid, angle, 2));
								}
							}
					}
				} break;
				case 1:
				{
					if (frontAndBack(objectid, collideobject) == "back")
					{
						if (getAngle(objectid, collideobject) > 0 && getAngle(objectid, collideobject) < 90)
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, getBias(objectid, angle, direction)))
									moveCharacter(objectid, ghostid, -gameWorldObjectS[objectid].speed, getBias(objectid, angle, direction));
							}
							else
							{
								if (moveIsPossible(ghostid, -getBias(objectid, angle, 0), gameWorldObjectS[objectid].speed))
									moveCharacter(objectid, ghostid, -getBias(objectid, angle, 0), gameWorldObjectS[objectid].speed);
							}
						}
						else
						{
							if (getAngle(objectid, collideobject) > 90 && getAngle(objectid, collideobject) < 180)
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, -getBias(objectid, angle, direction)))
										moveCharacter(objectid, ghostid, -gameWorldObjectS[objectid].speed, -getBias(objectid, angle, direction));
								}
								else
								{
									if (moveIsPossible(ghostid, -getBias(objectid, angle, 3), -gameWorldObjectS[objectid].speed))
										moveCharacter(objectid, ghostid, -getBias(objectid, angle, 3), -gameWorldObjectS[objectid].speed);
								}
							}
						}
					}
				} break;
				case 2:
				{
					if (frontAndBack(objectid, collideobject) == "front")
					{
						if (getAngle(objectid, collideobject) > 0 && getAngle(objectid, collideobject) < 90)
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, getBias(objectid, angle, direction)))
									moveCharacter(objectid, ghostid, gameWorldObjectS[objectid].speed, getBias(objectid, angle, direction));
							}
							else
							{
								if (moveIsPossible(ghostid, getBias(objectid, angle, 0), gameWorldObjectS[objectid].speed))
									moveCharacter(objectid, ghostid, getBias(objectid, angle, 0), gameWorldObjectS[objectid].speed);
							}
						}
						else
						{
							if (getAngle(objectid, collideobject) > 90 && getAngle(objectid, collideobject) < 180)
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, -getBias(objectid, angle, direction)))
										moveCharacter(objectid, ghostid, gameWorldObjectS[objectid].speed, -getBias(objectid, angle, direction));
								}
								else
								{
									if (moveIsPossible(ghostid, getBias(objectid, angle, 3), -gameWorldObjectS[objectid].speed))
										moveCharacter(objectid, ghostid, getBias(objectid, angle, 3), -gameWorldObjectS[objectid].speed);
								}
							}
						}
					}
				} break;
				case 3:
				{
					if (getAngle(objectid, collideobject) > 0 && getAngle(objectid, collideobject) < 90)
					{
						if (frontAndBack(objectid, collideobject) == "front")
						{
							if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
							{
								if (moveIsPossible(ghostid, -getBias(objectid, angle, direction), -gameWorldObjectS[objectid].speed))
									moveCharacter(objectid, ghostid, -getBias(objectid, angle, direction), -gameWorldObjectS[objectid].speed);
							}
							else
							{
								if (moveIsPossible(ghostid, -gameWorldObjectS[objectid].speed, -getBias(objectid, angle, 1)))
									moveCharacter(objectid, ghostid, -gameWorldObjectS[objectid].speed, -getBias(objectid, angle, 1));
							}
						}
						else
							if (frontAndBack(objectid, collideobject) == "back")
							{
								if (!isNecessaryForGlidingToBeReversed(objectid, angle, direction))
								{
									if (moveIsPossible(ghostid, getBias(objectid, angle, direction), -gameWorldObjectS[objectid].speed))
										moveCharacter(objectid, ghostid, getBias(objectid, angle, direction), -gameWorldObjectS[objectid].speed);
								}
								else
								{
									if (moveIsPossible(ghostid, gameWorldObjectS[objectid].speed, -getBias(objectid, angle, 2)))
										moveCharacter(objectid, ghostid, gameWorldObjectS[objectid].speed, -getBias(objectid, angle, 2));
								}
							}
					}
				} break;
			}
		}
		else
		{
		}
	}
}

int compensatingDirection(int direction, string position, double angle)
{
	int result = -1;
	switch (direction)
	{
		case 0:
		{
			if (position == "front")
				result = 2;
			else
				if (position == "back")
					result = 1;
		} break;
		case 1:
		{
			if (angle > 90)
				result = 0;
			else
				if (angle < 90)
					result = 3;
		} break;
		case 2:
		{
			if (angle > 90)
				result = 0;
			else
				if (angle < 90)
					result = 3;
		} break;
		case 3:
		{
			if (position == "back")
				result = 1;
			else
				if (position == "front")
					result = 2;
		} break;
	}
	return result;
}

int getQuarter(int objectid, int objectToCheck)
{
	//X1 = agk::GetSpriteXByOffset(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]); //x круга
	//Y1 = agk::GetSpriteYByOffset(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]); //y круга
	X1 = gameWorldObjectS[objectToCheck].x + agk::GetSpriteWidth(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]) / 2;
	Y1 = gameWorldObjectS[objectToCheck].y + agk::GetSpriteHeight(gameWorldObjectS[objectToCheck].sprites[gameWorldObjectS[objectToCheck].direction]) / 2;
	X2 = agk::GetSpriteXByOffset(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]); //x персонажа
	Y2 = agk::GetSpriteYByOffset(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]) +
		agk::GetSpriteHeight(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction]) / 2; //y персонажа

	int quarter = -1;
	if (X2 >= X1 && Y2 <= Y1)
	{
		quarter = 1;
	}
	else
	{
		if (X2 <= X1 && Y2 <= Y1)
		{
			quarter = 2;
		}
		else
		{
			if (X2 <= X1 && Y2 >= Y1)
			{
				quarter = 3;
			}
			else
			{
				if (X2 >= X1 && Y2 >= Y1)
				{
					quarter = 4;
				}
			}
		}
	}
	return quarter;
}

bool isCircle(int objectid, int ghostid, int direction)
{
	moveGhost(ghostid, direction);
	int collideobject = objectWeCollidedWith(ghostid);
	ghostGoHome(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].bonetype == 2)
			return true;
		else
			return false;
	}
	return false;
}

void GlideCircle(int objectid, int ghostid, int direction)
{
	moveGhost(ghostid, direction);
	int collideobject = objectWeCollidedWith(ghostid);
	if (collideobject != -1)
	{
		if (gameWorldObjectS[collideobject].bonetype == 2)
		{
			int quarter = getQuarter(objectid, collideobject);
			switch (direction)
			{
				case 0:
				{
					if (quarter == 1)
					{
						moveGhost(ghostid, 2);
						if (moveIsPossible(ghostid))
						{
							moveCharacter(objectid, ghostid, direction);
							moveCharacter(objectid, ghostid, 2);
							motion_log << "(glide circle) moving in both directions: " << direction << " and "<< 2 << endl;
						}
						else
						{
							ghostGoHome(ghostid);
							if (moveIsPossible(ghostid, 2))
							{
								moveCharacter(objectid, ghostid, 2);
								motion_log << "(glide circle) moving in direction: " << 2 << endl;
							}
							else
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
								motion_log << "(glide circle) move impossible" << endl;
							}
						}
					}
					else
					{
						if (quarter == 2)
						{
							moveGhost(ghostid, 1);
							if (moveIsPossible(ghostid))
							{
								moveCharacter(objectid, ghostid, direction);
								moveCharacter(objectid, ghostid, 1);
								motion_log << "(glide circle) moving in both directions: " << direction << " and " << 1 << endl;
							}
							else
							{
								ghostGoHome(ghostid);
								if (moveIsPossible(ghostid, 1))
								{
									moveCharacter(objectid, ghostid, 1);
									motion_log << "(glide circle) moving in direction: " << 1 << endl;
								}
								else
								{
									switchAnimation(ghostid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
									switchAnimation(objectid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
									motion_log << "(glide circle) move impossible" << endl;
								}
							}
						}
					}
				} break;
				case 1:
				{
					if (quarter == 1)
					{
						moveGhost(ghostid, 3);
						if (moveIsPossible(ghostid))
						{
							moveCharacter(objectid, ghostid, direction);
							moveCharacter(objectid, ghostid, 3);
							motion_log << "(glide circle) moving in both directions: " << direction << " and " << 3 << endl;
						}
						else
						{
							ghostGoHome(ghostid);
							if (moveIsPossible(ghostid, 3))
							{
								moveCharacter(objectid, ghostid, 3);
								motion_log << "(glide circle) moving in direction: " << 3 << endl;
							}
							else
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
								motion_log << "(glide circle) move impossible" << endl;
							}
						}
					}
					else
					{
						if (quarter == 4)
						{
							moveGhost(ghostid, 0);
							if (moveIsPossible(ghostid))
							{
								moveCharacter(objectid, ghostid, direction);
								moveCharacter(objectid, ghostid, 0);
								motion_log << "(glide circle) moving in both directions: " << direction << " and " << 0 << endl;
							}
							else
							{
								ghostGoHome(ghostid);
								if (moveIsPossible(ghostid, 0))
								{
									moveCharacter(objectid, ghostid, 0);
									motion_log << "(glide circle) moving in direction: " << 0 << endl;
								}
								else
								{
									switchAnimation(ghostid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
									switchAnimation(objectid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
									motion_log << "(glide circle) move impossible" << endl;
								}
							}
						}
					}
				} break;
				case 2:
				{
					if (quarter == 2)
					{
						moveGhost(ghostid, 3);
						if (moveIsPossible(ghostid))
						{
							moveCharacter(objectid, ghostid, direction);
							moveCharacter(objectid, ghostid, 3);
							motion_log << "(glide circle) moving in both directions: " << direction << " and " << 3 << endl;
						}
						else
						{
							ghostGoHome(ghostid);
							if (moveIsPossible(ghostid, 3))
							{
								moveCharacter(objectid, ghostid, 3);
								motion_log << "(glide circle) moving in direction: " << 3 << endl;
							}
							else
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
								motion_log << "(glide circle) move impossible" << endl;
							}
						}
					}
					else
					{
						if (quarter == 3)
						{
							moveGhost(ghostid, 0);
							if (moveIsPossible(ghostid))
							{
								moveCharacter(objectid, ghostid, direction);
								moveCharacter(objectid, ghostid, 0);
								motion_log << "(glide circle) moving in both directions: " << direction << " and " << 0 << endl;
							}
							else
							{
								ghostGoHome(ghostid);
								if (moveIsPossible(ghostid, 0))
								{
									moveCharacter(objectid, ghostid, 0);
									motion_log << "(glide circle) moving in direction: " << 0 << endl;
								}
								else
								{
									switchAnimation(ghostid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
									switchAnimation(objectid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
									motion_log << "(glide circle) move impossible" << endl;
								}
							}
						}
					}
				} break;
				case 3:
				{
					if (quarter == 3)
					{
						moveGhost(ghostid, 1);
						if (moveIsPossible(ghostid))
						{
							moveCharacter(objectid, ghostid, direction);
							moveCharacter(objectid, ghostid, 1);
							motion_log << "(glide circle) moving in both directions: " << direction << " and " << 1 << endl;
						}
						else
						{
							ghostGoHome(ghostid);
							if (moveIsPossible(ghostid, 1))
							{
								moveCharacter(objectid, ghostid, 1);
								motion_log << "(glide circle) moving in direction: " << 1 << endl;
							}
							else
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
								motion_log << "(glide circle) move impossible" << endl;
							}
						}
					}
					else
					{
						if (quarter == 4)
						{
							moveGhost(ghostid, 2);
							if (moveIsPossible(ghostid))
							{
								moveCharacter(objectid, ghostid, direction);
								moveCharacter(objectid, ghostid, 2);
								motion_log << "(glide circle) moving in both directions: " << direction << " and " << 4 << endl;
							}
							else
							{
								ghostGoHome(ghostid);
								if (moveIsPossible(ghostid, 2))
								{
									moveCharacter(objectid, ghostid, 2);
									motion_log << "(glide circle) moving in direction: " << 2 << endl;
								}
								else
								{
									switchAnimation(ghostid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
									switchAnimation(objectid, 0);
									agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
									motion_log << "(glide circle) move impossible" << endl;
								}
							}
						}
					}
				} break;
			}
		}
	}
	else
		motion_log << "WTF-case!"<<endl;
}

void GlideCircleDefined(int objectid, int ghostid, int circleid, int direction)
{
	moveGhost(ghostid, direction);
	int quarter = getQuarter(objectid, circleid);
	switch (direction)
	{
		case 0:
		{
			if (quarter == 1)
			{
				moveGhost(ghostid, 2);
				if (moveIsPossible(ghostid))
				{
					moveCharacter(objectid, ghostid, direction);
					moveCharacter(objectid, ghostid, 2);
					motion_log << "(glide circle) moving in both directions: " << direction << " and " << 2 << endl;
				}
				else
				{
					ghostGoHome(ghostid);
					if (moveIsPossible(ghostid, 2))
					{
						moveCharacter(objectid, ghostid, 2);
						motion_log << "(glide circle) moving in direction: " << 2 << endl;
					}
					else
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						motion_log << "(glide circle) move impossible" << endl;
					}
				}
			}
			else
			{
				if (quarter == 2)
				{
					moveGhost(ghostid, 1);
					if (moveIsPossible(ghostid))
					{
						moveCharacter(objectid, ghostid, direction);
						moveCharacter(objectid, ghostid, 1);
						motion_log << "(glide circle) moving in both directions: " << direction << " and " << 1 << endl;
					}
					else
					{
						ghostGoHome(ghostid);
						if (moveIsPossible(ghostid, 1))
						{
							moveCharacter(objectid, ghostid, 1);
							motion_log << "(glide circle) moving in direction: " << 1 << endl;
						}
						else
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							motion_log << "(glide circle) move impossible" << endl;
						}
					}
				}
			}
		} break;
		case 1:
		{
			if (quarter == 1)
			{
				moveGhost(ghostid, 3);
				if (moveIsPossible(ghostid))
				{
					moveCharacter(objectid, ghostid, direction);
					moveCharacter(objectid, ghostid, 3);
					motion_log << "(glide circle) moving in both directions: " << direction << " and " << 3 << endl;
				}
				else
				{
					ghostGoHome(ghostid);
					if (moveIsPossible(ghostid, 3))
					{
						moveCharacter(objectid, ghostid, 3);
						motion_log << "(glide circle) moving in direction: " << 3 << endl;
					}
					else
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						motion_log << "(glide circle) move impossible" << endl;
					}
				}
			}
			else
			{
				if (quarter == 4)
				{
					moveGhost(ghostid, 0);
					if (moveIsPossible(ghostid))
					{
						moveCharacter(objectid, ghostid, direction);
						moveCharacter(objectid, ghostid, 0);
						motion_log << "(glide circle) moving in both directions: " << direction << " and " << 0 << endl;
					}
					else
					{
						ghostGoHome(ghostid);
						if (moveIsPossible(ghostid, 0))
						{
							moveCharacter(objectid, ghostid, 0);
							motion_log << "(glide circle) moving in direction: " << 0 << endl;
						}
						else
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							motion_log << "(glide circle) move impossible" << endl;
						}
					}
				}
			}
		} break;
		case 2:
		{
			if (quarter == 2)
			{
				moveGhost(ghostid, 3);
				if (moveIsPossible(ghostid))
				{
					moveCharacter(objectid, ghostid, direction);
					moveCharacter(objectid, ghostid, 3);
					motion_log << "(glide circle) moving in both directions: " << direction << " and " << 3 << endl;
				}
				else
				{
					ghostGoHome(ghostid);
					if (moveIsPossible(ghostid, 3))
					{
						moveCharacter(objectid, ghostid, 3);
						motion_log << "(glide circle) moving in direction: " << 3 << endl;
					}
					else
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						motion_log << "(glide circle) move impossible" << endl;
					}
				}
			}
			else
			{
				if (quarter == 3)
				{
					moveGhost(ghostid, 0);
					if (moveIsPossible(ghostid))
					{
						moveCharacter(objectid, ghostid, direction);
						moveCharacter(objectid, ghostid, 0);
						motion_log << "(glide circle) moving in both directions: " << direction << " and " << 0 << endl;
					}
					else
					{
						ghostGoHome(ghostid);
						if (moveIsPossible(ghostid, 0))
						{
							moveCharacter(objectid, ghostid, 0);
							motion_log << "(glide circle) moving in direction: " << 0 << endl;
						}
						else
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							motion_log << "(glide circle) move impossible" << endl;
						}
					}
				}
			}
		} break;
		case 3:
		{
			if (quarter == 3)
			{
				moveGhost(ghostid, 1);
				if (moveIsPossible(ghostid))
				{
					moveCharacter(objectid, ghostid, direction);
					moveCharacter(objectid, ghostid, 1);
					motion_log << "(glide circle) moving in both directions: " << direction << " and " << 1 << endl;
				}
				else
				{
					ghostGoHome(ghostid);
					if (moveIsPossible(ghostid, 1))
					{
						moveCharacter(objectid, ghostid, 1);
						motion_log << "(glide circle) moving in direction: " << 1 << endl;
					}
					else
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						motion_log << "(glide circle) move impossible" << endl;
					}
				}
			}
			else
			{
				if (quarter == 4)
				{
					moveGhost(ghostid, 2);
					if (moveIsPossible(ghostid))
					{
						moveCharacter(objectid, ghostid, direction);
						moveCharacter(objectid, ghostid, 2);
						motion_log << "(glide circle) moving in both directions: " << direction << " and " << 4 << endl;
					}
					else
					{
						ghostGoHome(ghostid);
						if (moveIsPossible(ghostid, 2))
						{
							moveCharacter(objectid, ghostid, 2);
							motion_log << "(glide circle) moving in direction: " << 2 << endl;
						}
						else
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							motion_log << "(glide circle) move impossible" << endl;
						}
					}
				}
			}
		} break;
	}
}

int compensatingDirectionCircle(int direction, int quarter)
{
	int result = -1;
	switch (direction)
	{
		case 0:
		{
			if (quarter == 1)
				result = 1;
			else
				if (quarter == 2)
					result = 2;
		} break;
		case 1:
		{
			if (quarter == 1)
				result = 0;
			else
				if (quarter == 4)
					result = 3;
		} break;
		case 2:
		{
			if (quarter == 2)
				result = 0;
			else
				if (quarter == 3)
					result = 3;
		} break;
		case 3:
		{
			if (quarter == 3)
				result = 2;
			else
				if (quarter == 4)
					result = 1;
		} break;
	}
	return result;
}

void manageCharacterMove(int objectid, int ghostid, int direction)
{
	if (moveIsPossible(ghostid, direction))
	{
		moveCharacter(objectid, ghostid, direction);
		motion_log << "moving in direction: " << direction << endl;
	}
	else
	{
		if (isCircle(objectid, ghostid, direction))
		{
			GlideCircle(objectid, ghostid, direction);
			motion_log << "gliding circle in direction: " << direction << endl;
		}
		else
			if (isPossibleToGlide(objectid, ghostid, direction))
			{
				glideCharacter(objectid, ghostid, direction);
				motion_log << "gliding in direction: " << direction << endl;
			}
			else
			{
				switchAnimation(ghostid, 0);
				agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
				switchAnimation(objectid, 0);
				agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
				motion_log << "moving impossible" << direction << endl;
			}
	}
}

void manageCharacterMove(int objectid, int ghostid, int direction1, int direction2)
{
	moveGhost(ghostid, direction1);
	moveGhost(ghostid, direction2);
	int collideobject = objectWeCollidedWith(ghostid);
	ghostGoHome(ghostid);

	if (collideobject != -1 && gameWorldObjectS[collideobject].solid)
	{
		if (gameWorldObjectS[collideobject].bonetype == 1)
		{
			if (compensatingDirection(direction1, frontAndBack(objectid, collideobject), getAngle(objectid, collideobject)) == direction2)
			{
				if (isPossibleToGlide(objectid, ghostid, direction2))
				{
					glideCharacter(objectid, ghostid, direction2);
					if (gameWorldObjectS[objectid].direction != direction2)
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
					}
					gameWorldObjectS[ghostid].direction = direction2;
					switchAnimation(ghostid, 1);
					gameWorldObjectS[objectid].direction = direction2;
					switchAnimation(objectid, 1);
					motion_log << "gliding direction2: " << direction2 << endl;
					return;
				}
			}
			else
			{
				if (isPossibleToGlide(objectid, ghostid, direction1))
				{
					glideCharacter(objectid, ghostid, direction1);
					if (gameWorldObjectS[objectid].direction != direction1)
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
					}
					gameWorldObjectS[ghostid].direction = direction1;
					switchAnimation(ghostid, 1);
					gameWorldObjectS[objectid].direction = direction1;
					switchAnimation(objectid, 1);
					motion_log << "gliding direction1: " << direction1 << endl;
					return;
				}
				else
					if (isPossibleToGlide(objectid, ghostid, direction2))
					{
						glideCharacter(objectid, ghostid, direction2);
						if (gameWorldObjectS[objectid].direction != direction2)
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						}
						gameWorldObjectS[ghostid].direction = direction2;
						switchAnimation(ghostid, 1);
						gameWorldObjectS[objectid].direction = direction2;
						switchAnimation(objectid, 1);
						motion_log << "gliding direction2: " << direction2 << endl;
						return;
					}
			}
		}
		else
		{
			if (gameWorldObjectS[collideobject].bonetype == 2)
			{
				int quarter = getQuarter(objectid, collideobject);
				if (compensatingDirectionCircle(direction1, quarter) == direction2)
				{
					GlideCircleDefined(objectid, ghostid, collideobject, direction2);
					if (gameWorldObjectS[objectid].direction != direction2)
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
					}
					gameWorldObjectS[ghostid].direction = direction2;
					switchAnimation(ghostid, 1);
					gameWorldObjectS[objectid].direction = direction2;
					switchAnimation(objectid, 1);
					motion_log << "gliding circle with direction2: " << direction2 << endl;
					return;
				}
			}
		}

		if (!moveIsPossible(ghostid, direction1) && !moveIsPossible(ghostid, direction2))
		{
			switchAnimation(ghostid, 0);
			agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
			switchAnimation(objectid, 0);
			agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
			motion_log << "move impossible" << endl;
		}
		else
		{
			if (moveIsPossible(ghostid, direction1))
			{
				if (gameWorldObjectS[collideobject].bonetype == 0)
				{
					if (gameWorldObjectS[objectid].direction != direction1)
					{
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
					}
					gameWorldObjectS[ghostid].direction = direction1;
					switchAnimation(ghostid, 1);
					gameWorldObjectS[objectid].direction = direction1;
					switchAnimation(objectid, 1);
				}
				motion_log << "moving in direction1: " << direction1 << endl;
				moveCharacter(objectid, ghostid, direction1);
			}
			else
				if (moveIsPossible(ghostid, direction2))
				{
					if (gameWorldObjectS[collideobject].bonetype == 0)
					{
						if (gameWorldObjectS[objectid].direction != direction2)
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						}
						gameWorldObjectS[ghostid].direction = direction2;
						switchAnimation(ghostid, 1);
						gameWorldObjectS[objectid].direction = direction2;
						switchAnimation(objectid, 1);
					}
					motion_log << "moving in direction2: " << direction2 << endl;
					moveCharacter(objectid, ghostid, direction2);
				}
		}
	}
	else
	{
		moveCharacter(objectid, ghostid, direction1);
		moveCharacter(objectid, ghostid, direction2);
		motion_log << "moving in both directions: " << direction1<<" and "<<direction2<<endl;
		moveGhost(ghostid, direction1);
		moveGhost(ghostid, direction2);
		moveGhost(ghostid, direction1);
		moveGhost(ghostid, direction2);
		collideobject = objectWeCollidedWith(ghostid);
		if (!(collideobject != -1 && gameWorldObjectS[collideobject].solid))
		{
			if (gameWorldObjectS[objectid].direction != direction1)
			{
				switchAnimation(ghostid, 0);
				agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
				switchAnimation(objectid, 0);
				agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
			}
			gameWorldObjectS[ghostid].direction = direction1;
			switchAnimation(ghostid, 1);
			gameWorldObjectS[objectid].direction = direction1;
			switchAnimation(objectid, 1);
		}
	}
}

double getDistanceBetweenSpriteCenters(int sprite1, int sprite2)
{
	double x1 = agk::GetSpriteXByOffset(sprite1);
	double y1 = agk::GetSpriteYByOffset(sprite1);
	double x2 = agk::GetSpriteXByOffset(sprite2);
	double y2 = agk::GetSpriteYByOffset(sprite2);
	return sqrt((x2-x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool isFarEnoughFromTheOtherWaves(int wave_sprite, int x, int y, vector <int> other_visible_waves, int M)
{
	bool result = true;
	agk::SetSpritePosition(wave_sprite, x, y);
	if (other_visible_waves.size() != 0)
	{
		for (int j = 0; j < other_visible_waves.size(); j++)
		{
			wave_log << "isFarEnoughFromTheOtherWaves, wave[" << j << "] = " << getDistanceBetweenSpriteCenters(wave_sprite, gameWorldObjectS[other_visible_waves[j]].sprites[gameWorldObjectS[other_visible_waves[j]].direction]) << endl;
			if (getDistanceBetweenSpriteCenters(wave_sprite, gameWorldObjectS[other_visible_waves[j]].sprites[gameWorldObjectS[other_visible_waves[j]].direction]) < M)
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

bool isFarEnoughFromTheOtherWavesInTheGroup(int wave_sprite, int x, int y, vector <int> waves_to_create, int index_to_stop, int N)
{
	bool result = true;
	agk::SetSpritePosition(wave_sprite, x, y);
	if (waves_to_create.size() != 0)
	{
		for (int j = 0; j < index_to_stop; j++)
		{
			wave_log << "isFarEnoughFromTheOtherWavesInTheGroup, wave[" << j << "] = " << getDistanceBetweenSpriteCenters(wave_sprite, gameWorldObjectS[waves_to_create[j]].sprites[gameWorldObjectS[waves_to_create[j]].direction]) << endl;
			if (getDistanceBetweenSpriteCenters(wave_sprite, gameWorldObjectS[waves_to_create[j]].sprites[gameWorldObjectS[waves_to_create[j]].direction]) < N)
			{
				result = false;
				break;
			}
		}
	}
	else
	{
		wave_log << "?!?!?!" << endl;
	}
	return result;
}

void startNewGroup(vector <int> waves_to_create, vector <int> other_visible_waves, int x1, int x2, int y1, int y2, int M, int N)
{
	if(waves_to_create.size() != 0)
	{
		for (int i = 0; i < waves_to_create.size(); i++)
		{
			int x = randomBetweenTwoNumbers(x1, y1);
			int y = randomBetweenTwoNumbers(x2, y2);
			wave_log << "x = " << x << " y = " << y << endl;
			if (i == 0)
			{
				while (!isFarEnoughFromTheOtherWaves(gameWorldObjectS[waves_to_create[i]].sprites[gameWorldObjectS[waves_to_create[i]].direction], x, y, other_visible_waves, M))
				{
					int x = randomBetweenTwoNumbers(x1, y1);
					int y = randomBetweenTwoNumbers(x2, y2);
					wave_log << "x = " << x << " y = " << y << endl;
				}
			}
			else
			{
				while (!isFarEnoughFromTheOtherWaves(gameWorldObjectS[waves_to_create[i]].sprites[gameWorldObjectS[waves_to_create[i]].direction], x, y, other_visible_waves, M) &&
					!isFarEnoughFromTheOtherWavesInTheGroup(gameWorldObjectS[waves_to_create[i]].sprites[gameWorldObjectS[waves_to_create[i]].direction], x, y, waves_to_create, i, N))
				{
					int x = randomBetweenTwoNumbers(x1, y1);
					int y = randomBetweenTwoNumbers(x2, y2);
					wave_log << "x = " << x << " y = " << y << endl;
				}
			}
			agk::SetSpriteVisible(gameWorldObjectS[waves_to_create[i]].sprites[gameWorldObjectS[waves_to_create[i]].direction], true);
			agk::PlaySprite(gameWorldObjectS[waves_to_create[i]].sprites[gameWorldObjectS[waves_to_create[i]].direction]);
		}
	}
	else
	{
		return;
	}
}

void setWaveTimer(int timer)
{
	wave_timer = timer;
	wave_log << "wave_timer = " << wave_timer << endl;
}

int manageWaves(vector <vector<int>> waves, int x1, int x2, int y1, int y2, int timer, int M, int N)
{
	for (int i = 0; i < waves.size(); i++)
	{
		for (int j = 0; j < waves[i].size(); j++)
		{
			if (!agk::GetSpritePlaying(gameWorldObjectS[waves[i][j]].sprites[gameWorldObjectS[waves[i][j]].direction]))
			{
				agk::SetSpriteVisible(gameWorldObjectS[waves[i][j]].sprites[gameWorldObjectS[waves[i][j]].direction], 0);
			}
		}
	}
	if (timer == wave_timer)
	{
		int group_to_start = -1;
		int last_turned_on_group = -1;
		vector <vector <int>> visible_waves;
		vector <int> other_visible_waves;
		for (int i = 0; i < waves.size(); i++)
		{
			int count_wave_turned_on = 0;
			vector<int> waves_to_add_to_visible_waves;
			for (int j = 0; j < waves[i].size(); j++)
			{
				if (agk::GetSpritePlaying(gameWorldObjectS[waves[i][j]].sprites[gameWorldObjectS[waves[i][j]].direction]))
				{
					waves_to_add_to_visible_waves.push_back(waves[i][j]);
					count_wave_turned_on++;
				}
			}
			if (count_wave_turned_on == waves[i].size())
			{
				last_turned_on_group = i;
			}
			else
			{
				if (last_turned_on_group != -1)
				{
					break;
				}
			}
			if (waves_to_add_to_visible_waves.size() != 0)
			{
				visible_waves.push_back(waves_to_add_to_visible_waves);
			}
		}
		if (last_turned_on_group == -1 || last_turned_on_group == waves.size() - 1)
		{
			group_to_start = 0;
			wave_log << "group to start = " << group_to_start << endl;
			vector<int> waves_to_create;
			for (int i = 0; i < waves[group_to_start].size(); i++)
			{
				waves_to_create.push_back(waves[group_to_start][i]);
			}
			if (visible_waves.size() != 0)
			{
				for (int i = 0; i < visible_waves.size(); i++)
				{
					if (i != group_to_start)
					{
						for (int j = 0; j < visible_waves[i].size(); j++)
						{
							other_visible_waves.push_back(visible_waves[i][j]);
						}
					}
				}
			}
			timer = 0;
			setWaveTimer(randomBetweenTwoNumbers(20, 30));
			startNewGroup(waves_to_create, other_visible_waves, x1, x2, y1, y2, M, N);
		}
		else
		{
			group_to_start = last_turned_on_group + 1;
			wave_log << "group to start = " <<group_to_start << endl;
			vector<int> waves_to_create;
			for (int i = 0; i < waves[group_to_start].size(); i++)
			{
				waves_to_create.push_back(waves[group_to_start][i]);
			}
			if (visible_waves.size() != 0)
			{
				for (int i = 0; i < visible_waves.size(); i++)
				{
					if (i != group_to_start)
					{
						for (int j = 0; j < visible_waves[i].size(); j++)
						{
							other_visible_waves.push_back(visible_waves[i][j]);
						}
					}
				}
			}
			timer = 0;
			setWaveTimer(randomBetweenTwoNumbers(40, 70));
			startNewGroup(waves_to_create, other_visible_waves, x1, x2, y1, y2, M, N);
		}
	}
	return timer;
}

void moveObjects(vector <vector<int>> objects, int x1, int x2, int y1, int y2, int direction)
{
	switch (direction)
	{
		case 0: //down
			break;
		case 1: //left
			break;
		case 2: //right
			
			break;
		case 3: //up
			break;
	}
}

bool buttonPressedIsTrue(string button)
{
	if (hold(button))
		return true;
	return false;
}

void gameObjectUpdate(int objectid, int ghostid)
{
	bool collision = false;
	int n = gameWorldObjectS[objectid].sprites.size();
	int objects = gameWorldObjectS.size();
	for (int i = 0; i < n; i++)
	{
		if(gameWorldObjectS[objectid].underplayer == false)
			agk::SetSpriteDepth(gameWorldObjectS[objectid].sprites[i], 10000 - gameWorldObjectS[objectid].y - agk::GetSpriteHeight(gameWorldObjectS[objectid].sprites[i]));
		else
			agk::SetSpriteDepth(gameWorldObjectS[objectid].sprites[i], 10000 - gameWorldObjectS[objectid].y);
		if (gameWorldObjectS[objectid].underobject != -1)
		{
			agk::SetSpriteDepth(gameWorldObjectS[objectid].sprites[i], 1 + agk::GetSpriteDepth(gameWorldObjectS[gameWorldObjectS[objectid].underobject].sprites[gameWorldObjectS[gameWorldObjectS[objectid].underobject].direction]));
		}
		agk::SetSpriteVisible(gameWorldObjectS[objectid].sprites[i], false);
		agk::SetSpritePosition(gameWorldObjectS[objectid].sprites[i], gameWorldObjectS[objectid].x, gameWorldObjectS[objectid].y);
		agk::SetSpriteScale(gameWorldObjectS[objectid].sprites[i], gameWorldObjectS[objectid].scalex, gameWorldObjectS[objectid].scaley);
		agk::SetSpriteAngle(gameWorldObjectS[objectid].sprites[i], gameWorldObjectS[objectid].angle);
		//agk::SetSpriteSnap(gameWorldObjectS[objectid].sprites[i], 1);
		if (gameWorldObjectS[objectid].controllable == true)
		{
			agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[i], gameWorldObjectS[ghostid].x, gameWorldObjectS[ghostid].y);
			agk::SetSpriteScale(gameWorldObjectS[ghostid].sprites[i], gameWorldObjectS[ghostid].scalex, gameWorldObjectS[ghostid].scaley);
		}
	}
	if (gameWorldObjectS[objectid].sndactive == 1)
		gameWorldObjectS[objectid].playsnd = agk::PlaySound(gameWorldObjectS[objectid].snd, 100, gameWorldObjectS[objectid].sndloop);
	if (gameWorldObjectS[objectid].sprite_actives[gameWorldObjectS[objectid].direction] == 1 && gameWorldObjectS[objectid].controllable == false)
		agk::PlaySprite(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], gameWorldObjectS[objectid].fps, gameWorldObjectS[objectid].spriteloop);
	agk::SetSpriteVisible(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], true);
	agk::StepPhysics(0.0001);

	if (gameWorldObjectS[objectid].controllable == true)
	{
		if(edges == "agk::Round is used")
			agk::SetViewOffset(agk::Round(gameWorldObjectS[objectid].x - agk::GetVirtualWidth()/2), agk::Round(gameWorldObjectS[objectid].y - agk::GetVirtualHeight()/2));
		else if (edges == "agk::Floor is used")
			agk::SetViewOffset(agk::Floor(gameWorldObjectS[objectid].x - agk::GetVirtualWidth() / 2), agk::Floor(gameWorldObjectS[objectid].y - agk::GetVirtualHeight() / 2));
		else if (edges == "agk::Nothing is used")
			agk::SetViewOffset(gameWorldObjectS[objectid].x - agk::GetVirtualWidth() / 2, gameWorldObjectS[objectid].y - agk::GetVirtualHeight() / 2);
		//agk::SetViewOffset(5500, 5500);
			if (pressed("z"))
			{
				if (gameWorldObjectS[ghostid].direction == 0)
				{
					agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[ghostid].x, gameWorldObjectS[ghostid].y + gameWorldObjectS[ghostid].speed * 20);
					agk::StepPhysics(0.0001);
					for (int i = 0; i < objects; i++)
					{
						if (!(agk::GetPhysicsCollision(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[i].sprites[gameWorldObjectS[i].direction])))
						{
							collision = false;
						}
						else
						{
							collision = true;
							stateUpdate(i);
							touched = 1;
							if (gameWorldObjectS[i].info_count == true)
							{
								if ((getStateCount(i) <= gameWorldObjectS[i].flavor_texts.size()) && (gameWorldObjectS[i].flavor_texts.size() != 0))
								{
									if ((text_page < gameWorldObjectS[i].flavor_texts[getStateCount(i) - 1].size()) && (gameWorldObjectS[i].flavor_texts[getStateCount(i) - 1].size() != 0) && (anyended() || !anyactive()))
									{
										murder();
										activatedialog(gameWorldObjectS[i].dialogues[getStateCount(i) - 1][text_page]);
										text_page++;
									}
									else
									{
										if ((anyended() || !anyactive()))
										{
											murder();
											text_page = 0;
											touched = 0;
										}
									}
								}
								else
								{
									if (gameWorldObjectS[i].flavor_texts.size() != 0)
									{
										if ((text_page < gameWorldObjectS[i].flavor_texts[gameWorldObjectS[i].flavor_texts.size() - 1].size()) && (gameWorldObjectS[i].flavor_texts[gameWorldObjectS[i].flavor_texts.size() - 1].size() != 0))
										{
											murder();
											activatedialog(gameWorldObjectS[i].dialogues[gameWorldObjectS[i].flavor_texts.size() - 1][text_page]);
											text_page++;
										}
										else
										{
											murder();
											text_page = 0;
											touched = 0;
										}
									}
								}
							}
							//string iwanttodie = initiateDialog("meow2");
							/*
							if (gameWorldObjectS[i].flavor_texts.size() != gameWorldObjectS[i].dialogues.size())
							{
								agk::Print("Something went wrong!");
							}
							else
							{
								int count = 0;
								for (int j = 0; j < gameWorldObjectS[i].flavor_texts.size(); j++)
								{
									if (gameWorldObjectS[i].flavor_texts[j].size() == gameWorldObjectS[i].dialogues[j].size())
										count++;
								}
								if (count == gameWorldObjectS[i].flavor_texts.size())
								{
									agk::Print("Something went right! @_@");
								}
								else
								{
									agk::Print("Something went wrong!");
								}
							}
							agk::Print(gameWorldObjectS[i].dialogues[0][0].c_str());
							activatedialog(gameWorldObjectS[i].dialogues[0][0]);*/
							//:O
							/*
							if (gameWorldObjectS[i].info_count == true)
							{
								if (getStateCount(i) <= gameWorldObjectS[i].flavor_texts.size())
								{
									if (text_page < gameWorldObjectS[i].flavor_texts[getStateCount(i) - 1].size())
									{
										if ((2*2==4))
										{
											//deactivatedialog(narradialog);
											//activatedialog(gameWorldObjectS[i].dialogues[getStateCount(i) - 1][text_page]);
											
											text_page++;
										}
									}
									else
									{
										//deactivatedialog(narradialog);
										text_page = 0;
										touched = 0;
										agk::Print("zzz");
									}
								}
								else
								{
									if (text_page < gameWorldObjectS[i].flavor_texts[gameWorldObjectS[i].flavor_texts.size() - 1].size())
									{
										if ((2 * 2 == 4))
										{
											agk::Print("we're here");
											//deactivatedialog(narradialog);
											activatedialog(initiateDialog("qwe"));
											text_page++;
										}
									}
									else
									{

										//deactivatedialog(narradialog);
										text_page = 0;
										touched = 0;
										agk::Print("zzz");
									}
								}
							}*/
							//:O
							if ((gameWorldObjectS[i].sndtype == 1 || gameWorldObjectS[i].sndtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sndactive == 0)
									switchSound(i, 1);
								else
									if (gameWorldObjectS[i].sndactive == 1)
										switchSound(i, 0);
							}
							if ((gameWorldObjectS[i].animationtype == 1 || gameWorldObjectS[i].animationtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 0)
									switchAnimation(i, 1);
								else
									if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 1)
										switchAnimation(i, 0);
							}
							break;
						}
					}
				}
				if (gameWorldObjectS[ghostid].direction == 1)
				{
					agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[ghostid].x - gameWorldObjectS[ghostid].speed * 20, gameWorldObjectS[ghostid].y);
					agk::StepPhysics(0.0001);
					for (int i = 0; i < objects; i++)
					{
						if (!(agk::GetPhysicsCollision(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[i].sprites[gameWorldObjectS[i].direction])))
						{
							collision = false;
						}
						else
						{
							collision = true;
							touched = 1;
							stateUpdate(i);
							if ((gameWorldObjectS[i].sndtype == 1 || gameWorldObjectS[i].sndtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sndactive == 0)
									switchSound(i, 1);
								else
									if (gameWorldObjectS[i].sndactive == 1)
										switchSound(i, 0);
							}
							if ((gameWorldObjectS[i].animationtype == 1 || gameWorldObjectS[i].animationtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 0)
									switchAnimation(i, 1);
								else
									if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 1)
										switchAnimation(i, 0);
							}
							break;
						}
					}
				}
				if (gameWorldObjectS[ghostid].direction == 2)
				{
					agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[ghostid].x + gameWorldObjectS[ghostid].speed * 20, gameWorldObjectS[ghostid].y);
					agk::StepPhysics(0.0001);
					for (int i = 0; i < objects; i++)
					{
						if (!(agk::GetPhysicsCollision(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[i].sprites[gameWorldObjectS[i].direction])))
						{
							collision = false;
						}
						else
						{
							collision = true;
							touched = 1;
							stateUpdate(i);
							if ((gameWorldObjectS[i].sndtype == 1 || gameWorldObjectS[i].sndtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sndactive == 0)
									switchSound(i, 1);
								else
									if (gameWorldObjectS[i].sndactive == 1)
										switchSound(i, 0);
							}
							if ((gameWorldObjectS[i].animationtype == 1 || gameWorldObjectS[i].animationtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 0)
									switchAnimation(i, 1);
								else
									if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 1)
										switchAnimation(i, 0);
							}
							break;
						}
					}
				}
				if (gameWorldObjectS[ghostid].direction == 3)
				{
					agk::SetSpritePosition(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[ghostid].x, gameWorldObjectS[ghostid].y - gameWorldObjectS[ghostid].speed * 20);
					agk::StepPhysics(0.0001);
					for (int i = 0; i < objects; i++)
					{
						if (!(agk::GetPhysicsCollision(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], gameWorldObjectS[i].sprites[gameWorldObjectS[i].direction])))
						{
							collision = false;
						}
						else
						{
							collision = true;
							touched = 1;
							stateUpdate(i);
							if ((gameWorldObjectS[i].sndtype == 1 || gameWorldObjectS[i].sndtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sndactive == 0)
									switchSound(i, 1);
								else
									if (gameWorldObjectS[i].sndactive == 1)
										switchSound(i, 0);
							}
							if ((gameWorldObjectS[i].animationtype == 1 || gameWorldObjectS[i].animationtype == 2) && (touched == 0))
							{
								if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 0)
									switchAnimation(i, 1);
								else
									if (gameWorldObjectS[i].sprite_actives[gameWorldObjectS[i].direction] == 1)
										switchAnimation(i, 0);
							}
							break;
						}
					}
				}
			}
			if (pressed("x"))
				if (touched == 1)
				{
					/*if (textouted(narradialog) == false)
						instanttext(narradialog);
					else
						deactivatedialog(narradialog);
						*/
					touched = 0;
				}
			/*
			if (touched == 0)
				agk::Print("not touched");
			else
				agk::Print("touched");*/

			switch(arrowButtonsPressedCount())
			{
				case 0:
					{
						firstkeypressed = "none";
						secondkeypressed = "none";
						thirdkeypressed = "none";
						fourthkeypressed = "none";

						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						for (int i = 0; i < objects; i++)
						{
							if (gameWorldObjectS[i].sndtype == 3)
								switchSound(i, 0);
							if (gameWorldObjectS[i].animationtype == 3)
								switchAnimation(i, 0);
						}
					} break;
				case 1:
					{
						if (hold("down"))
						{
							firstkeypressed = "down";
							if (gameWorldObjectS[objectid].direction != 0)
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							}
							gameWorldObjectS[ghostid].direction = 0;
							switchAnimation(ghostid, 1);
							gameWorldObjectS[objectid].direction = 0;
							switchAnimation(objectid, 1);
							manageCharacterMove(objectid, ghostid, 0);
						}
						else if (hold("left"))
						{
							firstkeypressed = "left";
							if (gameWorldObjectS[objectid].direction != 1)
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							}
							gameWorldObjectS[ghostid].direction = 1;
							switchAnimation(ghostid, 1);
							gameWorldObjectS[objectid].direction = 1;
							switchAnimation(objectid, 1);
							manageCharacterMove(objectid, ghostid, 1);
						}
						else if (hold("right"))
						{
							firstkeypressed = "right";
							if (gameWorldObjectS[objectid].direction != 2)
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							}
							gameWorldObjectS[ghostid].direction = 2;
							switchAnimation(ghostid, 1);
							gameWorldObjectS[objectid].direction = 2;
							switchAnimation(objectid, 1);
							manageCharacterMove(objectid, ghostid, 2);
						}
						else if (hold("up"))
						{
							firstkeypressed = "up";
							if (gameWorldObjectS[objectid].direction != 3)
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							}
							gameWorldObjectS[ghostid].direction = 3;
							switchAnimation(ghostid, 1);
							gameWorldObjectS[objectid].direction = 3;
							switchAnimation(objectid, 1);
							manageCharacterMove(objectid, ghostid, 3);
						}

						secondkeypressed = "none";
						thirdkeypressed = "none";
						fourthkeypressed = "none";
					} break;
				case 2:
					{
						if (!buttonPressedIsTrue(firstkeypressed))
							firstkeypressed = "none";

						if (firstkeypressed == "none")
							{
								if (hold("down"))
									firstkeypressed = "down";
								else if (hold("left"))
									firstkeypressed = "left";
								else if (hold("right"))
									firstkeypressed = "right";
								else if (hold("up"))
									firstkeypressed = "up";
							}

						if (hold("down") && firstkeypressed != "down")
							secondkeypressed = "down";
						else if (hold("left") && firstkeypressed != "left")
							secondkeypressed = "left";
						else if (hold("right") && firstkeypressed != "right")
							secondkeypressed = "right";
						else if (hold("up") && firstkeypressed != "up")
							secondkeypressed = "up";

						if (!directionsAreOpposite(directionStringToInt(firstkeypressed), directionStringToInt(secondkeypressed)))
						{
							manageCharacterMove(objectid, ghostid, directionStringToInt(firstkeypressed), directionStringToInt(secondkeypressed));
						}
						else
						{
							if (gameWorldObjectS[objectid].direction != directionStringToInt(secondkeypressed))
							{
								switchAnimation(ghostid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
								switchAnimation(objectid, 0);
								agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
							}
							gameWorldObjectS[ghostid].direction = directionStringToInt(secondkeypressed);
							switchAnimation(ghostid, 1);
							gameWorldObjectS[objectid].direction = directionStringToInt(secondkeypressed);
							switchAnimation(objectid, 1);
							manageCharacterMove(objectid, ghostid, directionStringToInt(secondkeypressed));
						}

						thirdkeypressed = "none";
						fourthkeypressed = "none";
					} break;
				case 3:
					{
						if (!buttonPressedIsTrue(firstkeypressed))
							firstkeypressed = "none";

						if (firstkeypressed == "none")
							{
								if (hold("down"))
									firstkeypressed = "down";
								else if (hold("left"))
									firstkeypressed = "left";
								else if (hold("right"))
									firstkeypressed = "right";
								else if (hold("up"))
									firstkeypressed = "up";
							}

						if (!buttonPressedIsTrue(secondkeypressed) || secondkeypressed == firstkeypressed)
							secondkeypressed = "none";

						if (secondkeypressed == "none")
							{
								if (hold("down") && firstkeypressed != "down")
									secondkeypressed = "down";
								else if (hold("left") && firstkeypressed != "left")
									secondkeypressed = "left";
								else if (hold("right") && firstkeypressed != "right")
									secondkeypressed = "right";
								else if (hold("up") && firstkeypressed != "up")
									secondkeypressed = "up";
							}

						if (hold("down") && firstkeypressed != "down" && secondkeypressed != "down")
							thirdkeypressed = "down";
						else if (hold("left") && firstkeypressed != "left" && secondkeypressed != "left")
							thirdkeypressed = "left";
						else if (hold("right") && firstkeypressed != "right" && secondkeypressed != "right")
							thirdkeypressed = "right";
						else if (hold("up") && firstkeypressed != "up" && secondkeypressed != "up")
							thirdkeypressed = "up";

						if (gameWorldObjectS[objectid].direction != resultDirection(directionStringToInt(firstkeypressed), directionStringToInt(secondkeypressed), directionStringToInt(thirdkeypressed)))
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						}
						gameWorldObjectS[ghostid].direction = resultDirection(directionStringToInt(firstkeypressed), directionStringToInt(secondkeypressed), directionStringToInt(thirdkeypressed));
						switchAnimation(ghostid, 1);
						gameWorldObjectS[objectid].direction = resultDirection(directionStringToInt(firstkeypressed), directionStringToInt(secondkeypressed), directionStringToInt(thirdkeypressed));
						switchAnimation(objectid, 1);
						manageCharacterMove(objectid, ghostid, resultDirection(directionStringToInt(firstkeypressed), directionStringToInt(secondkeypressed), directionStringToInt(thirdkeypressed)));
						
						fourthkeypressed = "none";
					} break;
				case 4:
					{
						if (!buttonPressedIsTrue(firstkeypressed))
							firstkeypressed = "none";

						if (firstkeypressed == "none")
							{
								if (hold("down"))
									firstkeypressed = "down";
								else if (hold("left"))
									firstkeypressed = "left";
								else if (hold("right"))
									firstkeypressed = "right";
								else if (hold("up"))
									firstkeypressed = "up";
							}
					
						if (!buttonPressedIsTrue(secondkeypressed) || secondkeypressed == firstkeypressed)
							secondkeypressed = "none";

						if (secondkeypressed == "none")
							{
								if (hold("down") && firstkeypressed != "down")
									secondkeypressed = "down";
								else if (hold("left") && firstkeypressed != "left")
									secondkeypressed = "left";
								else if (hold("right") && firstkeypressed != "right")
									secondkeypressed = "right";
								else if (hold("up") && firstkeypressed != "up")
									secondkeypressed = "up";
							}

						if (!buttonPressedIsTrue(thirdkeypressed) || thirdkeypressed == firstkeypressed || thirdkeypressed == secondkeypressed)
							thirdkeypressed = "none";

						if (thirdkeypressed == "none")
							{
								if (hold("down") && firstkeypressed != "down" && secondkeypressed != "down")
									thirdkeypressed = "down";
								else if (hold("left") && firstkeypressed != "left" && secondkeypressed != "left")
									thirdkeypressed = "left";
								else if (hold("right") && firstkeypressed != "right" && secondkeypressed != "right")
									thirdkeypressed = "right";
								else if (hold("up") && firstkeypressed != "up" && secondkeypressed != "up")
									thirdkeypressed = "up";
							}

						if (hold("down") && firstkeypressed != "down" && secondkeypressed != "down" && thirdkeypressed != "down")
							fourthkeypressed = "down";
						else if (hold("left") && firstkeypressed != "left" && secondkeypressed != "left" && thirdkeypressed != "left")
							fourthkeypressed = "left";
						else if (hold("right") && firstkeypressed != "right" && secondkeypressed != "right" && thirdkeypressed != "right")
							fourthkeypressed = "right";
						else if (hold("up") && firstkeypressed != "up" && secondkeypressed != "up" && thirdkeypressed != "up")
							fourthkeypressed = "up";

						if (gameWorldObjectS[objectid].direction != oppositeDirection(directionStringToInt(fourthkeypressed)))
						{
							switchAnimation(ghostid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
							switchAnimation(objectid, 0);
							agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						}
						gameWorldObjectS[ghostid].direction = oppositeDirection(directionStringToInt(fourthkeypressed));
						switchAnimation(ghostid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[ghostid].sprites[gameWorldObjectS[ghostid].direction], 1);
						gameWorldObjectS[objectid].direction = oppositeDirection(directionStringToInt(fourthkeypressed));
						switchAnimation(objectid, 0);
						agk::SetSpriteFrame(gameWorldObjectS[objectid].sprites[gameWorldObjectS[objectid].direction], 1);
						for (int i = 0; i < objects; i++)
						{
							if (gameWorldObjectS[i].sndtype == 3)
								switchSound(i, 0);
							if (gameWorldObjectS[i].animationtype == 3)
								switchAnimation(i, 0);
						}
					} break;
			}
			int collideobject = objectWeCollidedWith(ghostid);
			if (collideobject != -1 && gameWorldObjectS[collideobject].isportal)
			{
				GoToRoom(gameWorldObjectS[collideobject].gotoroom);
			}
	}
}