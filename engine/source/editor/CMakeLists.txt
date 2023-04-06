set(TARGET_NAME SmoothEditor)

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PRIVATE
 source/main.cpp
 source/editor.cpp
 source/editor_global_context.cpp
 source/editor_input_manager.cpp
 source/editor_scene_manager.cpp
 source/editor_ui.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE
 include
)

# target_include_directories(
#   ${TARGET_NAME} 
#   PUBLIC $<BUILD_INTERFACE:${THIRD_PARTY_DIR}/stb>
# )

target_link_libraries(${TARGET_NAME} PUBLIC
  SmoothRuntime
)
