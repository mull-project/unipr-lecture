#ifndef UNIPR_LECTURE_FILE_H
#define UNIPR_LECTURE_FILE_H

#include <fstream>
#include <string>

class File {
public:
  bool open(const std::string &name) {
    _file.open(name, std::fstream::in);
    return _file.operator bool();
  }
  int32_t read(char *buffer, int32_t len) {
    if (_file.is_open()) {
      _file.read(buffer, sizeof(char) * len);
      return _file.gcount();
    }
    return -1;
  }
  int32_t getString(char *buffer, int32_t len) {
    if (_file.is_open()) {
      int32_t count = read(buffer, len);
      buffer[count] = '\0';
      return count;
    }
    return -1;
  }

private:
  std::ifstream _file;
};

#endif // UNIPR_LECTURE_FILE_H
