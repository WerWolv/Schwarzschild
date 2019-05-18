#pragma once

#include <switch.h>
#include <string>
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

    class UIElementArgs {
    public:
        UIElementArgs(){}
        ~UIElementArgs(){}
    };

    class ButtonArgs : public UIElementArgs {
    public:
        ButtonArgs() : UIElementArgs() {}
        ButtonArgs(int x, int y, int w, int h, std::string text) : UIElementArgs(), x(x), y(y), w(w), h(h), text(text) {}
        ~ButtonArgs(){}
        int x, y, w, h;
        std::string text;
    };

    class ImageArgs : public UIElementArgs {
    public:
        ImageArgs() : UIElementArgs() {}
        ImageArgs(int x, int y, std::string path) : UIElementArgs(), x(x), y(y), path(path) {}
        ~ImageArgs(){}
        int x, y;
        std::string path;
    };

    class TextArgs : public UIElementArgs {
    public:
        TextArgs() : UIElementArgs() {}
        TextArgs(int x, int y, TTF_Font *font, std::string text) : UIElementArgs(), x(x), y(y), font(font), text(text) {}
        ~TextArgs(){}
        int x, y;
        TTF_Font *font;
        std::string text;
    };
}