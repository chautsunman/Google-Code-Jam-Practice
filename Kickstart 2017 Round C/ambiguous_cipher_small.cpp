#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const unordered_map<char, int> LETTER_MAP({
  {'A', 0},
  {'B', 1},
  {'C', 2},
  {'D', 3},
  {'E', 4},
  {'F', 5},
  {'G', 6},
  {'H', 7},
  {'I', 8},
  {'J', 9},
  {'K', 10},
  {'L', 11},
  {'M', 12},
  {'N', 13},
  {'O', 14},
  {'P', 15},
  {'Q', 16},
  {'R', 17},
  {'S', 18},
  {'T', 19},
  {'U', 20},
  {'V', 21},
  {'W', 22},
  {'X', 23},
  {'Y', 24},
  {'Z', 25}
});

string encrypt(const string &word) {
  string encryptedWord(word);

  encryptedWord[0] = LETTERS[LETTER_MAP.at(word[1])];
  encryptedWord[word.length() - 1] = LETTERS[LETTER_MAP.at(word[word.length() - 2])];
  for (int i = 1; i <= word.length() - 2; i++) {
    encryptedWord[i] = LETTERS[(LETTER_MAP.at(word[i - 1]) + LETTER_MAP.at(word[i + 1])) % 26];
  }

  return encryptedWord;
}

int main() {
  int t;
  cin >> t;

  unordered_map< string, vector<string> > allEncryptedWords;
  string word;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      word.erase();
      word.push_back(LETTERS[i]);
      word.push_back(LETTERS[j]);
      allEncryptedWords[encrypt(word)].push_back(word);
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        word.erase();
        word.push_back(LETTERS[i]);
        word.push_back(LETTERS[j]);
        word.push_back(LETTERS[k]);
        allEncryptedWords[encrypt(word)].push_back(word);
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        for (int l = 0; l < 26; l++) {
          word.erase();
          word.push_back(LETTERS[i]);
          word.push_back(LETTERS[j]);
          word.push_back(LETTERS[k]);
          word.push_back(LETTERS[l]);
          allEncryptedWords[encrypt(word)].push_back(word);
        }
      }
    }
  }

  for (int i = 1; i <= t; i++) {
    string encryptedWord;
    cin >> encryptedWord;

    string decryptedWord = (allEncryptedWords[encryptedWord].size() == 1) ? allEncryptedWords[encryptedWord][0] : "AMBIGUOUS";

    cout << "Case #" << i << ": " << decryptedWord << endl;
  }

  return 0;
}
