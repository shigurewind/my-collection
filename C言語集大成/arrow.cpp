#include "main.h"
#include "field.h"
#include "player.h"
#include "enemy.h"
#include "arrow.h"

struct ARROW arrow[];

char arrowStyle[2] = {
	'-','|'
};



void UpdateArrow() {

	for (int i = 0; i < g_Player[0].arrowIsOut + 1; i++) {
		if (arrow[i].use == true) {


			//–î‚ÌˆÚ“®
			switch (arrow[i].flag)
			{
			case 0:
				arrow[i].x++;
				break;
			case 1:
				arrow[i].y--;
				break;
			case 2:
				arrow[i].x--;
				break;
			case 3:
				arrow[i].y++;
				break;

			}

			//“–‚½‚è”»’è
			int answer = CheckField(arrow[i].y, arrow[i].x);
			switch (answer)
			{
			case 1:
				arrow[i].use = false;
				break;
			case 4:
				arrow[i].use = false;
				break;
			}
		}
	}

}

void DrawArrow() {

	for (int i = 0; i < g_Player[0].arrowIsOut + 1; i++) {
		if (arrow[i].use == true) {
			//printf("”­ŽË‚·‚é");
			SetField(arrow[i].y, arrow[i].x, arrow[i].style);
		}

	}

}

//Player‚ÌˆÊ’u‚©‚ç”­ŽËA‘æ‚Ž”Ô–î
void SetArrow(int y, int x, int n) {


	switch (g_Player->flag)
	{
	case 0:
		//‰E‚É”­ŽË
		arrow[n].use = true;
		arrow[n].flag = 0;
		arrow[n].x = g_Player->x + 1;
		arrow[n].y = g_Player->y;
		arrow[n].style = arrowStyle[0];

		break;
	case 1:
		//ã‚É”­ŽË
		arrow[n].use = true;
		arrow[n].flag = 1;
		arrow[n].x = g_Player->x;
		arrow[n].y = g_Player->y - 1;
		arrow[n].style = arrowStyle[1];

		break;
	case 2:
		//¶‚É”­ŽË
		arrow[n].use = true;
		arrow[n].flag = 2;
		arrow[n].x = g_Player->x - 1;
		arrow[n].y = g_Player->y;
		arrow[n].style = arrowStyle[0];

		break;
	case 3:
		//‰º‚É”­ŽË
		arrow[n].use = true;
		arrow[n].flag = 3;
		arrow[n].x = g_Player->x;
		arrow[n].y = g_Player->y + 1;
		arrow[n].style = arrowStyle[1];

		break;

	default:
		break;
	}

}
