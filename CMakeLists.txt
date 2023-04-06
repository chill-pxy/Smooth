cmake_minimum_required(VERSION 3.20)

project(Smooth VERSION 0.1)

SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(BUILD_SHARED_LIBS OFF)

include(CMakeDependentOption)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set(SMOOTH_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_INSTALL_PREFIX "${SMOOTH_ROOT_DIR}/bin")
set(BINARY_ROOT_DIR "${CMAKE_INSTALL_PREFIX}/")
set(CONFIG_DIR "${SMOOTH_ROOT_DIR}")


SET(OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/out)
if (NOT EXISTS ${OUT_DIR})
    file(MAKE_DIRECTORY ${OUT_DIR})
endif ()

if(NOT "${CMAKE_CURRENT_SOURCE_DIR}/engine/configs/deployment/SmoothEditor.ini")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/engine/configs/deployment/SmoothEditor.ini ${OUT_DIR}) 
endif ()

if(NOT "${CMAKE_CURRENT_SOURCE_DIR}/engine/source/editor/resource/SmoothEditorBigIcon.png")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/engine/source/editor/resource/SmoothEditorBigIcon.png ${OUT_DIR})
endif()

if(NOT "${CMAKE_CURRENT_SOURCE_DIR}/engine/source/editor/resource/SmoothEditorSmallIcon.png")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/engine/source/editor/resource/SmoothEditorSmallIcon.png ${OUT_DIR})
endif()

if(NOT "${CMAKE_CURRENT_SOURCE_DIR}/engine/source/editor/resource/SmoothEditorFont.TTF")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/engine/source/editor/resource/SmoothEditorFont.TTF ${OUT_DIR})
endif()

SET(EXECUTABLE_OUTPUT_PATH ${OUT_DIR})
SET(LIBRARY_OUTPUT_PATH ${OUT_DIR})

add_subdirectory(engine)