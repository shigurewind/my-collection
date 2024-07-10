#include "main.h"
#include "ui.h"
#include "player.h"
#include "field.h"



char UI_org[DISP_H][DISP_W + 1] = {
	"                                                  |                             ",
	"                                                  |  HP:                        ",
	"                                                  |  Arrow:                     ",
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

	updateArrowNum();
	updateHP();
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

void updateHP() {
	char HPdisplay[11] = { ' ' };
	for (int i = 0; i < g_Player[0].hp; i++) {
		HPdisplay[i * 2] = '0';
		if (i == g_Player[0].hp - 1) continue;
		HPdisplay[i * 2 + 1] = '_';
	}
	memcpy(&UI_org[1][57], HPdisplay, g_Player[0].hp * 2);
}

void updateArrowNum() {
	char charArrowNum[4];
	_itoa(g_Player[0].arrownum, charArrowNum, 10);
	memcpy(&UI_org[2][59], charArrowNum, 3);
}





