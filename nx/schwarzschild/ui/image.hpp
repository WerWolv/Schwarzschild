#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>
#include <schwarzschild/ui/text.hpp>

namespace sws::ui {
    class Image : public IUIElement {
    public:
        Image(int x, int y, IUIElement *parent, sws::types::ImageArgs args) : sws::ui::IUIElement(x, y, parent, args) {
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
        sws::types::ImageArgs m_args;
        SDL_Surface* m_surface;
        SDL_Texture* m_texture;
    };
}