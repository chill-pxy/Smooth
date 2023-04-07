#pragma once

#include <string>

namespace Smooth
{
    enum class LanguageType : int
    {
        Chinese = 0,
        English = 1
    };

    struct EditorText
    {
        std::string MENU          = "菜单";
        std::string RELOAD_SCENE  = "重新加载场景";
        std::string SAVE_SCENE    = "保存当前场景";
        std::string EXIT          = "退出";

        std::string WINDOW        = "窗口";
        std::string WORLD_OBJECTS = "场景物体";
        std::string SCENE         = "场景";
        std::string FILE_CONTENT  = "文件管理器";
        std::string DETAILS       = "属性";

        std::string LANGUAGE      = "语言";

        std::string TRANSLATE     = "平移";
        std::string ROTATE        = "旋转";
        std::string SCALE         = "缩放";

        std::string EDITOR_MODE   = "编辑模式";
    };

    class EditorLanguage
    {
    public:
        void initialize();
        void SelectLanguage(LanguageType language);

        EditorText getEditorText(){ return editor_text; }
    
    private:
        void ChangeTextContent(LanguageType language);

        EditorText editor_text;
        LanguageType language_type {LanguageType::Chinese};
    };
}