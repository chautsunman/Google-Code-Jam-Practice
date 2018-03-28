#include <iostream>
#include "string.h"
using namespace std;

int exist(const char* pattern1, const char* pattern1End, const char* pattern2, const char* pattern2End) {
  if (pattern1 >= pattern1End) {
    if (pattern2 >= pattern2End) {
      return 1;
    } else if (pattern2[0] != '*') {
      return 0;
    } else {
      return exist(pattern1, pattern1End, pattern2 + 1, pattern2End);
    }
  }

  if (pattern2 >= pattern2End) {
    if (pattern1 >= pattern1End) {
      return 1;
    } else if (pattern1[0] != '*') {
      return 0;
    } else {
      return exist(pattern1 + 1, pattern1End, pattern2, pattern2End);
    }
  }

  if (pattern1[0] != '*' && pattern2[0] != '*') {
    return (pattern1[0] == pattern2[0]) ? exist(pattern1 + 1, pattern1End, pattern2 + 1, pattern2End) : 0;
  }

  if (pattern1[0] == '*' && pattern2[0] != '*' || pattern1[0] != '*' && pattern2[0] == '*') {
    if (pattern1[0] != '*' && pattern2[0] == '*') {
      const char* temp = pattern1;
      pattern1 = pattern2;
      pattern2 = temp;
      temp = pattern1End;
      pattern1End = pattern2End;
      pattern2End = temp;
    }

    return
        exist(pattern1 + 1, pattern1End, pattern2, pattern2End) ||
        exist(pattern1 + 1, pattern1End, pattern2 + 1, pattern2End) ||
        exist(pattern1 + 1, pattern1End, pattern2 + 2, pattern2End) ||
        exist(pattern1 + 1, pattern1End, pattern2 + 3, pattern2End) ||
        exist(pattern1 + 1, pattern1End, pattern2 + 4, pattern2End);
  } else {
    return
        exist(pattern1 + 1, pattern1End, pattern2, pattern2End) ||
        exist(pattern1, pattern1End, pattern2 + 1, pattern2End);
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    char pattern1[201];
    char pattern2[201];
    cin >> pattern1 >> pattern2;

    cout << "Case #" << i << ": " << ((exist(pattern1, pattern1 + strlen(pattern1), pattern2, pattern2 + strlen(pattern2))) ? "TRUE" : "FALSE") << endl;
  }

  return 0;
}
