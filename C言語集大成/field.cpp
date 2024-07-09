/*******************************************************************************
 * �^�C�g��:		field�v���O����
 * �v���O������:	field.cpp
 * �쐬��:		GP11A132 99 �O������
 * �쐬��:		2024/05/26
 *******************************************************************************/

 /*******************************************************************************
  * �C���N���[�h�t�@�C��
  *******************************************************************************/
#include "main.h"
#include "field.h"
#include "player.h"
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
	  //extern PLAYER g_Player[PLAYER_MAX];

	  // �}�b�v�f�[�^
char field_org[FIELD_H][FIELD_W + 1] = {
	// �I���W�i��field�f�[�^�i����+1���Ă���͕̂�����NULL�̕��j
	"****************************************************************************************************",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                                                                                  *",
	"*       *                                                                                          *",
	"*       *                              *                                                           *",
	"*                    *******           *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                    **********                             *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*****************       ****************                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *           ##############                                  *",
	"*                                      *           ##############                                  *",
	"*                                      *           ##############                                  *",
	"*                                                                                                  *",
	"*                                                                      ***********                 *",
	"*                                                                                                  *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                  **                  *                                                           *",
	"*                  **                  *                                                           *",
	"*                  **                  *                                                           *",
	"*                                      *                                                           *",
	"*                                      *             ***********                                   *",
	"*                                      *             ***********                                   *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"****************************************************************************************************",

};

char field[FIELD_H][FIELD_W + 1] = {
	// �\���pfield�f�[�^�i����+1���Ă���͕̂�����NULL�̕��j
	"****************************************************************************************************",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"****************************************************************************************************",
};

// field�̏���������
void InitField(void)
{
	/* �I���W�i��field�f�[�^��\���pfield�f�[�^�փR�s�[ */
	memcpy(field, field_org, sizeof(field));
	// SetMode(GAME_PLAYER);
}

// field�̏I������
void UninitField(void)
{
}

// field�̍X�V����
void UpdateField(void)
{
	/* �I���W�i��field�f�[�^��\���pfield�f�[�^�փR�s�[ */
	memcpy(field, field_org, sizeof(field));
}

// field�`�揈��
void DrawField(void)
{
	/* �������x���� */
	// std::this_thread::sleep_for(std::chrono::milliseconds(10));

	/* ��ʃN���A */
	//std::system("cls");

	/* �}�b�v�`�揈�� */
	//OLD
	//if (g_Player->x < MAP_W / 2 && g_Player->y < MAP_H / 2)
	//{
	//	// ����
	//	for (int i = 0; i < MAP_H; i++)
	//	{
	//		for (int j = 0; j < MAP_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);

	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x < MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2)
	//{
	//	// ����
	//	for (int i = FIELD_H - MAP_H; i < FIELD_H; i++)
	//	{
	//		for (int j = 0; j < MAP_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x < MAP_W / 2 && MAP_H / 2 <= g_Player->y <= FIELD_H - MAP_H / 2)
	//{
	//	// ����
	//	for (int i = g_Player->y - MAP_H / 2; i < g_Player->y + MAP_H / 2; i++)
	//	{
	//		for (int j = 0; j < MAP_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2)
	//{
	//	// �E��
	//	for (int i = 0; i < MAP_H; i++)
	//	{
	//		for (int j = FIELD_W - MAP_W; j < FIELD_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (MAP_W / 2 <= g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2)
	//{
	//	// ����
	//	for (int i = 0; i < MAP_H; i++)
	//	{
	//		for (int j = g_Player->x - MAP_W / 2; j < g_Player->x + MAP_W / 2; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2)
	//{
	//	// �E��
	//	for (int i = FIELD_H - MAP_H; i < FIELD_H; i++)
	//	{
	//		for (int j = FIELD_W - MAP_W; j < FIELD_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x > FIELD_W - MAP_W / 2 && MAP_H / 2 <= g_Player->y <= FIELD_H - MAP_H / 2)
	//{
	//	// �E��
	//	for (int i = g_Player->y - MAP_H / 2; i < g_Player->y + MAP_H / 2; i++)
	//	{
	//		for (int j = FIELD_W - MAP_W; j < FIELD_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}

	//else if (MAP_W / 2 <= g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2)
	//{
	//	// ����
	//	for (int i = FIELD_H - MAP_H; i < FIELD_H; i++)
	//	{
	//		for (int j = g_Player->x - MAP_W / 2; j < g_Player->x + MAP_W / 2; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else
	//{
	//	// ����
	//	for (int i = g_Player->y - MAP_H / 2; i < g_Player->y + MAP_H / 2; i++)
	//	{
	//		for (int j = g_Player->x - MAP_W / 2; j < g_Player->x + MAP_W / 2; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	if (g_Player->x < MAP_W / 2 && g_Player->y < MAP_H / 2) {
		// ����
		AddinUI(0, MAP_H, 0, MAP_W, 0, 0);
	}
	else if (g_Player->x < MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2) {
		// ����
		AddinUI(FIELD_H - MAP_H, FIELD_H, 0, MAP_W, 0, 0);
	}
	else if (g_Player->x < MAP_W / 2 && g_Player->y >= MAP_H / 2 && g_Player->y <= FIELD_H - MAP_H / 2) {
		// ����
		AddinUI(g_Player->y - MAP_H / 2, g_Player->y + MAP_H / 2, 0, MAP_W, 0, 0);
	}
	else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2) {
		// �E��
		AddinUI(0, MAP_H, FIELD_W - MAP_W, FIELD_W, 0, 0);
	}
	else if (g_Player->x >= MAP_W / 2 && g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2) {
		// ����
		AddinUI(0, MAP_H, g_Player->x - MAP_W / 2, g_Player->x + MAP_W / 2, 0, 0);
	}
	else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2) {
		// �E��
		AddinUI(FIELD_H - MAP_H, FIELD_H, FIELD_W - MAP_W, FIELD_W, 0, 0);
	}
	else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y >= MAP_H / 2 && g_Player->y <= FIELD_H - MAP_H / 2) {
		// �E��
		AddinUI(g_Player->y - MAP_H / 2, g_Player->y + MAP_H / 2, FIELD_W - MAP_W, FIELD_W, 0, 0);
	}
	else if (g_Player->x >= MAP_W / 2 && g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2) {
		// ����
		AddinUI(FIELD_H - MAP_H, FIELD_H, g_Player->x - MAP_W / 2, g_Player->x + MAP_W / 2, 0, 0);
	}
	else {
		// ����
		AddinUI(g_Player->y - MAP_H / 2, g_Player->y + MAP_H / 2, g_Player->x - MAP_W / 2, g_Player->x + MAP_W / 2, 0, 0);
	}



}

void AddinUI(int startY, int endY, int startX, int endX, int offsetY, int offsetX) {
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			SetUI(i - startY + offsetY, j - startX + offsetX, field[i][j]);
		}
	}
}

// �w�肵�����W��data����������
void SetField(int y, int x, char data)
{
	field[y][x] = data;
}

// �w�肵�����W�ɏ�����Ă���field�f�[�^���擾����
char GetField(int y, int x)
{
	return field[y][x];
}

// �w�肵�����W��OK�ȏꏊ�H
// OK�ȏꏊ�Ȃ�0
// NG�ȏꏊ�Ȃ�0�ȊO
int CheckField(int y, int x)
{
	int ans = 0; // �Ƃ肠����OK���Z�b�g���Ă���

	// NG�ȏꏊ�H
	char data = field[y][x];
	switch (data)
	{
	case '*':
		ans = 1; // �� ���̏ꏊ��NG�������̂�1���Z�b�g����
		break;
	case 'V':
	case 'A':
	case '<':
	case '>':
		ans = 2; //Player
		break;
	case '|':
	case'-':
		ans = 3;//��
		break;
	case'E':
		ans = 4;//�G
		break;





	default:
		break;
	}

	return ans; // ���ʂ�Ԃ�
}
