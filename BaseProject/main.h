/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   BaseProject = main.h
//
//   2019.09.20   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
//#pragma once

//定数
//---------------------------------
// 定数
//-------------------------------
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

// 列挙型
//-------------------------------

//シーン管理用
enum SCENE_ID {
	SCENE_ID_INIT			//初期化
	, SCENE_ID_TITLE		//タイトル
	, SCENE_ID_GAME			//ゲーム
	, SCENE_ID_GAMEOVER		//ゲームオーバー
	, SCENE_ID_MAX
};

//プロトタイプ宣言
//---------------------------------
bool SystemInit(void);		//システムの初期化
//初期化用シーン
void InitScene(void);
//タイトルシーン用
void TitleScene(void);
void TitleDraw(void);
//ゲームシーン用
void GameScene(void);
void GameDraw(void);
//ゲームオーバー用
void GameOverScene(void);
void GameOverDraw(void);

