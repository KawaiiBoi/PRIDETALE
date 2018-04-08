#include "font.h"
#include "template.h"
#include <vector>



using namespace std;








struct sound {
	int id;
};

vector <sound> soundS;

int loadsound(string name) {
	string path = "resources/";
	path += name;
	path += ".wav";
	sound sample;
	sample.id=agk::LoadSound(path.c_str());
	soundS.push_back(sample);
	return soundS.size() - 1;
}

struct color {
	int r, g, b;
};

vector <color> colorS;

int createcolor(int r, int g, int b) {
	color sample;
	sample.r = r;
	sample.g = g;
	sample.b = b;
	colorS.push_back(sample);
	return colorS.size() - 1;
}

struct font {
	vector <vector <int> > ids;
	vector <char> symbols;
	vector <vector <string> > names;
	vector <bool> coloraf;
};

vector <font> fontS;

int createfont(vector <char> symbols, vector <vector <string> > names, vector <bool> coloraf ) {
	font sample;
	sample.symbols = symbols;
	sample.coloraf = coloraf;
	sample.names = names;
	fontS.push_back(sample);
	return fontS.size() - 1;
}

void loadfont(int id, string name) {
	string path = "resources/";
	path += name;
	path += ".png";
	fontS[id].ids.resize(fontS[id].names.size());
	int from = agk::LoadImage(path.c_str());
	for (int y = 0; y < fontS[id].names.size(); y++) for(int x=0; x< fontS[id].names[y].size(); x++) {
		string load;
		load+=fontS[id].names[y][x];
		fontS[id].ids[y].push_back(agk::LoadSubImage(from, load.c_str()));
	}
}

struct position {
	int x, y;
};

vector <position> positionS;

int createposition(int x, int y) {
	position sample;
	sample.x = x;
	sample.y = y;
	positionS.push_back(sample);
	return positionS.size() - 1;
}

struct text {
	int shaking, colordelay;
	string message;
	vector <vector <int> > ids;
	vector <int> colorsid;
	vector <int> soundsid;
	vector <int> positions;
	vector <bool> coloraf;
	bool animate;
};

vector <text> textS;


int createtext(int x, int y, string message, int fontid, vector <int> colorsid, vector <int> soundsid, int interval, int shaking, float sizing, bool animate) {
	text sample;
	sample.message = message;
	sample.soundsid = soundsid;
	sample.shaking = shaking;
	sample.colorsid = colorsid;
	sample.animate = animate;
	int ofx = 0;
	

	

	int s = 0;
	for (int i = 0; i < message.size(); i++) if (message[i]!=' '){
		
		
		for(int yy=0; yy<fontS[fontid].symbols.size(); yy++) {
		

			if (fontS[fontid].symbols[yy] == message[i]) {
				
			
				

				sample.coloraf.push_back(fontS[fontid].coloraf[yy]);

					

				

				sample.positions.push_back(createposition(x + ofx + interval*i, y));
				sample.ids.resize(sample.ids.size() + 1);

				for (int xx = 0; xx < fontS[fontid].names[yy].size(); xx++) {

					
					int image = agk::CopyImage(fontS[fontid].ids[yy][xx], 0, 0, agk::GetImageWidth(fontS[fontid].ids[yy][xx]), agk::GetImageHeight(fontS[fontid].ids[yy][xx]));
				
					

					agk::ResizeImage(image, agk::GetImageWidth(image)*sizing, agk::GetImageHeight(image)*sizing);
					
					
					sample.ids[s].push_back(agk::CreateSprite(image));

					agk::SetSpritePosition(sample.ids[s][sample.ids[s].size()-1], x + ofx + interval*i, y);
					
					agk::SetSpriteVisible(sample.ids[s][sample.ids[s].size() - 1], 0);
					
				}
				
				break;
				
				}

			}		
		
		ofx += agk::GetSpriteWidth(sample.ids[s][0]);
		s++;
	}


	
	

	textS.push_back(sample);
	return textS.size() - 1;
}

struct textproc {
	int id, delay, cur;
};

vector <textproc> textprocS;

vector <char> silent = { 'ä', 'ê', 'à', '/', 'á', '%', '#', '&', '$', '*', '@', '?', '+','>','}','{','<', '_','~','=' ,'-',']',')','[','(','!','^' ,';', ',', '.','|', '`', ' ' };

int showtext(int textid, int delay) {
	textproc sample;
	sample.id = textid;
	sample.delay = delay;
	sample.cur = 0;
	textprocS.push_back(sample);
	return textprocS.size() - 1;
}

void setspritecolor(int sprite, int id) {
	agk::SetSpriteColorRed(sprite, colorS[id].r);
	agk::SetSpriteColorGreen(sprite, colorS[id].g);
	agk::SetSpriteColorBlue(sprite, colorS[id].b);
}

void updatetexts() {
	for (int i = 0; i < textprocS.size(); i++) {
		int s = 0;
		for (int j = 0; j < textS[textprocS[i].id].message.size() && j*textprocS[i].delay<=textprocS[i].cur; j++) {
			
			if (textS[textprocS[i].id].message[j] != ' ') {

				

				for (int xx = 0; xx<textS[textprocS[i].id].ids[s].size(); xx++) {
					agk::SetSpriteVisible(textS[textprocS[i].id].ids[s][xx], 0);
				}

				int nowx;

				if (textS[textprocS[i].id].animate) nowx = textprocS[i].cur%textS[textprocS[i].id].ids[s].size();
				else nowx = min(textprocS[i].cur, textS[textprocS[i].id].ids[s].size()-1);

				agk::SetSpriteVisible(textS[textprocS[i].id].ids[s][nowx], 1);
				
				
				agk::SetSpritePosition
				(
					textS[textprocS[i].id].ids[s][nowx], 
					positionS[ textS[textprocS[i].id].positions[s]].x + rand() % (textS[textprocS[i].id].shaking * 2 + 1) - textS[textprocS[i].id].shaking, 
					positionS[ textS[textprocS[i].id].positions[s]].y + rand() % (textS[textprocS[i].id].shaking * 2 + 1) - textS[textprocS[i].id].shaking
				);
				
				
				
				if (textS[textprocS[i].id].coloraf[s]) setspritecolor(textS[textprocS[i].id].ids[s][nowx], textS[textprocS[i].id].colorsid[textprocS[i].cur%textS[textprocS[i].id].colorsid.size()]);

				
				
				s++;
			}
	}
		if(textprocS[i].delay!=0 && textS[textprocS[i].id].soundsid.size()>0)
		if (textprocS[i].cur%textprocS[i].delay == 0 && textprocS[i].cur/textprocS[i].delay<textS[textprocS[i].id].message.size()) 
		if (find(silent.begin(), silent.end(), textS[textprocS[i].id].message[textprocS[i].cur / textprocS[i].delay]) == silent.end())
		agk::PlaySound(soundS[textS[textprocS[i].id].soundsid[(textprocS[i].cur / textprocS[i].delay) % textS[textprocS[i].id].soundsid.size()]].id);
				
				
				

		textprocS[i].cur++;
	}

	
}

/*
void hidetext(int textid) {

}

*/
void instanttext(int textprocid) {
	int wascolor = textprocS[textprocid].cur%textS[textprocS[textprocid].id].colorsid.size();
	for (textprocS[textprocid].cur = 99999;textprocS[textprocid].cur%textS[textprocS[textprocid].id].colorsid.size() != wascolor; textprocS[textprocid].cur++);
}


/*
int createdialog(vector<text>texts, vector<int>delays) {

}

struct dialogproc {

};

vector <dialogproc> dialogprocS;

int showdialog(int dialogid) {

}

void updatedialogs() {

}

void hidedialog(int dialogid) {

}

void deletedialog(int dialogid) {

}

void instantdialog(int dialogid) {

}
*/