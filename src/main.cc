#include <iostream>
#include <regex>
#include <string>
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "file_operation.h"
#include "jcc.h"

#define version_info  "  jcc version '0.0.1'\n\
  a toy compiler\n\
  COPYRIGHT@JUN"

int main(int argc, char** argv) {

  CLI::App app{"the noob's compiler jcc"};
  // version 
  bool version{false};
  app.add_flag("-v, --v", version, "Version description")->ignore_case();
  // source_code_path
  std::vector<std::string> include_pathes;
  app.add_option("-I", include_pathes, "Source files path");
  // parse args 
  CLI11_PARSE(app, argc, argv);

  if(version) {
    std::cout << version_info << std::endl;
    exit(0);
  }
  auto jcc = Jcc::GetJcc(); 
  jcc->SetIncludePathes(include_pathes);
  return 0;
}