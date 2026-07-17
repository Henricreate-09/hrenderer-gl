#pragma once

#include <fstream>
#include "Core.hpp"

namespace File {
    String ReadAsset(const String &assetName);

    // TODO: Write definitions for these functions
    void WriteFile(const String &filePath, const String &contents);
    String ReadFile(const String &filePath);
    void DeleteFile(const String &filePath);
}