#ifndef TOKEN_H_
#define TOKEN_H_
#include <unordered_map> 
#include <vector>
#include <variant>
#include "c_types.h"

namespace jcc {

using Lexical_Desc = std::variant<int, double, std::string>;

struct lexical_unit {
  Lexical_Desc desc;
  uint64_t lex_id;
};

class token_table {
 public:
  token_table() = default; 
  struct item {
    base_type type;
    std::string value;
  };
 private:
  std::vector<item> items_;
};

class grammar {
 public:

 private:
  std::unordered_map<std::string,int> generated_exprs_;
};


}
#endif