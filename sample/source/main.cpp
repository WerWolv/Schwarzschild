#include <stdlib.h>
#include <stdio.h>
#include <switch.h>

#include <schwarzschild.hpp>

#include <gui_test.hpp>

#define NXLINK_DEBUG 1

int main(int argc, char **argv) {
    schwarzschild::Application *app = new schwarzschild::Application();

    #if NXLINK_DEBUG
        socketInitializeDefault();
        nxlinkStdio();
    #endif

    app->registerGui("test", new GuiTest());

    app->start();

    delete app;

    #if NXLINK_DEBUG
        socketExit();
    #endif
}