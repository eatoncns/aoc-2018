#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "Checksum.hpp"
#include <string>
#include <vector>

using namespace std;

TEST_CASE("Checksum") {
  Checksum checksum;
  vector<string> examples{"abcdef", "bababc", "abbcde", "abcccd", "aabcdd", "abcdee", "ababab"};
  for (string example : examples) {
    checksum.add(example);
  }
  REQUIRE(checksum.calculate() == 12);
}
