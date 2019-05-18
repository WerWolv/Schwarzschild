#pragma once

#include <string>

#include <switch.h>
#include <SDL_ttf.h>

namespace schwarzschild::utils {
    typedef union {
        struct {
            u8 r, g, b, a;
        };
        u32 rgba;
    } rgba_color_t;

    class Fonts {
    public:
        static Result createNintendoFont(TTF_Font **font, int size) {
            PlFontData fontData;

            Result rc = plGetSharedFontByType(&fontData, PlSharedFontType_Standard);
            if (R_FAILED(rc)) {
                return SchwarzschildError_FontLoadingFailed;
            }

            *font = TTF_OpenFontRW(SDL_RWFromMem(fontData.address, fontData.size), 1, size);

            return 0;
        }
    private:
        Fonts() {}
    };
}