#ifndef SCAN_H_
#define SCAN_H_
#include <regex>
#include <shared_mutex>
#include <string>
#include <type_traits>
#include <unordered_map> 
#include <vector>
#include <variant>
#include "c_types.h"

namespace jcc {
// use to mark keywords
enum Tag {
  NUMBER = 256,  
};

class Token {
 public:
  Token(int tag) : tag_(tag) {
  }

  virtual std::string to_string() {
    return std::to_string(tag_);
  }

  const int tag_;
};

class Number : public Token {
 public:
  Number(std::variant<int, double> value):
    Token(static_cast<int>(Tag::NUMBER)),
    value_(std::move(value)){
  }

  std::string to_string() override;  
  std::variant<int, double> value_;
};

class Word : public Token {
 public:
  Word(int tag, std::string lexeme):
    Token(tag), lexeme_(lexeme) {
  }
  
  std::string to_string() override {
    return lexeme_;
  }

  std::string lexeme_;
};

// ----------------------------------------------------------------------------
class identifier_pattern {
 public:
  identifier_pattern(const std::initializer_list<std::string>& patterns) {
    for(auto& item : patterns) 
      patterns_.emplace_back(item);
  }

  bool match(std::string str);
 private:
  std::vector<std::regex> patterns_;
};

} // namespace jcc
#endif