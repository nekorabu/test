/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   keycheck.h
//
//   2019.09.20   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
//#pragma once

// 入力情報用
enum KEY_ID {
	KEY_ID_SPACE
	, KEY_ID_PAUSE
	, KEY_ID_MOUSE_LEFT
	, KEY_ID_MOUSE_MIDDLE
	, KEY_ID_MOUSE_RIGHT
	, KEY_ID_MAX
};

// extern宣言
//---------------------------------
extern bool keyOld[KEY_ID_MAX];		//１フレーム前の入力状態
extern bool keyNew[KEY_ID_MAX];		//現在の入力状態
extern bool keyDownTrigger[KEY_ID_MAX];//ダウン時のトリガー
extern bool keyUpTrigger[KEY_ID_MAX];	//アップ時のトリガー

// プロトタイプ宣言
//---------------------------------
void KeyInit(void);				//入力情報の初期化
void KeyCheck(void);			//入力情報の確認
