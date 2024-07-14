#include "stone.h"
#include "field.h"

STONE stone[STONEMAX];

void InitStone() {
	for (int i = 0; i < STONEMAX; ++i) {
		stone[i].use = TRUE;
	}

	stone[0].y = 8;
	stone[0].x = 4;
}

void checkStone(int y, int x) {
	for (int i = 0; i < STONEMAX; ++i) {
		if (stone[i].y == y && stone[i].x == x) {
			stone[i].use = FALSE;
		}
	}
}

void DrawStone() {
	for (int i = 0; i < STONEMAX; i++)
	{
		if (stone[i].use) {
			SetField(stone[i].y, stone[i].x, '@');
		}

	}
}