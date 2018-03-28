#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int l, r;
    cin >> l >> r;

    int maxPairs = (l <= r) ? l : r;

    int maxNumber = 0;

    for (int j = maxPairs; j > 0; j--) {
      maxNumber += j;
    }

    cout << "Case #" << i << ": " << maxNumber << endl;
  }

  return 0;
}
