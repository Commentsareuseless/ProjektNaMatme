#pragma once

#include <iostream>

#define LVL_INFO    (1 << 0)
#define LVL_DEBUG   (1 << 1)
#define LVL_ERROR   (1 << 2)

// Suppress logs by removing one of levels from this macro
#define LOG_LEVEL (LVL_INFO | LVL_DEBUG | LVL_ERROR)

#if LOG_LEVEL & LVL_INFO
#   define LOG_info(message) \
        std::cerr << "[INFO]\t" << (message) << std::endl;
#else
#   define LOG_info(message)
#endif

#if LOG_LEVEL & LVL_DEBUG
#   define LOG_debug(debugMessage) \
        std::cerr << "[DEBUG]\t" << (debugMessage) << std::endl;
#else
#   define LOG_debug(debugMessage)
#endif

#if LOG_LEVEL & LVL_ERROR
#   define LOG_error(errorMessage) \
        std::cerr << "[ERROR]\t" << (errorMessage) << std::endl;
#else
#   define LOG_error(errorMessage)
#endif



