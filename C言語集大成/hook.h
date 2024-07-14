#pragma once

#include "main.h"
#include "player.h"
#include "field.h"

#define HOOKMAX (7)



struct HOOK
{
	BOOL use;



	//ˆÊ’u
	int x;
	int y;

	//hook‚Ì•ûŒü
	int flag;
};

extern HOOK hook[HOOKMAX];

void UpdateHook(void);
void DrawHook(void);
void UseHook(int y, int x, int f);

