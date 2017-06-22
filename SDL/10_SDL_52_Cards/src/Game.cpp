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
	for (int i = 0; i < 52; i++) {
		isClicked[i] = false;
	}
}

Game::~Game() {
	Close();
}

void Game::Init() {
	m_window = SDL_CreateWindow("Press space for random rectangle",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
			WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}

void Game::LoadMedia() {

	SDL_Surface* loadedSurfaceBackground = IMG_Load("back.jpg");
	if (loadedSurfaceBackground == NULL) {
		std::cerr << "Unable to load image " << "background.jpg"
				<< "! SDL_image Error: " << IMG_GetError();
	}

	/*SDL_SetColorKey(loadedSurfaceBackground, SDL_TRUE,
	 SDL_MapRGB(loadedSurfaceBackground->format, 255, 255, 255));*/

	SDL_Surface* loadedSurfaceCards = IMG_Load("card-deck.png");
	if (loadedSurfaceCards == NULL) {
		std::cerr << "Unable to load image " << "card-deck.png"
				<< "! SDL_image Error: " << IMG_GetError();
	}

//			SDL_SetColorKey(loadedSurfaceCards, SDL_TRUE,
//					SDL_MapRGB(loadedSurfaceCards->format, 255, 255, 255));

	m_backgroundTexture = SDL_CreateTextureFromSurface(m_renderer,
			loadedSurfaceBackground);
	if (m_backgroundTexture == NULL) {
		cerr << "Failed to convert image surface to texture background.";
	}

	m_currentTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurfaceCards);
	if (m_currentTexture == NULL) {
		cerr << "Failed to convert image surface to texture2.";
	} else {
		int offsetX = CARD_WIDTH;
		for (int i = 0; i < 13; i++) {
			m_gSpriteClips[i].x = i * offsetX;
			m_gSpriteClips[i].y = 0;
			m_gSpriteClips[i].w = CARD_WIDTH;
			m_gSpriteClips[i].h = CARD_HEIGHT;
		}

		for (int i = 0; i < 13; i++) {
			m_gSpriteClips[i + 13].x = i * offsetX;
			m_gSpriteClips[i + 13].y = CARD_HEIGHT;
			m_gSpriteClips[i + 13].w = CARD_WIDTH;
			m_gSpriteClips[i + 13].h = CARD_HEIGHT;
		}
		for (int i = 0; i < 13; i++) {
			m_gSpriteClips[i + 2 * 13].x = i * offsetX;
			m_gSpriteClips[i + 2 * 13].y = 2 * CARD_HEIGHT;
			m_gSpriteClips[i + 2 * 13].w = CARD_WIDTH;
			m_gSpriteClips[i + 2 * 13].h = CARD_HEIGHT;
		}
		for (int i = 0; i < 13; i++) {
			m_gSpriteClips[i + 3 * 13].x = i * offsetX;
			m_gSpriteClips[i + 3 * 13].y = 3 * CARD_HEIGHT;
			m_gSpriteClips[i + 3 * 13].w = CARD_WIDTH;
			m_gSpriteClips[i + 3 * 13].h = CARD_HEIGHT;
		}
		m_BackToCard.x = 2 * CARD_WIDTH;
		m_BackToCard.y = 4 * CARD_HEIGHT;
		m_BackToCard.w = CARD_WIDTH;
		m_BackToCard.h = CARD_HEIGHT;
	}
	SDL_FreeSurface(loadedSurfaceCards);
	SDL_FreeSurface(loadedSurfaceBackground);

}

void Game::Close() {
	SDL_DestroyTexture(m_backgroundTexture);
	SDL_DestroyTexture(m_currentTexture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void Game::render() {
	SDL_RenderCopy(m_renderer, m_backgroundTexture, NULL, NULL);
	SDL_Rect rect;
	int offsetX = 35;
	int offsetY = 105;
	rect.w = CARD_WIDTH;
	rect.h = CARD_HEIGHT;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 13; col++) {
			rect.x = offsetX + col * CARD_WIDTH;
			rect.y = offsetY + row * CARD_HEIGHT;
			if (isClicked[col + row * 13])
				SDL_RenderCopy(m_renderer, m_currentTexture,
						&m_gSpriteClips[col + row * 13], &rect);
			else
				SDL_RenderCopy(m_renderer, m_currentTexture, &m_BackToCard, &rect);
		}
	}
	SDL_RenderPresent(m_renderer);
}

void Game::clickCard(int x, int y) {
	x -= 35;
	y -= 105;

	if (x < 13 * CARD_WIDTH && y < 4 * CARD_HEIGHT
		&& x > 0 && y > 0 ) {
		int countX = 0;
		while (true) {
			x -= CARD_WIDTH;
			if (x < 0)
				break;
			else
				countX++;
		}

		int countY = 0;
		while (true) {
			y -= CARD_HEIGHT;
			if (y < 0)
				break;
			else
				countY++;
		}

		isClicked[countX + countY * 13] = true;

	}

}
