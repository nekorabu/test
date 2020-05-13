/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   effect.cpp
//
//   2019.09.26   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"
#include "effect.h"

//変数
//---------------------------------
//画面切替エフェクト
bool fadeIn;
bool fadeOut;
int fadeCnt;

//一時停止エフェクト
bool pauseFlag;

//エフェクトの初期化
//---------------------------------------------
void EffectInit(void)
{
	//画面切替エフェクト
	fadeIn = false;
	fadeOut = false;
	fadeCnt = 0;
	//一時停止エフェクト
	pauseFlag = false;
}

// フェードイン処理
//---------------------------------------------
bool FadeInScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeCnt = 0;
		fadeIn = false;
		return false;
	}
}

// フェードアウト処理
//---------------------------------------------
bool FadeOutScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeCnt = 0;
		fadeOut = false;
		return false;
	}
}