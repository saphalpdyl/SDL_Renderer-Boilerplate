#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>

// User defined Headers
#include "SDL_Constants.hpp"
#include "SDL_Functions.hpp"

int main()
{
    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;

    // Creating and initializing required components
    SDL_Func::initializeEverything( "Texture & Keyboard Event" , gWindow , gRenderer , IMG_INIT_FLAGS );

	SDL_SetRenderDrawColor( gRenderer , 0xFF , 0 , 0 , 0xFF );
	SDL_Rect fillRect = { SCREEN_WIDTH / 4 , SCREEN_HEIGHT / 4 , SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };
	SDL_RenderFillRect( gRenderer , &fillRect );
	SDL_RenderPresent( gRenderer );

	SDL_Delay( 3000 );

    SDL_Func::close(gWindow , gRenderer , nullptr , 0);
    return RETURN_SUCCESS;
}
