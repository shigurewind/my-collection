#include "gameover.h"
#include "main.h"

#include "box.h"
#include "enemy.h"


int isSelected = 0;

int OpenBoxNum;
int KilledEnemyNum;

BOOL isBottonPressed = FALSE;


void RestartSelected() {
	system("cls");

	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "             ____    _    __  __ _____    _____     _______ ____               " << std::endl;
	std::cout << "            / ___|  / `  |  `/  | ____|  / _ ` `   / / ____|  _ `              " << std::endl;
	std::cout << "           | |  _  / _ ` | |`/| |  _|   | | | ` ` / /|  _| | |_) |             " << std::endl;
	std::cout << "           | |_| |/ ___ `| |  | | |___  | |_| |` V / | |___|  _ <              " << std::endl;
	std::cout << "            `____/_/   `_`_|  |_|_____|  `___/  `_/  |_____|_| `_`             " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                やり直しますか？                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                 -> | やり直す |                  終了する                     " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
}

void ExitSelected() {
	system("cls");

	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "             ____    _    __  __ _____    _____     _______ ____               " << std::endl;
	std::cout << "            / ___|  / `  |  `/  | ____|  / _ ` `   / / ____|  _ `              " << std::endl;
	std::cout << "           | |  _  / _ ` | |`/| |  _|   | | | ` ` / /|  _| | |_) |             " << std::endl;
	std::cout << "           | |_| |/ ___ `| |  | | |___  | |_| |` V / | |___|  _ <              " << std::endl;
	std::cout << "            `____/_/   `_`_|  |_|_____|  `___/  `_/  |_____|_| `_`             " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                やり直しますか？                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                      やり直す               -> | 終了する |                   " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
}


void UpdateOver() {
	char key_A = GetKeyState('A'),     // W押し確認
		key_Left = GetKeyState(VK_LEFT),// 上押し確認	
		key_D = GetKeyState('D'),// S押し確認
		key_Right = GetKeyState(VK_RIGHT),// 下押し確認
		key_Space = GetKeyState(' '),// スペース押し確認
		key_Enter = GetKeyState(VK_RETURN);// Enter押し確認

	if (_kbhit()) {
		if (key_A < 0 || key_Left < 0) {
			if (!isBottonPressed) {
				isSelected--;
				isBottonPressed = TRUE;
				system("cls");
				if (isSelected < 0) {
					isSelected = OVERNUM - 1;
				}
			}
		}
		if (key_D < 0 || key_Right < 0) {
			if (!isBottonPressed) {
				isSelected++;
				isBottonPressed = TRUE;
				system("cls");
				isSelected = isSelected % OVERNUM;
			}
		}
		if (key_Space < 0 || key_Enter < 0) {
			if (!isBottonPressed) {
				isBottonPressed = TRUE;
				switch (isSelected) {
				case 0:
					SetMode(GAME_MENU);
					Init();
					break;
				case 1:
					exit(0);
					break;
				}
			}
		}
	}

	if (key_A >= 0 && key_D >= 0 && key_Space >= 0 && key_Enter >= 0 && key_Right >= 0 && key_Left >= 0) {
		isBottonPressed = FALSE;
	}
}


void DrawOver() {
	switch (isSelected)
	{
	case 0:
		RestartSelected();
		break;
	case 1:
		ExitSelected();
		break;
	}
}

void UpdateClear() {

}

void DrawClear() {
	system("cls");

	for (int i = 0; i < BOX_MAX; i++) {
		if (box[i].use == FALSE) {
			OpenBoxNum++;
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++) {
		if (g_Enemy[i].alive == FALSE) {
			KilledEnemyNum++;
		}
	}




	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "           ____    _    __  __ _____    ____ _     _____    _    ____          " << std::endl;
	std::cout << "          / ___|  / `  |  `/  | ____|  / ___| |   | ____|  / `  |  _ `         " << std::endl;
	std::cout << "         | |  _  / _ ` | |`/| |  _|   | |   | |   |  _|   / _ ` | |_) |        " << std::endl;
	std::cout << "         | |_| |/ ___ `| |  | | |___  | |___| |___| |___ / ___ `|  _ <         " << std::endl;
	std::cout << "          `____/_/   `_`_|  |_|_____|  `____|_____|_____/_/   `_`_| `_`        " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                おめでとう！                                   " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                      無事に島から出られた、よく頑張った！                     " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                              開けた宝箱数：" << OpenBoxNum << "             " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                              敵の討伐数：" << KilledEnemyNum << "          " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;


	std::this_thread::sleep_for(std::chrono::milliseconds(3000));



	exit(0);


	//exit(0);



}



