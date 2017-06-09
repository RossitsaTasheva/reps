#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gCurrentTexture = NULL;

bool InitSDL();
bool LoadMedia(string path);
void RenderImage(SDL_Rect& rect);
void ModifyPosition(int x, int y, SDL_Rect& rect);
bool IsInsideImage(SDL_Event& e, SDL_Rect& imageRect);
void ModifyImageSize(int w, int h, SDL_Rect& rect);
void Close();

int main(int args, char* argc[]) {
	InitSDL() ? cerr << "" : cerr << "Failed to init sdl.";
	LoadMedia("pattern.png") ? cerr << "" : cerr << "Failed to load media";

	bool quit = false;
	SDL_Event e;
	SDL_Rect rect { 20, 20, 200, 200 };
	int counter = 0;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN: {
				if (IsInsideImage(e, rect)) {
					counter++;
					ModifyPosition(40, 40, rect);
					RenderImage(rect);
					if (counter == 2) {
						counter = 0;
						ModifyImageSize(100, 100, rect);
						RenderImage(rect);
					}
				}
			} //end case SDL_MOUSEBUTTONDOWN
			} //end switch
		} // end nested loop
		RenderImage(rect);
	} // end main loop

	Close();

	return 0;
}

bool InitSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "Failed to initialize SDL.";
		return false;
	}

	gWindow = SDL_CreateWindow("Task 4", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		cerr << "Failed to create window.";
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) {
		cerr << "Failed to crate renderer.";
		return false;
	}

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);

	//int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cerr << "Failed to initalize image loading.";
		return false;
	}

	return true;
}

bool LoadMedia(string path) {
	SDL_Surface* imgSurface = IMG_Load(path.c_str());
	if (imgSurface == NULL) {
		cerr << "Failed to load image: " << path;
		return false;
	}

	gCurrentTexture = SDL_CreateTextureFromSurface(gRenderer, imgSurface);
	if (gCurrentTexture == NULL) {
		cerr << "Failed to convert image surface to texture.";
		return false;
	}

	SDL_FreeSurface(imgSurface);

	return true;
}

void RenderImage(SDL_Rect& rect) {
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gCurrentTexture, NULL, &rect);
	SDL_RenderPresent(gRenderer);
}

void ModifyPosition(int x, int y, SDL_Rect& rect) {
	rect.x = x;
	rect.y = y;
}

bool IsInsideImage(SDL_Event& e, SDL_Rect& imageRect) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if ((x >= imageRect.x && x <= imageRect.x + imageRect.w)
				&& (y >= imageRect.y && y <= imageRect.y + imageRect.h)) {
			return true;
		}
	}

	return false;
}

void ModifyImageSize(int w, int h, SDL_Rect& rect) {
	rect.w = w;
	rect.h = h;
}

void Close() {
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
	IMG_Quit();
}
