include(ExternalProject)

set(spd_src_path "${CMAKE_BINARY_DIR}/spdlog-src")
set(spd_build_path "${CMAKE_BINARY_DIR}/spdlog-build")
ExternalProject_Add(SPDLOG
    GIT_REPOSITORY     git@github.com:gabime/spdlog.git
    GIT_TAG            "v1.8.5"
    SOURCE_DIR         ${spd_src_path} 
    BINARY_DIR         ${spd_build_path}
    CONFIGURE_COMMAND  ${CMAKE_COMMAND} ${spd_src_path}
    BUILD_COMMAND      ${CMAKE_COMMAND} --build ${spd_build_path}
    INSTALL_COMMAND    ""
    TEST_COMMAND       ""
    CMAKE_ARGS         -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=${spd_build_path}
)

