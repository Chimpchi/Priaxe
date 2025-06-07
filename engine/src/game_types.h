#pragma once

#include "core/application.h"

typedef struct game
{
    window_config win_config;

    b8 (*init)(struct game* game_instance);
    b8 (*update)(struct game* game_instance, f32 delta_time);
    b8 (*render)(struct game* game_instance, f32 delta_time);
    void (*on_resize)(struct game* game_instance, u32 width, u32 height);
    void* state;
} game;