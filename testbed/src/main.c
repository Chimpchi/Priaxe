#include <core/logger.h>
#include <core/asserts.h>

#include <platform/platform.h>

int main(void)
{
    PRIAXE_FATAL("Test Message: %f", 61.123f);
    PRIAXE_ERROR("Test Message: %f", 61.123f);
    PRIAXE_WARN("Test Message: %f", 61.123f);
    PRIAXE_INFO("Test Message: %f", 61.123f);
    PRIAXE_DEBUG("Test Message: %f", 61.123f);
    PRIAXE_TRACE("Test Message: %f", 61.123f);

    PRIAXE_INFO("Hello, World! %i %i", 34543, 43);

    platform_state state;
    if(platform_startup(&state, "Priaxe Engine", 100, 100, 1280, 720))
    {
        while(TRUE)
        {
            platform_pump_messages(&state);
        }
    }
    
    platform_shutdown(&state);
    return 0;
}