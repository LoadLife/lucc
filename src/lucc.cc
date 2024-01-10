#include "lucc.h"
namespace lucc{

void Lucc::init() {
  std::call_once(init_flag_, &Lucc::init_internal, this);
}

void Lucc::set_include_paths(std::vector<std::string>& include_paths) {
  include_paths_ = std::move(include_paths);  
}

void Lucc::set_src_files(std::vector<std::string>& src_files) {
  src_files_ = std::move(src_files);  
}

void Lucc::init_internal() {

}

}