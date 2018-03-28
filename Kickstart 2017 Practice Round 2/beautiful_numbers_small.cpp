#include <iostream>
using namespace std;

bool checkBeautiful(int n, int j) {
  if (n == 1) {
    return true;
  }

  if (n % j != 1) {
    return false;
  }

  return checkBeautiful(n / j, j);
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    int b = n;

    for (int j = 2; j < n; j++) {
      if (checkBeautiful(n, j)) {
        b = j;
        break;
      }
    }

    cout << "Case #" << i << ": " << b << endl;
  }

  return 0;
}
