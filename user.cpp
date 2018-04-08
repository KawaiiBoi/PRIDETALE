#include "user.h"
#include "template.h"
using namespace std;

bool pressed(string button) {
	if(button=="lkm") return agk::GetRawMouseLeftPressed();
	if (button == "pkm") return agk::GetRawMouseRightPressed();
	if (button == "z") return agk::GetRawKeyPressed(90);
	if (button == "x") return agk::GetRawKeyPressed(88);
	if (button == "up") return agk::GetRawKeyPressed(38);
	if (button == "down") return agk::GetRawKeyPressed(40);
	if (button == "left") return agk::GetRawKeyPressed(37);
	if (button == "right") return agk::GetRawKeyPressed(39);
}

bool hold(string button) {
	if (button == "lkm") return agk::GetRawMouseLeftState();
	if (button == "pkm") return agk::GetRawMouseRightState();
	if (button == "z") return agk::GetRawKeyState(90);
	if (button == "x") return agk::GetRawKeyState(88);
	if (button == "up") return agk::GetRawKeyState(38);
	if (button == "down") return agk::GetRawKeyState(40);
	if (button == "left") return agk::GetRawKeyState(37);
	if (button == "right") return agk::GetRawKeyState(39);
}

