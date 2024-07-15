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
#include "enemy.h"
#include "field.h"
#include "player.h"

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
ENEMY g_Enemy[ENEMY_MAX];

int enemySpeed;//敵の移動時間間隔






// プレイヤーの初期化処理
void InitEnemy(void)
{
	// 構造体の初期化
	for (int i = 0; i < ENEMY_MAX; i++) {
		g_Enemy[i].alive = true;
	}

	g_Enemy[0].y = 5;
	g_Enemy[0].x = 25;

	g_Enemy[1].y = 7;
	g_Enemy[1].x = 30;

	g_Enemy[2].y = 6;
	g_Enemy[2].x = 20;

	enemySpeed = 30;
}


// プレイヤーの終了処理
void UninitEnemy(void)
{

}


// プレイヤーの更新処理
void UpdateEnemy(void)
{
	if (interval % enemySpeed == 0) {



		// 動く前の座標を保存しておく（移動してぶつかった時はこの座標へ戻す為）
		for (int i = 0; i < ENEMY_MAX; i++) {
			g_Enemy[i].old_x = g_Enemy[i].x;
			g_Enemy[i].old_y = g_Enemy[i].y;



			//std::this_thread::sleep_for(std::chrono::milliseconds(500));

			int dir = GetRand(0, 3);


			switch (dir)
			{
			case 0:
				g_Enemy[i].x--;
				break;
			case 1:
				g_Enemy[i].x++;
				break;
			case 2:
				g_Enemy[i].y--;
				break;
			case 3:
				g_Enemy[i].y++;
				break;
			default:
				break;
			}


			// MAPとの当たり判定処理
			// 移動した先はNGな場所？
			int answer = CheckField(g_Enemy[i].y, g_Enemy[i].x);

			switch (answer)
			{
			case 1:
			case 5:
			case 6:
			case 7:// 移動してはNGな場所だったので前の場所へ戻す
				g_Enemy[i].y = g_Enemy[i].old_y;
				g_Enemy[i].x = g_Enemy[i].old_x;
				break;
			case 2:
				if (g_Enemy[i].alive == true) {
					g_Enemy[i].y = g_Enemy[i].old_y;
					g_Enemy[i].x = g_Enemy[i].old_x;
					g_Enemy[i].alive = false;
					g_Player[0].hp -= 1;
				}

				break;


			default:
				break;
			}

		}


	}



}

//char mark[ENEMY_MAX]{
//	'E','H','B'
//};

// プレイヤーの描画処理
void DrawEnemy(void)
{

	for (int i = 0; i < ENEMY_MAX; i++) {
		if (g_Enemy[i].alive == true) {
			// プレイヤーをMAPの指定座標へ書き込む
			SetField(g_Enemy[i].y, g_Enemy[i].x, 'E');
		}

	}

}




