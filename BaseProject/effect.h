/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   effect.h
//
//   2019.09.26   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
//#pragma once

//変数
//---------------------------------
//画面切替エフェクト
extern bool fadeIn;
extern bool fadeOut;
extern int fadeCnt;

//一時停止エフェクト
extern bool pauseFlag;


//プロトタイプ宣言
//---------------------------------
void EffectInit(void);					//エフェクトの初期化
bool FadeInScreen(int fadeStep);		//フェードイン用(fadeStep:速度)
bool FadeOutScreen(int fadeStep);		//フェードアウト用(fadeStep:速度)
