#pragma once

#include <SDL.h>
#include <switch.h>

#include <schwarzschild/utils/types.hpp>

namespace sws::ui {
    class IUIElement {
    public:
        IUIElement(int x, int y, IUIElement *parent, sws::types::UIElementArgs args) : m_x(x), m_y(y), m_parent(parent) {}
        
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
        template<typename T, typename std::enable_if<std::is_base_of<sws::ui::IUIElement, T>::value>::type* = nullptr, typename K>
        T* addUIElement(int x, int y, K args) {
            T *uiElement = new T(x, y, this, args);
            m_uiElements.push_back(uiElement);

            return uiElement;
        }

        IUIElement* getParent() {
            return m_parent;
        }

    private:
        IUIElement();

        std::vector<sws::ui::IUIElement*> m_uiElements;
        int m_x, m_y;
        IUIElement *m_parent;
    };
}