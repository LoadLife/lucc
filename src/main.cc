#include<iostream>
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"

#define version_info  "  jcc version 0.0.1\n\
  a toy compiler\n\
  COPYRIGHT@JUN\n"

int main(int argc, char** argv){
  CLI::App app{"jcc the noob's compiler"};
  bool version{false};
  app.add_flag("-v", version, "Flag description.");
  CLI11_PARSE(app, argc, argv);

  if(version){
    std::cout << version_info;
  }
  return 0;
}