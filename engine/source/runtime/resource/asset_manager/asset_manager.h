#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

#include "runtime/core/meta/json.h"
#include "runtime/resource/asset_manager/asset_manager.h"
#include "runtime/core/meta/serializer/serializer.h"

namespace Smooth
{
    class AssetManager
    {
    public:
        template<typename AssetType>
        bool loadAsset(const std::string& asset_url, AssetType& out_asset) const
        {
            std::filesystem::path asset_path = getFullPath(asset_url);
            std::ifstream asset_json_file(asset_path);
            if(!asset_json_file)
            {
                std::cout<<"open file:"<<asset_path<<" failed"<<std::endl;
                return false;
            }

            std::stringstream buffer;
            buffer << asset_json_file.rdbuf();
            std::string asset_json_text(buffer.str());

            //parse to json object and read to runtime res object
            std::string error;
            auto&& asset_json = Json::parse(asset_json_text, error);
            if(!error.empty())
            {
                std::cout<<"parse json file:"<<asset_url<<" failed"<<std::endl;
                return false;
            }

            Serializer::read(asset_json, out_asset);
            return true;
        }
        
        template<typename AssetType>
        bool saveAsset(const AssetType& out_asset, const std::string& asset_url) const;
        
        std::filesystem::path getFullPath(const std::string& relative_path) const;
    };
}