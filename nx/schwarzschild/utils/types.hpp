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
        ButtonArgs(TTF_Font *font, std::string text) : UIElementArgs(), font(font), text(text) {}
        ~ButtonArgs(){}
        TTF_Font *font;
        std::string text;
    };

    class FooterArgs : public UIElementArgs {
    public:
        FooterArgs() : UIElementArgs() {}
        FooterArgs(std::string path, TTF_Font *fontbutton, std::string textbutton, TTF_Font *font, std::string text) : UIElementArgs(), path(path), fontbutton(fontbutton), textbutton(textbutton), font(font), text(text) {}
        ~FooterArgs(){}
        std::string path;
        TTF_Font *fontbutton;
        std::string textbutton;
        TTF_Font *font;
        std::string text;
    };

    class HeaderArgs : public UIElementArgs {
    public:
        HeaderArgs() : UIElementArgs() {}
        HeaderArgs(std::string path, TTF_Font *font, std::string text) : UIElementArgs(), path(path), font(font), text(text) {}
        ~HeaderArgs(){}
        std::string path;
        TTF_Font *font;
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