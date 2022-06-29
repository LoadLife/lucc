#include <iostream>
#include <regex>
#include <string>
#include "file_operation.h"
#include "jcc.h"
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "internal/scanner.h"
#include "j_utility.h"

#define version_info      \
  "Version 'jcc_0.0.1'\n" \
  "a toy compiler\n"      \
  "COPYRIGHT@JUN "

using namespace jcc;

int main(int argc, char** argv) {
  PUSH_WS();
  // parse args 
  CLI::App app{"the noob's compiler jcc"};
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
  auto jcc = Jcc::get_jcc(); 
  dir_info dir("/"); 
  dir.dir_file_pathes();
  POP_WS();
  return 0;
}