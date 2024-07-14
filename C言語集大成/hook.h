#pragma once

#include "main.h"
#include "player.h"
#include "field.h"

#define HOOKMAX (7)



struct HOOK
{
	BOOL use;



	//�ʒu
	int x;
	int y;

	//hook�̕���
	int flag;
};

extern HOOK hook[HOOKMAX];

void UpdateHook(void);
void DrawHook(void);
void UseHook(int y, int x, int f);

