/*******************************************************************************
* �^�C�g��:		Player�v���O����
* �v���O������:	player.cpp
* �쐬��:		GP11A132 99 �O������
* �쐬��:		2024/05/26
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "field.h"
#include "arrow.h"
#include "enemy.h"
#include "hook.h"
#include "stone.h"
#include "door.h"
#include "ui.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾(����Ȋ֐���p�ӂ��Ă���܂���錾/�֐��̐�����)
*******************************************************************************/



/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
PLAYER g_Player[PLAYER_MAX];

int playerMoveSpeed;//player�ړ����ԊԊu
//int playerActionSpeed;//player���쎞�ԊԊu

bool jPressed = false;
bool kPressed = false;
bool lPressed = false;


//�v���C���[�̕���
char div_p[4]{
	'>','A','<','V'
};
//������
char div_player = div_p[0];




// �t�B�[���h�p�����o�[�ϐ�





// �v���C���[�̏���������
void InitPlayer(void)
{

	// �\���̂̏�����


	//������
	g_Player[0].y = 61;
	g_Player[0].x = 78;

	//test
	/*g_Player[0].y = 6;
	g_Player[0].x = 145;*/


	g_Player[0].hp = 3;
	g_Player[0].hpMax = 3;


	g_Player[0].flag = 0;

	playerMoveSpeed = 3;

	//playerActionSpeed = 4;

	g_Player[0].arrownum = 10;

	g_Player[0].arrowIsOut = 0;

	g_Player[0].isAttack = false;

	g_Player[0].heartFraNum = 0;

	g_Player[0].keyNum = 0;
}


// �v���C���[�̏I������
void UninitPlayer(void)
{

}


// �v���C���[�̍X�V����
void UpdatePlayer(void)
{
	if (g_Player[0].hp <= 0) {
		SetMode(GAME_OVER);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		return;
	}//0�Ȃ�ʂ���

	// �����O�̍��W��ۑ����Ă����i�ړ����ĂԂ��������͂��̍��W�֖߂��ׁj
	g_Player[0].old_x = g_Player[0].x;
	g_Player[0].old_y = g_Player[0].y;


	//�V�����ړ�����
	char key_W = GetKeyState('W'),     // W�����m�F
		key_S = GetKeyState('S'),      // S�����m�F
		key_A = GetKeyState('A'),      // A�����m�F
		key_D = GetKeyState('D'),      // D�����m�F
		key_Space = GetKeyState(' '), // Space�����m�F
		key_J = GetKeyState('J'),
		key_K = GetKeyState('K'),
		key_L = GetKeyState('L');



	if (_kbhit())
	{
		//�ړ�
		if (interval % playerMoveSpeed == 0) {
			if (key_W < 0)
			{
				g_Player[0].y -= 1;
				div_player = div_p[1];
				g_Player[0].flag = 1;
			}
			if (key_A < 0)
			{
				g_Player[0].x -= 1;
				div_player = div_p[2];
				g_Player[0].flag = 2;
			}
			if (key_S < 0)
			{
				g_Player[0].y += 1;
				div_player = div_p[3];
				g_Player[0].flag = 3;
			}
			if (key_D < 0)
			{
				g_Player[0].x += 1;
				div_player = div_p[0];
				g_Player[0].flag = 0;
			}
		}

		//����



			//�U��
		if (key_J < 0) {
			if (!jPressed) {
				jPressed = true;
				Attack();
			}
		}

		//shoot
		if (key_K < 0) {
			if (!kPressed)
			{
				kPressed = true;
				if (g_Player[0].arrownum > 0) {
					SetArrow(g_Player[0].y, g_Player[0].x, g_Player[0].arrowIsOut, g_Player[0].flag);
					g_Player[0].arrowIsOut++;
					g_Player[0].arrownum--;
				}
				if (g_Player[0].arrowIsOut > 20) {
					g_Player[0].arrowIsOut = 0;
				}
			}

		}

		//������
		if (key_L < 0) {
			if (!lPressed) {
				lPressed = true;
				UseHook(g_Player[0].y, g_Player[0].x, g_Player[0].flag);

			}

		}

	}

	//�{�^�����O������
	if (key_J >= 0) {
		jPressed = false;
	}
	if (key_K >= 0) {
		kPressed = false;
	}
	if (key_L >= 0) {
		lPressed = false;
	}
	//Sleep(3);


	// MAP�Ƃ̓����蔻�菈��
	// 
	// 
	// �ړ��������NG�ȏꏊ�H
	int answer = CheckField(g_Player[0].y, g_Player[0].x);
	switch (answer)
	{
	case 1:	// �ړ����Ă�NG�ȏꏊ�������̂őO�̏ꏊ�֖߂�
		g_Player[0].y = g_Player[0].old_y;
		g_Player[0].x = g_Player[0].old_x;
		break;
	case 4://�G�ɓ����蔻��

		for (int i = 0; i < ENEMY_MAX; i++) {
			if (g_Enemy[i].x == g_Player[0].x && g_Enemy[i].y == g_Player[0].y && g_Enemy[i].alive == TRUE) {
				g_Player[0].hp -= 1;
				g_Enemy[i].alive = false;
			}
		}
		g_Player[0].y = g_Player[0].old_y;
		g_Player[0].x = g_Player[0].old_x;


		break;

	case 5://DOOR�ɂ�����
		if (g_Player[0].keyNum > 0) {
			int doornum = CheckDoor(g_Player[0].y, g_Player[0].x);
			door[doornum].opened = TRUE;
			g_Player[0].keyNum--;
			SetMessage(3);//DOOR���J����Message

		}
		else
		{
			g_Player[0].y = g_Player[0].old_y;
			g_Player[0].x = g_Player[0].old_x;
		}


		break;

	case 7:
		g_Player[0].hp--;
		g_Player[0].y = g_Player[0].old_y;
		g_Player[0].x = g_Player[0].old_x;
		SetMessage(4);

		break;

	case 8:
		SetMode(GAME_CLEAR);
		break;
	}


}


// �v���C���[�̕`�揈��
void DrawPlayer(void)
{



	if (g_Player[0].hp > 0) {
		SetField(g_Player[0].y, g_Player[0].x, div_player);
	}//�O�ȉ��Ȃ�X�L�b�v

	//�U���\��
	if (g_Player[0].isAttack == TRUE) {

		SetField(g_Player[0].attack_y1, g_Player[0].attack_x1, '+');
		SetField(g_Player[0].attack_y2, g_Player[0].attack_x2, '+');
		g_Player[0].isAttack = FALSE;
	}




	// �v���C���[��MAP�̎w����W�֏�������

}

void Attack()
{
	g_Player[0].isAttack = true;

	switch (g_Player[0].flag)
	{
	case 0:
		g_Player[0].attack_x1 = g_Player[0].x + 1;
		g_Player[0].attack_x2 = g_Player[0].x + 2;
		g_Player[0].attack_y1 = g_Player[0].y;
		g_Player[0].attack_y2 = g_Player[0].y;

		break;
	case 1:
		g_Player[0].attack_x1 = g_Player[0].x;
		g_Player[0].attack_x2 = g_Player[0].x;
		g_Player[0].attack_y1 = g_Player[0].y - 1;
		g_Player[0].attack_y2 = g_Player[0].y - 2;

		break;
	case 2:
		g_Player[0].attack_x1 = g_Player[0].x - 1;
		g_Player[0].attack_x2 = g_Player[0].x - 2;
		g_Player[0].attack_y1 = g_Player[0].y;
		g_Player[0].attack_y2 = g_Player[0].y;

		break;
	case 3:
		g_Player[0].attack_x1 = g_Player[0].x;
		g_Player[0].attack_x2 = g_Player[0].x;
		g_Player[0].attack_y1 = g_Player[0].y + 1;
		g_Player[0].attack_y2 = g_Player[0].y + 2;

		break;

	default:
		break;
	}

	//�΂�j��
	checkStone(g_Player[0].attack_y1, g_Player[0].attack_x1);
	checkStone(g_Player[0].attack_y2, g_Player[0].attack_x2);

	//enemy��|��
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (g_Enemy[i].alive == TRUE) {
			if ((g_Enemy[i].x == g_Player[0].attack_x1 && g_Enemy[i].y == g_Player[0].attack_y1) || (g_Enemy[i].x == g_Player[0].attack_x2 && g_Enemy[i].y == g_Player[0].attack_y2)) {
				g_Enemy[i].alive = FALSE;
			}
		}

	}
}






