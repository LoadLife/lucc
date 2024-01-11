#ifndef SCANNER_H_
#define SCANNER_H_
#include "file_sys.h"
#include "token.h"
#include <map>
#include <string>
#include <vector>

namespace lucc {

class Scanner {
public:
  explicit Scanner(const std::string &file_name)
      : file_name_(file_name), cur_loc_{file_name, 1, 1} {
    ReadFileToString(file_name, text_);
    // mark file end
    text_.push_back('\0');
    cur_text_iter_ = text_.begin();
  }

  std::unique_ptr<Token> Scan();

private:
  unsigned char ScanPeek();
  unsigned char ScanNext();
  void PutBack();
  bool ScanTry(const unsigned char &c);
  bool ScanTest(const unsigned char &c);
  void ParseIdentifier();
  void ParseNum();

  // Token tok_{0};
  int cur_ws_;
  Location cur_loc_;
  std::string cur_token_str_;

  std::string text_ = "";
  std::string file_name_;
  std::string::const_iterator cur_text_iter_;
};

} // namespace lucc
#endif
