#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>
#include <variant>
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


}


#endif