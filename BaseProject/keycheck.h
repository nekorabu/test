/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   keycheck.h
//
//   2019.09.20   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
//#pragma once

// ���͏��p
enum KEY_ID {
	KEY_ID_SPACE
	, KEY_ID_PAUSE
	, KEY_ID_MOUSE_LEFT
	, KEY_ID_MOUSE_MIDDLE
	, KEY_ID_MOUSE_RIGHT
	, KEY_ID_MAX
};

// extern�錾
//---------------------------------
extern bool keyOld[KEY_ID_MAX];		//�P�t���[���O�̓��͏��
extern bool keyNew[KEY_ID_MAX];		//���݂̓��͏��
extern bool keyDownTrigger[KEY_ID_MAX];//�_�E�����̃g���K�[
extern bool keyUpTrigger[KEY_ID_MAX];	//�A�b�v���̃g���K�[

// �v���g�^�C�v�錾
//---------------------------------
void KeyInit(void);				//���͏��̏�����
void KeyCheck(void);			//���͏��̊m�F
