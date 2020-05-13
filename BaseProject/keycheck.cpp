/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   keycheck.cpp
//
//   2019.09.24   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"
#include "keycheck.h"

//入力情報管理用
bool keyOld[KEY_ID_MAX];		//１フレーム前の入力状態
bool keyNew[KEY_ID_MAX];		//現在の入力状態
bool keyDownTrigger[KEY_ID_MAX];//ダウン時のトリガー
bool keyUpTrigger[KEY_ID_MAX];	//アップ時のトリガー

//入力情報の初期化
void KeyInit(void)
{
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = false;
		keyNew[keyID] = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
	}
}

//入力情報の確認
void KeyCheck(void)
{
	//Oldの準備
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}
	//	mouseButtonOld = mouseButton;

		//MOUSEの情報を取得する
	//	GetMousePoint(&mousePos.x, &mousePos.y);
	//	mouseButton = GetMouseInput();

		//現在の状態を取得する
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);
	//	keyNew[KEY_ID_MOUSE_LEFT] = mouseButton & MOUSE_INPUT_LEFT;
	//	keyNew[KEY_ID_MOUSE_MIDDLE] = mouseButton & MOUSE_INPUT_MIDDLE;
	//	keyNew[KEY_ID_MOUSE_RIGHT] = mouseButton & MOUSE_INPUT_RIGHT;

		//トリガーの算出
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
		//ダウントリガー
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		//アップトリガー
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}
