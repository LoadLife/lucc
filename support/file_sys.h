#ifndef SUPPORT_FILE_SYS_H_
#define SUPPORT_FILE_SYS_H_
#include "logger.h"
#include <filesystem>
#include <fstream>

namespace lucc {

namespace fs = std::filesystem;
class DirInfo {
public:
  DirInfo(std::string path)
      : dir_path_(fs::path(path)), dir_entry_(dir_path_) {}

  bool DirExist() { return dir_entry_.exists(); }

  std::vector<fs::path> DirFilePathes();

private:
  fs::path dir_path_;
  fs::directory_entry dir_entry_;
};

inline void ReadFileToString(const std::string path, std::string &dst) {
  std::ifstream file_in(path, std::ios::in);
  if (!file_in) {
    spdlog::critical("File \"{0}\" doesn't existed!", path);
    exit(-1);
  }
  std::string buffer(std::istreambuf_iterator<char>(file_in), {});
  file_in.close();
  dst.swap(buffer);
}

} // namespace lucc
#endif