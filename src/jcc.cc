#include "jcc.h"
namespace jcc{

void Jcc::init() {
  std::call_once(init_flag_, &Jcc::init_internal, this);
}

void Jcc::set_include_paths(std::vector<std::string>& include_paths) {
  include_paths_ = std::move(include_paths);  
}

void Jcc::set_src_files(std::vector<std::string>& src_files) {
  src_files_ = std::move(src_files);  
}

void Jcc::init_internal() {

}

}