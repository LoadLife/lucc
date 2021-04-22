include(ExternalProject)

set(SPD_SRC_PATH "${CMAKE_BINARY_DIR}/spdlog-src")
set(SPD_BUILD_PATH "${CMAKE_BINARY_DIR}/spdlog-build")
ExternalProject_Add(SPDLOG
    GIT_REPOSITORY     git@github.com:gabime/spdlog.git
    GIT_TAG            "v1.8.5"
    SOURCE_DIR         ${SPD_SRC_PATH} 
    BINARY_DIR         ${SPD_BUILD_PATH}
    CONFIGURE_COMMAND  ${CMAKE_COMMAND} ${SPD_SRC_PATH}
    BUILD_COMMAND      ${CMAKE_COMMAND} --build ${SPD_BUILD_PATH}
    INSTALL_COMMAND    ""
    TEST_COMMAND       ""
)

ExternalProject_Get_Property(SPDLOG BINARY_DIR)
set(SPDLOG_PATH ${BINARY_DIR}/${CMAKE_CFG_INTDIR}/spdlogd.lib)