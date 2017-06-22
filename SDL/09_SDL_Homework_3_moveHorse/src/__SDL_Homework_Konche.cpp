//============================================================================
// Name        : __SDL_Homowork_3.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"
using namespace std;

int main(int args, char* argc[]) {

	Game game;
	SDL_Rect rect { 200, 200, IMAGE_WIDTH, IMAGE_HEIGHT };
	// game.ModifyPosition(400,400, &rect);

	bool quit = false;
	bool click = false;
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
			{
				if (game.IsInsideImage(&e, &rect))
				{
					click = true;
				}
				case SDL_KEYDOWN:
				if (click == true)
				{
					game.moveImage(&e, &rect);
				}
				break;
			} //end case SDL_MOUSEBUTTONDOWN
			} //end switch

		} // end nested loop

		SDL_RenderClear(game.getRenderer());
		SDL_RenderCopy(game.getRenderer(), game.background, NULL, NULL);

		if (game.touchLeft(&rect) == true)
		{
			//SDL_RenderCopy(game.getRenderer(), game.currentTexture, 0, &rect);
		} else if (game.touchRight(&rect) == true) {
			SDL_RenderCopy(game.getRenderer(), game.imageNat, 0, &rect);
		}
		else if (game.touchUp(&rect) == true)
		{
			SDL_RenderCopyEx(game.getRenderer(), game.currentTexture, 0, &rect,
					0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (game.touchDown(&rect) == true)
		{
			SDL_RenderCopyEx(game.getRenderer(), game.currentTexture, 0, &rect,
					45.00, NULL, SDL_FLIP_NONE);
		}
		else
		{
			SDL_RenderCopy(game.getRenderer(), game.currentTexture, 0, &rect);
		}
		SDL_RenderPresent(game.getRenderer());
	}

	return 0;
}

