#pragma once

#include <schwarzschild/ui/image.hpp>
#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/ui/text.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Header : public IUIElement {
    public:
        Header(int x, int y, IUIElement *parent, schwarzschild::types::HeaderArgs args) : schwarzschild::ui::IUIElement(x, y, parent, args) {
            m_args = args;

            IUIElement::addUIElement<schwarzschild::ui::Image>(100, 40, schwarzschild::types::ImageArgs(args.path));
            IUIElement::addUIElement<schwarzschild::ui::Text>(195, 56, schwarzschild::types::TextArgs(args.font, args.text));
        }
        
        ~Header() {

        }

        void render(SDL_Renderer *renderer, int x, int y) {
            // TODO: Support color schemes
            SDL_SetRenderDrawColor(renderer, schwarzschild::resources::SwitchColors::Color_Dark_Text.r,
                                             schwarzschild::resources::SwitchColors::Color_Dark_Text.g,
                                             schwarzschild::resources::SwitchColors::Color_Dark_Text.b,
                                             schwarzschild::resources::SwitchColors::Color_Dark_Text.a);

            int w, h;
            SDL_GetRendererOutputSize(renderer, &w, &h);

            SDL_RenderDrawLine(renderer, 45, 130, w - 45 , 130);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::types::HeaderArgs m_args;
    };
}

