#pragma once

#include <switch.h>
#include <functional>
#include <vector>
#include <memory>

#include <SDL.h>

#include <schwarzschild/ui/ui_element.hpp>
#include <schwarzschild/utils/types.hpp>

namespace schwarzschild {

    class Gui {
    public:
        enum InputType {
            KEY_HELD,
            KEY_NOT_HELD,
            KEY_DOWN,
            KEY_UP
        };

        Gui() {

        }

        virtual ~Gui() {

        }
    
        virtual void render(SDL_Renderer **renderer) = 0;
        virtual void update() = 0;

        void onInput(u32 keys, InputType inputType) {
            switch (inputType) {
                case KEY_HELD:
                    for (u32 i = 0; i < m_buttonHeldCallbacks.size(); i++)
                        m_buttonHeldCallbacks[i].second();
                    break;
                case KEY_NOT_HELD:
                    for (u32 i = 0; i < m_buttonNotHeldCallbacks.size(); i++)
                        m_buttonNotHeldCallbacks[i].second();
                    break;
                case KEY_DOWN:
                    for (u32 i = 0; i < m_buttonDownCallbacks.size(); i++)
                        m_buttonDownCallbacks[i].second();
                    break;
                case KEY_UP:
                    for (u32 i = 0; i < m_buttonUpCallbacks.size(); i++)
                        m_buttonUpCallbacks[i].second();
                    break;
            }
        }
    
    std::vector<schwarzschild::ui::IUIElement*>& getUIElements() {
        return m_uiElements;
    }    

    protected:
        Result registerButtonHandler(HidControllerKeys key, InputType inputType, std::function<void()> function) {
            switch (inputType) {
                case KEY_HELD:
                    m_buttonHeldCallbacks.push_back(std::make_pair(key, function));
                    break;
                case KEY_NOT_HELD:
                    m_buttonNotHeldCallbacks.push_back(std::make_pair(key, function));
                    break;
                case KEY_DOWN:
                    m_buttonDownCallbacks.push_back(std::make_pair(key, function));
                    break;
                case KEY_UP:
                    m_buttonUpCallbacks.push_back(std::make_pair(key, function));
                    break;
            }

            return 0;
        }

        template<typename T, typename std::enable_if<std::is_base_of<schwarzschild::ui::IUIElement, T>::value>::type* = nullptr, typename K>
        Result addUIElement(K args) {
            m_uiElements.push_back(new T(args));

            return 0;
        }

        Result quit() {
            SDL_Event quitEvent;
            quitEvent.type = SDL_QUIT;
            quitEvent.quit.type = SDL_QUIT;

            SDL_PushEvent(&quitEvent);

            return 0;
        }

    private:
        std::vector<std::pair<HidControllerKeys, std::function<void()>>> m_buttonHeldCallbacks;
        std::vector<std::pair<HidControllerKeys, std::function<void()>>> m_buttonNotHeldCallbacks;
        std::vector<std::pair<HidControllerKeys, std::function<void()>>> m_buttonDownCallbacks;
        std::vector<std::pair<HidControllerKeys, std::function<void()>>> m_buttonUpCallbacks;

        std::vector<schwarzschild::ui::IUIElement*> m_uiElements;
    };
}