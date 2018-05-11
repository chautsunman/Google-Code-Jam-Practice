#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

typedef unordered_map<char, int> CharCount;

class Word {
  public:
    string word;
    int length;
    CharCount charCount;

    Word(string word) : word(word) {
      length = word.length();
      for (int j = 1; j < length - 1; j++) {
        if (charCount.count(word[j])) {
          charCount[word[j]]++;
        } else {
          charCount[word[j]] = 1;
        }
      }
    }
};

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int l;
    cin >> l;

    unordered_map< char, vector<Word> > wordFirstLetterMap;
    for (int j = 0; j < l; j++) {
      string word;
      cin >> word;

      if (!wordFirstLetterMap.count(word[0])) {
        wordFirstLetterMap[word[0]] = vector<Word>();
      }

      wordFirstLetterMap[word[0]].push_back(Word(word));
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

    int longStringLength = longString.length();
    for (int j = 0; j < longStringLength - 1; j++) {
      vector<Word> &words = wordFirstLetterMap[longString[j]];

      vector<int> matchedWords;

      for (int k = 0; k < words.size(); k++) {
        if (j + words[k].length > longStringLength) {
          continue;
        }

        if (longString[j + words[k].length - 1] != words[k].word[words[k].length - 1]) {
          continue;
        }

        CharCount charCount = words[k].charCount;
        for (int l = j + 1; l <= j + words[k].length - 2; l++) {
          if (charCount.count(longString[l])) {
            charCount[longString[l]]--;
          } else {
            break;
          }
        }

        bool match = true;

        for (CharCount::iterator it = charCount.begin(); it != charCount.end(); it++) {
          if (it->second != 0) {
            match = false;
            break;
          }
        }

        if (match) {
          count++;
          matchedWords.push_back(k);
        }
      }

      for (int k = matchedWords.size() - 1; k >= 0; k--) {
        words.erase(words.begin() + matchedWords[k]);
      }
    }

    cout << "Case #" << i << ": " << count << endl;
  }

  return 0;
}
