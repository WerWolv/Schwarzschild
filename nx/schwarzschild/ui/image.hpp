#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Image : public IUIElement {
    public:
        Image(schwarzschild::utils::ImageArgs args) : schwarzschild::ui::IUIElement(args) {
            m_args = args;

            m_surface = IMG_Load(args.path.c_str());

            if (!m_surface) {
                SDL_Log("IMG_Load: %s\n", IMG_GetError());
            }

            m_texture = nullptr;
        }
        
        ~Image() {
            SDL_FreeSurface(m_surface);
            SDL_DestroyTexture(m_texture);
        }

        void render(SDL_Renderer *renderer) {
            if (m_texture == nullptr)
                m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);

            int textureWidth  = 0;
            int textureHeight = 0;

            SDL_QueryTexture(m_texture, NULL, NULL, &textureWidth, &textureHeight);

            SDL_Rect rect = { m_args.x, m_args.y, textureWidth, textureHeight };
            SDL_RenderCopy(renderer, m_texture, NULL, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }
    private:
        schwarzschild::utils::ImageArgs m_args;
        SDL_Surface* m_surface;
        SDL_Texture* m_texture;
    };
}