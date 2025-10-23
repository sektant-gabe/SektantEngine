set(LIBRARY_SOURCES "GameLoop.cpp")
set(LIBRARY_HEADERS "GameLoop.h")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("Core" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("Core" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries("Core" PRIVATE fmt::fmt-header-only)
target_link_libraries("Core" PRIVATE glfw)
target_link_libraries("Core" PRIVATE OpenGL::GL)
target_link_libraries("Core" PRIVATE imgui::imgui)
target_link_libraries("Core" PRIVATE implot::implot)

target_set_warnings(
    TARGET
    "Core"
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS}
)

if (${ENABLE_LTO})
    target_enable_lto("Core" optimized)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("Core")
endif ()
