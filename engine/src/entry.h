#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

extern b8 startup_game(game* out_game);

int main(void)
{
    game game_instance;
    if(!startup_game(& game_instance))
    {
        PRIAXE_FATAL("Failed to start game.");
        return -1;
    }

    if(!game_instance.init | !game_instance.update | !game_instance.render | !game_instance.on_resize)
    {
        PRIAXE_FATAL("Engine function pointers have not been assigned.");
        return -1;
    }

    if(!application_startup(&game_instance))
    {
        PRIAXE_INFO("Failed to startup application.");
        return -1;
    }
    
    if(!application_run())
    {
        PRIAXE_INFO("Application did not shutdown properly.");
        return -1;
    }

    return 0;
}