#include <iostream>
#include <string>
using namespace std;

long long countBlues(const string pattern, int bluesPerPattern, long long end) {
  long long blues = end / pattern.size() * bluesPerPattern;

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

    long long start, end;
    cin >> start >> end;
    start--;
    end--;

    int bluesPerPattern = 0;
    for (int j = 0; j < pattern.size(); j++) {
      if (pattern[j] == 'B') {
        bluesPerPattern++;
      }
    }

    long long bluesJ = countBlues(pattern, bluesPerPattern, end);
    long long bluesI = (start != 0) ? countBlues(pattern, bluesPerPattern, start - 1) : 0;

    cout << "Case #" << i << ": " << bluesJ - bluesI << endl;
  }

  return 0;
}
