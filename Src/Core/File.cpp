#include "File.hpp"

String File::ReadAsset(const String &assetName)
{
    String path = "./Assets/" + assetName;
    
    // TODO: Add error handling
    std::ifstream asset(path);
    String line{ "" };
    String contents{ "" };
    
    while (std::getline(asset, line)) {
        contents += line + '\n';
    }
    
    asset.close();
    return contents;
}
