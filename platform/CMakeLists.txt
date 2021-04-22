file(GLOB platform_src ./*.cc)
add_library(platform STATIC ${platform_src})
target_include_directories(platform PUBLIC ${PROJECT_BINARY_DIR}/generate
                                    PUBLIC ${PROJECT_SOURCE_DIR}/platform)