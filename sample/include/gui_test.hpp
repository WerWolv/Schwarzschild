#pragma once

#include <schwarzschild.hpp>

class GuiTest : public schwarzschild::Gui {
public:
    GuiTest() : schwarzschild::Gui() {
        printf("GuiTest constr\n");

        TTF_Font* fontSize42 = NULL;
        TTF_Font* fontSize80 = NULL;

        schwarzschild::utils::Fonts::createNintendoFont(&fontSize42, 42);
        schwarzschild::utils::Fonts::createNintendoFont(&fontSize80, 80);

        Gui::registerButtonHandler(KEY_PLUS, Gui::InputType::KEY_DOWN, std::bind(&GuiTest::onPlusButtonPressed, this));

        Gui::addUIElement<schwarzschild::ui::Header>(0, 0, schwarzschild::types::HeaderArgs("sdmc:/icon.png", fontSize42, "Schwarzschild"));
        Gui::addUIElement<schwarzschild::ui::Button>(50, 200, schwarzschild::types::ButtonArgs(500, 100, "Test"));
        Gui::addUIElement<schwarzschild::ui::Image>(50, 350, schwarzschild::types::ImageArgs("sdmc:/logo.png"));
        Gui::addUIElement<schwarzschild::ui::Text>(50, 700, schwarzschild::types::TextArgs(fontSize80, "Hello World!"));
    }

    ~GuiTest() {
        printf("GuiTest deconstr\n");
    }

    void render(SDL_Renderer **renderer) override {
        static int w = 1920, h = 1080;

        SDL_SetRenderDrawColor(*renderer, schwarzschild::resources::SwitchColors::Color_Dark_Background.r,
                                          schwarzschild::resources::SwitchColors::Color_Dark_Background.g,
                                          schwarzschild::resources::SwitchColors::Color_Dark_Background.b,
                                          schwarzschild::resources::SwitchColors::Color_Dark_Background.a);
        SDL_Rect f = {0, 0, w, h};
        SDL_RenderFillRect(*renderer, &f);
    }

    void update() {
        printf("GuiTest update\n");
    }

    void onPlusButtonPressed() {
        Gui::quit();
    }

};