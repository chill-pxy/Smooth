#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace Smooth
{
    class AssetManager
    {
    public:
        template<typename AssetType>
        bool loadAsset(const std::string& asset_url, AssetType& out_asset) const;
        
        template<typename AssetType>
        bool saveAsset(const AssetType& out_asset, const std::string& asset_url) const;
        
        std::filesystem::path getFullPath(const std::string& relative_path) const;
    };
}