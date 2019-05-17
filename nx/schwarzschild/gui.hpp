#pragma once

#include <switch.h>
#include <functional>
#include <vector>

#include <SDL.h>

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

        void update() {

        }

        virtual void onInput(u32 keys, InputType inputType) final {
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
    
        virtual Result registerButtonHandler(HidControllerKeys key, InputType inputType, std::function<void()> function) final {
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

    protected:
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

    };
}