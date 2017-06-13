/*
 * Constants.h
 *
 *  Created on: 12.06.2017 г.
 *      Author: Rossi
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include <stdio.h>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Button constants
const int BUTTON_WIDTH = 100;
const int BUTTON_HEIGHT = 100;
const int TOTAL_BUTTONS = 5;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Mouse button sprites
SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];


#endif /* CONSTANTS_H_ */
