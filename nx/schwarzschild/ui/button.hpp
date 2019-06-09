#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/ui/text.hpp>
#include <schwarzschild/utils/types.hpp>

namespace sws::ui {
    class Button : public IUIElement {
    public:
        int margin = 40;

        Button(int x, int y, IUIElement *parent, sws::types::ButtonArgs args) : sws::ui::IUIElement(x, y, parent, args) {
            m_args = args;

            m_textChild = IUIElement::addUIElement<sws::ui::Text>(margin, margin, sws::types::TextArgs(args.font, args.text));
        }
        
        ~Button() {

        }

        void render(SDL_Renderer *renderer, int x, int y) {
            // TODO: Support color schemes
            SDL_SetRenderDrawColor(renderer, sws::resources::colors::nx::Color_Dark_Text.r,
                                             sws::resources::colors::nx::Color_Dark_Text.g,
                                             sws::resources::colors::nx::Color_Dark_Text.b,
                                             sws::resources::colors::nx::Color_Dark_Text.a);

            SDL_Rect outlineRect = { x, y, m_textChild->w + 2 + margin * 2, margin * 2 + m_textChild->h + 2 };
            SDL_RenderFillRect(renderer, &outlineRect);

            // TODO: Support color schemes
            SDL_SetRenderDrawColor(renderer, sws::resources::colors::nx::Color_Dark_Background.r,
                                             sws::resources::colors::nx::Color_Dark_Background.g,
                                             sws::resources::colors::nx::Color_Dark_Background.b,
                                             sws::resources::colors::nx::Color_Dark_Background.a);

            SDL_Rect rect = { x + 1, y + 1, m_textChild->w + margin * 2, margin * 2 + m_textChild->h };
            SDL_RenderFillRect(renderer, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        sws::types::ButtonArgs m_args;
        sws::ui::Text *m_textChild;
    };
}