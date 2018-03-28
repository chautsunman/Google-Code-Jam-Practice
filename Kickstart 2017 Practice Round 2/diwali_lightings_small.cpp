#include <iostream>
#include <string>
using namespace std;

int countBlues(const string pattern, int bluesPerPattern, int end) {
  int blues = end / pattern.size() * bluesPerPattern;

  for (int i = 0; i <= end % pattern.size(); i++) {
    if (pattern[i] == 'B') {
      blues++;
    }
  }

  return blues;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    string pattern;
    cin >> pattern;

    int start, end;
    cin >> start >> end;
    start--;
    end--;

    int bluesPerPattern = 0;
    for (int j = 0; j < pattern.size(); j++) {
      if (pattern[j] == 'B') {
        bluesPerPattern++;
      }
    }

    int bluesJ = countBlues(pattern, bluesPerPattern, end);
    int bluesI = (start != 0) ? countBlues(pattern, bluesPerPattern, start - 1) : 0;

    cout << "Case #" << i << ": " << bluesJ - bluesI << endl;
  }

  return 0;
}
