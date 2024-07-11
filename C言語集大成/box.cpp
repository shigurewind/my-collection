#include "box.h"
#include "field.h"
#include "ui.h"



BOX box[BOX_MAX];

void InitBox() {
	for (int i = 0; i < BOX_MAX; i++)
	{
		box[i].use = true;
	}
	box[0].type = 0;
	box[0].y = 2;
	box[0].x = 5;

}

void UpdateBox() {
	for (int i = 0; i < BOX_MAX; i++) {
		if (box[i].y == g_Player[0].y && box[i].x == g_Player[0].x && box[i].use == true) {
			switch (box[i].type)
			{
			case 0:
				g_Player[0].arrownum += 5;
				SetMessage(0);
				break;
			case 1:
				break;
			case 2:
				break;

			}
			box[i].use = false;
		}
	}



	//Message•\Ž¦
}


void DrawBox() {
	for (int i = 0; i < BOX_MAX; i++)
	{
		if (box[i].use) {
			SetField(box[i].y, box[i].x, 'B');
		}
	}

}