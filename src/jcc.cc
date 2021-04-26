#include "jcc.h"
namespace jcc{

void Jcc::Init() {
  std::call_once(init_flag_, &Jcc::InitInternal, this);
}

void Jcc::SetIncludePathes(std::vector<std::string>& include_pathes) {
  include_pathes_ = std::move(include_pathes);  
}

void Jcc::SetSrcFiles(std::vector<std::string>& src_files) {
  src_files_ = std::move(src_files);  
}

void Jcc::InitInternal() {

}

}