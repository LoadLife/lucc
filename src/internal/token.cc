#include "token.h"
namespace jcc{

std::string Number::to_string() {
  std::string str;
  std::visit( [&str](auto& value) {
       str = std::to_string(value);
    }, value_);
  return str;
}

// ----------------------------------------------------------------------------


}