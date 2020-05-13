/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   BaseProject = main.cpp
//
//   2019.09.19   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlibライブラリを使用する
#include "main.h"
#include "keycheck.h"
#include "effect.h"

//変数
//---------------------------------
//シーン管理用
int sceneCounter;
SCENE_ID sceneID;
SCENE_ID scenePreID;			//一つ前のシーンID
int aaaa = 0;

// ========= WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// システムの初期化
	if (SystemInit() == false)
	{
		return -1;
	}

	// --------ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//画面消去

		//シーンカウンタの初期化
		if (sceneID != scenePreID)
		{
			sceneCounter = 0;
			scenePreID = sceneID;
		}

		KeyCheck();				//キー情報の確認

		switch (sceneID)
		{
		case SCENE_ID_INIT:			//初期化
			InitScene();
			sceneID = SCENE_ID_TITLE;
			break;

		case SCENE_ID_TITLE:		//タイトル
			// 画面切替エフェクト
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}//エフェクト終了後の処理
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{	//エフェクト終了後の処理
					sceneID = SCENE_ID_GAME;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}

			TitleScene();
			break;

		case SCENE_ID_GAME:			//ゲーム
			// 画面切替エフェクト
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}//エフェクト終了後の処理
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{	//エフェクト終了後の処理
					sceneID = SCENE_ID_GAMEOVER;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}

			GameScene();
			break;

		case SCENE_ID_GAMEOVER:		//ゲームオーバー
			// 画面切替エフェクト
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}//エフェクト終了後の処理
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{	//エフェクト終了後の処理
					sceneID = SCENE_ID_INIT;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}

			GameOverScene();
			break;

		default:
			break;
		}

		sceneCounter++;
		ScreenFlip();		//裏画面を表画面に瞬間コピー
	}

	DxLib_End();			// DXライブラリの終了処理
	return 0;				//このプログラムの終了
}

//---------------------------------------------
// システムの初期化
bool SystemInit(void)
{
	// ----------システム処理
	SetWindowText("BaseProject");
	//システム処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:フルスクリーン
	if (DxLib_Init() == -1)							//DXライブラリ初期化処理
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//ひとまずバックバッファに描画

	KeyInit();				//キー情報の初期化
	EffectInit();			//エフェクトの初期化

	// ------グラフィックの登録　---------

	// ------変数初期化　-----------
	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	scenePreID = SCENE_ID_MAX;
	fadeIn = true;

	return true;
}

//初期化用シーン
//---------------------------------------------
void InitScene(void)
{
}

//分割数選択シーン用
//---------------------------------------------
void TitleScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
//		sceneID = SCENE_ID_GAME;
		fadeOut = true;
	}

	TitleDraw();
}

void TitleDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "TitleScene : %d", sceneCounter);

	DrawBox(100, 100, 700, 500, GetColor(0, 255, 0), true);
}

//ゲームシーン用
//---------------------------------------------
void GameScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
//		sceneID = SCENE_ID_GAMEOVER;
		fadeOut = true;
	}

	// Pause機能
	if (keyDownTrigger[KEY_ID_PAUSE])
	{
		pauseFlag = !pauseFlag;
	}

	// Pause時
	if (pauseFlag)
	{
		SetDrawBright(128, 128, 128);
	}

	// 通常動作時
	else
	{
		//各種処理
		aaaa++;
	}

	//画面描画
	GameDraw();

	// Pauseメッセージを描画
	if (pauseFlag)
	{
		SetDrawBright(255, 255, 255);
		DrawString((SCREEN_SIZE_X - 9 * 8) / 2, (SCREEN_SIZE_Y - 16) / 2, "P A U S E", 0xFFFFFF);
	}
}

void GameDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "GameScene : %d", sceneCounter);
	DrawFormatString(50, 50, GetColor(255, 255, 255), "%d", aaaa);

	DrawBox(100, 100, 700, 500, GetColor(255, 0, 0), true);
}

//ゲームオーバー用
//---------------------------------------------
void GameOverScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
//		sceneID = SCENE_ID_TITLE;
		fadeOut = true;
	}

	GameOverDraw();
}

void GameOverDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "GameOverScene : %d", sceneCounter);

	DrawBox(100, 100, 700, 500, GetColor(0, 0, 255), true);
}
