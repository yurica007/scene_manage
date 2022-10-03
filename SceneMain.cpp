#include "SceneMain.h"
#include "DxLib.h"

void SceneMain::init()
{
	m_textPosX = 0;
	m_textVecX = 4;

	m_isEnd = false;
}

void SceneMain::update()
{
	// •¶š‚ÌˆÚ“®
	m_textPosX += m_textVecX;
	if (m_textPosX < 0)
	{
		m_textPosX = 0;
		m_textVecX = 4;
	}
	if (m_textPosX > 300)
	{
		m_textPosX = 300;
		m_textVecX = -4;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isEnd = true;
	}
}

void SceneMain::draw()
{
	DrawString(m_textPosX, 0,"ƒƒCƒ“‰æ–Ê",GetColor(255,255,255));
}