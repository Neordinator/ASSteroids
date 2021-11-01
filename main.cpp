#include "mainStage.hpp"
#include "menuStage.hpp"

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(W, H), L"ASSteroids");
	window.setFramerateLimit(60);
	while (true)
	{
		if (playMenuStage(window) == 1)
		{
			playMainStage(window, W, H);
		} else {
			break;
		}
	}

	return 0;
}