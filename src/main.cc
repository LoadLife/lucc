#include<iostream>
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"

int main(int argc, char** argv){
  CLI::App app{"jcc description"};
  bool flag{false};
  app.add_flag("-v", flag, "Flag description.");
  CLI11_PARSE(app, argc, argv);
  std::cout << "hello jcc" << std::endl;
  return 0;
}