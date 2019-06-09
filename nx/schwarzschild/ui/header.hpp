#pragma once

#include <schwarzschild/ui/image.hpp>
#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/ui/text.hpp>
#include <schwarzschild/utils/types.hpp>

namespace sws::ui {
    class Header : public IUIElement {
    public:
        Header(int x, int y, IUIElement *parent, sws::types::HeaderArgs args) : sws::ui::IUIElement(x, y, parent, args) {
            m_args = args;

            // TODO: use the Image size to compute Text and Line positions
            IUIElement::addUIElement<sws::ui::Image>(100, 40, sws::types::ImageArgs(args.path));
            IUIElement::addUIElement<sws::ui::Text>(195, 56, sws::types::TextArgs(args.font, args.text));
        }
        
        ~Header() {

        }

        void render(SDL_Renderer *renderer, int x, int y) {
            // TODO: Support color schemes
            SDL_SetRenderDrawColor(renderer, sws::resources::colors::nx::Color_Dark_Text.r,
                                             sws::resources::colors::nx::Color_Dark_Text.g,
                                             sws::resources::colors::nx::Color_Dark_Text.b,
                                             sws::resources::colors::nx::Color_Dark_Text.a);

            SDL_RenderDrawLine(renderer, 45, 130, SDL_WINDOW_WIDTH - 45 , 130);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        sws::types::HeaderArgs m_args;
    };
}

