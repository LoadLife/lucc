#include <stdio.h>
#include "internal/scan.h"

namespace jcc {

std::string Number::to_string() {
  std::string str;
  std::visit( [&str](auto& value) {
       str = std::to_string(value);
    }, value_);
  return str;
}

// ----------------------------------------------------------------------------

void identifier_pattern::insert_pattern(TokenKind kind, const std::initializer_list<std::string>& desc) {
  std::vector<std::regex> tmp;
  for(auto i : desc) {
    tmp.emplace_back(i); 
  }
  pattern_map_[kind] = std::move(tmp);
}

bool identifier_pattern::match(std::shared_ptr<Token> token) {
  auto kind = token->get_token_kind();
  if(!pattern_map_.count(kind)) {
    spdlog::critical("invalid kind for token {0}", token->to_string());
    exit(0);
  }
  const auto& pattern =  pattern_map_.at(kind);
  for(auto& i : pattern) {
    if(std::regex_match(token->to_string(), i)){
      spdlog::info("success match \"{}\"", token->to_string()); 
      return true;
    }
  }
  return false;
}

} //namespace jcc