#include "main.h"
#include "ui.h"
#include "player.h"
#include "field.h"


char UI_org[DISP_H][DISP_W + 1] = {
	"                                                  |         HP:100              ",
	"                                                  |       Arrow:10              ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"                                                  |                             ",
	"--------------------------------------------------------------------------------",
	"           Use WASD to move    J:Attack    K:Shoot    L:Heal                    ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
};

char UI[DISP_H][DISP_W + 1] = {
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
};

void InitUI() {
	memcpy(UI, UI_org, sizeof(UI));
}

void UninitUI() {

}

void UpdateUI() {
	memcpy(UI, UI_org, sizeof(UI));
}

void DrawUI() {
	/* ‰æ–ÊƒNƒŠƒA */
	std::system("cls");

	for (int i = 0; i < DISP_H; i++) {
		//std::cout << &UI[i][0] << "\n";
		printf("%s\n", &UI[i][0]);
	};


}

void SetUI(int y, int x, char data)
{
	UI[y][x] = data;
}

void SetMessage(int m) {

}

