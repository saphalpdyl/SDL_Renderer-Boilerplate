//
// Created by saphal on 9/27/22.
//

#include "SDL_Functions.hpp"

namespace SDL_Func {
    SDL_Texture* loadTexture(const char* imgSrc , SDL_Renderer*& renderer)
    {
        if ( renderer == nullptr )
        {
            logErr("Expected : SDL_Renderer*& but nullptr was passed");
            return nullptr;
        }

        SDL_Surface* loadedSurface = nullptr;
        SDL_Texture* convertedTexture = nullptr;

        loadedSurface = SDL_LoadBMP(imgSrc);
        if ( loadedSurface == nullptr)
        {
            logErr("Couldn't load image"  << SDL_GetError() );
            return nullptr;
        }

        convertedTexture = SDL_CreateTextureFromSurface( renderer , loadedSurface);
        if ( convertedTexture == nullptr )
        {
            logErr("Couldn't Load Texture"  << SDL_GetError() );
            SDL_FreeSurface(loadedSurface);
            return nullptr;
        }

        SDL_FreeSurface(loadedSurface);
        return convertedTexture;
    }

    RETURN_RES initializeEverything(const char* winName , SDL_Window*& window , SDL_Renderer*& renderer , IMG_InitFlags SDL_IMG_FLAGS)
    {

        // Check if Previously initialized
        if ( window != nullptr || renderer != nullptr)
        {
            logErr("Looks like SDL was pre-initialized ");
            return RETURN_FAILURE;
        }

        // Initializing SDL Everything
        if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 || !(IMG_Init(SDL_IMG_FLAGS) & SDL_IMG_FLAGS) )
        {
            logErr("Failed to init SDL and/or SDL_Image : "  << SDL_GetError() );
            return RETURN_FAILURE;
        }

        // Window Creation and Checking
        window = SDL_CreateWindow(winName , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
        if ( window == nullptr )
        {
            logErr("Failed to Create Window : " << SDL_GetError());
            return RETURN_FAILURE;
        }

        renderer = SDL_CreateRenderer( window , -1 , SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor( renderer , 0 , 0 , 1 , 1);
        if ( renderer == nullptr )
        {
            logErr("Failed to create renderer : " << SDL_GetError());
            return RETURN_FAILURE;
        }

        return RETURN_SUCCESS;
    }

    RETURN_RES close(SDL_Window*& window , SDL_Renderer*& renderer , SDL_Texture** texArrayPtr , size_t texArrayLength)
    {
        // Destroying Texture
				if ( texArrayPtr != nullptr && texArrayLength != 0)
				{
					for (size_t texArrayCounter = 0 ; texArrayCounter < texArrayLength ; texArrayPtr++ , texArrayCounter++ )
					{
							if (*texArrayPtr != nullptr )
									SDL_DestroyTexture(*texArrayPtr);
					}
				}
        // Destroying the Renderer
        SDL_DestroyRenderer( renderer );
        renderer = nullptr;

        // Destroying window
        SDL_DestroyWindow( window );
        window = nullptr;

        // Quiting
        SDL_Quit();
        return RETURN_SUCCESS;
    }
}
