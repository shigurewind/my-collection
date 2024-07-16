/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		GP11A132 99 外岡高明
* 作成日:		2024/05/26
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "field.h"
#include "player.h"
#include "enemy.h"
#include "arrow.h"
#include "ui.h"
#include "box.h"
#include "hook.h"
#include "stone.h"
#include "door.h"
#include "menu.h"
#include "gameover.h"

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

//最初のMode
int g_Mode = GAME_TITLE;		// 現在動作している状態（ゲームモード）

int interval = 1;




/*******************************************************************************
 関数名:	int main( void )
 引数:		void
 戻り値:	正常終了: int型の 0
 説明:		メイン関数
*******************************************************************************/
int main(void)
{
	Init();			// ゲーム全体の初期化処理

	// ゲームモードが終了じゃない間、永久に繰り返す
	while (GetMode() < GAME_END)
	{

		//while (interval % timespace == 0) 
		Update();	// ゲーム全体の更新処理
		Draw();		// ゲーム全体の描画処理



		if (interval <= 240) {
			interval++;
		}
		else {
			interval = 0;
		}






	}

	Uninit();		// ゲーム全体の終了処理

	return 0;
}



// ゲーム全体の初期化処理
void Init(void)
{
	// タイトルの初期化処理
	InitTitle();

	//Fieldの初期化処理
	InitField();

	InitUI();

	//Playerの初期化
	InitPlayer();

	InitEnemy();

	InitBox();

	InitStone();

	InitDoor();


}


// ゲーム全体の終了処理
void Uninit(void)
{
	// キー入力待ち
	std::rewind(stdin);
	std::cin.get();

	//タイトルの終了処理
	UninitTitle();

	//Fieldの終了処理
	UninitField();

	//Playerの終了処理
	UninitPlayer();

	UninitEnemy();
}


// ゲーム全体の更新処理
void Update(void)
{
	// 現在のモードによって処理分けをする
	switch (GetMode())
	{
	case GAME_TITLE:
		UpdateTitle();
		break;
	case GAME_MENU:
		UpdateMenu();

		break;


	case GAME_FIELD:

		UpdatePlayer();
		UpdateHook();
		UpdateEnemy();
		UpdateArrow();
		UpdateBox();
		UpdateField();


		UpdateUI();









		break;

	case GAME_OVER:
		UpdateOver();
		break;

	case GAME_CLEAR:
		UpdateClear();

		break;

	case GAME_END:

		break;


		// 本来はここへ他のゲームモードを追加する
		// 例えば、フィールドとかバトルとか、エンディングとか、、、


	}

}


// ゲーム全体の描画処理
void Draw(void)
{

	// 現在のモードによって処理分けをする
	switch (GetMode())
	{
	case GAME_TITLE:
		DrawTitle();
		break;
	case GAME_MENU:
		DrawMenu();
		break;

	case GAME_FIELD:
		DrawPlayer();
		DrawHook();
		DrawEnemy();
		DrawArrow();

		DrawBox();

		DrawStone();

		DrawDoor();

		DrawField();

		DrawMessage();

		DrawUI();

		break;

	case GAME_OVER:
		DrawOver();
		break;

	case GAME_CLEAR:
		DrawClear();
		break;


		// 本来はここへ他のゲームモードを追加する
		// 例えば、フィールドとかバトルとか、エンディングとか、、、



	}

}


// 現在のゲームモードを取得する
int GetMode(void)
{
	return g_Mode;
}


// ゲームモードを変更する
void SetMode(int mode)
{

	g_Mode = mode;
}


// ランダム取得
int GetRand(int min, int max)
{
	static int flagRand = 0;
	static std::mt19937 g_mt;

	if (flagRand == 0)
	{
		// ランダム生成準備
		std::random_device rnd;	// 非決定的な乱数生成器
		g_mt.seed(rnd());		// メルセンヌ・ツイスタ版　引数は初期SEED
		flagRand = 1;
	}

	std::uniform_int_distribution<> random(min, max);	// 生成ランダムは0～100の範囲
	int answer = random(g_mt);
	return answer;
}



