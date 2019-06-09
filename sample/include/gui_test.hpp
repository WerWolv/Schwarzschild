#pragma once

#include <schwarzschild.hpp>

class GuiTest : public sws::Gui {
public:
    GuiTest() : sws::Gui() {
        printf("GuiTest constr\n");

        TTF_Font* fontSize42      = NULL;
        TTF_Font* fontSize42Icons = NULL;
        TTF_Font* fontSize80      = NULL;

        sws::utils::Fonts::createNintendoFont(&fontSize42, 42, PlSharedFontType_Standard);
        sws::utils::Fonts::createNintendoFont(&fontSize42Icons, 42, PlSharedFontType_NintendoExt);
        sws::utils::Fonts::createNintendoFont(&fontSize80, 80, PlSharedFontType_Standard);

        Gui::registerButtonHandler(KEY_PLUS, Gui::InputType::KEY_DOWN, std::bind(&GuiTest::onPlusButtonPressed, this));

        Gui::addUIElement<sws::ui::Header>(0, 0, sws::types::HeaderArgs("romfs:/icon.png", fontSize42, "Schwarzschild"));
        Gui::addUIElement<sws::ui::Text>(50, 200, sws::types::TextArgs(fontSize80, "Hello World!"));
        Gui::addUIElement<sws::ui::Image>(50, 330, sws::types::ImageArgs("romfs:/logo.png"));
        Gui::addUIElement<sws::ui::Button>(50, 660, sws::types::ButtonArgs(fontSize42, "My button"));
        // TODO: Find a better way to handle Shared Font Extended with text
        Gui::addUIElement<sws::ui::Footer>(0, 0, sws::types::FooterArgs("romfs:/icon2.png", fontSize42Icons, "\uE0E1          \uE0E0", fontSize42, "    Back      OK"));
    }

    ~GuiTest() {
        printf("GuiTest deconstr\n");
    }

    void render(SDL_Renderer **renderer) override {
        static int w = SDL_WINDOW_WIDTH, h = SDL_WINDOW_HEIGHT;

        SDL_SetRenderDrawColor(*renderer, sws::resources::colors::nx::Color_Dark_Background.r,
                                          sws::resources::colors::nx::Color_Dark_Background.g,
                                          sws::resources::colors::nx::Color_Dark_Background.b,
                                          sws::resources::colors::nx::Color_Dark_Background.a);
        SDL_Rect f = {0, 0, w, h};
        SDL_RenderFillRect(*renderer, &f);
    }

    void update() {
        printf("GuiTest update\n");
    }

    void onPlusButtonPressed() {
        printf("asdasdasd\n");
        Gui::quit();
    }
};