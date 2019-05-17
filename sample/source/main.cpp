#include <stdlib.h>
#include <stdio.h>
#include <switch.h>

#include <schwarzschild.hpp>

#include <gui_test.hpp>

int main(int argc, char **argv) {
    schwarzschild::Application *app = new schwarzschild::Application();

    socketInitializeDefault();
    nxlinkStdio();

    app->registerGui("test", new GuiTest());

    app->start();

    delete app;

    socketExit();
}