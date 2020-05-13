/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   keycheck.cpp
//
//   2019.09.24   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"
#include "keycheck.h"

//���͏��Ǘ��p
bool keyOld[KEY_ID_MAX];		//�P�t���[���O�̓��͏��
bool keyNew[KEY_ID_MAX];		//���݂̓��͏��
bool keyDownTrigger[KEY_ID_MAX];//�_�E�����̃g���K�[
bool keyUpTrigger[KEY_ID_MAX];	//�A�b�v���̃g���K�[

//���͏��̏�����
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

//���͏��̊m�F
void KeyCheck(void)
{
	//Old�̏���
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}
	//	mouseButtonOld = mouseButton;

		//MOUSE�̏����擾����
	//	GetMousePoint(&mousePos.x, &mousePos.y);
	//	mouseButton = GetMouseInput();

		//���݂̏�Ԃ��擾����
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);
	//	keyNew[KEY_ID_MOUSE_LEFT] = mouseButton & MOUSE_INPUT_LEFT;
	//	keyNew[KEY_ID_MOUSE_MIDDLE] = mouseButton & MOUSE_INPUT_MIDDLE;
	//	keyNew[KEY_ID_MOUSE_RIGHT] = mouseButton & MOUSE_INPUT_RIGHT;

		//�g���K�[�̎Z�o
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
		//�_�E���g���K�[
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		//�A�b�v�g���K�[
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}
