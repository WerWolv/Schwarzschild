#pragma once

enum {
    Module_Schwarzschild = 555
};

enum {
    SchwarzschildError_AlreadyExists     = 1,
    SchwarzschildError_NotFound          = 2,
    SchwarzschildError_FontLoadingFailed = 10
};

#include <schwarzschild/application.hpp>
#include <schwarzschild/resources/colors.hpp>
#include <schwarzschild/ui/button.hpp>
#include <schwarzschild/ui/footer.hpp>
#include <schwarzschild/ui/header.hpp>
#include <schwarzschild/ui/image.hpp>
#include <schwarzschild/ui/text.hpp>