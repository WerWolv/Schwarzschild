#include <stdlib.h>
#include <stdio.h>
#include <switch.h>

#include <schwarzschild.hpp>

#include <gui_test.hpp>

#define NXLINK_DEBUG 1

int main(int argc, char **argv) {
    sws::Application *app = new sws::Application();

    #if NXLINK_DEBUG
        socketInitializeDefault();
        nxlinkStdio();
    #endif

    romfsInit();

    app->registerGui("test", new GuiTest());

    app->start();

    romfsExit();

    delete app;

    #if NXLINK_DEBUG
        socketExit();
    #endif
}