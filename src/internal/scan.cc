#include "internal/scan.h"

namespace jcc {

std::string Number::to_string() {
  std::string str;
  std::visit( [&str](auto& value) {
    if( std::is_same<double&, decltype(value)>() ) { 
       str = "DOUBLE_" + std::to_string(value);
    } else if( std::is_same<int&, decltype(value)>() ) {
      str = "INT_" + std::to_string(value);
    }
  }, value_);
  return str;
}

bool identifier_pattern::match(std::string ) {

}

}