#pragma once

#include <string>

#include <switch.h>
#include <SDL_ttf.h>

#define DBG_PRINT(x, ...) (printf("[DEBUG] %s:%d | " x "\n", __PRETTY_FUNCTION__, __LINE__ __VA_OPT__(,) __VA_ARGS__))

namespace sws::utils {
    typedef union {
        struct {
            u8 r, g, b, a;
        };
        u32 rgba;
    } rgba_color_t;

    class Fonts {
    public:
        static Result createNintendoFont(TTF_Font **font, int size, PlSharedFontType type) {
            PlFontData fontData;

            Result rc = plGetSharedFontByType(&fontData, type);
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