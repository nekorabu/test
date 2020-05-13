/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   BaseProject = main.h
//
//   2019.09.20   Majima
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
//#pragma once

//�萔
//---------------------------------
// �萔
//-------------------------------
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

// �񋓌^
//-------------------------------

//�V�[���Ǘ��p
enum SCENE_ID {
	SCENE_ID_INIT			//������
	, SCENE_ID_TITLE		//�^�C�g��
	, SCENE_ID_GAME			//�Q�[��
	, SCENE_ID_GAMEOVER		//�Q�[���I�[�o�[
	, SCENE_ID_MAX
};

//�v���g�^�C�v�錾
//---------------------------------
bool SystemInit(void);		//�V�X�e���̏�����
//�������p�V�[��
void InitScene(void);
//�^�C�g���V�[���p
void TitleScene(void);
void TitleDraw(void);
//�Q�[���V�[���p
void GameScene(void);
void GameDraw(void);
//�Q�[���I�[�o�[�p
void GameOverScene(void);
void GameOverDraw(void);

