/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   effect.cpp
//
//   2019.09.26   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"
#include "effect.h"

//�ϐ�
//---------------------------------
//��ʐؑփG�t�F�N�g
bool fadeIn;
bool fadeOut;
int fadeCnt;

//�ꎞ��~�G�t�F�N�g
bool pauseFlag;

//�G�t�F�N�g�̏�����
//---------------------------------------------
void EffectInit(void)
{
	//��ʐؑփG�t�F�N�g
	fadeIn = false;
	fadeOut = false;
	fadeCnt = 0;
	//�ꎞ��~�G�t�F�N�g
	pauseFlag = false;
}

// �t�F�[�h�C������
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

// �t�F�[�h�A�E�g����
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