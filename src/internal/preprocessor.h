#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_
#include <list>
#include <string>
#include <vector>

namespace lucc {

class PreProcessor {
 public:
  explicit PreProcessor() {
  }
  void AddIncludePath(std::string path);
 private:
  std::list<std::string> included_paths_;
  std::vector<std::string> src_files_;
}; 

}

#endif