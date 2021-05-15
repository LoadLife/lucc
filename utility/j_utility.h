#ifndef J_UTILITY_H_
#define J_UTILITY_H_
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "spdlog/spdlog.h"

namespace fs = std::filesystem;

class dir_info {
 public:
  dir_info(std::string path) : dir_path_(fs::path(path)), dir_entry_(dir_path_) {}

  bool dir_exist() { return dir_entry_.exists(); } 

  std::vector<fs::path> dir_file_pathes() {
    std::vector<fs::path> tmp;
    if(!dir_exist()) {
      spdlog::info("do exit this path");
      return tmp;
    }
    for(const auto &file : fs::directory_iterator(dir_path_)) {
      tmp.push_back(file);
    } 
    return tmp;
  }
 private:
  fs::path dir_path_;
  fs::directory_entry dir_entry_;
};

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