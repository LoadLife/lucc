#ifndef J_UTILITY_H_
#define J_UTILITY_H_
#include <fstream>
#include <regex>
#include <string>
#include "spdlog/spdlog.h"

inline void readFileToString(const std::string path, std::string& dst) {
  std::ifstream file_in(path, std::ios::in);
  if(!file_in) {
    spdlog::critical("File \"{0}\" doesn't existed!", path);
    exit(-1);
  }
  std::string buffer(std::istreambuf_iterator<char>(file_in), {});
  file_in.close();
  dst.swap(buffer);
}

#endif