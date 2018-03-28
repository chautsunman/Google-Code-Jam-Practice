#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    string s;
    cin >> s;

    int minOperations = s.length();

    if (s.length() == 6) {
      if ((s[2] == s[0] && s[3] == s[1] && s[4] == s[0] && s[5] == s[1]) ||
          (s[3] == s[0] && s[4] == s[1] && s[5] == s[2])) {
        minOperations = 5;
      }
    }

    cout << "Case #" << i << ": " << minOperations << endl;
  }

  return 0;
}
