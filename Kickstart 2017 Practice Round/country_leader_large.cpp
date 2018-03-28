#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
  string tStr;
  int t;
  getline(cin, tStr);
  t = stoi(tStr);

  for (int i = 1; i <= t; i++) {
    string nStr;
    int n;
    getline(cin, nStr);
    n = stoi(nStr);

    vector<string> names(n);
    int* letters = new int[n];

    for (int j = 0; j < n; j++) {
      getline(cin, names[j]);
    }

    sort(names.begin(), names.end());

    for (int j = 0; j < n; j++) {
      unordered_set<char> letter;
      for (int k = 0; k < names[j].length(); k++) {
        letter.insert(names[j][k]);
      }

      letters[j] = letter.size();
    }

    int maxLetters = 0;
    int maxLettersIndex = 0;
    for (int j = 0; j < n; j++) {
      if (letters[j] > maxLetters) {
        maxLetters = letters[j];
        maxLettersIndex = j;
      }
    }

    string leader = names[maxLettersIndex];

    cout << "Case #" << i << ": " << leader << endl;
  }

  return 0;
}
