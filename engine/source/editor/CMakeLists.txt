set(TARGET_NAME SmoothEditor)

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PRIVATE
 source/main.cpp
 source/editor.cpp
 source/editor_global_context.cpp
 source/editor_input_manager.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE
 include
)

target_link_libraries(${TARGET_NAME} PUBLIC
  SmoothRuntime
)
