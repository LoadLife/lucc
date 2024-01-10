#include <iostream>
#include <regex>
#include <string>
#include "lucc.h"
#include "CLI11/CLI11.hpp"
#include "internal/scanner.h"
#include "logger.h"

#define version_info      \
  "Version 'lucc_0.0.1'\n" \
  "a toy compiler\n"      \
  "COPYRIGHT@JUN "

using namespace lucc;

int main(int argc, char** argv) {
  PUSH_WS();
  // parse args 
  CLI::App app{"<the noob's compiler lucc>"};
  bool version{false};
  std::vector<std::string> include_pathes;
  app.add_flag("-v, --v", version, "Version description")->ignore_case();
  app.add_option("-I", include_pathes, "Source files path");
  CLI11_PARSE(app, argc, argv);

  if(version) {
    std::cout << version_info << std::endl;
    POP_WS();
    exit(0);
  }
  //[remove] tmp test code
  Scanner scanner("/home/jerry/Project/lucc/test/test.cc");
  while (scanner.Scan()->kind_ != END)
  {}
  
  POP_WS();
  return 0;
}