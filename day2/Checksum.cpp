#include "Checksum.hpp"
#include <algorithm>

using namespace std;

namespace {
  class IdCheck {
  private:
    int seen = 0;
    bool seenTwo = false;
    bool seenThree = false;
    char currentLetter;
    string sortedId;

    void recordOldLetter() {
      if (!seenTwo && seen == 2) {
        seenTwo = true;
      }
      if (!seenThree && seen == 3) {
        seenThree = true;
      }
    }

    void resetForNewLetter(char letter) {
      currentLetter = letter;
      seen = 1;
    }

    bool searchFinished() {
      return seenTwo && seenThree;
    }

  public:
    IdCheck(const string& inputBoxId) : sortedId(inputBoxId) {
      sort(sortedId.begin(), sortedId.end());
      currentLetter = sortedId[0];
    }

    void run() {
      for(char letter : sortedId) {
        if (letter == currentLetter) {
          seen += 1;
        }
        else {
          recordOldLetter();
          if (searchFinished()) {
            return;
          }
          resetForNewLetter(letter);
        }
      }
      recordOldLetter();
    }

    bool hasExactlyTwo() {
      return seenTwo;
    }

    bool hasExactlyThree() {
      return seenThree;
    }
  };
}

void Checksum::add(const string& boxId) {
  string sortedId(boxId);
  IdCheck idCheck(sortedId);
  idCheck.run();
  if (idCheck.hasExactlyTwo()) {
    exactlyTwo++;
  }
  if(idCheck.hasExactlyThree()) {
    exactlyThree++;
  }
}

int Checksum::calculate() {
  return exactlyTwo * exactlyThree;
}
