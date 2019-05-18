#pragma once

#include <switch.h>
#include <string>

namespace schwarzschild::utils {
    typedef union {
        struct {
            u8 r, g, b, a;
        };
        u32 rgba;
    } rgba_color_t;


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
}