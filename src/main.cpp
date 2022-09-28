#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// User defined Headers
#include "SDL_Constants.hpp"
#include "SDL_Functions.hpp"

int main()
{
    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;

    // Creating and initializing required components
    SDL_Func::initializeEverything( "Texture & Keyboard Event" , gWindow , gRenderer , IMG_INIT_FLAGS );

    SDL_Func::close(gWindow , gRenderer , nullptr , 0);
    return RETURN_SUCCESS;
}
