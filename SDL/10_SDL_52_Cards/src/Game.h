/*
 * Game.h
 *
 *  Created on: 20.06.2017 г.
 *      Author: Rossi
 */

#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

const int CARD_WIDTH = 44;
const int CARD_HEIGHT = 68;

class Game {
public:
	Game();
	virtual ~Game();

	void render();
	void clickCard(int, int);
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	SDL_Texture* m_currentTexture;
	SDL_Texture* m_backgroundTexture;

	SDL_Rect m_gSpriteClips[52];
	SDL_Rect m_BackToCard;

	bool isClicked[52];

	void Init();
	void LoadMedia();
	void Close();
};
#endif /* GAME_H_ */
