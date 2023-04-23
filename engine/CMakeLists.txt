
set(ENGINE_ROOT_DIR "${SMOOTH_ROOT_DIR}/engine")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")
set(ENGINE_ASSET_DIR "/asset")

set(DEPLOY_CONFIG_DIR "configs/deployment")
set(DEVELOP_CONFIG_DIR "configs/development")

# option(ENABLE_PHYSICS_DEBUG_RENDERER "Enable Physics Debug Renderer" OFF)

# if(NOT WIN32)
#   if(ENABLE_PHYSICS_DEBUG_RENDERER)
#     message(WARNING "Disable Physics Debug Renderer")
#     set(ENABLE_PHYSICS_DEBUG_RENDERER OFF CACHE BOOL "" FORCE)
#   endif()
# endif()

# if(ENABLE_PHYSICS_DEBUG_RENDERER)
#   set(JOLT_ASSET_DIR "/jolt-asset")
# endif()

# set(SHADER_COMPILE_TARGET SmoothShaderCompile)
#add_subdirectory(shader)

add_subdirectory(3rdparty)

add_subdirectory(source/runtime)
add_subdirectory(source/editor)
add_subdirectory(source/meta_parser)
#add_subdirectory(source/test)

set(CODEGEN_TARGET "SmoothPreCompile")
include(source/precompile/precompile.cmake)
set_target_properties("${CODEGEN_TARGET}" PROPERTIES FOLDER "Engine" )

add_dependencies(SmoothRuntime "${CODEGEN_TARGET}")
add_dependencies("${CODEGEN_TARGET}" "SmoothParser")
