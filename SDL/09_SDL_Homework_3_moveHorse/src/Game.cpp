/*
 * Game.cpp
 *
 *  Created on: 20.06.2017 г.
 *      Author: Rossi
 */

#include "Game.h"

Game::Game() {
	Init();
	LoadMedia();
}

Game::~Game() {
	Close();
}

void Game::Init() {
	window = SDL_CreateWindow("Press space for random rectangle",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
			WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Game::LoadMedia() {
	SDL_Surface* loadedSurface1 = IMG_Load("horse.jpg");
	if (loadedSurface1 == NULL) {
		std::cerr << "Unable to load image " << "horse.jpg"
				<< "! SDL_image Error: " << IMG_GetError();
	}
//	SDL_SetColorKey(loadedSurface1, SDL_TRUE,
//				SDL_MapRGB(loadedSurface1->format, 255, 255, 255));

	SDL_Surface* loadedSurface2 = IMG_Load("image.jpg");
		if (loadedSurface2 == NULL) {
			std::cerr << "Unable to load image " << "image.jpg"
					<< "! SDL_image Error: " << IMG_GetError();
		}
		SDL_Surface* loadedSurface3 = IMG_Load("nat.jpg");
				if (loadedSurface3 == NULL) {
					std::cerr << "Unable to load image " << "nat.jpg"
							<< "! SDL_image Error: " << IMG_GetError();
				}

	/*SDL_SetColorKey(loadedSurface2, SDL_TRUE,
			SDL_MapRGB(loadedSurface2->format, 255, 255, 255));*/

	currentTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface1);
	if (currentTexture == NULL) {
		cerr << "Failed to convert image surface to texture1.";
	}

	background = SDL_CreateTextureFromSurface(renderer, loadedSurface2);
	if (background == NULL) {
		cerr << "Failed to convert image surface to texture2.";
	}
	imageNat = SDL_CreateTextureFromSurface(renderer, loadedSurface3);
		if (imageNat == NULL) {
			cerr << "Failed to convert image surface to texture3.";
		}
	SDL_FreeSurface(loadedSurface1);
	SDL_FreeSurface(loadedSurface2);
	SDL_FreeSurface(loadedSurface3);
}

void Game::Close() {
	//SDL_DestroyTexture(rects);
	SDL_DestroyTexture(imageNat);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(currentTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}

void Game::moveImage(SDL_Event* e, SDL_Rect* rect) {
	int step = 10;
	switch (e->key.keysym.sym) {
	case SDLK_UP:
		if(rect->y != 0)
			rect->y -= step;
		break;
	case SDLK_DOWN:
		if(rect->y != WINDOW_HEIGHT-IMAGE_HEIGHT)
			rect->y += step;
		break;
	case SDLK_LEFT:
		if(rect->x != 0)
			rect->x -= step;
		break;
	case SDLK_RIGHT:
		if(rect->x != WINDOW_WIDTH-IMAGE_WIDTH)
			rect->x += step;
		break;
	}
}

bool Game::IsInsideImage(SDL_Event* e, SDL_Rect* rect) {

	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if ((x >= rect->x && x <= rect->x + rect->w)
				&& (y >= rect->y && y <= rect->y + rect->h)) {
			return true;
		}
	}

	return false;

}

void Game::ModifyPosition(int x, int y, SDL_Rect* rect) {
	rect->x = x;
	rect->y = y;
}

void Game::ModifyImageSize(int w, int h, SDL_Rect& rect) {
	if (w <= WINDOW_WIDTH && h <= WINDOW_HEIGHT) {
			rect.w = w;
			rect.h = h;
		}
}

bool Game::touchLeft(SDL_Rect* rect) {
	if(rect->x == WINDOW_WIDTH-IMAGE_WIDTH){
	return true;
	}
	return false;
}
bool Game::touchRight(SDL_Rect* rect) {
	if(rect->y == WINDOW_HEIGHT-IMAGE_HEIGHT){
	return true;
	}
	return false;
}
bool Game::touchUp(SDL_Rect* rect) {
	if(rect->x == 0){
	return true;
	}
	return false;
}
bool Game::touchDown(SDL_Rect* rect) {
	if(rect->y == 0){
	return true;
	}
	return false;
}
