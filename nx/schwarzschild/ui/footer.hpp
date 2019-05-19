#pragma once

#include <schwarzschild/ui/image.hpp>
#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/ui/text.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Footer : public IUIElement {
    public:
        Footer(int x, int y, IUIElement *parent, schwarzschild::types::FooterArgs args) : schwarzschild::ui::IUIElement(x, y, parent, args) {
            m_args = args;

            IUIElement::addUIElement<schwarzschild::ui::Image>(100, SDL_WINDOW_HEIGHT - 130 + 30, schwarzschild::types::ImageArgs(args.path));
            // TODO: compute the text size before rendering and then compute the relative position
            IUIElement::addUIElement<schwarzschild::ui::Text>(SDL_WINDOW_WIDTH - 550, SDL_WINDOW_HEIGHT - 130 + 46, schwarzschild::types::TextArgs(args.font, args.text));
            IUIElement::addUIElement<schwarzschild::ui::Text>(SDL_WINDOW_WIDTH - 550, SDL_WINDOW_HEIGHT - 130 + 46, schwarzschild::types::TextArgs(args.fontbutton, args.textbutton));
        }
        
        ~Footer() {

        }

        void render(SDL_Renderer *renderer, int x, int y) {
            // TODO: Support color schemes
            SDL_SetRenderDrawColor(renderer, schwarzschild::resources::SwitchColors::Color_Dark_Text.r,
                                             schwarzschild::resources::SwitchColors::Color_Dark_Text.g,
                                             schwarzschild::resources::SwitchColors::Color_Dark_Text.b,
                                             schwarzschild::resources::SwitchColors::Color_Dark_Text.a);

            SDL_RenderDrawLine(renderer, 45, SDL_WINDOW_HEIGHT - 130, SDL_WINDOW_WIDTH - 45 , SDL_WINDOW_HEIGHT - 130);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::types::FooterArgs m_args;
    };
}

