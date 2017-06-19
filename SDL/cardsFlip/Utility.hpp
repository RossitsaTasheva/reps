/*
 * Utility.hpp
 *
 *  Created on: 19.06.2017 г.
 *      Author: Rossi
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

const int RECT_WIDTH = 150;
const int RECT_HEIGHT = 200;

bool init();

bool loadMedia();

void close();

bool IsInsideImage(SDL_Event& e, SDL_Rect& imageRect);

SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;


#endif /* UTILITY_HPP_ */
