#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Texture.h"
using namespace std;

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 50;
bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;

//Scene sprites
SDL_Rect gSpriteClips[12];
Texture gSpriteSheetTexture;

int main(int argc, char* args[]) {
	//Start up SDL and create window
	init() ? cerr << "" : cerr << "Failed to initialize sdl.";
	loadMedia() ? cerr << "" : cerr << "Failed to load media.";

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		SDL_SetRenderDrawColor(gRenderer, 58, 38, 32, 0);
		SDL_RenderClear(gRenderer);

		for (int y = 0; y <= RECT_HEIGHT * 7; y += RECT_HEIGHT) {
			bool even = ((y / 10) % 2 == 0);

			for (int x = RECT_WIDTH * even; x <= RECT_WIDTH * (6 + even);
					x += RECT_WIDTH * 2) {
				SDL_Rect fillRect =
						{ x, y, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
				SDL_RenderFillRect(gRenderer, &fillRect);
			}

		}
		int offsetX = 50;
		for (int i = 0; i < 8; i++) {
			gSpriteSheetTexture.Render(i * offsetX, 50, &gSpriteClips[5]);
			gSpriteSheetTexture.Render(i * offsetX, 300, &gSpriteClips[11]);
		}
		gSpriteSheetTexture.Render(0, 0, &gSpriteClips[4]);
		gSpriteSheetTexture.Render(350, 0, &gSpriteClips[4]);
		gSpriteSheetTexture.Render(0, 350, &gSpriteClips[10]);
		gSpriteSheetTexture.Render(350, 350, &gSpriteClips[10]);

		gSpriteSheetTexture.Render(50, 0, &gSpriteClips[3]);
		gSpriteSheetTexture.Render(300, 0, &gSpriteClips[3]);
		gSpriteSheetTexture.Render(50, 350, &gSpriteClips[9]);
		gSpriteSheetTexture.Render(300, 350, &gSpriteClips[9]);

		gSpriteSheetTexture.Render(100, 0, &gSpriteClips[2]);
		gSpriteSheetTexture.Render(250, 0, &gSpriteClips[2]);
		gSpriteSheetTexture.Render(100, 350, &gSpriteClips[8]);
		gSpriteSheetTexture.Render(250, 350, &gSpriteClips[8]);

		gSpriteSheetTexture.Render(150, 0, &gSpriteClips[1]);
		gSpriteSheetTexture.Render(200, 0, &gSpriteClips[0]);
		gSpriteSheetTexture.Render(150, 350, &gSpriteClips[7]);
		gSpriteSheetTexture.Render(200, 350, &gSpriteClips[6]);

		//Update screen
		SDL_RenderPresent(gRenderer);

	} //while

	close();

	return 0;
}
bool init() {

	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError()
				<< endl;
		success = false;
	} else {

		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cerr << "Window could not be created! SDL Error: %s"
					<< SDL_GetError() << endl;
			success = false;
		} else {

			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				cerr << "Renderer could not be created! SDL Error: %s"
						<< SDL_GetError() << endl;
				success = false;
			} else {

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cerr
							<< "SDL_image could not initialize! SDL_image Error: %s"
							<<
							IMG_GetError() << endl;
					success = false;

				}
			}
		}
	}

	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	gSpriteSheetTexture.gRenderer = gRenderer;
	if (!gSpriteSheetTexture.LoadFromFile("figures2.png")) {
		cout << "Failed to load sprite sheet texture!\n";
		success = false;
	} else {
		int offsetX = 50;
		for (int i = 0; i < 6; i++) {
			gSpriteClips[i].x = i * offsetX;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 50;
			gSpriteClips[i].h = 50;
		}

		for (int i = 0; i < 6; i++) {
			gSpriteClips[i + 6].x = i * offsetX;
			gSpriteClips[i + 6].y = 50;
			gSpriteClips[i + 6].w = 50;
			gSpriteClips[i + 6].h = 50;
		}

	}

	return success;
}

void close() {

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
