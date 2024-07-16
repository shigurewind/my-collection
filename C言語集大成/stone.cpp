#include "stone.h"
#include "field.h"

STONE stone[STONEMAX];

void InitStone() {
	for (int i = 0; i < STONEMAX; ++i) {
		stone[i].use = TRUE;
	}

	stone[0].y = 61;
	stone[0].x = 87;

	stone[1].y = 61;
	stone[1].x = 88;

	stone[2].y = 36;
	stone[2].x = 103;

	stone[3].y = 37;
	stone[3].x = 103;

	stone[4].y = 21;
	stone[4].x = 83;

	stone[5].y = 21;
	stone[5].x = 113;

	stone[6].y = 21;
	stone[6].x = 114;

	stone[7].y = 21;
	stone[7].x = 115;

	stone[8].y = 21;
	stone[8].x = 116;

	stone[9].y = 3;
	stone[9].x = 16;

	stone[10].y = 4;
	stone[10].x = 16;

	stone[11].y = 17;
	stone[11].x = 9;

	stone[12].y = 18;
	stone[12].x = 9;

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