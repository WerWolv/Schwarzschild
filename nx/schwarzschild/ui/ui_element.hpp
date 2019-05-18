#pragma once

#include <SDL.h>
#include <switch.h>

#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class IUIElement {
    public:
        IUIElement(schwarzschild::utils::UIElementArgs args) {}
        
        virtual ~IUIElement() { }

        virtual void render(SDL_Renderer *renderer) = 0;
        virtual void update() = 0;
        virtual void onInteract(u64 kdown) = 0;

    private:
        IUIElement();
    };
}