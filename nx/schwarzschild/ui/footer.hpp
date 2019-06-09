#pragma once

#include <schwarzschild/ui/image.hpp>
#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/ui/text.hpp>
#include <schwarzschild/utils/types.hpp>

namespace sws::ui {
    class Footer : public IUIElement {
    public:
        Footer(int x, int y, IUIElement *parent, sws::types::FooterArgs args) : sws::ui::IUIElement(x, y, parent, args) {
            m_args = args;

            IUIElement::addUIElement<sws::ui::Image>(100, SDL_WINDOW_HEIGHT - 130 + 30, sws::types::ImageArgs(args.path));
            // TODO: compute the text size before rendering and then compute the relative position
            IUIElement::addUIElement<sws::ui::Text>(SDL_WINDOW_WIDTH - 550, SDL_WINDOW_HEIGHT - 130 + 46, sws::types::TextArgs(args.font, args.text));
            IUIElement::addUIElement<sws::ui::Text>(SDL_WINDOW_WIDTH - 550, SDL_WINDOW_HEIGHT - 130 + 46, sws::types::TextArgs(args.fontbutton, args.textbutton));
        }
        
        ~Footer() {

        }

        void render(SDL_Renderer *renderer, int x, int y) {
            // TODO: Support color schemes
            SDL_SetRenderDrawColor(renderer, sws::resources::colors::nx::Color_Dark_Text.r,
                                             sws::resources::colors::nx::Color_Dark_Text.g,
                                             sws::resources::colors::nx::Color_Dark_Text.b,
                                             sws::resources::colors::nx::Color_Dark_Text.a);

            SDL_RenderDrawLine(renderer, 45, SDL_WINDOW_HEIGHT - 130, SDL_WINDOW_WIDTH - 45 , SDL_WINDOW_HEIGHT - 130);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        sws::types::FooterArgs m_args;
    };
}

