include(ExternalProject)
ExternalProject_Add(CLI11
    GIT_REPOSITORY     git@github.com:CLIUtils/CLI11.git
    GIT_TAG            v1.9.1
    SOURCE_DIR         "${CMAKE_BINARY_DIR}/CLI11-src"
    BINARY_DIR         "${CMAKE_BINARY_DIR}/CLI11-build"
    CONFIGURE_COMMAND  ""
    BUILD_COMMAND      ""
    INSTALL_COMMAND    ""
    TEST_COMMAND       ""
)