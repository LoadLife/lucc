#ifndef SCAN_H_
#define SCAN_H_
#include <unordered_map> 
#include <shared_mutex>
#include <string>
#include <type_traits>
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

  std::string to_string() override {
    std::string str;
    std::visit([&str](auto& value) {
      if( std::is_same<double&, decltype(value)>() ) { 
        str = "DOUBLE_" + std::to_string(value);
      } else if( std::is_same<int&, decltype(value)>() ) {
        str = "INT_" + std::to_string(value);
      }
    }, value_);
    return str;
  }
  
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

} // namespace jcc
#endif