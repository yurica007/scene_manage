#pragma once

#include "SceneBase.h"

class SceneManager
{
public:
	// �V�[���̎�ޒ�`
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,

		kSceneKindNum
	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager();

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();


private:
	SceneKind	m_kind;

	SceneBase* m_pScene;

//	SceneTitle	m_title;
//	SceneMain	m_main;
};