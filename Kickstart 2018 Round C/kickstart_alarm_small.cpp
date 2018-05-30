#include <iostream>
#include <vector>
using namespace std;

long long pow(int base, int exponent) {
  long long result = 1;
  while (exponent > 0) {
    result = result * base % 1000000007;
    exponent--;
  }
  return result;
}

long long calculatePower(const vector<int>& a, int n, int i) {
  long long power = 0;

  for (int l = 1; l <= n; l++) {
    for (int j = 0; j < n - l + 1; j++) {
      for (int k = j; k < j + l; k++) {
        power = (power + a[k] * pow(k - j + 1, i) % 1000000007) % 1000000007;
      }
    }
  }

  return power;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, k, x1, y1, c, d, e1, e2, f;
    cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;

    vector<int> a(n);
    a[0] = (x1 + y1) % f;
    long long x, y, xLast = x1, yLast = y1;
    for (int j = 1; j < n; j++) {
      x = (c * xLast + d * yLast + e1) % f;
      y = (d * xLast + c * yLast + e2) % f;
      a[j] = (x + y) % f;
      xLast = x;
      yLast = y;
    }

    long long totalPower = 0;

    for (int j = 1; j <= k; j++) {
      totalPower = (totalPower + calculatePower(a, n, j) % 1000000007) % 1000000007;
    }

    cout << "Case #" << i << ": " << totalPower % 1000000007 << endl;
  }

  return 0;
}
