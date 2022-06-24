#include "preprocessor.h"

namespace jcc {

void Preprocessor::add_include_path(std::string path) {
  if (path.back() != '/') 
    path += '/';
  if (path.front() != '/')
    path = "./" + path;
  included_paths.push_front(path);
}



}