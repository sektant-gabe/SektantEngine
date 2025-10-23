set(LIBRARY_SOURCES "./src/GameLoop.cpp")
set(LIBRARY_HEADERS
    "./include/GameLoop.h"
    "./include/Timer.h"
    "./include/Types.h"
    "./include/Macros.h"
)
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("System" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("System" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries("System" PRIVATE fmt::fmt-header-only)
target_link_libraries("System" PRIVATE glfw)
target_link_libraries("System" PRIVATE OpenGL::GL)
target_link_libraries("System" PRIVATE imgui::imgui)
target_link_libraries("System" PRIVATE implot::implot)
target_link_libraries("System" PRIVATE implot::implot)

target_set_warnings(
    TARGET
    "System"
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS}
)

if (${ENABLE_LTO})
    target_enable_lto("System" optimized)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("System")
endif ()
