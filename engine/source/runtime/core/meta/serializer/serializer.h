#pragma once

#include "runtime/core/meta/json.h"
#include "runtime/core/meta/reflection/reflection.h"

namespace Smoooth
{
    template<typename...>
    inline constexpr bool always_false = false;

    class Serializer
    {
    public:
        // template<typename T>
        // static Json writePointer(T* instance)
        // {
        //     return Json::object {{"$typeName", Json{"*"}}, {"$context", Serializer::write(*instance)}};
        // }

        template<typename T>
        static T*& readPointer(const Json& json_context, T*& instance)
        {
            assert(instance == nullptr);
            std::string type_name = json_context["$typeName"].string_value();
            assert(!type_name.empty());
            if('*' == type_name[0])
            {
                instance = new T;
                read(json_context["$context"], *instance);
            }
            else
            {
                instance = static_cast<T*>(
                    Smooth::Reflection::TypeMeta::newFromNameAndJson(type_name, json_context["$context"]).m_instance);
            }
            return instance;
        }
        
        // template<typename T>
        // static Json write(const Reflection::ReflectionPtr<T>& instance)
        // {
        //     T* instance_ptr = static_cast<T*>(instance.operator->());
        //     std::string type_name = instance.getTypeName();
        //     return Json::object { {"$typeName", Json(type_name)},
        //                         {"$context", Reflection::TypeMeta::writeByName(type_name, instance_ptr)} };
        // }

        template<typename T>
        static T*& read(const Json& json_context, Smooth::Reflection::ReflectionPtr<T>& instance)
        {
            std::string type_name = json_context["$typeName"].string_value();
            instance.setTypeName(type_name);

        }
    };
}