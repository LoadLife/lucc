#ifndef SCANNER_H_
#define SCANNER_H_
#include <map>
#include <shared_mutex>
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
    cur_text_iter_ = text_.begin();
  }
  void scan();
  
private:
  unsigned char scan_peek();  
  unsigned char scan_next();
  bool scan_try(const unsigned char& c);
  bool scan_test(const unsigned char& c);

  std::string file_name_;
  Location cur_loc_;
  std::string cur_token_str_ = "";
  unsigned int cur_ws_ = 0;
  std::string text_ = "";
  std::string::const_iterator cur_text_iter_;  
};

} // namespace jcc
#endif

