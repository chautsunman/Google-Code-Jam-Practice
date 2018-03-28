#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<bool> s;
  s.push_back(false);

  while (s.size() < 100000) {
    s.push_back(false);

    for (int i = s.size() - 2; i >= 0; i--) {
      s.push_back(1 - s[i]);
    }
  }

  for (int i = 1; i <= t; i++) {
    int k;
    cin >> k;

    cout << "Case #" << i << ": " << s[k - 1] << endl;
  }

  return 0;
}
