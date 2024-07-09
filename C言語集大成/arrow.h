#pragma once

#define ARROW_MAX (100)

struct ARROW
{
	//矢の番号
	int number;

	//使っているかどうか判断
	BOOL use;

	//矢の位置
	int x;
	int y;

	//方向、0右、1上、2左、3下
	int flag;

	char style;


};

extern struct ARROW arrow[ARROW_MAX];



/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

void UpdateArrow(void);
void DrawArrow(void);

void SetArrow(int x, int y, int n);
