#include <fstream>
#include <string>
#include <iostream>

#include "runtime/resource/config_manager/config_manager.h"

namespace Smooth
{
    void ConfigManager::initialize(const std::filesystem::path& config_file_path)
    {
        std::ifstream config_file(config_file_path);
        std::string   config_line;

        while(std::getline(config_file, config_line))
        {
            size_t seperate_pos = config_line.find_first_of('=');
            if(seperate_pos > 0 && seperate_pos < (config_line.length() -1 ))
            {
                std::string name  = config_line.substr(0, seperate_pos);
                std::string value = config_line.substr(seperate_pos + 1, config_line.length() - seperate_pos - 1);
                if(name == "BinaryRootFolder")
                {
                    m_root_folder = config_file_path.parent_path();
                }
                if(name == "AssetFolder")
                {
                    m_asset_folder = m_root_folder / value;
                }
                if(name == "BigIconFile")
                {
                    m_editor_big_icon_path = m_root_folder / value;
                }
                if(name == "SmallIconFile")
                {
                    m_editor_small_icon_path = m_root_folder / value;
                }
                if(name == "FontFile")
                {
                    m_editor_font_path = m_root_folder / value;
                }
            }
        }
        std::cout<<m_root_folder<<std::endl;
        std::cout<<m_editor_big_icon_path<<std::endl;
    }

    const std::filesystem::path& ConfigManager::getRootFolder() const { return m_root_folder; }
    const std::filesystem::path& ConfigManager::getAssetFolder() const{ return m_asset_folder; }
    const std::filesystem::path& ConfigManager::getEditorBigIconPath() const{ return m_editor_big_icon_path; }
    const std::filesystem::path& ConfigManager::getEditorSmallIconPath() const{ return m_editor_small_icon_path; }
    const std::filesystem::path& ConfigManager::getEditorFontPath() const{ return m_editor_font_path; }
}