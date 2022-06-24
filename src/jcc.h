#ifndef JCC_H_
#define JCC_H_
#include <mutex>
#include <string>
#include <vector>
namespace jcc{

class Jcc {
 public:
  static Jcc* get_jcc() {
    // cpp11 and later guarantee static variable init thread safe
    static Jcc jcc;
    return &jcc;
  }
  void init();
  void set_include_paths(std::vector<std::string>& include_paths);
  void set_src_files(std::vector<std::string>& src_files);
 private:
  Jcc() = default;
  void init_internal();
  std::once_flag init_flag_;
  std::vector<std::string> include_paths_;
  std::vector<std::string> src_files_;
};

} //namespace jcc
#endif // JCC_H_