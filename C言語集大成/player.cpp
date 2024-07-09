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
int playerActionSpeed;//player���쎞�ԊԊu



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

	for (int i = 0; i < PLAYER_MAX; i++) {
		g_Player[i].x = 0;
		g_Player[i].y = 0;

		g_Player[i].old_x = 0;
		g_Player[i].old_y = 0;

		g_Player[i].hp = 100;
	}

	//������
	g_Player[0].y = 2;
	g_Player[0].x = 2;
	g_Player[0].hp = 100;

	g_Player[0].flag = 0;

	playerMoveSpeed = 4;

	playerActionSpeed = 5;

	g_Player[0].arrownum = 10;

	g_Player[0].arrowIsOut = 0;
}


// �v���C���[�̏I������
void UninitPlayer(void)
{

}


// �v���C���[�̍X�V����
void UpdatePlayer(void)
{
	if (g_Player[0].hp <= 0) {
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
		key_attack = GetKeyState(' '), // Space�����m�F
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
		if (interval % playerActionSpeed == 0) {

			//�U��
			if (key_J < 0) {

			}

			//shoot
			if (key_K < 0) {

				if (g_Player[0].arrownum > 0) {
					SetArrow(g_Player[0].y, g_Player[0].x, g_Player[0].arrowIsOut);
					g_Player[0].arrowIsOut++;
					g_Player[0].arrownum--;
				}
				if (g_Player[0].arrowIsOut > 20) {
					g_Player[0].arrowIsOut = 0;
				}

			}

			//heal
			if (key_L < 0) {

			}
		}


	}

	//�O�̈ړ�����
	//���A���^�C������
	//if (_kbhit() == 0)
	//{
	//	// �����ɏ����E�F�C�g�����Ƃ�������}�����邩���H
	//	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	//	return;
	//}

	//// �L�[���͏���
	//int key = _getch();
	//if ((key == 0) || (key == 224))	// ����Key�Ȃ�����P�x�擾����
	//{
	//	key = _getch();
	//}

	//// �����ꂽkey�̕����ֈړ�������
	//switch (key)
	//{
	//case 'a':
	//case 0x4b:	// ��
	//	g_Player[0].x -= 1;
	//	div_player = div_p[2];
	//	break;

	//case 'd':
	//case 0x4d:	// ��
	//	g_Player[0].x += 1;
	//	div_player = div_p[0];
	//	break;

	//case 'w':
	//case 0x48:	// ��
	//	g_Player[0].y -= 1;
	//	div_player = div_p[1];
	//	break;

	//case 's':
	//case 0x50:	// ��
	//	g_Player[0].y += 1;
	//	div_player = div_p[3];
	//	break;

	//case'j':
	//	//�ł�
	//	break;
	//case'k':
	//	//�V���[�g
	//	break;
	//case'l':
	//	//��
	//	break;


	//default:
	//	break;
	//}

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
	case 2://�����蔻��

		break;

	default:
		break;
	}


}


// �v���C���[�̕`�揈��
void DrawPlayer(void)
{

	for (int i = 0; i < PLAYER_MAX; i++) {

		if (g_Player[0].hp <= 0) {
			continue;
		}//�O�ȉ��Ȃ�X�L�b�v

		SetField(g_Player[i].y, g_Player[i].x, div_player);
	}
	// �v���C���[��MAP�̎w����W�֏�������

}




