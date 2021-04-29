#ifndef TOKEN_H_
#define TOKEN_H_
#include <unordered_map> 
#include <shared_mutex>
#include <vector>
#include <variant>
#include "c_types.h"

namespace jcc {

using Lexical_Desc = std::variant<int, double, std::string>;

// describe a token name and its id in token_table 
struct lexical_unit {
  Lexical_Desc desc;
  uint64_t lex_id;
};

// token_table define
class token_table {
 public:
  token_table() = default; 
  void insertToken(lexical_unit& lexical_unit);
  struct item {
    base_type type;
    std::string value;
  };
 private:
  struct lex_visitor{
    template <typename T>
    void operator()(T& ref){
     items_.size(); 
    }
  } visitor;
  std::vector<item> items_;
  std::shared_mutex shared_lock_;
};
}
#endif