#include "main.h"
#include "ui.h"
#include "player.h"
#include "field.h"

bool isMessageMode;



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
	/* 画面クリア */
	std::system("cls");

	for (int i = 0; i < DISP_H; i++) {
		//std::cout << &UI[i][0] << "\n";
		printf("%s\n", &UI[i][0]);
	};

	if (isMessageMode) {
		//Message表示、時間止まる
		while (true) {
			if (_kbhit() && _getch() == ' ') {
				break;
			}
		}

		ClearMessage();
	}

}

void SetUI(int y, int x, char data)
{
	UI[y][x] = data;
}



void updateHP()
{
	char HPdisplay[11] = { ' ' };
	for (int i = 0; i < g_Player[0].hp; i++) {
		HPdisplay[i * 2] = '0';
		if (i == g_Player[0].hp - 1) continue;
		HPdisplay[i * 2 + 1] = '_';
	}
	memcpy(&UI_org[1][57], HPdisplay, g_Player[0].hp * 2);
}

void updateArrowNum()
{
	char charArrowNum[4];
	_itoa(g_Player[0].arrownum, charArrowNum, 10);
	memcpy(&UI_org[2][59], charArrowNum, 3);
}

//LifeFragments表示
void updateLifeFragments()
{

}

char MessageBar_org[Message_h][Message_w + 1] = {
	"==================================================",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|   スペース(Space)キーを押すと進む  |",
	"==================================================",

};

char MessageBar[Message_h][Message_w + 1] = {
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
};

void UpdateMessage()
{
	if (isMessageMode) {
		memcpy(MessageBar, MessageBar_org, sizeof(MessageBar));
	}
	for (int i = 0; i < Message_h; i++)
	{
		memcpy(&UI[i + 5][15], &MessageBar[i][0], Message_w);
	}

}

void SetMessage(int type) {
	isMessageMode = true;

	//0:arrow+5  1:lifeFra+1  2:heal+1  3:key+1
	switch (type)
	{
	case 0:
		char comment[] = "矢5本を見つけた！";

		break;
		/*case 1:
			break;
		case 2:
			break;
		case 3:
			break;*/
	}
}

void ClearMessage() {
	isMessageMode = false;
	for (int i = 0; i < Message_h; i++)
	{
		for (int j = 0; j < Message_w; j++)
		{
			UI[i][j] = ' ';
		}

	}
}





