#ifndef SCAN_H_
#define SCAN_H_
#include <map>
#include <shared_mutex>
#include <string>
#include <vector>
#include "token.h"
#include "c_types.h"
#include "spdlog/spdlog.h"

namespace jcc {

class identifier_pattern {
 public:
  identifier_pattern() = default;

  void insert_pattern(TokenKind kind, const std::initializer_list<std::string>& desc);

  bool match(std::shared_ptr<Token> token);

 private:

  std::map<TokenKind, std::vector<std::regex>> pattern_map_;
};



} // namespace jcc
#endif

