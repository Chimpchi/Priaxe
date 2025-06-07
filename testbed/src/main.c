#include "game.h"

#include <entry.h>
#include <platform/platform.h>

b8 startup_game(game* out_game)
{
    out_game->win_config.x = 100;
    out_game->win_config.y = 100;
    out_game->win_config.width = 1920;
    out_game->win_config.height = 1080;
    out_game->win_config.title = "Priaxe Engine Testbed";

    out_game->init = game_init;
    out_game->update = game_update;
    out_game->render = game_render;
    out_game->on_resize = game_on_resize;

    out_game->state = platform_allocate(sizeof(game_state), FALSE);
    return TRUE;
}