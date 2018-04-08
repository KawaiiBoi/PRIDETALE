#include "dialog.h"
#include "access.h"
struct dialog {
	vector <vector <int> > image;
	vector <int> sound;

	vector <vector <int> > imagewait;
	vector <int> x;
	vector <int> y;
	vector <vector <int> > xchange;
	vector <vector <int> > ychange;
	vector <vector <int> > movewait;
	vector <vector <float> > scalex;
	vector <vector <float> > scaley;
	vector <vector <int> > scalewait;
	vector <vector <int> > r;
	vector <vector <int> > g;
	vector <vector <int> > b;
	vector <vector <int> > colorwait;
	vector <int> spritewait;

	string id;
	int state;
	bool active;

	vector <bool> playsound;

	vector <int> sprite;
};
vector <dialog> Sdialog;
int Ndialog = 0;
bool Cdialog(dialog s1, dialog s2) {
	if (s1.id.size() != s2.id.size()) return s1.id.size() < s2.id.size(); ////для всех comp
	return s1.id < s2.id;
}
string Adialog(vector <vector <int> > image, vector <int> sound, vector <vector <int> > imagewait, vector <int> x, vector <int> y, vector <vector <int> > xchange, vector <vector <int> > ychange, vector <vector <int> > movewait, vector <vector <float> > scalex, vector <vector <float> > scaley, vector <vector <int> > scalewait, vector <vector <int> > r, vector <vector <int> > g, vector <vector <int> > b, vector <vector <int> > colorwait, vector <int> spritewait, vector <bool> playsound) {
	dialog sample;
	sample.image = image;
	sample.sound = sound;
	sample.imagewait = imagewait;
	sample.x = x;
	sample.y = y;
	sample.xchange = xchange;
	sample.ychange = ychange;
	sample.movewait = movewait;
	sample.scalex = scalex;
	sample.scaley = scaley;
	sample.scalewait = scalewait;
	sample.r = r;
	sample.g = g;
	sample.b = b;
	sample.colorwait = colorwait;
	sample.spritewait = spritewait;
	sample.playsound = playsound;
	for (int i = 0; i < sample.image.size(); i++) {
		sample.sprite.push_back(agk::CreateSprite(sample.image[i][0]));
		agk::FixSpriteToScreen(sample.sprite[i], 1);
		agk::SetSpritePosition(sample.sprite[i], sample.x[i], sample.y[i]);
		agk::SetSpriteVisible(sample.sprite[i], 0);
		agk::SetSpriteDepth(sample.sprite[i], 0);
	}
	sample.active = 0;
	sample.id = "dialog" + to_string(Ndialog);
	Sdialog.push_back(sample);
	Ndialog++;
	return sample.id;
}
int Gdialog(string id) {
	if (Sdialog.size() == 0) return -1;
	int left = 0, right = Sdialog.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (id > Sdialog[mid].id || id.size() > Sdialog[mid].id.size())
			left = mid + 1;
		else if (id < Sdialog[mid].id || id.size() < Sdialog[mid].id.size())
			right = mid - 1;
		else return mid;
	}
	return -1;
}
void old_Ddialog(string id) {
	int got = Gdialog(id);
	if (got == -1) return;

	for (int i = 0; i < Sdialog[got].sprite.size(); i++)
		agk::DeleteSprite(Sdialog[got].sprite[i]);

	for (int i = 0; i < Sdialog[got].image.size(); i++)
		for (int j = 0; j < Sdialog[got].image[i].size(); j++)
			agk::DeleteImage(Sdialog[got].image[i][j]);

	for (int i = 0; i < Sdialog[got].sound.size(); i++)
		agk::DeleteSound(Sdialog[got].sound[i]);

	Sdialog[got] = Sdialog[Sdialog.size() - 1];
	Sdialog.resize(Sdialog.size() - 1);
	sort(Sdialog.begin(), Sdialog.end(), Cdialog);
}
void new_Ddialog(string id) {
	int got = Gdialog(id);
	if (got == -1) return;

	for (int i = 0; i < Sdialog[got].sprite.size(); i++)
		agk::DeleteSprite(Sdialog[got].sprite[i]);

	Sdialog[got] = Sdialog[Sdialog.size() - 1];
	Sdialog.resize(Sdialog.size() - 1);
	sort(Sdialog.begin(), Sdialog.end(), Cdialog);
}
void activatedialog(string id) {
	int got = Gdialog(id);
	if (got == -1) return;
	Sdialog[got].active = 1;
	Sdialog[got].state = 0;
}
void deactivatedialog(string id) {
	int got = Gdialog(id);
	if (got == -1) return;
	Sdialog[got].active = 0;
	for (int i = 0; i < Sdialog[got].sprite.size(); i++)
		agk::SetSpriteVisible(Sdialog[got].sprite[i], 0);
}
void updatedialogs() {
	for (int i = 0; i < Sdialog.size(); i++)
		if (Sdialog[i].active) {
			for (int j = 0, demand = 0; j < Sdialog[i].sprite.size() && demand <= Sdialog[i].state; j++) {
				agk::SetSpriteVisible(Sdialog[i].sprite[j], 1);
				int k;

				//изображение
				if (Sdialog[i].imagewait.size() == Sdialog[i].sprite.size())
					if (Sdialog[i].imagewait[j].size() == Sdialog[i].image[j].size()) {
						int maximagedemand = 0;
						for (k = 0; k < Sdialog[i].imagewait[j].size(); k++)
							maximagedemand += Sdialog[i].imagewait[j][k];
						maximagedemand++;
						int imagedemand = 0;
						for (k = 0; k < Sdialog[i].imagewait[j].size() && imagedemand <= Sdialog[i].state%maximagedemand; k++)
							imagedemand += Sdialog[i].imagewait[j][k];
						k--;
						agk::SetSpriteImage(Sdialog[i].sprite[j], Sdialog[i].image[j][k]);
					}

				//цвет
				if (Sdialog[i].colorwait.size() == Sdialog[i].sprite.size())
					if (Sdialog[i].colorwait[j].size() == Sdialog[i].r[j].size() && Sdialog[i].colorwait[j].size()>0) {
						int maxcolordemand = 0;
						for (k = 0; k < Sdialog[i].colorwait[j].size(); k++)
							maxcolordemand += Sdialog[i].colorwait[j][k];
						maxcolordemand++;
						int colordemand = 0;
						for (k = 0; k < Sdialog[i].colorwait[j].size() && colordemand <= Sdialog[i].state%maxcolordemand; k++)
							colordemand += Sdialog[i].colorwait[j][k];
						k--;
						agk::SetSpriteColorRed(Sdialog[i].sprite[j], Sdialog[i].r[j][k]);
						agk::SetSpriteColorGreen(Sdialog[i].sprite[j], Sdialog[i].g[j][k]);
						agk::SetSpriteColorBlue(Sdialog[i].sprite[j], Sdialog[i].b[j][k]);
					}

				//позиция
				if (Sdialog[i].movewait.size() == Sdialog[i].sprite.size())
					if (Sdialog[i].movewait[j].size() == Sdialog[i].xchange[j].size() && Sdialog[i].movewait[j].size() > 0) {
						int maxmovedemand = 0;
						for (k = 0; k < Sdialog[i].movewait[j].size(); k++)
							maxmovedemand += Sdialog[i].movewait[j][k];
						maxmovedemand++;
						int movedemand = 0;
						for (k = 0; k < Sdialog[i].movewait[j].size() && movedemand <= Sdialog[i].state%maxmovedemand; k++)
							movedemand += Sdialog[i].movewait[j][k];
						k--;
						agk::SetSpritePosition(Sdialog[i].sprite[j], Sdialog[i].x[j] + Sdialog[i].xchange[j][k], Sdialog[i].y[j] + Sdialog[i].ychange[j][k]);
					}


				//размер
				if (Sdialog[i].scalewait.size() == Sdialog[i].sprite.size())
					if (Sdialog[i].scalewait[j].size() == Sdialog[i].scalex[j].size() && Sdialog[i].scalewait[j].size()>0) {
						int maxscaledemand = 0;
						for (k = 0; k < Sdialog[i].scalewait[j].size(); k++)
							maxscaledemand += Sdialog[i].scalewait[j][k];
						maxscaledemand++;
						int scaledemand = 0;
						for (k = 0; k < Sdialog[i].scalewait[j].size() && scaledemand <= Sdialog[i].state%maxscaledemand; k++)
							scaledemand += Sdialog[i].scalewait[j][k];
						k--;
						agk::SetSpriteScale(Sdialog[i].sprite[j], Sdialog[i].scalex[j][k], Sdialog[i].scaley[j][k]);
					}


				if (Sdialog[i].spritewait.size() == Sdialog[i].sprite.size()) {

					//звук
					if (demand == Sdialog[i].state && Sdialog[i].sound.size() == Sdialog[i].sprite.size() && Sdialog[i].playsound[j])
						agk::PlaySound(Sdialog[i].sound[j]);

					//цикл
					demand += Sdialog[i].spritewait[j];

				}

			}

			//статус
			Sdialog[i].state++;

		}
}

struct storage {
	vector <vector <int> > image;
	string id;
};
vector <storage> Sstorage;
int Nstorage = 0;
bool Cstorage(storage s1, storage s2) {
	if (s1.id.size() != s2.id.size()) return s1.id.size() < s2.id.size(); ////для всех comp
	return s1.id < s2.id;
}
string Astorage() {
	storage sample;
	sample.image.resize(95);
	sample.id = "storage" + to_string(Nstorage);
	Sstorage.push_back(sample);
	Nstorage++;
	return sample.id;
}
int Gstorage(string id) {
	if (Sstorage.size() == 0) return -1;
	int left = 0, right = Sstorage.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (id > Sstorage[mid].id || id.size() > Sstorage[mid].id.size())
			left = mid + 1;
		else if (id < Sstorage[mid].id || id.size() < Sstorage[mid].id.size())
			right = mid - 1;
		else return mid;
	}
	return -1;
}
void Dstorage(string id) {
	int got = Gstorage(id);
	if (got == -1) return;

	for (int i = 0; i < Sstorage[got].image.size(); i++)
		for (int j = 0; j < Sstorage[got].image[i].size(); j++)
			agk::DeleteImage(Sstorage[got].image[i][j]);

	Sstorage[got] = Sstorage[Sstorage.size() - 1];
	Sstorage.resize(Sstorage.size() - 1);
	sort(Sstorage.begin(), Sstorage.end(), Cstorage);
}
void Lstorage(string id, vector <int> symbols, string font, int frames) {
	int got = Gstorage(id);
	if (got == -1) return;
	for (int i = 0; i < symbols.size(); i++)
		for (int j = 0; j < frames; j++)
			Sstorage[got].image[symbols[i] - 32].push_back(agk::LoadImage(("resources/" + font + "/" + to_string(symbols[i]) + char(int('a') + j) + ".png").c_str()));
}


string lines
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

) {
	dialog sample;
	sample.active = 0;
	sample.id = "dialog" + to_string(Ndialog);
	Sdialog.push_back(sample);
	Ndialog++;

	int gotd = Gdialog(sample.id);
	int gots = Gstorage(storageid);



	int adx = 0;
	int ady = 0;
	int dad = 0;

	for (int w = 0; w < text.size(); w++) {
		if (startsparag[w]) {
			adx = 0; ady += ystep * (flexdistance ? scale : 1); dad = 0;
		}
		for (int i = 0; i < text[w].size(); i++) {



			int potent = 0;
			bool kill = 0;

			for (int v = w; v < text.size() && !kill; v++)
				for (int j = (v == w ? i : 0); j < text[v].size(); j++) {
					if (text[v][j] == ' ') { kill = 1; break; }
					if (!flexdistance) potent += agk::GetImageWidth(Sstorage[gots].image[int(text[v][j]) - 32][0])*scale + (j == text[v].size() - 1 || text[v][j + 1] == ' ' ? 0 : distance[v]);
					else potent += agk::GetImageWidth(Sstorage[gots].image[int(text[v][j]) - 32][0])*scale + (j == text[v].size() - 1 || text[v][j + 1] == ' ' ? 0 : distance[v])  *scale;
				}

			if (flexdistance && x + potent + adx + dad*scale > length) {
				adx = jump*scale; ady += ystep*scale; dad = 0;

				bool escape = 0;
				for (; w < text.size(); w++) {
					for (; i < text[w].size(); i++) if (text[w][i] != ' ') {
						escape = 1; break;
					}
					if (escape) break;
					i = 0;
				}

			}
			if (!flexdistance && x + potent + adx + dad > length)
			{
				adx = jump; ady += ystep; dad = 0;


				bool escape = 0;
				for (; w < text.size(); w++) {
					for (; i < text[w].size(); i++) if (text[w][i] != ' ') {
						escape = 1; break;
					}
					if (escape) break;
					i = 0;
				}

			}



			if (flexdistance) {
				Sdialog[gotd].x.push_back(x + adx + dad*scale);
				Sdialog[gotd].y.push_back(y + ady);
			}
			else {
				Sdialog[gotd].x.push_back(x + adx + dad);
				Sdialog[gotd].y.push_back(y + ady);
			}

			Sdialog[gotd].image.resize(Sdialog[gotd].image.size() + 1);
			Sdialog[gotd].imagewait.resize(Sdialog[gotd].imagewait.size() + 1);

			for (int j = 0; j < frames; j++) {
				Sdialog[gotd].image[Sdialog[gotd].image.size() - 1].push_back(Sstorage[gots].image[int(text[w][i]) - 32][j]);
				Sdialog[gotd].imagewait[Sdialog[gotd].imagewait.size() - 1].push_back(framewait);
			}

			adx += agk::GetImageWidth(Sstorage[gots].image[int(text[w][i]) - 32][0])*scale;
			dad += distance[w];

			Sdialog[gotd].scalex.resize(Sdialog[gotd].scalex.size() + 1);
			Sdialog[gotd].scaley.resize(Sdialog[gotd].scaley.size() + 1);
			Sdialog[gotd].scalewait.resize(Sdialog[gotd].scalewait.size() + 1);
			Sdialog[gotd].scalex[Sdialog[gotd].scalex.size() - 1].push_back(scale);
			Sdialog[gotd].scaley[Sdialog[gotd].scaley.size() - 1].push_back(scale);
			Sdialog[gotd].scalewait[Sdialog[gotd].scalewait.size() - 1].push_back(1);


			Sdialog[gotd].sprite.push_back(agk::CreateSprite(Sdialog[gotd].image[Sdialog[gotd].image.size() - 1][0]));
			agk::FixSpriteToScreen(Sdialog[gotd].sprite[Sdialog[gotd].sprite.size() - 1], 1);
			agk::SetSpritePosition(Sdialog[gotd].sprite[Sdialog[gotd].sprite.size() - 1], Sdialog[gotd].x[Sdialog[gotd].x.size() - 1], Sdialog[gotd].y[Sdialog[gotd].y.size() - 1]);


			agk::SetSpriteVisible(Sdialog[gotd].sprite[Sdialog[gotd].sprite.size() - 1], 0);


			Sdialog[gotd].movewait.resize(Sdialog[gotd].movewait.size() + 1);

			for (int j = 0; j < shakecount; j++)
				Sdialog[gotd].movewait[Sdialog[gotd].movewait.size() - 1].push_back(shakewait);

			Sdialog[gotd].xchange.resize(Sdialog[gotd].xchange.size() + 1);
			Sdialog[gotd].ychange.resize(Sdialog[gotd].ychange.size() + 1);

			if (flexshake) {
				for (int j = 0; j < shakecount; j++) {
					Sdialog[gotd].xchange[Sdialog[gotd].xchange.size() - 1].push_back(((rand() % ((shake[w] * 2) + 1)) - shake[w]) *scale);
					Sdialog[gotd].ychange[Sdialog[gotd].ychange.size() - 1].push_back(((rand() % ((shake[w] * 2) + 1)) - shake[w]) *scale);
				}
			}
			else {
				for (int j = 0; j < shakecount; j++) {
					Sdialog[gotd].xchange[Sdialog[gotd].xchange.size() - 1].push_back((rand() % ((shake[w] * 2) + 1)) - shake[w]);
					Sdialog[gotd].ychange[Sdialog[gotd].ychange.size() - 1].push_back((rand() % ((shake[w] * 2) + 1)) - shake[w]);
				}
			}



			Sdialog[gotd].r.push_back(r[w]);
			Sdialog[gotd].g.push_back(g[w]);
			Sdialog[gotd].b.push_back(b[w]);
			Sdialog[gotd].colorwait.resize(Sdialog[gotd].colorwait.size() + 1);
			for (int j = 0; j < r[w].size(); j++)
				Sdialog[gotd].colorwait[Sdialog[gotd].colorwait.size() - 1].push_back(colorwait[w]);


			Sdialog[gotd].spritewait.push_back((i == text[w].size() - 1 ? wait[w] : spritewait[w]));

			Sdialog[gotd].sound.push_back(sound[w]);

			Sdialog[gotd].playsound.push_back(find(silent.begin(), silent.end(), int(text[w][i])) == silent.end());



		}


	}





	return sample.id;

}




bool textouted(string dialogid) {
	int got = Gdialog(dialogid);
	if (got == -1) return 0;
	int demand = 0;
	for (int i = 0; i < Sdialog[got].spritewait.size() - 1; i++) demand += Sdialog[got].spritewait[i];
	return Sdialog[got].state >= demand;
}
bool activedialog(string dialogid) {
	int got = Gdialog(dialogid);
	if (got == -1) return 0;
	return Sdialog[got].active;
}
void instanttext(string dialogid) {
	int got = Gdialog(dialogid);
	if (got == -1) return;
	int maxcolordemand = 0;
	int k;
	for (k = 0; k < Sdialog[got].colorwait[0].size(); k++)
		maxcolordemand += Sdialog[got].colorwait[0][k];
	maxcolordemand++;
	int oldstat = Sdialog[got].state%maxcolordemand;
	Sdialog[got].state = 99999;
	int nowstat = Sdialog[got].state%maxcolordemand;
	Sdialog[got].state += oldstat - nowstat;
}
float linelastx(string dialogid, int y, int scale, int dist) {
	int got = Gdialog(dialogid);
	if (got == -1) return 0.1;
	int gotx = -99999, gotid = -1;
	for (int i = 0; i < Sdialog[got].y.size(); i++) {
		if (Sdialog[got].y[i] == y && Sdialog[got].x[i] >= gotx) {
			gotx = Sdialog[got].x[i];
			gotid = i;
		}
	}
	if (gotid == -1) return 0.1;
	return gotx + agk::GetSpriteWidth(Sdialog[got].sprite[gotid])*scale + dist*scale;
}
float dialogmaxy(string dialogid) {
	int got = Gdialog(dialogid);
	if (got == -1 || Sdialog[got].y.size() == 0) return 0.1;
	return *max_element(Sdialog[got].y.begin(), Sdialog[got].y.end());
}
void murder() {
	for (int i = 0; i<Sdialog.size(); i++)
		if (activedialog(Sdialog[i].id))
			deactivatedialog(Sdialog[i].id);
}
bool anyended() {
	for (int i = 0; i < Sdialog.size(); i++)
		if (textouted(Sdialog[i].id))
			return 1;
	return 0;
}
bool anyactive() {
	for (int i = 0; i < Sdialog.size(); i++)
		if (activedialog(Sdialog[i].id))
			return 1;
	return 0;
}