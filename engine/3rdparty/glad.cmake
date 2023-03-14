SET(GLAD_DIR glad)
add_library(glad SHARED)

target_sources(glad PRIVATE
        ${GLAD_DIR}/src/glad.c
        )

target_include_directories(glad PUBLIC
        ${GLAD_DIR}/include
        )