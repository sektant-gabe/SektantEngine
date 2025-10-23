add_executable("sandbox" sandbox/sandbox.cpp)
target_link_libraries("sandbox" PRIVATE fmt::fmt-header-only)
target_link_libraries("sandbox" PRIVATE glfw)
target_link_libraries("sandbox" PRIVATE OpenGL::GL)
target_link_libraries("sandbox" PRIVATE imgui::imgui)
target_link_libraries("sandbox" PRIVATE implot::implot)
target_link_libraries("sandbox" PRIVATE SKT)

if (${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "sandbox"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif ()

if (${ENABLE_LTO})
    target_enable_lto("sandbox" optimized)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("sandbox")
endif ()
