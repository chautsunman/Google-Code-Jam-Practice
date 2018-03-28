#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int r, c;
    cin >> r >> c;

    int n = 0;

    if (r > c) {
      int temp = c;
      c = r;
      r = temp;
    }

    if (r == 2) {
      n = c - 1;
    } else {
      n = ((c - 1) * (r - 1)) % 1000000007;

      for (int l = 2; l <= r - 1; l++) {
        n = (n + ((c - l) * (r - l) * l) % 1000000007) % 1000000007;
      }
    }

    cout << "Case #" << i << ": " << n << endl;
  }

  return 0;
}
