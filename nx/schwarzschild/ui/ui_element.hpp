#pragma once

#include <SDL.h>
#include <switch.h>

#include <schwarzschild/utils/types.hpp>

namespace schwarzschild::ui {
    class IUIElement {
    public:
        IUIElement(int x, int y, schwarzschild::types::UIElementArgs args) : m_x(x), m_y(y) {}
        
        virtual ~IUIElement() { }

        virtual void render(SDL_Renderer *renderer, int x, int y) = 0;
        virtual void update() = 0;
        virtual void onInteract(u64 kdown) = 0;

        void renderInternal(SDL_Renderer *renderer, int x, int y) {
            this->render(renderer, x + m_x, y + m_y);
            
            for (auto &uiElement : m_uiElements)
                uiElement->renderInternal(renderer, x + m_x, y + m_y);
        }

    protected:
        template<typename T, typename std::enable_if<std::is_base_of<schwarzschild::ui::IUIElement, T>::value>::type* = nullptr, typename K>
        Result addUIElement(int x, int y, K args) {
            m_uiElements.push_back(new T(x, y, args));

            return 0;
        }

    private:
        IUIElement();

        std::vector<schwarzschild::ui::IUIElement*> m_uiElements;
        int m_x, m_y;
    };
}