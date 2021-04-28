#include <iostream>
#include <regex>
#include <string>
#include "file_operation.h"
#include "jcc.h"
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "spdlog/spdlog.h"
#include "internal/lex.h"

#define version_info  "  jcc version '0.0.1'\n\
  a toy compiler\n\
  COPYRIGHT@JUN"
using namespace jcc;
int main(int argc, char** argv) {

  // parse args 
  CLI::App app{"the noob's compiler jcc"};
  bool version{false};
  app.add_flag("-v, --v", version, "Version description")->ignore_case();
  std::vector<std::string> include_pathes;
  app.add_option("-I", include_pathes, "Source files path");
  CLI11_PARSE(app, argc, argv);

  if(version) {
    std::cout << version_info << std::endl;
    exit(0);
  }
  spdlog::info("Start to get jcc instance");
  auto jcc = Jcc::GetJcc(); 
  jcc->SetIncludePathes(include_pathes);
  return 0;

}