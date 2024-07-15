#include "hook.h"
#include "enemy.h"

int hookFlag;
int hooknum;

HOOK hook[HOOKMAX];

void UpdateHook() {
	if (g_Player[0].isHook == TRUE) {

		switch (hookFlag)
		{
		case 0:
			if (hooknum == 0) {
				hook[hooknum].x++;
			}
			else {
				hook[hooknum].x = hook[hooknum - 1].x + 1;
			}
			break;
		case 1:
			if (hooknum == 0) {
				hook[hooknum].y--;
			}
			else {
				hook[hooknum].y = hook[hooknum - 1].y - 1;
			}

			break;
		case 2:
			if (hooknum == 0) {
				hook[hooknum].x--;
			}
			else {
				hook[hooknum].x = hook[hooknum - 1].x - 1;
			}
			break;
		case 3:
			if (hooknum == 0) {
				hook[hooknum].y++;
			}
			else {
				hook[hooknum].y = hook[hooknum - 1].y + 1;
			}
			break;
		}

		if (CheckField(hook[hooknum].y, hook[hooknum].x) == 1 || CheckField(hook[hooknum].y, hook[hooknum].x) == 5 || CheckField(hook[hooknum].y, hook[hooknum].x) == 6)//•Ç‚Æ‚©‚ ‚½‚é
		{
			if (hooknum == 0)
			{
				g_Player[0].isHook = FALSE;
			}
			else
			{
				g_Player[0].y = hook[hooknum - 1].y;
				g_Player[0].x = hook[hooknum - 1].x;
				g_Player[0].isHook = FALSE;
			}

		}
		else if (CheckField(hook[hooknum].y, hook[hooknum].x) == 4)//“G‚ð‚ ‚½‚é
		{
			g_Player[0].isHook = FALSE;
			if (hooknum > 1)
			{
				for (int i = 0; i < ENEMY_MAX; i++)
				{
					if (g_Enemy[i].y == hook[hooknum].y && g_Enemy[i].x == hook[hooknum].x) {
						g_Enemy[i].y = hook[1].y;
						g_Enemy[i].x = hook[1].x;

					}
					//“G‚ð‰Í‚É•ß‚Ü‚¦‚é
					if (CheckField(g_Enemy[i].y, g_Enemy[i].x) == 7) {
						g_Enemy[i].alive = FALSE;
					}
				}
			}
			/*else {
				g_Player[0].isHook = FALSE;
			}*/
		}
		else
		{
			hook[hooknum].use = TRUE;
		}

		hooknum++;

		if (hooknum == HOOKMAX) {
			hooknum = 0;
			g_Player[0].isHook = FALSE;
		}

	}


}


void DrawHook() {
	if (g_Player[0].isHook) {
		for (int i = 0; i < HOOKMAX; ++i) {
			if (hook[i].use == TRUE)
			{
				SetField(hook[i].y, hook[i].x, 'o');
			}
		}
	}
}

//player‚ÌˆÊ’u‚©‚çA‚†•ûŒü‚Ö
void UseHook(int y, int x, int f) {
	hooknum = 0;

	for (int i = 0; i < HOOKMAX; i++)
	{
		hook[i].y = y;
		hook[i].x = x;

	}

	g_Player[0].isHook = TRUE;
	hookFlag = f;


}