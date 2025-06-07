#include "application.h"
#include "game_types.h"

#include "logger.h"
#include "platform/platform.h"

typedef enum application_state
{
    UNDEFINED, INITIALIZING, RUNNING, SUSPENDED, SHUTTING_DOWN
} application_state;

typedef struct application_info
{
    game* game_instance;
    application_state app_state;
    platform_state platform_state;
    i16 width, height;
    f64 last_time;

} application_info;

static application_info app_info;

b8 application_startup(game* game_instance)
{
    // TODO: Do saftey check to ensure engine does not start more than once.

    if(app_info.app_state != UNDEFINED)
    {
        PRIAXE_ERROR("Failed to run startup. Application already created!");
        return FALSE;
    }

    app_info.game_instance = game_instance;

    PRIAXE_FATAL("Test Message: %f", 61.123f);
    PRIAXE_ERROR("Test Message: %f", 61.123f);
    PRIAXE_WARN("Test Message: %f", 61.123f);
    PRIAXE_INFO("Test Message: %f", 61.123f);
    PRIAXE_DEBUG("Test Message: %f", 61.123f);
    PRIAXE_TRACE("Test Message: %f", 61.123f);

    PRIAXE_INFO("Hello, World! %i %i", 34543, 43);
    
    initialize_logging();
    app_info.app_state = INITIALIZING;

    if(!platform_startup(&app_info.platform_state, game_instance->win_config.title, game_instance->win_config.x, game_instance->win_config.y, game_instance->win_config.width, game_instance->win_config.height))
    {
        app_info.app_state = UNDEFINED;
        return FALSE;
    }

    if(!app_info.game_instance->init(app_info.game_instance))
    {
        PRIAXE_FATAL("Unable to initialize game.");
        return FALSE;
    }
    
    app_info.app_state = RUNNING;
    return TRUE;
}

b8 application_run()
{
    while(app_info.app_state == RUNNING)
    {
        platform_pump_messages(&app_info.platform_state);

        if(!app_info.game_instance->update(app_info.game_instance, 0.0f))
        {
            PRIAXE_FATAL("Failed to update, closing engine.");
            break;
        }

        if(!app_info.game_instance->render(app_info.game_instance, 0.0f))
        {
            PRIAXE_FATAL("Failed to render, closing engine.");
            break;
        }
    }
    
    app_info.app_state = SHUTTING_DOWN;
    platform_shutdown(&app_info.platform_state);
    app_info.app_state = UNDEFINED;
    return TRUE;
}