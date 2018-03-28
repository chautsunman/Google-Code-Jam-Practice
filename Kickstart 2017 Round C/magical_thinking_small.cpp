#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string getPossibleAnswer(int i, int questions) {
  string possibleAnswer = "";

  while (i >= 2) {
    possibleAnswer += (i % 2 == 1) ? 'T' : 'F';
    i /= 2;
  }
  possibleAnswer += (i % 2 == 1) ? 'T' : 'F';
  while (possibleAnswer.length() < questions) {
    possibleAnswer += 'F';
  }
  reverse(possibleAnswer.begin(), possibleAnswer.end());

  return possibleAnswer;
}

int calculateScore(const string &answer, const string &correctAnswer) {
  int score = 0;

  for (int i = 0; i < answer.length(); i++) {
    if (answer[i] == correctAnswer[i]) {
      score++;
    }
  }

  return score;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, q;
    cin >> n >> q;

    vector<string> friendAnswers(n);
    for (int j = 0; j < n; j++) {
      cin >> friendAnswers[j];
    }
    string myAnswer;
    cin >> myAnswer;
    vector<int> friendScores(n);
    for (int j = 0; j < n; j++) {
      cin >> friendScores[j];
    }

    vector<string> possibleAnswers;
    for (int j = 0; j < pow(2, q); j++) {
      string possibleAnswer = getPossibleAnswer(j, q);

      bool matchFriendAnswers = true;
      for (int k = 0; k < n; k++) {
        if (friendScores[k] != calculateScore(friendAnswers[k], possibleAnswer)) {
          matchFriendAnswers = false;
        }
      }

      if (matchFriendAnswers) {
        possibleAnswers.push_back(possibleAnswer);
      }
    }

    int maxScore = 0;
    for (vector<string>::iterator it = possibleAnswers.begin(); it != possibleAnswers.end(); it++) {
      int possibleScore = calculateScore(myAnswer, *it);

      if (possibleScore > maxScore) {
        maxScore = possibleScore;
      }
    }

    cout << "Case #" << i << ": " << maxScore << endl;
  }

  return 0;
}
