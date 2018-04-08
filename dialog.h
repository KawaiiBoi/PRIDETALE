#pragma once
#include "access.h"
extern struct dialog;
extern vector <dialog> Sdialog;
extern int Ndialog;
extern bool Cdialog(dialog s1, dialog s2);
extern string Adialog(vector <vector <int> > image, vector <int> sound, vector <vector <int> > imagewait, vector <int> x, vector <int> y, vector <vector <int> > xchange, vector <vector <int> > ychange, vector <vector <int> > movewait, vector <vector <float> > scalex, vector <vector <float> > scaley, vector <vector <int> > scalewait, vector <vector <int> > r, vector <vector <int> > g, vector <vector <int> > b, vector <vector <int> > colorwait, vector <int> spritewait, vector <bool> playsound);
extern int Gdialog(string id);
extern void old_Ddialog(string id);
extern void new_Ddialog(string id);
extern void activatedialog(string id);
extern void deactivatedialog(string id);
extern void updatedialogs();

extern struct storage;
extern vector <storage> Sstorage;
extern int Nstorage;
extern bool Cstorage(storage s1, storage s2);
extern string Astorage();
extern int Gstorage(string id);
extern void Dstorage(string id);
extern void Lstorage(string id, vector <int> symbols, string font, int frames);

extern string lines
(
	vector <string> text,

	vector <int> wait,

	vector <bool> startsparag,

	vector <int> shake,
	vector <int> spritewait,
	vector <int> distance,
	vector <int> sound,

	vector <vector <int> > r,
	vector <vector <int> > g,
	vector <vector <int> > b,
	vector <int> colorwait,

	int y,
	int x,
	int jump,
	int length,

	int ystep,
	float scale,
	bool flexdistance,

	int shakewait,
	int shakecount,
	bool flexshake,

	string storageid,
	int frames,
	int framewait,

	vector <int> silent
);



extern bool textouted(string dialogid);
extern bool activedialog(string dialogid);
extern void instanttext(string dialogid);
extern float linelastx(string dialogid, int y, int scale, int dist);
extern float dialogmaxy(string dialogid);
extern void murder();
extern bool anyended();
extern bool anyactive();