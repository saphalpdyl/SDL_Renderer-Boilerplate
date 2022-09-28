//
// Created by saphal on 9/27/22.
//

#ifndef INC_43_SDL_TEXTURE_KEYBOARD_EVENTS_SDL_CONSTANTS_H
#define INC_43_SDL_TEXTURE_KEYBOARD_EVENTS_SDL_CONSTANTS_H

#include <iostream>
#include <SDL2/SDL_image.h>

inline constexpr int SCREEN_WIDTH { 800 };
inline constexpr int SCREEN_HEIGHT { 600 };

inline constexpr IMG_InitFlags IMG_INIT_FLAGS {IMG_INIT_PNG};

#define logErr(x) std::cout << x<< std::endl

enum eReturnMode{
    RETURN_SUCCESS = 0,
    RETURN_FAILURE = -1
} ;

typedef int RETURN_RES;

#endif //INC_43_SDL_TEXTURE_KEYBOARD_EVENTS_SDL_CONSTANTS_H
