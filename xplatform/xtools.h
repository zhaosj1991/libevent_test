#pragma once

#include <string>
#include <iostream>

#define LOG(level, msg) std::cout << level << ":" << __FILE__ << ":" << \
__LINE__ << ": " << msg << std::endl;
#define LOGDEBUG(msg) LOG("DEBUG", msg)
#define LOGINFO(msg) LOG("INFO", msg)
#define LOGERROR(msg) LOG("ERROR", msg)