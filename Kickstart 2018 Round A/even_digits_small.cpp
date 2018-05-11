#include <iostream>
using namespace std;

bool allEvenDigits(int n) {
  while (n > 0) {
    if (n % 2 == 1) {
      return false;
    }

    n /= 10;
  }

  return true;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    int presses = 0;

    if (!allEvenDigits(n)) {
      for (int j = 1; n + j <= 200000; j++) {
        if (allEvenDigits(n + j)) {
          presses = j;
          break;
        }
      }

      for (int j = 1; n - j >= 0; j++) {
        if (allEvenDigits(n - j)) {
          if (j < presses) {
            presses = j;
          }

          break;
        }
      }
    }

    cout << "Case #" << i << ": " << presses << endl;
  }

  return 0;
}
