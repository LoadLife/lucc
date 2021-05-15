#ifndef SCAN_H_
#define SCAN_H_
#include <map>
#include <regex>
#include <shared_mutex>
#include <string>
#include <type_traits>
#include <unordered_map> 
#include <vector>
#include <variant>
#include "c_types.h"
#include "spdlog/spdlog.h"

namespace jcc {
// use to mark keywords
enum TokenKind : unsigned short {
  NUMBER = 0,
  IDENTIFIER,
  KEYWORD,  
};

class Token {
 public:
  Token(int kind) : kind_(kind) {}

  virtual std::string to_string() { return std::to_string(kind_); }

  TokenKind get_token_kind() { return static_cast<TokenKind>(kind_); }

  const int kind_;
};

class Number : public Token {
 public:
  Number(std::variant<int, double> value): 
    Token(static_cast<int>(TokenKind::NUMBER)), value_(std::move(value)) {
  }

  std::string to_string() override;  
  std::variant<int, double> value_;
};

class Word : public Token {
 public:
  Word(std::string lexeme) : Token(IDENTIFIER), lexeme_(lexeme) {}
  
  std::string to_string() override { return lexeme_; }

  std::string lexeme_;
};

// ----------------------------------------------------------------------------

class identifier_pattern {
 public:
  identifier_pattern() = default;

  void insert_pattern(TokenKind kind, const std::initializer_list<std::string>& desc);

  bool match(std::shared_ptr<Token> token);
 private:

  std::map<TokenKind, std::vector<std::regex>> pattern_map_;
};

// ----------------------------------------------------------------------------


} // namespace jcc
#endif

