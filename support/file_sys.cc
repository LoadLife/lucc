#include "file_sys.h"
namespace lucc {

std::vector<fs::path> DirInfo::DirFilePathes() {
  PUSH_WS();
  std::vector<fs::path> tmp;
  if (!DirExist()) {
    spdlog::critical("don't exist this folder {}", dir_entry_.path().string());
    return tmp;
  }
  for (const auto &file : fs::directory_iterator(dir_path_)) {
    tmp.push_back(file.path());
  }
  POP_WS();
  return tmp;
}

} // namespace lucc