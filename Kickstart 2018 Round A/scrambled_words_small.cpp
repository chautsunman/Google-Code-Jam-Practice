#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int l;
    cin >> l;

    vector<string> dictionary(l);
    for (int j = 0; j < l; j++) {
      cin >> dictionary[j];
    }

    char s1, s2;
    int n, a, b, c, d;
    cin >> s1 >> s2 >> n >> a >> b >> c >> d;

    string longString = "";
    longString += s1;
    longString += s2;
    long long xLast = s2, xLast2 = s1;
    long long x;
    for (long long j = 3; j <= n; j++) {
      x = (a * xLast + b * xLast2 + c) % d;
      longString += 97 + (x % 26);
      xLast2 = xLast;
      xLast = x;
    }

    int count = 0;

    for (int j = 0; j < l; j++) {
      string word = dictionary[j];
      int wordLength = word.length();
      unordered_map<char, int> charCount;
      for (int k = 1; k < wordLength - 1; k++) {
        if (charCount.count(word[k])) {
          charCount[word[k]]++;
        } else {
          charCount[word[k]] = 1;
        }
      }
      unordered_map<char, int> charCount2 = charCount;

      for (int k = 0; k < longString.length() - wordLength + 1; k++) {
        if (longString[k] == word[0] && longString[k + wordLength - 1] == word[wordLength - 1]) {
          for (int l = k + 1; l <= k + wordLength - 2; l++) {
            if (charCount2.count(longString[l])) {
              charCount2[longString[l]]--;
            } else {
              break;
            }
          }

          bool match = true;

          for (unordered_map<char, int>::iterator it = charCount2.begin(); it != charCount2.end(); it++) {
            if (it->second != 0) {
              match = false;
              break;
            }
          }

          if (match) {
            count++;
            break;
          }

          charCount2 = charCount;
        }
      }
    }

    cout << "Case #" << i << ": " << count << endl;
  }

  return 0;
}
