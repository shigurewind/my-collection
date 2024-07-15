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

	g_Enemy[0].y = 5;
	g_Enemy[0].x = 25;

	g_Enemy[1].y = 7;
	g_Enemy[1].x = 30;

	g_Enemy[2].y = 6;
	g_Enemy[2].x = 20;

	enemySpeed = 30;
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
			case 7:// �ړ����Ă�NG�ȏꏊ�������̂őO�̏ꏊ�֖߂�
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
		if (g_Enemy[i].alive == true) {
			// �v���C���[��MAP�̎w����W�֏�������
			SetField(g_Enemy[i].y, g_Enemy[i].x, 'E');
		}

	}

}




