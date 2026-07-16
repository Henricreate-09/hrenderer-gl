#pragma once

#include "Core.hpp"

namespace Debug {
    void Log(String info);
    void LogWarning(String info);
    void LogError(String info);

    void ErrorCrash(String error);
    
    String GetGLFWError();
}