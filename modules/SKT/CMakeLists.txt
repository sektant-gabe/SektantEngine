set(LIBRARY_SOURCES src/GameLoop.cpp src/Entrypoint.cpp)

set(LIBRARY_HEADERS
    SKT/GameLoop.h
    SKT/Timer.h
    SKT/Types.h
    SKT/Entrypoint.h
    SKT/Window.h
    SKT/Macros.h
)
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("SKT" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("SKT" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries("SKT" PRIVATE fmt::fmt-header-only)
target_link_libraries("SKT" PRIVATE glfw)
target_link_libraries("SKT" PRIVATE OpenGL::GL)
target_link_libraries("SKT" PRIVATE imgui::imgui)
target_link_libraries("SKT" PRIVATE implot::implot)

if (${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "SKT"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif ()

if (${ENABLE_LTO})
    target_enable_lto("SKT" optimized)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target(
        "SKT
    "
    )
endif ()
