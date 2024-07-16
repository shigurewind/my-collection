#include "main.h"
#include "door.h"
#include "field.h"


DOOR door[DOORMAX];

void InitDoor() {


	door[0].startY = 44;
	door[0].startX = 79;
	door[0].H = 2;
	door[0].W = 4;

	door[1].startY = 24;
	door[1].startX = 105;
	door[1].H = 2;
	door[1].W = 2;

	door[2].startY = 13;
	door[2].startX = 91;
	door[2].H = 1;
	door[2].W = 2;

	door[3].startY = 11;
	door[3].startX = 21;
	door[3].H = 5;
	door[3].W = 4;

	door[4].startY = 10;
	door[4].startX = 135;
	door[4].H = 2;
	door[4].W = 6;



}

//DOORÇÃî‘çÜÇGET
int CheckDoor(int y, int x)
{
	for (int i = 0; i < DOORMAX; ++i) {
		if (door[i].startY <= y && y <= door[i].startY + door[i].H && door[i].startX <= x && x <= door[i].startX + door[i].W) {
			return i;
		}
	}

	return DOORMAX + 1;
}

void DrawDoor()
{
	for (int i = 0; i < DOORMAX; i++)
	{
		if (!door[i].opened) {
			for (int j = door[i].startY; j < door[i].startY + door[i].H; ++j) {
				for (int k = door[i].startX; k < door[i].startX + door[i].W; k++)
				{
					SetField(j, k, '#');
				}
			}
		}
	}
}


