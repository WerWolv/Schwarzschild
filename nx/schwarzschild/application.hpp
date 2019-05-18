#pragma once

#include <map>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <schwarzschild/gui.hpp>

namespace schwarzschild {

    class Application {
    public:
        Application() {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
                SDL_Log("SDL_Init: %s\n", SDL_GetError());
            }

            m_window = SDL_CreateWindow("sdl2_gles2", 0, 0, 1920, 1080, 0);
            if (!m_window) {
                SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
                SDL_Quit();
            }

            m_renderer = SDL_CreateRenderer(m_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (!m_renderer) {
                SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
                SDL_Quit();
            }

            for (int i = 0; i < 2; i++) {
                if (SDL_JoystickOpen(i) == NULL) {
                    SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
                    SDL_Quit();
                }
            }

            Result rc = plInitialize();
            if (R_FAILED(rc)) {
                fatalSimple(rc);
            }

            TTF_Init();

            m_appRunning = true;
        }

        ~Application() {
            for (auto [name, gui] : m_registeredGuis)
                delete gui;

            m_registeredGuis.clear();

            plExit();

            TTF_Quit();
            IMG_Quit();

            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
        }

        Result start() {
            SDL_Event event;

            while (m_appRunning) {
                while (SDL_PollEvent(&event)) {
                    switch (event.type) {
                        case SDL_JOYAXISMOTION:
                            SDL_Log("Joystick %d axis %d value: %d\n",
                                    event.jaxis.which,
                                    event.jaxis.axis, event.jaxis.value);
                            break;

                        case SDL_JOYBUTTONDOWN:                       
                            m_registeredGuis[m_currGui]->onInput(1 << event.jbutton.which, Gui::InputType::KEY_DOWN);
                            m_buttonDown[event.jbutton.which] = true;
                            break;
                        case SDL_JOYBUTTONUP:                       
                            m_registeredGuis[m_currGui]->onInput(1 << event.jbutton.which, Gui::InputType::KEY_UP);
                            m_buttonDown[event.jbutton.which] = false;
                            break;
                        case SDL_QUIT:
                            m_appRunning = false;
                            break;
                        default:
                            break;
                    }
                }

                SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
                SDL_RenderClear(m_renderer);

                if (m_registeredGuis[m_currGui] != nullptr)
                    m_registeredGuis[m_currGui]->render(&m_renderer);

                for (u8 i = 0; i < sizeof(m_buttonDown); i++) 
                    m_registeredGuis[m_currGui]->onInput(1 << i, m_buttonDown[i] ? Gui::InputType::KEY_HELD : Gui::InputType::KEY_NOT_HELD);

                for (auto uiElement : m_registeredGuis[m_currGui]->getUIElements())
                    uiElement->renderInternal(m_renderer, 0, 0);

                SDL_RenderPresent(m_renderer);
            }

            return 0;
        }

        Result registerGui(std::string guiName, Gui *gui) {
            if (m_registeredGuis.find(guiName) == m_registeredGuis.end()) {
                if (m_registeredGuis.size() == 0)
                    m_currGui = guiName;

                m_registeredGuis.insert(std::make_pair(guiName, gui));
                
                return 0; 
            }
            
            return SchwarzschildError_AlreadyExists;
        }

        Result switchGui(std::string guiName) {
            if (m_registeredGuis.find(guiName) != m_registeredGuis.end()) {
                m_currGui = guiName;
                
                return 0;
            }
            
            return SchwarzschildError_NotFound;
        }

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        bool m_appRunning;

        std::map<std::string, Gui*> m_registeredGuis;
        std::string m_currGui;

        bool m_buttonDown[32];
    };
}