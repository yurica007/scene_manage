#include "SceneMain.h"
#include "DxLib.h"

void SceneMain::init()
{
	m_textPosY = 0;
	m_textVecY = 4;

	m_isEnd = false;
}

void SceneMain::update()
{
	// •¶š‚ÌˆÚ“®
	m_textPosY += m_textVecY;
	if (m_textPosY < 0)
	{
		m_textPosY = 0;
		m_textVecY = 4;
	}
	if (m_textPosY > 200)
	{
		m_textPosY = 200;
		m_textVecY = -4;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isEnd = true;
	}
}

void SceneMain::draw()
{
	DrawString(0, m_textPosY,"ƒƒCƒ“‰æ–Ê",GetColor(255,255,255));
}