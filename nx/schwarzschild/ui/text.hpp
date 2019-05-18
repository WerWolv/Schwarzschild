#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Text : public IUIElement {
    public:
        Text(schwarzschild::utils::TextArgs args) : schwarzschild::ui::IUIElement(args) {
            m_args = args;

            // TODO: Support color schemes

            SDL_Color White = {255, 255, 255};
            m_surface = TTF_RenderText_Blended(args.font, args.text.c_str(), White);
        }
        
        ~Text() {
            SDL_FreeSurface(m_surface);
        }

        void render(SDL_Renderer *renderer) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, m_surface);

            int textureWidth  = 0;
            int textureHeight = 0;

            SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
            SDL_Rect rect = { m_args.x, m_args.y, textureWidth, textureHeight };

            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::utils::TextArgs m_args;
        SDL_Surface* m_surface;
    };
}