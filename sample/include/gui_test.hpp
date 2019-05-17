#pragma once

#include <schwarzschild/gui.hpp>

class GuiTest : public schwarzschild::Gui {
public:
    GuiTest() : schwarzschild::Gui() {
        printf("GuiTest constr\n");

        Gui::registerButtonHandler(KEY_PLUS, Gui::InputType::KEY_DOWN, std::bind(&GuiTest::onPlusButtonPressed, this));
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
        SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
        SDL_RenderClear(*renderer);

        // fill window bounds
        SDL_SetRenderDrawColor(*renderer, 111, 111, 111, 255);
        SDL_Rect f = {0, 0, w, h};
        SDL_RenderFillRect(*renderer, &f);

        draw_rects(*renderer, x, 0);
        draw_rects(*renderer, x, h - 64);

        SDL_RenderPresent(*renderer);
    }

    void update() {
        printf("GuiTest update\n");
    }

    void onPlusButtonPressed() {
        Gui::quit();
    }

};