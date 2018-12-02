#include "Checksum.hpp"
#include <algorithm>

using namespace std;

void Checksum::add(const string& boxId) {
  string sortedId(boxId);
  sort(sortedId.begin(), sortedId.end());
  char currentLetter = sortedId[0];
  int seen = 0;
  bool seenTwo = false;
  bool seenThree = false;
  for(char letter : sortedId) {
    if (letter == currentLetter) {
      seen += 1;
    }
    else {
      if (!seenTwo && seen == 2) {
        exactlyTwo++;
        seenTwo = true;
      }
      if (!seenThree && seen == 3) {
        exactlyThree++;
        seenThree = true;
      }
      if (seenTwo && seenThree) {
        break;
      }
      currentLetter = letter;
      seen = 1;
    }
  }
  if (!seenTwo && seen == 2) {
    exactlyTwo++;
    seenTwo = true;
  }
  if (!seenThree && seen == 3) {
    exactlyThree++;
    seenThree = true;
  }
}

int Checksum::calculate() {
  return exactlyTwo * exactlyThree;
}
