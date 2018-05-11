#include <iostream>
using namespace std;

bool legal(int n) {
  if (n % 9 == 0) {
    return false;
  }

  while (n > 0) {
    if (n % 10 == 9) {
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
    int f, l;
    cin >> f >> l;

    int turns = 2;

    for (int j = f + 1; j < l; j++) {
      if (legal(j)) {
        turns++;
      }
    }

    cout << "Case #" << i << ": " << turns << endl;
  }

  return 0;
}
