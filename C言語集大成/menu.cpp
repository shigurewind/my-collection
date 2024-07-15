#include "main.h"
#include "menu.h"

int itemElected;

BOOL isPressed = FALSE;

BOOL isIntroduction;

void StartElected() {
	system("cls");

	std::cout << "                                                                               " << std::endl;
	std::cout << "            _          _                          _                            " << std::endl;
	std::cout << "           / `      __| | __   __   ___   _ __   | |_   _   _   _ __    ___    " << std::endl;
	std::cout << "          / _ `    / _` | ` ` / /  / _ ` | '_ `  | __| | | | | | '__|  / _ `   " << std::endl;
	std::cout << "         / ___ `  | (_| |  ` V /  |  __/ | | | | | |_  | |_| | | |    |  __/   " << std::endl;
	std::cout << "        /_/   `_`  `__,_|   `_/    `___| |_| |_|  `__|  `__,_| |_|     `___|   " << std::endl;
	std::cout << "              _             ___         _                       _              " << std::endl;
	std::cout << "             (_)  _ __     |_ _|  ___  | |   __ _   _ __     __| |             " << std::endl;
	std::cout << "             | | | '_ `     | |  / __| | |  / _` | | '_ `   / _` |             " << std::endl;
	std::cout << "             | | | | | |    | |  {`__` | | | (_| | | | | | | (_| |             " << std::endl;
	std::cout << "             |_| |_| |_|   |___| |___/ |_|  `__,_| |_| |_|  `__,_|             " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                => GAME START                                  " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                        GAME INTRODUCTION(初心者おススメ)                      " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                   EXIT                                        " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
}

void IntroductionElected() {
	system("cls");

	std::cout << "                                                                               " << std::endl;
	std::cout << "            _          _                          _                            " << std::endl;
	std::cout << "           / `      __| | __   __   ___   _ __   | |_   _   _   _ __    ___    " << std::endl;
	std::cout << "          / _ `    / _` | ` ` / /  / _ ` | '_ `  | __| | | | | | '__|  / _ `   " << std::endl;
	std::cout << "         / ___ `  | (_| |  ` V /  |  __/ | | | | | |_  | |_| | | |    |  __/   " << std::endl;
	std::cout << "        /_/   `_`  `__,_|   `_/    `___| |_| |_|  `__|  `__,_| |_|     `___|   " << std::endl;
	std::cout << "              _             ___         _                       _              " << std::endl;
	std::cout << "             (_)  _ __     |_ _|  ___  | |   __ _   _ __     __| |             " << std::endl;
	std::cout << "             | | | '_ `     | |  / __| | |  / _` | | '_ `   / _` |             " << std::endl;
	std::cout << "             | | | | | |    | |  {`__` | | | (_| | | | | | | (_| |             " << std::endl;
	std::cout << "             |_| |_| |_|   |___| |___/ |_|  `__,_| |_| |_|  `__,_|             " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                 GAME START                                    " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                       => GAME INTRODUCTION(初心者おススメ)                    " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                   EXIT                                        " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
}

void ExitElected() {
	system("cls");

	std::cout << "                                                                               " << std::endl;
	std::cout << "            _          _                          _                            " << std::endl;
	std::cout << "           / `      __| | __   __   ___   _ __   | |_   _   _   _ __    ___    " << std::endl;
	std::cout << "          / _ `    / _` | ` ` / /  / _ ` | '_ `  | __| | | | | | '__|  / _ `   " << std::endl;
	std::cout << "         / ___ `  | (_| |  ` V /  |  __/ | | | | | |_  | |_| | | |    |  __/   " << std::endl;
	std::cout << "        /_/   `_`  `__,_|   `_/    `___| |_| |_|  `__|  `__,_| |_|     `___|   " << std::endl;
	std::cout << "              _             ___         _                       _              " << std::endl;
	std::cout << "             (_)  _ __     |_ _|  ___  | |   __ _   _ __     __| |             " << std::endl;
	std::cout << "             | | | '_ `     | |  / __| | |  / _` | | '_ `   / _` |             " << std::endl;
	std::cout << "             | | | | | |    | |  {`__` | | | (_| | | | | | | (_| |             " << std::endl;
	std::cout << "             |_| |_| |_|   |___| |___/ |_|  `__,_| |_| |_|  `__,_|             " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                 GAME START                                    " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                        GAME INTRODUCTION(初心者おススメ)                      " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                  => EXIT                                      " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
	std::cout << "                                                                               " << std::endl;
}

void IntroductionDisplay() {
	system("cls");

	std::cout << "          ===========================================================          " << std::endl;
	std::cout << "         *                                                           *         " << std::endl;
	std::cout << "        **                                                           **        " << std::endl;
	std::cout << "       *                          ゲーム紹介                           *       " << std::endl;
	std::cout << "     **                                                                 **     " << std::endl;
	std::cout << "   **          目が覚めたら、君は自分が名前を知らない島にいることを      **    " << std::endl;
	std::cout << " **                気づきました、手元に剣一本、かぎ爪しかない               ** " << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                        どうやってこの島で生き残って、                       |" << std::endl;
	std::cout << "|                         出口を見つけるか、さあー                            |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                冒険始まるよ！                               |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|            _____________________________________________________            |" << std::endl;
	std::cout << "|           |       剣(J)：自分前２単位を攻撃する                 |           |" << std::endl;
	std::cout << " *          |       弓(K)：矢があれば、シュートできる             |          * " << std::endl;
	std::cout << " *          |       鉤爪(L)：前7単位までにフッククローを発射し    |          * " << std::endl;
	std::cout << "  *         |             壁に引っかけて自分を引っ張り、          |         *  " << std::endl;
	std::cout << "   *        |             敵に当てて自分の前に引き寄せる          |        *   " << std::endl;
	std::cout << "    *       |                                                     |       *    " << std::endl;
	std::cout << "     *      |             道具を活かして、頑張れ！                |      *     " << std::endl;
	std::cout << "      *     |                 Spaceキーで戻る                     |     *      " << std::endl;
	std::cout << "      *=================================================================*      " << std::endl;


	char key_Space = GetKeyState(' ');// スペース押し確認

	if (_kbhit()) {
		if (key_Space < 0) {
			if (!isPressed) {
				isPressed = TRUE;
				isIntroduction = FALSE;
			}

		}
	}

	if (key_Space >= 0) {
		isPressed = FALSE;
	}

}



void UpdateMenu() {
	//Update menu
	//ボタン押し確認
	char key_W = GetKeyState('W'),     // W押し確認
		key_Up = GetKeyState(VK_UP),// 上押し確認	
		key_S = GetKeyState('S'),// S押し確認
		key_Down = GetKeyState(VK_DOWN),// 下押し確認
		key_Space = GetKeyState(' '),// スペース押し確認
		key_Enter = GetKeyState(VK_RETURN);// Enter押し確認

	if (_kbhit())
	{
		if (!isIntroduction) {
			if (key_W < 0 || key_Up < 0)
			{
				if (!isPressed) {
					isPressed = TRUE;
					system("cls");
					itemElected--;
					if (itemElected == -1) {
						itemElected = MenuNum - 1;
					}
				}

			}
			if (key_S < 0 || key_Down < 0) {
				if (!isPressed) {
					isPressed = TRUE;
					system("cls");
					itemElected++;
					itemElected = itemElected % MenuNum;
				}
			}

			if (key_Space < 0 || key_Enter < 0) {
				if (!isPressed) {
					isPressed = TRUE;
					//選択された項目を実行
					switch (itemElected) {
					case 0:
						//Game Start
						SetMode(GAME_FIELD);

						break;
					case 1:
						//Game intrduction
						system("cls");
						isIntroduction = true;

						break;
					case 2:
						//Game Exit

						break;
					}
				}
			}
		}



	}

	if (key_W >= 0 && key_S >= 0 && key_Space >= 0 && key_Enter >= 0 && key_Up >= 0 && key_Down >= 0) {
		isPressed = false;
	}

}

void DrawMenu() {
	//draw menu
	switch (itemElected)
	{
	case 0:
		StartElected();

		break;
	case 1:
		if (isIntroduction) {
			IntroductionDisplay();
		}
		else {
			IntroductionElected();
		}

		break;
	case 2:
		ExitElected();
		break;
	}

}

