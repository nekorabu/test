/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   effect.h
//
//   2019.09.26   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
//#pragma once

//�ϐ�
//---------------------------------
//��ʐؑփG�t�F�N�g
extern bool fadeIn;
extern bool fadeOut;
extern int fadeCnt;

//�ꎞ��~�G�t�F�N�g
extern bool pauseFlag;


//�v���g�^�C�v�錾
//---------------------------------
void EffectInit(void);					//�G�t�F�N�g�̏�����
bool FadeInScreen(int fadeStep);		//�t�F�[�h�C���p(fadeStep:���x)
bool FadeOutScreen(int fadeStep);		//�t�F�[�h�A�E�g�p(fadeStep:���x)
