#pragma once

#include <switch.h>
#include <SDL.h>

namespace sws::resources {
    namespace colors::nx {
        SDL_Color Color_Dark_Background     = { 0x2D, 0x2D, 0x2D, 0xFF };
        SDL_Color Color_Dark_Panel          = { 0x32, 0x32, 0x32, 0xFF };
        SDL_Color Color_Dark_Text           = { 0xFF, 0xFF, 0xFF, 0xFF };
        SDL_Color Color_Dark_Glowing        = { 0x1A, 0xBC, 0xFD, 0xFF };
        SDL_Color Color_Dark_Selected       = { 0x16, 0xC9, 0xC5, 0xFF };
        SDL_Color Color_Dark_Selected_Text  = { 0x00, 0xFF, 0xCA, 0xFF };
        SDL_Color Color_Light_Background    = { 0xEB, 0xEB, 0xEB, 0xFF };
        SDL_Color Color_Light_Panel         = { 0xF0, 0xF0, 0xF0, 0xFF };
        SDL_Color Color_Light_Text          = { 0x2D, 0x2D, 0x2D, 0xFF };
        SDL_Color Color_Light_Glowing       = { 0x00, 0xFF, 0xCA, 0xFF };
        SDL_Color Color_Light_Selected      = { 0x16, 0xC9, 0xC5, 0xFF };
        SDL_Color Color_Light_Selected_Text = { 0x32, 0x50, 0xF0, 0xFF };
    }
}
