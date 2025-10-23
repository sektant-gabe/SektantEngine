set(LIBRARY_SOURCES src/Vector3.cpp)
set(LIBRARY_HEADERS Physis/Physis.h Physis/Vector3.h)
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("Physis" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("Physis" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries("Physis" PRIVATE fmt::fmt-header-only)
target_link_libraries("Physis" PRIVATE glfw)
target_link_libraries("Physis" PRIVATE OpenGL::GL)
target_link_libraries("Physis" PRIVATE imgui::imgui)
target_link_libraries("Physis" PRIVATE implot::implot)

if (${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "Physis"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif ()

if (${ENABLE_LTO})
    target_enable_lto("Physis" optimized)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("Physis")
endif ()
