#ifndef JCC_H_
#define JCC_H_
#include <mutex>
#include <string>
#include <vector>
namespace jcc{

class Jcc {
 public:
  static Jcc* GetJcc() {
    // cpp11 and later guarantee static variable init thread safe
    static Jcc jcc;
    return &jcc;
  }
  void Init();
  void SetIncludePathes(std::vector<std::string>& include_pathes);
  void SetSrcFiles(std::vector<std::string>& src_files);
 private:
  Jcc() = default;
  void InitInternal();
  std::once_flag init_flag_;
  std::vector<std::string> include_pathes_;
  std::vector<std::string> src_files_;
};

} //namespace jcc
#endif // JCC_H_