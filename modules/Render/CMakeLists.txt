set(LIBRARY_SOURCES "./src/TGAImage.cpp" "./src/WriteTGA.cpp")
set(LIBRARY_HEADERS "./include/TGAImage.h" "./include/WriteTGA.h" "./include/Window.h")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("Render" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("Render" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries("Render" PRIVATE fmt::fmt-header-only)
target_link_libraries("Render" PRIVATE glfw)
target_link_libraries("Render" PRIVATE OpenGL::GL)
target_link_libraries("Render" PRIVATE imgui::imgui)
target_link_libraries("Render" PRIVATE implot::implot)

target_set_warnings(
    TARGET
    "Render"
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS}
)

if (${ENABLE_LTO})
    target_enable_lto("Render" optimized)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("Render")
endif ()

file(
    GENERATE
    OUTPUT .gitignore
    CONTENT "*"
)
