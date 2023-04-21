#pragma once

#include <functional>

#include "runtime/core/meta/json.h"

namespace Smooth
{
    
#if defined(_REFLECTION_PARSER_)
#define META(...) __attribute__((annotate(#__VA_ARGS__)))
#define CLASS(class_name, ...) class __attribute__((annotate(#__VA_ARGS__))) class_name
#define STRUCT(struct_name, ...) struct __attribute__((annotate(#__VA_ARGS__))) struct_name

#else
#define META(...)
#define CLASS(class_name, ...) class class_name
#define STRUCT(struct_name, ...) struct struct_name
#endif //_REFLECTION_PARSER_

#define REFLECTION_BODY(class_name) \
    friend class Reflection::TypeFieldReflectionOparator::Type##class_name##Operator; \
    friend class Serializer;

#define REFLECTION_TYPE(class_name) \
    namespace Reflection \
    { \
        namespace TypeFieldReflectionOparator \
        { \
            class Type##class_name##Operator; \
        } \
    };

#define REGISTER_FIELD_TO_MAP(name, value) TypeMetaRegisterinterface::registerToFieldMap(name, value);
#define REGISTER_Method_TO_MAP(name, value) TypeMetaRegisterinterface::registerToMethodMao(name, value);
#define REGISTER_BASE_CLASS_TO_MAP(name, value) TypeMetaRegisterinterface::registerToClassMap(name, value);
#define REGISTER_ARRAY_TO_MAP(name, value) TypeMetaRegisterinterface::registerToArrayMap(name, value);
#define UNREGISTER_ALL TypeMetaRegisterinterface::unregisterAll();

#define SMOOTH_REFLECTION_NEW(name, ...) Reflection::RelectionPtr(#name, new name(__VA_ARGS__));
#define SMOOTH_REFLECTION_DELETE(value) \
    if(value) \
    { \
        delete value.operator->(); \
        value.getPtrReference() == nullptr; \
    }
#define SMOOTH_REFLECTION_DEEP_COPY(type, dst_ptr, scrc_ptr) \
    *static_cast<type*>(dst_ptr) = *static_cast<type*>(src_ptr.getPtr());

#define TypeMetaDef(class_name, ptr) \
    Smooth::Reflection::ReflectionInstance(Smooth::Reflection::TypeMeta::newMetaFromName(#class_name), \ (class_name*)ptr)

#define TypeMetaDefPtr(class_name, ptr) \
    new Smooth::Reflecton::ReflectionInstance(Smooth::Reflection::TypeMeta::newMetaFromName(#class_name,) \ (class_name*)ptr)

    namespace Reflection
    {
        class TypeMeta;
        class FieldAccessor;
        class MethodAccessor;
        class ArrayAccessor;
        class ReflectionInstance;
    }

    typedef std::function<void(void*, void*)>      SetFunction;
    typedef std::function<void*(void*)>            GetFunction;
    typedef std::function<const char*()>           GetNameFunction;
    typedef std::function<void(int, void*, void*)> SetArrayFunc;
    typedef std::function<void*(int, void*)>       GetArrayFunc;
    typedef std::function<int(void*)>              GetSizeFunc;
    typedef std::function<bool()>                  GetBoolFunc;
    typedef std::function<void(void*)>             InvokeFunction;

    typedef std::function<void*(const Json&)>                           ConstructorWithJson;
    typedef std::function<Json(void*)>                                  WriteJsonByName;
    typedef std::function<int(Reflection::ReflectionInstance*&, void*)> GetBaseClassReflectionInstanceListFunc;

    typedef std::tuple<SetFunction, GetFunction, GetNameFunction, GetNameFunction, GetNameFunction, GetBoolFunc> FieldFunctionTuple;
    typedef std::tuple<GetNameFunction, InvokeFunction>                                                          MethodFunctionTuple;
    typedef std::tuple<GetBaseClassReflectionInstanceListFunc, ConstructorWithJson, WriteJsonByName>             ClassFunctionTuple;
    typedef std::tuple<SetArrayFunc, GetArrayFunc, GetSizeFunc, GetNameFunction, GetNameFunction>                ArrayFunctionTuple;
    
    namespace Reflection
    {
        class TypeMeta
        {
            friend class FieldAccessor;
            friend class ArrayAccessor;
            friend class TypeMetaRegisterinterface;

        public:
            TypeMeta();

            static TypeMeta newMetaFromName(std::string type_name);

            static ReflectionInstance newFromNameAndJson(std::string type_name, const Json& json_context);
        
        private:
            TypeMeta(std::string type_name);
        
        private:
            std::vector<FieldAccessor, std::allocator<FieldAccessor>>   m_fields;
            std::vector<MethodAccessor, std::allocator<MethodAccessor>> m_methods;
            std::string                                                 m_type_name;
            bool                                                        m_is_vaild;
        };

        class FieldAccessor
        {
            friend class TypeMeta;
        
        public:
            FieldAccessor();

        private:
            FieldFunctionTuple* m_functions;
            const char*         m_field_name;
            const char*         m_field_type_name;
        };

        class MethodAccessor
        {
            friend class TypeMeta;
        
        public:
            MethodAccessor();
        
        private:
            MethodFunctionTuple* m_functions;
            const char*          m_method_name;
        };

        class ReflectionInstance
        {
        public:
            ReflectionInstance(TypeMeta meta, void* instance) : m_meta(meta), m_instance(instance) {}
            ReflectionInstance() : m_meta(), m_instance(nullptr) {}
             
        public:
            TypeMeta m_meta;
            void*    m_instance;
        };

        template<typename T>
        class ReflectionPtr
        {
            template<typename U>
            friend class ReflectionPtr;

        public:
            ReflectionPtr(std::string type_name, T* instance) : m_type_name(type_name), m_instance(instance) {}
            ReflectionPtr() : m_type_name(), m_instance(nullptr) {}
            ReflectionPtr(const ReflectionPtr& dest) : m_type_name(dest.m_type_name), m_instance(dest.m_instance) {}

            void setTypeName(std::string name){ m_type_name = name; }

        private:
            std::string m_type_name {""};
            typedef T   m_type;
            T*          m_instance {nullptr};
        };
    }
}

