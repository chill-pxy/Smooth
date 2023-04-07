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
        std::string MENU;
        std::string RELOAD_SCENE;
        std::string SAVE_SCENE;
        std::string EXIT;

        std::string WINDOW;
        std::string WORLD_OBJECTS;
        std::string SCENE;
        std::string FILE_CONTENT;
        std::string DETAILS;

        std::string LANGUAGE;

        std::string TRANSLATE;
        std::string ROTATE;
        std::string SCALE;

        std::string EDITOR_MODE;

        std::string NAME;
        std::string TYPE;
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