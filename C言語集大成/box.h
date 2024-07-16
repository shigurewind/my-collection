#pragma once
#include "main.h"
#include "player.h"

#define BOX_MAX (18)


struct BOX
{


	//�󔠂̎��
	//�O�͖�+10�@�P�͐����j��+1�@�Q�͌�
	int type;

	//�󔠂̈ʒu
	int x;
	int y;

	//�g�������ǂ���
	bool use;

};

extern BOX box[];


void InitBox(void);
void UpdateBox(void);
void DrawBox(void);
