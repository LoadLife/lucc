#include "preprocessor.h"

namespace lucc {

void PreProcessor::AddIncludePath(std::string path) {
  if (path.back() != '/')
    path += '/';
  if (path.front() != '/')
    path = "./" + path;
  included_paths_.push_front(path);
}

} // namespace lucc