#include "DxLib.h"

#include "game.h"

#include "SceneTitle.h"
#include "SceneMain.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	SceneTitle title;
	SceneMain main;

	int sceneNo = 0;
	switch (sceneNo)
	{
	case 0:
		title.init();
		break;
	case 1:
		main.init();
		break;
	}
	

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		switch (sceneNo)
		{
		case 0:
			title.update();
			title.draw();

			if (title.isEnd())
			{
				title.end();
				main.init();
				sceneNo = 1;
			}
			break;
		case 1:
			main.update();
			main.draw();

			if (main.isEnd())
			{
				main.end();
				title.init();
				sceneNo = 0;
			}
			break;
		}

		//裏画面を表画面を入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	switch (sceneNo)
	{
	case 0:
		title.end();
		break;
	case 1:
		main.end();
		break;
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}