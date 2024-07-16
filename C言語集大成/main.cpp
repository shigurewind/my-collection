/*******************************************************************************
* �^�C�g��:		���C���v���O����
* �v���O������:	main.cpp
* �쐬��:		GP11A132 99 �O������
* �쐬��:		2024/05/26
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "field.h"
#include "player.h"
#include "enemy.h"
#include "arrow.h"
#include "ui.h"
#include "box.h"
#include "hook.h"
#include "stone.h"
#include "door.h"
#include "menu.h"
#include "gameover.h"

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

//�ŏ���Mode
int g_Mode = GAME_TITLE;		// ���ݓ��삵�Ă����ԁi�Q�[�����[�h�j

int interval = 1;




/*******************************************************************************
 �֐���:	int main( void )
 ����:		void
 �߂�l:	����I��: int�^�� 0
 ����:		���C���֐�
*******************************************************************************/
int main(void)
{
	Init();			// �Q�[���S�̂̏���������

	// �Q�[�����[�h���I������Ȃ��ԁA�i�v�ɌJ��Ԃ�
	while (GetMode() < GAME_END)
	{

		//while (interval % timespace == 0) 
		Update();	// �Q�[���S�̂̍X�V����
		Draw();		// �Q�[���S�̂̕`�揈��



		if (interval <= 240) {
			interval++;
		}
		else {
			interval = 0;
		}






	}

	Uninit();		// �Q�[���S�̂̏I������

	return 0;
}



// �Q�[���S�̂̏���������
void Init(void)
{
	// �^�C�g���̏���������
	InitTitle();

	//Field�̏���������
	InitField();

	InitUI();

	//Player�̏�����
	InitPlayer();

	InitEnemy();

	InitBox();

	InitStone();

	InitDoor();


}


// �Q�[���S�̂̏I������
void Uninit(void)
{
	// �L�[���͑҂�
	std::rewind(stdin);
	std::cin.get();

	//�^�C�g���̏I������
	UninitTitle();

	//Field�̏I������
	UninitField();

	//Player�̏I������
	UninitPlayer();

	UninitEnemy();
}


// �Q�[���S�̂̍X�V����
void Update(void)
{
	// ���݂̃��[�h�ɂ���ď�������������
	switch (GetMode())
	{
	case GAME_TITLE:
		UpdateTitle();
		break;
	case GAME_MENU:
		UpdateMenu();

		break;


	case GAME_FIELD:

		UpdatePlayer();
		UpdateHook();
		UpdateEnemy();
		UpdateArrow();
		UpdateBox();
		UpdateField();


		UpdateUI();









		break;

	case GAME_OVER:
		UpdateOver();
		break;

	case GAME_CLEAR:
		UpdateClear();

		break;

	case GAME_END:

		break;


		// �{���͂����֑��̃Q�[�����[�h��ǉ�����
		// �Ⴆ�΁A�t�B�[���h�Ƃ��o�g���Ƃ��A�G���f�B���O�Ƃ��A�A�A


	}

}


// �Q�[���S�̂̕`�揈��
void Draw(void)
{

	// ���݂̃��[�h�ɂ���ď�������������
	switch (GetMode())
	{
	case GAME_TITLE:
		DrawTitle();
		break;
	case GAME_MENU:
		DrawMenu();
		break;

	case GAME_FIELD:
		DrawPlayer();
		DrawHook();
		DrawEnemy();
		DrawArrow();

		DrawBox();

		DrawStone();

		DrawDoor();

		DrawField();

		DrawMessage();

		DrawUI();

		break;

	case GAME_OVER:
		DrawOver();
		break;

	case GAME_CLEAR:
		DrawClear();
		break;


		// �{���͂����֑��̃Q�[�����[�h��ǉ�����
		// �Ⴆ�΁A�t�B�[���h�Ƃ��o�g���Ƃ��A�G���f�B���O�Ƃ��A�A�A



	}

}


// ���݂̃Q�[�����[�h���擾����
int GetMode(void)
{
	return g_Mode;
}


// �Q�[�����[�h��ύX����
void SetMode(int mode)
{

	g_Mode = mode;
}


// �����_���擾
int GetRand(int min, int max)
{
	static int flagRand = 0;
	static std::mt19937 g_mt;

	if (flagRand == 0)
	{
		// �����_����������
		std::random_device rnd;	// �񌈒�I�ȗ���������
		g_mt.seed(rnd());		// �����Z���k�E�c�C�X�^�Ł@�����͏���SEED
		flagRand = 1;
	}

	std::uniform_int_distribution<> random(min, max);	// ���������_����0�`100�͈̔�
	int answer = random(g_mt);
	return answer;
}



