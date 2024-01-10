#include "internal/scanner.h"

namespace lucc {

std::unique_ptr<Token> Scanner::Scan() {
  // record token info
  cur_ws_ = 0;
  cur_token_str_ = "";
  while (ScanTry(' '))
    cur_ws_ += 1;
  auto token_loc = cur_loc_; 
  //token_loc.print();

  auto c = ScanNext();
  if (c == '\n') 
    return std::make_unique<Token>(NEW_LINE, token_loc, cur_ws_, cur_token_str_);

  cur_token_str_ += c;
  switch (c) {
  case '+':
    if (ScanTry('+')) {
      cur_token_str_ += '+';
    } else if (ScanTry('=')){
      cur_token_str_ += '=';
    }
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '-':
    if (ScanTry('-')) {
      cur_token_str_ += '-';
    } else if (ScanTry('>')) {
      cur_token_str_ += '>';
    } else if (ScanTry('=')) {
      cur_token_str_ += '=';
    }
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '(':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case ')':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '{':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case '}':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case ';':
    LOG_INFO("token_str: {}", cur_token_str_);
    return std::make_unique<Token>(str_keyword_map.at(cur_token_str_), token_loc, cur_ws_, cur_token_str_);
  case 'a' ... 'z':
  case 'A' ... 'Z':
  case '_': case '$':
    ParseIdentifier();
    return std::make_unique<Token>(IDENTIFIER, token_loc, cur_ws_, cur_token_str_);
  case '0'...'9':
    ParseNum();
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

unsigned char Scanner::ScanPeek() {
  if (*cur_text_iter_ == '\\' && *(cur_text_iter_ + 1) == '\n') {
    cur_loc_.col = 1;
    cur_loc_.row += 1;
    cur_text_iter_ += 2;
    cur_loc_.line_begin = cur_text_iter_;
    return ScanPeek();
  }
  return *cur_text_iter_;
}

unsigned char Scanner::ScanNext() {
  auto ret = ScanPeek();
  cur_text_iter_ += 1;
  if (ret == '\n') {
    cur_loc_.col = 1;
    cur_loc_.row += 1;
    cur_loc_.line_begin = cur_text_iter_;
  } else {
    cur_loc_.col += 1;
  }
  return ret;
}

bool Scanner::ScanTry(const unsigned char& c) {
  if (ScanPeek() == c) {
    ScanNext();
    return true;
  }
  return false;
}

bool Scanner::ScanTest(const unsigned char& c) {
  if (ScanPeek() == c) 
    return true;
  return false;
}

void Scanner::ParseIdentifier() {
  auto c = ScanPeek();
  while (std::isalnum(c) || c == '_' || c == '$')
  {
    cur_token_str_ += c;
    ScanNext();
    c = ScanPeek(); 
  }
  LOG_INFO("token_str: {}", cur_token_str_);
}

void Scanner::ParseNum() {
  auto c = ScanPeek();
  while (std::isalnum(c)) {
    cur_token_str_ += c;
    ScanNext();
    c = ScanPeek();
  }
  LOG_INFO("token_str: {}", cur_token_str_);
}

} //namespace lucc