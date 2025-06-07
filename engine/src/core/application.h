#pragma once

#include "defines.h"

struct  game;

typedef struct window_config {
    i16 x, y;
    i16 width, height;
    char* title;
} window_config;

PRIAXE_API b8 application_startup(struct game* game_instance);
PRIAXE_API b8 application_run();