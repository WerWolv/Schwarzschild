#pragma once

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class Text : public IUIElement {
    public:
        int w;
        int h;

        Text(int x, int y, IUIElement *parent, schwarzschild::types::TextArgs args) : schwarzschild::ui::IUIElement(x, y, parent, args) {
            m_args = args;

            // TODO: Support color schemes
            m_surface = TTF_RenderText_Blended(args.font, args.text.c_str(), schwarzschild::resources::SwitchColors::Color_Dark_Text);
            TTF_SizeText(args.font, args.text.c_str(), &m_w, &m_h);
            m_texture = nullptr;
        }
        
        ~Text() {
            SDL_FreeSurface(m_surface);
            SDL_DestroyTexture(m_texture);
        }

        void render(SDL_Renderer *renderer, int x, int y) {
            if (m_texture == nullptr)
                m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);

            SDL_Rect rect = { x, y, m_w, m_h };

            SDL_RenderCopy(renderer, m_texture, NULL, &rect);
        }

        void update() {

        }

        void onInteract(u64 kdown) {

        }

        u32 getTextWidth() {
            return m_w;
        }

        u32 getTextHeight() {
            return m_h;
        }

    private:
        schwarzschild::types::TextArgs m_args;
        SDL_Surface* m_surface;
        SDL_Texture* m_texture;

        int m_w, m_h;
    };
}