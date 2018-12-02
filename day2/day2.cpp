#include <iostream>
#include <fstream>
#include <vector>
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

bool differsByOne(const string& id1, const string& id2) {
  int differences = 0;
  for (int i = 0; i < id1.size(); ++i) {
    if (id1[i] != id2[i]) {
      differences++;
    }
    if(differences > 1) {
      return false;
    }
  }
  return differences == 1;
}

int partTwo(istream& input) {
  const vector<string> boxIds{istream_iterator<string>(input), istream_iterator<string>()};
  for (auto id1 = boxIds.begin() ; id1 != boxIds.end(); ++id1) {
    for (auto id2 = id1; ++id2 != boxIds.end(); ) {
      if (differsByOne(*id1, *id2)) {
        cout << *id1 << endl << *id2 << endl;
      }
    }
  }
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

