#configure CLI11
configure_file(CMakeLists.txt.in CLI/CMakeLists.txt)
#configure CLI_EXTERNAL
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . 
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CLI
    RESULT_VARIABLE result)
if(result)
  message(FATAL_ERROR "configure_cli_external error: ${result}")
endif()
#run CLI_EXTERNAL
execute_process(COMMAND ${CMAKE_COMMAND} --build . 
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CLI
    RESULT_VARIABLE result)
if(result)
  message(FATAL_ERROR "run_cli_external error: ${result}")
endif()
