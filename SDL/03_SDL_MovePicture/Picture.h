#ifndef SRC_PICTURE_H_
#define SRC_PICTURE_H_

#include <SDL2/SDL.h>

class Picture
{
public:

	Picture();
	~Picture();

	void setPosition( int x, int y );
	void handleEvent( SDL_Event* e , SDL_Rect& rec);
	void render(SDL_Renderer& renderer, SDL_Texture& texture, SDL_Rect& rec);

private:
	SDL_Point mPosition;
};

#endif /* SRC_PICTURE_H_ */
