#include <fstream>
#include <iterator>
#include <numeric>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

static const string USAGE = "usage: day1 <part number> <path to input file>";

int partOne(istream& input) {
  return accumulate(istream_iterator<int>(input), istream_iterator<int>(), 0);
}

int partTwo(istream& input) {
  const vector<int> frequencyChanges = vector<int>(istream_iterator<int>(input), istream_iterator<int>());
  const int size = frequencyChanges.size();
  unordered_set<int> frequencies{0};
  int currentFrequency = 0;
  for (int i = 0; ; i = (i+1)%size) {
    currentFrequency += frequencyChanges[i];
    if (frequencies.find(currentFrequency) != frequencies.end()) {
      return currentFrequency;
    }
    frequencies.insert(currentFrequency);
  }
  return -666;
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

