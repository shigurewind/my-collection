#pragma once
#include "main.h"
#include "player.h"

#define BOX_MAX (10)


struct BOX
{


	//�󔠂̎��
	//�O�͖�+5�@�P�͐����j��+1�@�Q�͌�
	int type;

	//�󔠂̈ʒu
	int x;
	int y;

	//�g�������ǂ���
	bool use;

};


void InitBox(void);
void UpdateBox(void);
void DrawBox(void);
