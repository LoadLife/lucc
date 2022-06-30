#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>
#include <variant>
#include <list>
#include <memory>
#include <unordered_map>
#include <climits>
#include <iostream>

namespace jcc {

struct Location {
  const std::string file_name_;
  unsigned row_;
  unsigned col_;
  std::string::const_iterator line_begin_;
  void print() {
    std::cout << "\"" << file_name_ << "\"" << " " << row_ << ", " << col_ << std::endl;
  }
};

enum TokenKind : unsigned short {
  LPAR = '(',
  RPAR = ')',
  LSQB = '[',
  RSQB = ']',
  COLON = ':',
  COMMA = ',',
  SEMI = ';',
  ADD = '+',
  SUB = '-',
  MUL = '*',
  DIV = '/',
  OR = '|',
  AND = '&',
  XOR = '^',
  LESS = '<',
  GREATER = '>',
  EQUAL = '=',
  DOT = '.',
  MOD = '%',
  LBRACE = '{',
  RBRACE = '}',
  TILDE = '~',
  NOT = '!',
  COND = '?',
  SHARP = '#',
  NEW_LINE = '\n',

  DSHARP = 128, // '##'
  PTR,
  INC,
  DEC,
  LEFT,
  RIGHT,
  LE,
  GE,
  EQ,
  NE,
  LOGICAL_AND,
  LOGICAL_OR,

  MUL_ASSIGN,
  DIV_ASSIGN,
  MOD_ASSIGN,
  ADD_ASSIGN,
  SUB_ASSIGN,
  LEFT_ASSIGN,
  RIGHT_ASSIGN,
  AND_ASSIGN,
  XOR_ASSIGN,
  OR_ASSIGN,

  ELLIPSIS,
  // Punctuators end

  // KEYWORD BEGIN
    // TYPE QUALIFIER BEGIN
  CONST,
  RESTRICT,
  VOLATILE,
  ATOMIC,
    // TYPE QUALIFIER END

    // TYPE SPECIFIER BEGIN
  VOID,
  CHAR,
  SHORT,
  INT,
  LONG,
  FLOAT,
  DOUBLE,
  SIGNED,
  UNSIGNED,
  BOOL,		// _Bool
  COMPLEX,	// _Complex
  STRUCT,
  UNION,
  ENUM,
    // TYPE SPECIFIER END

  ATTRIBUTE, // GNU extension __attribute__
    // FUNCTION SPECIFIER BEGIN
  INLINE,
  NORETURN,	// _Noreturn
    // FUNCTION SPECIFIER END

  ALIGNAS, // _Alignas

  STATIC_ASSERT, // _Static_assert
    // STORAGE CLASS SPECIFIER BEGIN
  TYPEDEF,
  EXTERN,
  STATIC,
  THREAD,	// _Thread_local
  AUTO,
  REGISTER,
    // STORAGE CLASS SPECIFIER END
  BREAK,
  CASE,
  CONTINUE,
  DEFAULT,
  DO,
  ELSE,
  FOR,
  GOTO,
  IF,
  RETURN,
  SIZEOF,
  SWITCH,
  WHILE,
  ALIGNOF, // _Alignof
  GENERIC, // _Generic
  IMAGINARY, // _Imaginary
  // KEYWORD END

  IDENTIFIER,
  CONSTANT,
  I_CONSTANT,
  C_CONSTANT,
  F_CONSTANT,
  LITERAL,

  // For the parser, a identifier is a typedef name or user defined type
  POSTFIX_INC,
  POSTFIX_DEC,
  PREFIX_INC,
  PREFIX_DEC,
  ADDR,  // '&'
  DEREF, // '*'
  PLUS,
  MINUS,
  CAST,

  // For preprocessor
  PP_IF,
  PP_IFDEF,
  PP_IFNDEF,
  PP_ELIF,
  PP_ELSE,
  PP_ENDIF,
  PP_INCLUDE,
  PP_DEFINE,
  PP_UNDEF,
  PP_LINE,
  PP_ERROR,
  PP_PRAGMA,
  PP_NONE,
  PP_EMPTY,

  IGNORE,
  INVALID,
  END,
  NOTOK = USHRT_MAX
};

extern std::unordered_map<std::string, TokenKind>  Str_Keywor_Map;

class Token {
 public:
  Token(int kind) : kind_(kind) {}

  TokenKind get_token_kind() const { return static_cast<TokenKind>(kind_); }
  std::string get_token_str() const { return token_str_; }

  bool is_punctuator() const { return LPAR <= kind_ && kind_ <= ELLIPSIS; }
  bool is_key_word() const { return CONST <= kind_ && kind_ < IDENTIFIER; }
  bool is_literal() const { return kind_ == LITERAL; }
  bool is_constant() const { return CONSTANT <= kind_ && kind_ <= F_CONSTANT; }
  bool is_identifier() const { return kind_ == IDENTIFIER; }
  bool is_EOF() const { return kind_ == END; }
  bool is_type_spec_qual() const { return CONST <= kind_ && kind_ <= ENUM; }
  bool is_decl() const { return CONST <= kind_ && kind_ <= REGISTER; }


  const int kind_;
  Location loc_;

 private:
  const std::string token_str_;
};

// ----------------------------------------------------------------

class TokenSequence {
 public:
  explicit TokenSequence();

 private:
  std::list<std::unique_ptr<Token>> token_ptr_list_;

};

}

#endif