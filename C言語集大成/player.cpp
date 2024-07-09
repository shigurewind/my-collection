/*******************************************************************************
* タイトル:		Playerプログラム
* プログラム名:	player.cpp
* 作成者:		GP11A132 99 外岡高明
* 作成日:		2024/05/26
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "field.h"
#include "arrow.h"

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
PLAYER g_Player[PLAYER_MAX];

int playerMoveSpeed;//player移動時間間隔
int playerActionSpeed;//player動作時間間隔



//プレイヤーの方向
char div_p[4]{
	'>','A','<','V'
};
//初期化
char div_player = div_p[0];




// フィールド用メンバー変数





// プレイヤーの初期化処理
void InitPlayer(void)
{

	// 構造体の初期化

	for (int i = 0; i < PLAYER_MAX; i++) {
		g_Player[i].x = 0;
		g_Player[i].y = 0;

		g_Player[i].old_x = 0;
		g_Player[i].old_y = 0;

		g_Player[i].hp = 100;
	}

	//初期化
	g_Player[0].y = 2;
	g_Player[0].x = 2;
	g_Player[0].hp = 100;

	g_Player[0].flag = 0;

	playerMoveSpeed = 4;

	playerActionSpeed = 5;

	g_Player[0].arrownum = 10;

	g_Player[0].arrowIsOut = 0;
}


// プレイヤーの終了処理
void UninitPlayer(void)
{

}


// プレイヤーの更新処理
void UpdatePlayer(void)
{
	if (g_Player[0].hp <= 0) {
		return;
	}//0ならぬける

	// 動く前の座標を保存しておく（移動してぶつかった時はこの座標へ戻す為）
	g_Player[0].old_x = g_Player[0].x;
	g_Player[0].old_y = g_Player[0].y;


	//新しい移動処理
	char key_W = GetKeyState('W'),     // W押し確認
		key_S = GetKeyState('S'),      // S押し確認
		key_A = GetKeyState('A'),      // A押し確認
		key_D = GetKeyState('D'),      // D押し確認
		key_attack = GetKeyState(' '), // Space押し確認
		key_J = GetKeyState('J'),
		key_K = GetKeyState('K'),
		key_L = GetKeyState('L');



	if (_kbhit())
	{
		//移動
		if (interval % playerMoveSpeed == 0) {
			if (key_W < 0)
			{
				g_Player[0].y -= 1;
				div_player = div_p[1];
				g_Player[0].flag = 1;
			}
			if (key_A < 0)
			{
				g_Player[0].x -= 1;
				div_player = div_p[2];
				g_Player[0].flag = 2;
			}
			if (key_S < 0)
			{
				g_Player[0].y += 1;
				div_player = div_p[3];
				g_Player[0].flag = 3;
			}
			if (key_D < 0)
			{
				g_Player[0].x += 1;
				div_player = div_p[0];
				g_Player[0].flag = 0;
			}
		}

		//動作
		if (interval % playerActionSpeed == 0) {

			//攻撃
			if (key_J < 0) {

			}

			//shoot
			if (key_K < 0) {

				if (g_Player[0].arrownum > 0) {
					SetArrow(g_Player[0].y, g_Player[0].x, g_Player[0].arrowIsOut);
					g_Player[0].arrowIsOut++;
					g_Player[0].arrownum--;
				}
				if (g_Player[0].arrowIsOut > 20) {
					g_Player[0].arrowIsOut = 0;
				}

			}

			//heal
			if (key_L < 0) {

			}
		}


	}

	//前の移動処理
	//リアルタイム処理
	//if (_kbhit() == 0)
	//{
	//	// ここに少しウェイト入れるとちらつきが抑えられるかも？
	//	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	//	return;
	//}

	//// キー入力処理
	//int key = _getch();
	//if ((key == 0) || (key == 224))	// 特殊Keyならもう１度取得する
	//{
	//	key = _getch();
	//}

	//// 押されたkeyの方向へ移動させる
	//switch (key)
	//{
	//case 'a':
	//case 0x4b:	// ←
	//	g_Player[0].x -= 1;
	//	div_player = div_p[2];
	//	break;

	//case 'd':
	//case 0x4d:	// →
	//	g_Player[0].x += 1;
	//	div_player = div_p[0];
	//	break;

	//case 'w':
	//case 0x48:	// ↑
	//	g_Player[0].y -= 1;
	//	div_player = div_p[1];
	//	break;

	//case 's':
	//case 0x50:	// ↓
	//	g_Player[0].y += 1;
	//	div_player = div_p[3];
	//	break;

	//case'j':
	//	//打つ
	//	break;
	//case'k':
	//	//シュート
	//	break;
	//case'l':
	//	//回復
	//	break;


	//default:
	//	break;
	//}

	// MAPとの当たり判定処理
	// 
	// 
	// 移動した先はNGな場所？
	int answer = CheckField(g_Player[0].y, g_Player[0].x);
	switch (answer)
	{
	case 1:	// 移動してはNGな場所だったので前の場所へ戻す
		g_Player[0].y = g_Player[0].old_y;
		g_Player[0].x = g_Player[0].old_x;
		break;
	case 2://当たり判定

		break;

	default:
		break;
	}


}


// プレイヤーの描画処理
void DrawPlayer(void)
{

	for (int i = 0; i < PLAYER_MAX; i++) {

		if (g_Player[0].hp <= 0) {
			continue;
		}//０以下ならスキップ

		SetField(g_Player[i].y, g_Player[i].x, div_player);
	}
	// プレイヤーをMAPの指定座標へ書き込む

}




