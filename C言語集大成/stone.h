#pragma once

#include "main.h"


#define STONEMAX (10)

struct STONE
{
	int y;
	int x;

	BOOL use;


};

extern STONE stone[STONEMAX];

void InitStone();
void checkStone(int y, int x);
void DrawStone();
