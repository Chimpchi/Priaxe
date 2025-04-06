#include "logger.h"
#include "asserts.h"
#include "../platform/platform.h"

//TEMP
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialize_logging()
{
    //Create log file
    return TRUE;
}

void shutdown_logging()
{
    //Clean up logging queued entries
}

void log_output(log_level level, const char* message, ...)
{
    const char* level_strings[6] = {
        "[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "
    };
    b8 is_error = level < LOG_LEVEL_WARN;

    // The Box Method
    const u32 msg_length = 8192;
    char out_message[msg_length];
    memset(out_message, 0, sizeof(out_message));
    
    __builtin_va_list arg_ptr;      // Using this instead of va_list since Daddy Microsoft headers love overriding GCC/Clang
    va_start(arg_ptr, message);
    vsnprintf(out_message, msg_length, message, arg_ptr);
    va_end(arg_ptr);

    char out_buffer[msg_length];
    sprintf(out_buffer, "%s%s\n", level_strings[level], out_message);

    if(is_error)
        platform_console_write_error(out_buffer, level);
    else
        platform_console_write(out_buffer, level);
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, line: %d\n", expression, message, file, line);
}