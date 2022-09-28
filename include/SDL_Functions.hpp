//
// Created by saphal on 9/27/22.
//

#ifndef INC_43_SDL_TEXTURE_KEYBOARD_EVENTS_SDL_FUNCTIONS_H
#define INC_43_SDL_TEXTURE_KEYBOARD_EVENTS_SDL_FUNCTIONS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// User defined Headers
#include "SDL_Constants.hpp"

namespace SDL_Func {
    /**
     *  Loads a texture from a BMP file. Currently only BMP is supported
     *
     *  @param imgSrc Relative or constant path to image file
     *  @param renderer Reference to image renderer
     *
     *  @returns SDL_Texture* if successful
     *  @returns nullptr if failed
     */
    SDL_Texture* loadTexture(const char* imgSrc , SDL_Renderer*& renderer);


    /**
     *
     * Initialize every fundamental component of SDL 2.0
     *
     * The fundamental components are SDL , Window , Renderer and SDL_Image.
     *
     *  @param winName Name of window to be created
     *  @param window Reference to window pointer [ Must be nullptr ]
     *  @param renderer Reference to renderer pointer [ Must be nullptr ]
     *  @param SDL_IMG_FLAGS Image initialization flags
     *
     *  @returns RETURN_FAILURE for failed cases
     *  @returns RETURN_SUCCESS for successful cases
     */
    RETURN_RES initializeEverything(const char* winName , SDL_Window*& window , SDL_Renderer*& renderer , IMG_InitFlags SDL_IMG_FLAGS);


    /**
     * Destroying and reassigns every SDL Component to a nullptr then , closes the program.
     *
     *  @param window Reference to window
     *  @param renderer Reference to renderer
     *  @param texArrayPtr Texture Array
     *  @param texArrayLength Length of Texture Array
     *
     *  @returns RETURN_FAILURE for failed cases
     *  @returns RETURN_SUCCESS for successful cases
     */
    RETURN_RES close(SDL_Window*& window , SDL_Renderer*& renderer , SDL_Texture** texArrayPtr , size_t texArrayLength);

}


#endif //INC_43_SDL_TEXTURE_KEYBOARD_EVENTS_SDL_FUNCTIONS_H
