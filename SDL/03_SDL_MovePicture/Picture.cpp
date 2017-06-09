/*
 * Picture.cpp
 *
 *  Created on: 2.06.2017 ?.
 *      Author: Vaniugata
 */

#include "Picture.h"

Picture::Picture()
{

}

Picture::~Picture()
{
}

void Picture::setPosition(int x, int y)
{
}

void Picture::handleEvent(SDL_Event* e, SDL_Rect& rec)
{
	if( e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if( (x >= rec.x && x <= rec.x + rec.w) &&
				(y >= rec.y && y <= rec.y + rec.h) )
		{
			rec.x = 40;
			rec.y = 40;
		}
	}
}

void Picture::render(SDL_Renderer& renderer, SDL_Texture& texture, SDL_Rect& rec)
{
	SDL_RenderCopy(&renderer, &texture, NULL, &rec);
	SDL_RenderPresent(&renderer);
}
