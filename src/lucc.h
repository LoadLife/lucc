#ifndef LUCC_H_
#define LUCC_H_
#include <mutex>
#include <string>
#include <vector>
namespace lucc {

class Lucc {
public:
  static Lucc *get_lucc() {
    // cpp11 and later guarantee static variable init thread safe
    static Lucc lucc;
    return &lucc;
  }
  void init();
  void set_include_paths(std::vector<std::string> &include_paths);
  void set_src_files(std::vector<std::string> &src_files);

private:
  Lucc() = default;
  void init_internal();
  std::once_flag init_flag_;
  std::vector<std::string> include_paths_;
  std::vector<std::string> src_files_;
};

} // namespace lucc
#endif // LUCC_H_