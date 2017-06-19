
#include "Texture.h"
#include "Utility.hpp"

SDL_Rect gSpriteClips[4];
SDL_Rect gCards[52];

Texture gSpriteSheetTexture;

int main(int argc, char* args[]) {

	init() ? cerr << "" : cerr << "Failed to initialize sdl.";
	loadMedia() ? cerr << "" : cerr << "Failed to load media.";

	bool quit = false;
	SDL_Event e;
	SDL_RenderClear(gRenderer);
	//Render the cards
	int xPos = 0;
	for (int i = 0; i < 4; i++)
	{
		gSpriteSheetTexture.Render(xPos, 0, &gSpriteClips[3]);
		xPos += 150;
	}

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
			for (int i = 0; i < 4; i++)
			{
				if (IsInsideImage(e, gSpriteClips[i]))
				{
				gSpriteSheetTexture.Render(gSpriteClips[i].x,
						gSpriteClips[i].y,
						&gSpriteClips[i]);
				}
			}
		//Update screen
		SDL_RenderPresent(gRenderer);

		} //while2
	}//while1
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
	bool success = true;
	gSpriteSheetTexture.gRenderer = gRenderer;
	if (!gSpriteSheetTexture.LoadFromFile("card.png")) {
		cout << "Failed to load sprite sheet texture!\n";
		success = false;
	} else {
		int offsetX = 150;
		for (int i = 0; i < 4; i++) {
			gSpriteClips[i].x = i * offsetX;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 150;
			gSpriteClips[i].h = 200;
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

bool IsInsideImage(SDL_Event& e, SDL_Rect& imageRect) {
	bool check = false;
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
	
		bool inside = true;

		if (x < imageRect.x) {
			inside = false;
		}
		else if (x > imageRect.x + RECT_WIDTH) {
			inside = false;
		}
		else if (y < imageRect.y) {
			inside = false;
		}
		else if (y > imageRect.y + RECT_HEIGHT) {
			inside = false;
		}
		else if (inside) {
			check = true;
		}
	}
	return check;
}


