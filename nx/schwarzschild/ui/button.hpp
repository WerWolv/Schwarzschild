#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Button : public IUIElement {
    public:
        Button(int x, int y, IUIElement *parent, schwarzschild::types::ButtonArgs args) : schwarzschild::ui::IUIElement(x, y, parent, args) {
            m_args = args;
        }
        
        ~Button() {

        }

        void render(SDL_Renderer *renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

            SDL_Rect rect = { x, y, m_args.w, m_args.h };
            SDL_RenderFillRect(renderer, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::types::ButtonArgs m_args;
    };
}

