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

void identifier_pattern::insert_pattern(Tag tag, const std::initializer_list<std::string>& desc) {
  std::vector<std::regex> tmp;
  for(auto i : desc) {
    tmp.emplace_back(i); 
  }
  patterns_[tag] = std::move(tmp);
}

bool identifier_pattern::match(std::shared_ptr<Token> token) {
  auto tag = token->get_token_tag();
  if(!patterns_.count(tag)) {
    spdlog::critical("invalid tag for token {0}", token->to_string());
    exit(0);
  }
  const auto& pattern =  patterns_.at(tag);
  for(auto& i : pattern) {
    if(std::regex_match(token->to_string(), i)){
      spdlog::info("success match \"{}\"", token->to_string()); 
      return true;
    }
  }
  return false;
}

} //namespace jcc