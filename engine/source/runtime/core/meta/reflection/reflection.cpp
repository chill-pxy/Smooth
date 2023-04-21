#include "runtime/core/meta/reflection/reflection.h"

namespace Smooth
{
    namespace Reflection
    {
        const char* k_unknown_type = "UnknownType";
        const char* k_unknown      = "Unknown";

        static std::map<std::string,  ClassFunctionTuple*>      m_class_map;
        static std::multimap<std::string, FieldFunctionTuple*>  m_field_map;
        static std::multimap<std::string, MethodFunctionTuple*> m_method_map;
        static std::map<std::string, ArrayFunctionTuple*>       m_array_map;

        TypeMeta::TypeMeta(std::string type_name)
        {
            m_is_vaild = false;
            m_fields.clear();
            m_methods.clear();
        }

        TypeMeta::TypeMeta() : m_type_name(k_unknown_type), m_is_vaild(false) 
        {
            m_fields.clear();
            m_methods.clear();
        }

        ReflectionInstance TypeMeta::newFromNameAndJson(std::string type_name, const Json& json_context)
        {
            auto iter = m_class_map.find(type_name);

            if(iter != m_class_map.end())
            {
                return ReflectionInstance(TypeMeta(type_name), (std::get<1>(*iter->second)(json_context)));
            }
            return ReflectionInstance();
        }
    }
}