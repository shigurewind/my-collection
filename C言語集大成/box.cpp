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
	box[0].y = 61;
	box[0].x = 101;

	box[1].type = 0;
	box[1].y = 57;
	box[1].x = 55;

	box[2].type = 2;
	box[2].y = 50;
	box[2].x = 30;

	box[3].type = 1;
	box[3].y = 54;
	box[3].x = 16;

	box[4].type = 1;
	box[4].y = 50;
	box[4].x = 106;

	box[5].type = 2;
	box[5].y = 40;
	box[5].x = 140;

	box[6].type = 1;
	box[6].y = 30;
	box[6].x = 100;

	box[7].type = 2;
	box[7].y = 33;
	box[7].x = 56;

	box[8].type = 1;
	box[8].y = 39;
	box[8].x = 18;

	box[9].type = 2;
	box[9].y = 22;
	box[9].x = 47;

	box[10].type = 0;
	box[10].y = 20;
	box[10].x = 66;

	box[11].type = 1;
	box[11].y = 15;
	box[11].x = 121;

	box[12].type = 1;
	box[12].y = 9;
	box[12].x = 100;

	box[13].type = 2;
	box[13].y = 9;
	box[13].x = 63;

	box[14].type = 1;
	box[14].y = 7;
	box[14].x = 17;

	box[15].type = 0;
	box[15].y = 5;
	box[15].x = 1;

	box[16].type = 1;
	box[16].y = 27;
	box[16].x = 6;

	box[17].type = 0;
	box[17].y = 27;
	box[17].x = 147;




}

//BOX“–‚½‚è”»’è
void UpdateBox() {
	for (int i = 0; i < BOX_MAX; i++) {
		if (box[i].y == g_Player[0].y && box[i].x == g_Player[0].x && box[i].use == true) {
			switch (box[i].type)
			{
			case 0:
				g_Player[0].arrownum += 10;
				SetMessage(0);
				break;
			case 1:
				g_Player[0].heartFraNum++;
				SetMessage(1);

				break;
			case 2:
				g_Player[0].keyNum++;
				SetMessage(2);

				break;
			case 3:


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