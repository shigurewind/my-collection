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
	std::cout << "                        GAME INTRODUCTION(���S�҂��X�X��)                      " << std::endl;
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
	std::cout << "                       => GAME INTRODUCTION(���S�҂��X�X��)                    " << std::endl;
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
	std::cout << "                        GAME INTRODUCTION(���S�҂��X�X��)                      " << std::endl;
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
	std::cout << "       *                          �Q�[���Љ�                           *       " << std::endl;
	std::cout << "     **                                                                 **     " << std::endl;
	std::cout << "   **          �ڂ��o�߂���A�N�͎��������O��m��Ȃ����ɂ��邱�Ƃ�      **    " << std::endl;
	std::cout << " **                �C�Â��܂����A�茳�Ɍ���{�A�����܂����Ȃ�               ** " << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                        �ǂ�����Ă��̓��Ő����c���āA                       |" << std::endl;
	std::cout << "|                         �o���������邩�A�����[                            |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                �`���n�܂��I                               |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|            _____________________________________________________            |" << std::endl;
	std::cout << "|           |       ��(J)�F�����O�Q�P�ʂ��U������                 |           |" << std::endl;
	std::cout << " *          |       �|(K)�F�����΁A�V���[�g�ł���             |          * " << std::endl;
	std::cout << " *          |       ���(L)�F�O7�P�ʂ܂łɃt�b�N�N���[�𔭎˂�    |          * " << std::endl;
	std::cout << "  *         |             �ǂɈ��������Ď�������������A          |         *  " << std::endl;
	std::cout << "   *        |             �G�ɓ��ĂĎ����̑O�Ɉ����񂹂�          |        *   " << std::endl;
	std::cout << "    *       |                                                     |       *    " << std::endl;
	std::cout << "     *      |             ������������āA�撣��I                |      *     " << std::endl;
	std::cout << "      *     |                 Space�L�[�Ŗ߂�                     |     *      " << std::endl;
	std::cout << "      *=================================================================*      " << std::endl;


	char key_Space = GetKeyState(' ');// �X�y�[�X�����m�F

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
	//�{�^�������m�F
	char key_W = GetKeyState('W'),     // W�����m�F
		key_Up = GetKeyState(VK_UP),// �㉟���m�F	
		key_S = GetKeyState('S'),// S�����m�F
		key_Down = GetKeyState(VK_DOWN),// �������m�F
		key_Space = GetKeyState(' '),// �X�y�[�X�����m�F
		key_Enter = GetKeyState(VK_RETURN);// Enter�����m�F

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
					//�I�����ꂽ���ڂ����s
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

