#ifndef SCANNER_H_
#define SCANNER_H_
#include <map>
#include <string>
#include <vector>
#include "token.h"
#include "j_utility.h"

namespace jcc {

class Scanner {
public:
  explicit Scanner(const std::string& file_name)
    :file_name_(file_name), cur_loc_{file_name, 1, 1} 
  {
    readFileToString(file_name, text_);
    // mark file end
    text_.push_back('\0'); 
    cur_text_iter_ = text_.begin();
  }

  std::unique_ptr<Token> scan();

private:
  unsigned char scan_peek();  
  unsigned char scan_next();
  void put_back();
  bool scan_try(const unsigned char& c);
  bool scan_test(const unsigned char& c);
  void parse_identifier();
  void parse_num();

  //Token tok_{0};
  int cur_ws_;
  Location cur_loc_;
  std::string cur_token_str_;

  std::string text_ = "";
  std::string file_name_;
  std::string::const_iterator cur_text_iter_;  
};

} // namespace jcc
#endif

