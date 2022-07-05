#include "internal/scanner.h"

namespace jcc {

std::unique_ptr<Token> Scanner::scan() {
  // record token info
  cur_ws_ = 0;
  cur_token_str_ = "";
  while (scan_try(' '))
    cur_ws_ += 1;
  auto token_loc = cur_loc_; 
  //token_loc.print();

  auto c = scan_next();
  if (c == '\n') 
    return std::make_unique<Token>(NEW_LINE, token_loc, cur_ws_, cur_token_str_);

  cur_token_str_ += c;
  switch (c) {
  case '+':
    if (scan_try('+')) {
      cur_token_str_ += '+';
    } else if (scan_try('=')){
      cur_token_str_ += '=';
    }
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '-':
    if (scan_try('-')) {
      cur_token_str_ += '-';
    } else if (scan_try('>')) {
      cur_token_str_ += '>';
    } else if (scan_try('=')) {
      cur_token_str_ += '=';
    }
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '(':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case ')':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '{':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '}':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case ';':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(Str_Keyword_Map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case 'a' ... 'z':
  case 'A' ... 'Z':
  case '_': case '$':
    parse_identifier();
    return std::make_unique<Token>(IDENTIFIER, token_loc, cur_ws_, cur_token_str_);
  case '0'...'9':
    parse_num();
    return std::make_unique<Token>(IDENTIFIER, token_loc, cur_ws_, cur_token_str_);
  case '=':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(EQUAL, token_loc, cur_ws_, cur_token_str_);  
  case '\0':
    return std::make_unique<Token>(END, token_loc, cur_ws_, cur_token_str_);
    LOG_INFO("token_str: {}", "file end");
    
  default:
    return std::make_unique<Token>();
  }
}

unsigned char Scanner::scan_peek() {
  if (*cur_text_iter_ == '\\' && *(cur_text_iter_ + 1) == '\n') {
    cur_loc_.col_ = 1;
    cur_loc_.row_ += 1;
    cur_text_iter_ += 2;
    cur_loc_.line_begin_ = cur_text_iter_;
    return scan_peek();
  }
  return *cur_text_iter_;
}

unsigned char Scanner::scan_next() {
  auto ret = scan_peek();
  cur_text_iter_ += 1;
  if (ret == '\n') {
    cur_loc_.col_ = 1;
    cur_loc_.row_ += 1;
    cur_loc_.line_begin_ = cur_text_iter_;
  } else {
    cur_loc_.col_ += 1;
  }
  return ret;
}

bool Scanner::scan_try(const unsigned char& c) {
  if (scan_peek() == c) {
    scan_next();
    return true;
  }
  return false;
}

bool Scanner::scan_test(const unsigned char& c) {
  if (scan_peek() == c) 
    return true;
  return false;
}

void Scanner::parse_identifier() {
  auto c = scan_peek();
  while (std::isalnum(c) || c == '_' || c == '$')
  {
    cur_token_str_ += c;
    scan_next();
    c = scan_peek(); 
  }
  LOG_INFO("token_str: {}", cur_token_str_);
}

void Scanner::parse_num() {
  auto c = scan_peek();
  while (std::isalnum(c)) {
    cur_token_str_ += c;
    scan_next();
    c = scan_peek();
  }
  LOG_INFO("token_str: {}", cur_token_str_);
}

} //namespace jcc