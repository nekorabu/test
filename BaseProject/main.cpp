/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   BaseProject = main.cpp
//
//   2019.09.19   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlib���C�u�������g�p����
#include "main.h"
#include "keycheck.h"
#include "effect.h"

//�ϐ�
//---------------------------------
//�V�[���Ǘ��p
int sceneCounter;
SCENE_ID sceneID;
SCENE_ID scenePreID;			//��O�̃V�[��ID
int aaaa = 0;

// ========= WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �V�X�e���̏�����
	if (SystemInit() == false)
	{
		return -1;
	}

	// --------�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//��ʏ���

		//�V�[���J�E���^�̏�����
		if (sceneID != scenePreID)
		{
			sceneCounter = 0;
			scenePreID = sceneID;
		}

		KeyCheck();				//�L�[���̊m�F

		switch (sceneID)
		{
		case SCENE_ID_INIT:			//������
			InitScene();
			sceneID = SCENE_ID_TITLE;
			break;

		case SCENE_ID_TITLE:		//�^�C�g��
			// ��ʐؑփG�t�F�N�g
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}//�G�t�F�N�g�I����̏���
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{	//�G�t�F�N�g�I����̏���
					sceneID = SCENE_ID_GAME;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}

			TitleScene();
			break;

		case SCENE_ID_GAME:			//�Q�[��
			// ��ʐؑփG�t�F�N�g
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}//�G�t�F�N�g�I����̏���
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{	//�G�t�F�N�g�I����̏���
					sceneID = SCENE_ID_GAMEOVER;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}

			GameScene();
			break;

		case SCENE_ID_GAMEOVER:		//�Q�[���I�[�o�[
			// ��ʐؑփG�t�F�N�g
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}//�G�t�F�N�g�I����̏���
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{	//�G�t�F�N�g�I����̏���
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
		ScreenFlip();		//����ʂ�\��ʂɏu�ԃR�s�[
	}

	DxLib_End();			// DX���C�u�����̏I������
	return 0;				//���̃v���O�����̏I��
}

//---------------------------------------------
// �V�X�e���̏�����
bool SystemInit(void)
{
	// ----------�V�X�e������
	SetWindowText("BaseProject");
	//�V�X�e������
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:�t���X�N���[��
	if (DxLib_Init() == -1)							//DX���C�u��������������
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//�ЂƂ܂��o�b�N�o�b�t�@�ɕ`��

	KeyInit();				//�L�[���̏�����
	EffectInit();			//�G�t�F�N�g�̏�����

	// ------�O���t�B�b�N�̓o�^�@---------

	// ------�ϐ��������@-----------
	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	scenePreID = SCENE_ID_MAX;
	fadeIn = true;

	return true;
}

//�������p�V�[��
//---------------------------------------------
void InitScene(void)
{
}

//�������I���V�[���p
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

//�Q�[���V�[���p
//---------------------------------------------
void GameScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
//		sceneID = SCENE_ID_GAMEOVER;
		fadeOut = true;
	}

	// Pause�@�\
	if (keyDownTrigger[KEY_ID_PAUSE])
	{
		pauseFlag = !pauseFlag;
	}

	// Pause��
	if (pauseFlag)
	{
		SetDrawBright(128, 128, 128);
	}

	// �ʏ퓮�쎞
	else
	{
		//�e�폈��
		aaaa++;
	}

	//��ʕ`��
	GameDraw();

	// Pause���b�Z�[�W��`��
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

//�Q�[���I�[�o�[�p
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
