#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_
#include <list>
#include <string>
#include <vector>

namespace jcc {

class Preprocessor {
 public:
  explicit Preprocessor() {
  }
  void add_include_path(std::string path);
 private:
  std::list<std::string> included_paths;
  std::vector<std::string> src_files;
}; 

}

#endif