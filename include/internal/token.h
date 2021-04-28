#ifndef TOKEN_H_
#define TOKEN_H_
#include <unordered_map> 
#include <vector>

namespace jcc {

struct token {
  std::string token_name = "hello world";
  uint64_t token_index;
};

class grammar {
 public:

 private:
  std::unordered_map<std::string, std::vector<std::string>> generated_exprs;

};


}
#endif