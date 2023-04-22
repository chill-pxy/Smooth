#include "runtime/resource/asset_manager/asset_manager.h"
#include "runtime/resource/config_manager/config_manager.h"
#include "runtime/tool/global/global_context.h"

namespace Smooth
{
    std::filesystem::path AssetManager::getFullPath(const std::string& relative_path) const
    {
        return std::filesystem::absolute(g_runtime_global_context.m_config_manager->getRootFolder() / relative_path);
    }
}
