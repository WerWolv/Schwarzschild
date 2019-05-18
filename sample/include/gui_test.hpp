#pragma once

#include <schwarzschild.hpp>

class GuiTest : public schwarzschild::Gui {
public:
    GuiTest() : schwarzschild::Gui() {
        printf("GuiTest constr\n");

        TTF_Font* fontSize40 = NULL;
        TTF_Font* fontSize80 = NULL;

        schwarzschild::utils::Fonts::createNintendoFont(&fontSize40, 40);
        schwarzschild::utils::Fonts::createNintendoFont(&fontSize80, 80);

        Gui::registerButtonHandler(KEY_PLUS, Gui::InputType::KEY_DOWN, std::bind(&GuiTest::onPlusButtonPressed, this));

        Gui::addUIElement<schwarzschild::ui::Button>(50, 50, schwarzschild::types::ButtonArgs(500, 100, "Test"));
        Gui::addUIElement<schwarzschild::ui::Image>(50, 200, schwarzschild::types::ImageArgs("sdmc:/test.png"));
        Gui::addUIElement<schwarzschild::ui::Text>(50, 550, schwarzschild::types::TextArgs(fontSize40, "Hello World in size 40!"));
        Gui::addUIElement<schwarzschild::ui::Text>(50, 640, schwarzschild::types::TextArgs(fontSize80, "Hello World in size 80!"));
    }

    ~GuiTest() {
        printf("GuiTest deconstr\n");
    }

    void draw_rects(SDL_Renderer *renderer, int x, int y) {
        // R
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect r = {x, y, 64, 64};
        SDL_RenderFillRect(renderer, &r);

        // G
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect g = {x + 64, y, 64, 64};
        SDL_RenderFillRect(renderer, &g);

        // B
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_Rect b = {x + 128, y, 64, 64};
        SDL_RenderFillRect(renderer, &b);
    }

    void render(SDL_Renderer **renderer) override {
        static int x = 0, w = 1920, h = 1080;
        // fill window bounds
        SDL_SetRenderDrawColor(*renderer, 111, 111, 111, 255);
        SDL_Rect f = {0, 0, w, h};
        SDL_RenderFillRect(*renderer, &f);

        draw_rects(*renderer, x, 0);
        draw_rects(*renderer, x, h - 64);
    }

    void update() {
        printf("GuiTest update\n");
    }

    void onPlusButtonPressed() {
        Gui::quit();
    }

};