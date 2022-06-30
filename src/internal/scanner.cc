#include <stdio.h>
#include <regex>
#include "internal/scanner.h"

namespace jcc {

void Scanner::scan() {
  auto c = scan_next();
  if (c == ' ' || c == '\n') {
    cur_ws_ += 1;
    return;
  } 

  switch (c) {
    case '+':
      cur_token_str_ += '+';
      if (scan_try('+')) {
        cur_token_str_ += '+';
        LOG_INFO("token_str: {}", cur_token_str_);
      } else {
        LOG_INFO("token_str: {}", cur_token_str_);
      }
      cur_token_str_ = "";
      cur_ws_ = 0;
      break;
    case '-':
      cur_token_str_ += '-';
      if (scan_try('-')) {
        cur_token_str_ += '+';
        LOG_INFO("token_str: {}", cur_token_str_);
      } else {
        LOG_INFO("token_str: {}", cur_token_str_);
      }
      cur_token_str_ = "";
      cur_ws_ = 0;
      break;
    default:
      break;
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

} //namespace jcc