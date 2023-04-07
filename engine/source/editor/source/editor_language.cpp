#include <iostream>

#include "editor_language.h"

namespace Smooth
{
    void EditorLanguage::initialize()
    {
        ChangeTextContent(language_type);
    }

    void EditorLanguage::SelectLanguage(LanguageType language)
    {
        language_type = language;
        ChangeTextContent(language_type);
    }

    void EditorLanguage::ChangeTextContent(LanguageType language)
    {
        switch (language)
        {
        case LanguageType::Chinese:
            editor_text.MENU          = "菜单";
            editor_text.RELOAD_SCENE  = "重新加载场景";
            editor_text.SAVE_SCENE    = "保存当前场景";
            editor_text.EXIT          = "退出";

            editor_text.WINDOW        = "窗口";
            editor_text.WORLD_OBJECTS = "场景物体";
            editor_text.SCENE         = "场景";
            editor_text.FILE_CONTENT  = "文件管理器";
            editor_text.DETAILS       = "属性";

            editor_text.LANGUAGE      = "语言";

            editor_text.TRANSLATE     = "平移";
            editor_text.ROTATE        = "旋转";
            editor_text.SCALE         = "缩放";

            editor_text.EDITOR_MODE   = "编辑模式";
            editor_text.NAME          = "名称";
            editor_text.TYPE          = "类型";
            break;

        case LanguageType::English:
            editor_text.MENU          = "Menu";
            editor_text.RELOAD_SCENE  = "Reload Scene";
            editor_text.SAVE_SCENE    = "Save Scene";
            editor_text.EXIT          = "Exit";

            editor_text.WINDOW        = "Window";
            editor_text.WORLD_OBJECTS = "World Objects";
            editor_text.SCENE         = "Scene";
            editor_text.FILE_CONTENT  = "File Content";
            editor_text.DETAILS       = "Details";

            editor_text.LANGUAGE      = "Language";

            editor_text.TRANSLATE     = "Translate";
            editor_text.ROTATE        = "Rotate";
            editor_text.SCALE         = "Scale";

            editor_text.EDITOR_MODE   = "Editor Mode";

            editor_text.NAME          = "Name";
            editor_text.TYPE          = "Type";
            break;

        default:
            break;
        }
    }
}