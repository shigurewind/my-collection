#include "main.h"
#include "door.h"
#include "field.h"


DOOR door[DOORMAX];

void InitDoor() {


	door[0].startY = 13;
	door[0].startX = 16;
	door[0].H = 2;
	door[0].W = 8;


}

//DOORÇÃî‘çÜÇGET
int CheckDoor(int y, int x)
{
	for (int i = 0; i < DOORMAX; ++i) {
		if (door[i].startY <= y <= door[i].startY + door[i].H && door[i].startX <= x <= door[i].startX + door[i].W) {
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


