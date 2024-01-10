#include "logger.h"

namespace lucc {

thread_local int ws = 0;
void Logger::push_white_space() {
  ws += 4;
  std::string ws_str(ws, ' ');
  auto tmp = pattern_;
  tmp.insert(tmp.begin() + 22, ws_str.begin(), ws_str.end());
  logger_instance_->set_pattern(tmp);
}

void Logger::pop_white_space() {
  if (ws < 4)
    return;
  ws -= 4;
  std::string ws_str(ws, ' ');
  auto tmp = pattern_;
  tmp.insert(tmp.begin() + 22, ws_str.begin(), ws_str.end());
  logger_instance_->set_pattern(tmp);
}
} // namespace lucc