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
#include "enemy.h"
#include "field.h"
#include "player.h"

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
ENEMY g_Enemy[ENEMY_MAX];

int enemySpeed;//�G�̈ړ����ԊԊu






// �v���C���[�̏���������
void InitEnemy(void)
{
	// �\���̂̏�����
	for (int i = 0; i < ENEMY_MAX; i++) {
		g_Enemy[i].alive = true;
	}

	g_Enemy[0].y = 50;
	g_Enemy[0].x = 77;

	g_Enemy[1].y = 53;
	g_Enemy[1].x = 92;

	g_Enemy[2].y = 51;
	g_Enemy[2].x = 54;

	g_Enemy[3].y = 56;
	g_Enemy[3].x = 18;

	g_Enemy[4].y = 31;
	g_Enemy[4].x = 55;

	g_Enemy[5].y = 33;
	g_Enemy[5].x = 89;


	g_Enemy[6].y = 38;
	g_Enemy[6].x = 21;

	g_Enemy[7].y = 25;
	g_Enemy[7].x = 36;

	g_Enemy[8].y = 22;
	g_Enemy[8].x = 76;

	g_Enemy[9].y = 25;
	g_Enemy[9].x = 113;

	g_Enemy[10].y = 18;
	g_Enemy[10].x = 114;

	g_Enemy[11].y = 14;
	g_Enemy[11].x = 65;

	g_Enemy[12].y = 13;
	g_Enemy[12].x = 74;

	g_Enemy[13].y = 8;
	g_Enemy[13].x = 22;

	g_Enemy[14].y = 6;
	g_Enemy[14].x = 52;

	g_Enemy[15].y = 4;
	g_Enemy[15].x = 30;

	g_Enemy[16].y = 7;
	g_Enemy[16].x = 135;

	g_Enemy[17].y = 42;
	g_Enemy[17].x = 137;

	g_Enemy[18].y = 61;
	g_Enemy[18].x = 92;

	g_Enemy[18].y = 52;
	g_Enemy[18].x = 114;




	enemySpeed = 40;
}


// �v���C���[�̏I������
void UninitEnemy(void)
{

}


// �v���C���[�̍X�V����
void UpdateEnemy(void)
{
	if (interval % enemySpeed == 0) {



		// �����O�̍��W��ۑ����Ă����i�ړ����ĂԂ��������͂��̍��W�֖߂��ׁj
		for (int i = 0; i < ENEMY_MAX; i++) {
			g_Enemy[i].old_x = g_Enemy[i].x;
			g_Enemy[i].old_y = g_Enemy[i].y;



			//std::this_thread::sleep_for(std::chrono::milliseconds(500));

			int dir = GetRand(0, 3);


			switch (dir)
			{
			case 0:
				g_Enemy[i].x--;
				break;
			case 1:
				g_Enemy[i].x++;
				break;
			case 2:
				g_Enemy[i].y--;
				break;
			case 3:
				g_Enemy[i].y++;
				break;
			default:
				break;
			}


			// MAP�Ƃ̓����蔻�菈��
			// �ړ��������NG�ȏꏊ�H
			int answer = CheckField(g_Enemy[i].y, g_Enemy[i].x);

			switch (answer)
			{
			case 1:
			case 5:
			case 6:
			case 7:
			case 8:// �ړ����Ă�NG�ȏꏊ�������̂őO�̏ꏊ�֖߂�
				g_Enemy[i].y = g_Enemy[i].old_y;
				g_Enemy[i].x = g_Enemy[i].old_x;
				break;
			case 2:
				if (g_Enemy[i].alive == true) {
					g_Enemy[i].y = g_Enemy[i].old_y;
					g_Enemy[i].x = g_Enemy[i].old_x;
					g_Enemy[i].alive = false;
					g_Player[0].hp -= 1;
				}

				break;


			default:
				break;
			}

		}


	}



}

//char mark[ENEMY_MAX]{
//	'E','H','B'
//};

// �v���C���[�̕`�揈��
void DrawEnemy(void)
{

	for (int i = 0; i < ENEMY_MAX; i++) {
		if (CheckField(g_Enemy[i].y, g_Enemy[i].x) == 7) {
			g_Enemy[i].alive = FALSE;
		}
		if (g_Enemy[i].alive == true) {
			// �v���C���[��MAP�̎w����W�֏�������
			SetField(g_Enemy[i].y, g_Enemy[i].x, 'E');
		}

	}

}






