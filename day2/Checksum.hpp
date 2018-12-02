#ifndef __CHECKSUM__
#define __CHECKSUM__

#include <string>

class Checksum {

private:
  int exactlyTwo = 0;
  int exactlyThree = 0;

public:
  void add(const std::string& boxId);

  int calculate();
};

#endif
