#pragma once

#define ARROW_MAX (100)

struct ARROW
{
	//��̔ԍ�
	int number;

	//�g���Ă��邩�ǂ������f
	BOOL use;

	//��̈ʒu
	int x;
	int y;

	//�����A0�E�A1��A2���A3��
	int flag;

	char style;


};

extern struct ARROW arrow[ARROW_MAX];



/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/

void UpdateArrow(void);
void DrawArrow(void);

void SetArrow(int x, int y, int n);
