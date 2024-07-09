/*******************************************************************************
 * タイトル:		fieldプログラム
 * プログラム名:	field.cpp
 * 作成者:		GP11A132 99 外岡高明
 * 作成日:		2024/05/26
 *******************************************************************************/

 /*******************************************************************************
  * インクルードファイル
  *******************************************************************************/
#include "main.h"
#include "field.h"
#include "player.h"
#include "ui.h"

  /*******************************************************************************
   * マクロ定義
   *******************************************************************************/

   /*******************************************************************************
	* 構造体定義
	*******************************************************************************/

	/*******************************************************************************
	 * プロトタイプ宣言(こんな関数を用意してありますよ宣言/関数の説明書)
	 *******************************************************************************/

	 /*******************************************************************************
	  * グローバル変数
	  *******************************************************************************/
	  //extern PLAYER g_Player[PLAYER_MAX];

	  // マップデータ
char field_org[FIELD_H][FIELD_W + 1] = {
	// オリジナルfieldデータ（横を+1しているのは文末のNULLの分）
	"****************************************************************************************************",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                                                                                  *",
	"*       *                                                                                          *",
	"*       *                              *                                                           *",
	"*                    *******           *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                    **********                             *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*****************       ****************                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *           ##############                                  *",
	"*                                      *           ##############                                  *",
	"*                                      *           ##############                                  *",
	"*                                                                                                  *",
	"*                                                                      ***********                 *",
	"*                                                                                                  *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                  **                  *                                                           *",
	"*                  **                  *                                                           *",
	"*                  **                  *                                                           *",
	"*                                      *                                                           *",
	"*                                      *             ***********                                   *",
	"*                                      *             ***********                                   *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"*                                      *                                                           *",
	"****************************************************************************************************",

};

char field[FIELD_H][FIELD_W + 1] = {
	// 表示用fieldデータ（横を+1しているのは文末のNULLの分）
	"****************************************************************************************************",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"*                                                                                                  *",
	"****************************************************************************************************",
};

// fieldの初期化処理
void InitField(void)
{
	/* オリジナルfieldデータを表示用fieldデータへコピー */
	memcpy(field, field_org, sizeof(field));
	// SetMode(GAME_PLAYER);
}

// fieldの終了処理
void UninitField(void)
{
}

// fieldの更新処理
void UpdateField(void)
{
	/* オリジナルfieldデータを表示用fieldデータへコピー */
	memcpy(field, field_org, sizeof(field));
}

// field描画処理
void DrawField(void)
{
	/* 処理速度調整 */
	// std::this_thread::sleep_for(std::chrono::milliseconds(10));

	/* 画面クリア */
	//std::system("cls");

	/* マップ描画処理 */
	//OLD
	//if (g_Player->x < MAP_W / 2 && g_Player->y < MAP_H / 2)
	//{
	//	// 左上
	//	for (int i = 0; i < MAP_H; i++)
	//	{
	//		for (int j = 0; j < MAP_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);

	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x < MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2)
	//{
	//	// 左下
	//	for (int i = FIELD_H - MAP_H; i < FIELD_H; i++)
	//	{
	//		for (int j = 0; j < MAP_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x < MAP_W / 2 && MAP_H / 2 <= g_Player->y <= FIELD_H - MAP_H / 2)
	//{
	//	// 左中
	//	for (int i = g_Player->y - MAP_H / 2; i < g_Player->y + MAP_H / 2; i++)
	//	{
	//		for (int j = 0; j < MAP_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2)
	//{
	//	// 右上
	//	for (int i = 0; i < MAP_H; i++)
	//	{
	//		for (int j = FIELD_W - MAP_W; j < FIELD_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (MAP_W / 2 <= g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2)
	//{
	//	// 中上
	//	for (int i = 0; i < MAP_H; i++)
	//	{
	//		for (int j = g_Player->x - MAP_W / 2; j < g_Player->x + MAP_W / 2; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2)
	//{
	//	// 右下
	//	for (int i = FIELD_H - MAP_H; i < FIELD_H; i++)
	//	{
	//		for (int j = FIELD_W - MAP_W; j < FIELD_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else if (g_Player->x > FIELD_W - MAP_W / 2 && MAP_H / 2 <= g_Player->y <= FIELD_H - MAP_H / 2)
	//{
	//	// 右中
	//	for (int i = g_Player->y - MAP_H / 2; i < g_Player->y + MAP_H / 2; i++)
	//	{
	//		for (int j = FIELD_W - MAP_W; j < FIELD_W; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}

	//else if (MAP_W / 2 <= g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2)
	//{
	//	// 中下
	//	for (int i = FIELD_H - MAP_H; i < FIELD_H; i++)
	//	{
	//		for (int j = g_Player->x - MAP_W / 2; j < g_Player->x + MAP_W / 2; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	//else
	//{
	//	// 中中
	//	for (int i = g_Player->y - MAP_H / 2; i < g_Player->y + MAP_H / 2; i++)
	//	{
	//		for (int j = g_Player->x - MAP_W / 2; j < g_Player->x + MAP_W / 2; j++)
	//		{
	//			//std::cout << field[i][j];
	//			SetUI(i, j, field[i][j]);
	//		}
	//		//std::cout << "\n";
	//	}
	//}
	if (g_Player->x < MAP_W / 2 && g_Player->y < MAP_H / 2) {
		// 左上
		AddinUI(0, MAP_H, 0, MAP_W, 0, 0);
	}
	else if (g_Player->x < MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2) {
		// 左下
		AddinUI(FIELD_H - MAP_H, FIELD_H, 0, MAP_W, 0, 0);
	}
	else if (g_Player->x < MAP_W / 2 && g_Player->y >= MAP_H / 2 && g_Player->y <= FIELD_H - MAP_H / 2) {
		// 左中
		AddinUI(g_Player->y - MAP_H / 2, g_Player->y + MAP_H / 2, 0, MAP_W, 0, 0);
	}
	else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2) {
		// 右上
		AddinUI(0, MAP_H, FIELD_W - MAP_W, FIELD_W, 0, 0);
	}
	else if (g_Player->x >= MAP_W / 2 && g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y < MAP_H / 2) {
		// 中上
		AddinUI(0, MAP_H, g_Player->x - MAP_W / 2, g_Player->x + MAP_W / 2, 0, 0);
	}
	else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2) {
		// 右下
		AddinUI(FIELD_H - MAP_H, FIELD_H, FIELD_W - MAP_W, FIELD_W, 0, 0);
	}
	else if (g_Player->x > FIELD_W - MAP_W / 2 && g_Player->y >= MAP_H / 2 && g_Player->y <= FIELD_H - MAP_H / 2) {
		// 右中
		AddinUI(g_Player->y - MAP_H / 2, g_Player->y + MAP_H / 2, FIELD_W - MAP_W, FIELD_W, 0, 0);
	}
	else if (g_Player->x >= MAP_W / 2 && g_Player->x <= FIELD_W - MAP_W / 2 && g_Player->y > FIELD_H - MAP_H / 2) {
		// 中下
		AddinUI(FIELD_H - MAP_H, FIELD_H, g_Player->x - MAP_W / 2, g_Player->x + MAP_W / 2, 0, 0);
	}
	else {
		// 中中
		AddinUI(g_Player->y - MAP_H / 2, g_Player->y + MAP_H / 2, g_Player->x - MAP_W / 2, g_Player->x + MAP_W / 2, 0, 0);
	}



}

void AddinUI(int startY, int endY, int startX, int endX, int offsetY, int offsetX) {
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			SetUI(i - startY + offsetY, j - startX + offsetX, field[i][j]);
		}
	}
}

// 指定した座標にdataを書き込む
void SetField(int y, int x, char data)
{
	field[y][x] = data;
}

// 指定した座標に書かれているfieldデータを取得する
char GetField(int y, int x)
{
	return field[y][x];
}

// 指定した座標はOKな場所？
// OKな場所なら0
// NGな場所なら0以外
int CheckField(int y, int x)
{
	int ans = 0; // とりあえずOKをセットしておく

	// NGな場所？
	char data = field[y][x];
	switch (data)
	{
	case '*':
		ans = 1; // 壁 その場所はNGだったので1をセットする
		break;
	case 'V':
	case 'A':
	case '<':
	case '>':
		ans = 2; //Player
		break;
	case '|':
	case'-':
		ans = 3;//矢
		break;
	case'E':
		ans = 4;//敵
		break;





	default:
		break;
	}

	return ans; // 結果を返す
}
