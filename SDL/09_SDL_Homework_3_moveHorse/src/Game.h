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

const int IMAGE_WIDTH = 200;
const int IMAGE_HEIGHT = 200;




class Game
{
public:
	Game();
	virtual ~Game();

	void moveImage(SDL_Event* , SDL_Rect*);
	bool IsInsideImage(SDL_Event* ,SDL_Rect*);
	void ModifyPosition(int, int, SDL_Rect*);
	void ModifyImageSize(int, int, SDL_Rect&);

	bool touchLeft(SDL_Rect*);
	bool touchRight(SDL_Rect* rect);
	bool touchUp(SDL_Rect* rect);
	bool touchDown(SDL_Rect* rect);
	SDL_Texture* currentTexture;
	SDL_Texture* background;
	SDL_Texture* imageNat;
//	void RenderRandomRect();
	SDL_Renderer* getRenderer();

private:

	SDL_Window* window;
	SDL_Renderer* renderer;

//	SDL_Texture* rects;


	void Init();
	void LoadMedia();
	void Close();


};
#endif /* GAME_H_ */
