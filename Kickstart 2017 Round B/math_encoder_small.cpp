#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) {
  int f = 1;

  for (int i = 1; i <= n; i++) {
    f *= i;
  }

  return f;
}

int combination(int n, int r) {
  return factorial(n) / (factorial(n - r) * factorial(r));
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int j = 0; j < n; j++) {
      cin >> numbers[j];
    }

    long long encode = 0;

    for (int j = 0; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = 2; l <= n && l <= k - j + 1; l++) {
          encode = (encode + ((numbers[k] - numbers[j]) * combination(k - j - 1, l - 2)) % 1000000007) % 1000000007;
        }
      }
    }

    cout << "Case #" << i << ": " << encode % 1000000007 << endl;
  }

  return 0;
}
