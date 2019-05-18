#pragma once

#include <SDL_ttf.h>

namespace schwarzschild::types {
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