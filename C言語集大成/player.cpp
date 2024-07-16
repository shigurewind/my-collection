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
#include "enemy.h"
#include "hook.h"
#include "stone.h"
#include "door.h"
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
PLAYER g_Player[PLAYER_MAX];

int playerMoveSpeed;//player移動時間間隔
//int playerActionSpeed;//player動作時間間隔

bool jPressed = false;
bool kPressed = false;
bool lPressed = false;


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


	//初期化
	g_Player[0].y = 61;
	g_Player[0].x = 78;

	//test
	/*g_Player[0].y = 6;
	g_Player[0].x = 145;*/


	g_Player[0].hp = 3;
	g_Player[0].hpMax = 3;


	g_Player[0].flag = 0;

	playerMoveSpeed = 3;

	//playerActionSpeed = 4;

	g_Player[0].arrownum = 10;

	g_Player[0].arrowIsOut = 0;

	g_Player[0].isAttack = false;

	g_Player[0].heartFraNum = 0;

	g_Player[0].keyNum = 0;
}


// プレイヤーの終了処理
void UninitPlayer(void)
{

}


// プレイヤーの更新処理
void UpdatePlayer(void)
{
	if (g_Player[0].hp <= 0) {
		SetMode(GAME_OVER);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
		key_Space = GetKeyState(' '), // Space押し確認
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



			//攻撃
		if (key_J < 0) {
			if (!jPressed) {
				jPressed = true;
				Attack();
			}
		}

		//shoot
		if (key_K < 0) {
			if (!kPressed)
			{
				kPressed = true;
				if (g_Player[0].arrownum > 0) {
					SetArrow(g_Player[0].y, g_Player[0].x, g_Player[0].arrowIsOut, g_Player[0].flag);
					g_Player[0].arrowIsOut++;
					g_Player[0].arrownum--;
				}
				if (g_Player[0].arrowIsOut > 20) {
					g_Player[0].arrowIsOut = 0;
				}
			}

		}

		//かぎ爪
		if (key_L < 0) {
			if (!lPressed) {
				lPressed = true;
				UseHook(g_Player[0].y, g_Player[0].x, g_Player[0].flag);

			}

		}

	}

	//ボタンを外したか
	if (key_J >= 0) {
		jPressed = false;
	}
	if (key_K >= 0) {
		kPressed = false;
	}
	if (key_L >= 0) {
		lPressed = false;
	}
	//Sleep(3);


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
	case 4://敵に当たり判定

		for (int i = 0; i < ENEMY_MAX; i++) {
			if (g_Enemy[i].x == g_Player[0].x && g_Enemy[i].y == g_Player[0].y && g_Enemy[i].alive == TRUE) {
				g_Player[0].hp -= 1;
				g_Enemy[i].alive = false;
			}
		}
		g_Player[0].y = g_Player[0].old_y;
		g_Player[0].x = g_Player[0].old_x;


		break;

	case 5://DOORにあたる
		if (g_Player[0].keyNum > 0) {
			int doornum = CheckDoor(g_Player[0].y, g_Player[0].x);
			door[doornum].opened = TRUE;
			g_Player[0].keyNum--;
			SetMessage(3);//DOORを開けるMessage

		}
		else
		{
			g_Player[0].y = g_Player[0].old_y;
			g_Player[0].x = g_Player[0].old_x;
		}


		break;

	case 7:
		g_Player[0].hp--;
		g_Player[0].y = g_Player[0].old_y;
		g_Player[0].x = g_Player[0].old_x;
		SetMessage(4);

		break;

	case 8:
		SetMode(GAME_CLEAR);
		break;
	}


}


// プレイヤーの描画処理
void DrawPlayer(void)
{



	if (g_Player[0].hp > 0) {
		SetField(g_Player[0].y, g_Player[0].x, div_player);
	}//０以下ならスキップ

	//攻撃表示
	if (g_Player[0].isAttack == TRUE) {

		SetField(g_Player[0].attack_y1, g_Player[0].attack_x1, '+');
		SetField(g_Player[0].attack_y2, g_Player[0].attack_x2, '+');
		g_Player[0].isAttack = FALSE;
	}




	// プレイヤーをMAPの指定座標へ書き込む

}

void Attack()
{
	g_Player[0].isAttack = true;

	switch (g_Player[0].flag)
	{
	case 0:
		g_Player[0].attack_x1 = g_Player[0].x + 1;
		g_Player[0].attack_x2 = g_Player[0].x + 2;
		g_Player[0].attack_y1 = g_Player[0].y;
		g_Player[0].attack_y2 = g_Player[0].y;

		break;
	case 1:
		g_Player[0].attack_x1 = g_Player[0].x;
		g_Player[0].attack_x2 = g_Player[0].x;
		g_Player[0].attack_y1 = g_Player[0].y - 1;
		g_Player[0].attack_y2 = g_Player[0].y - 2;

		break;
	case 2:
		g_Player[0].attack_x1 = g_Player[0].x - 1;
		g_Player[0].attack_x2 = g_Player[0].x - 2;
		g_Player[0].attack_y1 = g_Player[0].y;
		g_Player[0].attack_y2 = g_Player[0].y;

		break;
	case 3:
		g_Player[0].attack_x1 = g_Player[0].x;
		g_Player[0].attack_x2 = g_Player[0].x;
		g_Player[0].attack_y1 = g_Player[0].y + 1;
		g_Player[0].attack_y2 = g_Player[0].y + 2;

		break;

	default:
		break;
	}

	//石を破壊
	checkStone(g_Player[0].attack_y1, g_Player[0].attack_x1);
	checkStone(g_Player[0].attack_y2, g_Player[0].attack_x2);

	//enemyを倒す
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (g_Enemy[i].alive == TRUE) {
			if ((g_Enemy[i].x == g_Player[0].attack_x1 && g_Enemy[i].y == g_Player[0].attack_y1) || (g_Enemy[i].x == g_Player[0].attack_x2 && g_Enemy[i].y == g_Player[0].attack_y2)) {
				g_Enemy[i].alive = FALSE;
			}
		}

	}
}






