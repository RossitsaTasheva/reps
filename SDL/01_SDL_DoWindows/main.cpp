#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

const unsigned int SCREEN_WIDTH = 640;
const unsigned int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

int main(int args, char* argc[]) {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "Could not initialize SDL: " << SDL_GetError();
		return false;
	}

	//Create window
	gWindow = SDL_CreateWindow("MyFirstSDL", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		cerr << "Window could not be created: " << SDL_GetError();
		return false;
	}

	bool quit = false;
	SDL_Event e;

	int clickCounter = 0;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_MOUSEBUTTONDOWN && !quit) {
				//get mouse postion
				int x, y;
				SDL_GetMouseState(&x, &y);
				cout << "mouse x: " << x << " y: " << y << "\n";

				clickCounter++;
			}
		}
	}

	cout << "clicks: " << clickCounter;

	//Delete surface
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();

	return 0;
}
