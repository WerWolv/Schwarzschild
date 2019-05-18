#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Button : public IUIElement {
    public:
        Button(schwarzschild::utils::ButtonArgs args) : schwarzschild::ui::IUIElement(args) {
            m_args = args;
        }
        
        ~Button() {

        }

        void render(SDL_Renderer *renderer) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

            SDL_Rect rect = {m_args.x, m_args.y, m_args.w, m_args.h};
            SDL_RenderFillRect(renderer, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::utils::ButtonArgs m_args;
    };
}

