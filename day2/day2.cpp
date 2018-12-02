#include <iostream>
#include <fstream>
#include "Checksum.hpp"

using namespace std;

static const string USAGE = "usage: day2 <part number> <path to input file>";


int partOne(istream& input) {
  Checksum checksum;
  istream_iterator<string> boxIterator(input);
  istream_iterator<string> end;
  for (; boxIterator != end; boxIterator++) {
    checksum.add(*boxIterator);
  }
  return checksum.calculate();
}


int partTwo(istream& input) {
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    cout << USAGE << endl;
    return 1;
  }
  string filePath = argv[2];
  int part = stoi(argv[1]);
  ifstream inputFile(filePath);
  const int result = (part == 1) ? partOne(inputFile) : partTwo(inputFile);
  cout << result << endl;
  return 0;
}

