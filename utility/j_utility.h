#ifndef J_UTILITY_H_
#define J_UTILITY_H_
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace jcc {

extern thread_local int ws;
class Logger {
  public:
    static Logger* get_instance() {
      static Logger logger;
      return &logger;
    }
    template<typename... Ts>
    void debug_log(const Ts&... args) {
      logger_instance_->info(args...); 
    }

    void push_white_space() {
      ws += 4;
      std::string ws_str(ws, ' ');
      auto tmp = pattern_;
      tmp.insert(tmp.begin() + 22, ws_str.begin(), ws_str.end());
      logger_instance_->set_pattern(tmp);

    }

    void pop_white_space() {
      if(ws<4) 
        return;
      ws -=4;
      std::string ws_str(ws, ' '); 
      auto tmp = pattern_;
      tmp.insert(tmp.begin() + 22, ws_str.begin(), ws_str.end());
      logger_instance_->set_pattern(tmp);
    }
  private:
    Logger()
    {
      auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
      logger_instance_ = std::make_shared<spdlog::logger>("mylogger", sink);
      logger_instance_->set_pattern(pattern_);
    }
    std::shared_ptr<spdlog::logger> logger_instance_;
    std::string pattern_ = "[%H:%M:%S] [thread %t] %v";
};

#define PUSH_WS()                                                 \
  do {                                                            \
    Logger::get_instance()->debug_log("+enter {}()", __func__);   \
    Logger::get_instance()->push_white_space();                   \
  } while(0)                                                      

#define POP_WS()                                                  \
  do {                                                            \
    Logger::get_instance()->pop_white_space();                    \
    Logger::get_instance()->debug_log("-exit {}()", __func__);    \
  } while(0)

#define LOG_INFO(...) \
  Logger::get_instance()->debug_log(__VA_ARGS__)

// ----------------------------------------------------------------------------

namespace fs = std::filesystem;
class dir_info {
 public:
  dir_info(std::string path) : dir_path_(fs::path(path)), dir_entry_(dir_path_) {}

  bool dir_exist() { return dir_entry_.exists(); } 

  std::vector<fs::path> dir_file_pathes() {
    PUSH_WS();
    std::vector<fs::path> tmp;
    if(!dir_exist()) {
      spdlog::critical("don't exist this folder {}", dir_entry_.path().string());
      return tmp;
    }
    for(const auto &file : fs::directory_iterator(dir_path_)) {
      tmp.push_back(file.path());
    } 
    POP_WS();
    return tmp;

  }
 private:
  fs::path dir_path_;
  fs::directory_entry dir_entry_;
};


inline void readFileToString(const std::string path, std::string& dst) {
  std::ifstream file_in(path, std::ios::in);
  if(!file_in) {
    spdlog::critical("File \"{0}\" doesn't existed!", path);
    exit(-1);
  }
  std::string buffer(std::istreambuf_iterator<char>(file_in), {});
  file_in.close();
  dst.swap(buffer);
}

}
#endif