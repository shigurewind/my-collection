#pragma once
#include "main.h"
#include "player.h"

#define BOX_MAX (10)


struct BOX
{


	//•ó” ‚Ìí—Ş
	//‚O‚Í–î+5@‚P‚Í¶–½”j•Ğ+1@‚Q‚ÍŒ®
	int type;

	//•ó” ‚ÌˆÊ’u
	int x;
	int y;

	//g‚Á‚½‚©‚Ç‚¤‚©
	bool use;

};


void InitBox(void);
void UpdateBox(void);
void DrawBox(void);
