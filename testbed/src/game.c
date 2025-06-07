#include "game.h"

#include <core/logger.h>

b8 game_init(game* game_instance)
{
    PRIAXE_DEBUG("Application layer has been created!");
    return TRUE;
}

b8 game_update(game* game_instance, f32 delta_time)
{
    return TRUE;
}

b8 game_render(game* game_instance, f32 delta_time)
{
    return TRUE;
}

void game_on_resize(game* game_instance, u32 width, u32 height)
{

}