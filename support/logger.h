#ifndef SUPPORT_LOGGER_H_
#define SUPPORT_LOGGER_H_

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
namespace lucc {

// used for log's withe space indentation
extern thread_local int ws;

class Logger {
public:
  static Logger *get_instance() {
    static Logger logger;
    return &logger;
  }
  template <typename... Ts> void debug_log(Ts &&...args) {
    logger_instance_->info(std::forward<Ts>(args)...);
  }

  void push_white_space();

  void pop_white_space();

private:
  Logger() {
    auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    logger_instance_ = std::make_shared<spdlog::logger>("mylogger", sink);
    logger_instance_->set_pattern(pattern_);
  }
  std::shared_ptr<spdlog::logger> logger_instance_;
  std::string pattern_ = "[%H:%M:%S] [thread %t] %v";
};

#define PUSH_WS()                                                              \
  do {                                                                         \
    Logger::get_instance()->debug_log("+enter {}()", __func__);                \
    Logger::get_instance()->push_white_space();                                \
  } while (0)

#define POP_WS()                                                               \
  do {                                                                         \
    Logger::get_instance()->pop_white_space();                                 \
    Logger::get_instance()->debug_log("-exit {}()", __func__);                 \
  } while (0)

#define LOG_INFO(...) Logger::get_instance()->debug_log(__VA_ARGS__)
} // namespace lucc

#endif