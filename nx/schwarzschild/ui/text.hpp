#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Text : public IUIElement {
    public:
        Text(int x, int y, schwarzschild::types::TextArgs args) : schwarzschild::ui::IUIElement(x, y, args) {
            m_args = args;

            // TODO: Support color schemes

            SDL_Color White = {255, 255, 255};
            m_surface = TTF_RenderText_Blended(args.font, args.text.c_str(), White);
            m_texture = nullptr;
        }
        
        ~Text() {
            SDL_FreeSurface(m_surface);
            SDL_DestroyTexture(m_texture);
        }

        void render(SDL_Renderer *renderer, int x, int y) {
            if (m_texture == nullptr)
                m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);

            int textureWidth  = 0;
            int textureHeight = 0;

            SDL_QueryTexture(m_texture, NULL, NULL, &textureWidth, &textureHeight);
            SDL_Rect rect = { x, y, textureWidth, textureHeight };

            SDL_RenderCopy(renderer, m_texture, NULL, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::types::TextArgs m_args;
        SDL_Surface* m_surface;
        SDL_Texture* m_texture;
    };
}