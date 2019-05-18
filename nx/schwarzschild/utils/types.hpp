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
        ButtonArgs(int w, int h, std::string text) : UIElementArgs(), w(w), h(h), text(text) {}
        ~ButtonArgs(){}
        int w, h;
        std::string text;
    };

    class ImageArgs : public UIElementArgs {
    public:
        ImageArgs() : UIElementArgs() {}
        ImageArgs(std::string path) : UIElementArgs(), path(path) {}
        ~ImageArgs(){}
        std::string path;
    };

    class TextArgs : public UIElementArgs {
    public:
        TextArgs() : UIElementArgs() {}
        TextArgs(TTF_Font *font, std::string text) : UIElementArgs(), font(font), text(text) {}
        ~TextArgs(){}
        TTF_Font *font;
        std::string text;
    };
}