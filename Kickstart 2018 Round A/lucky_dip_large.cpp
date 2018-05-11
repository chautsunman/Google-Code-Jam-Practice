#include <iostream>
#include <stdio.h>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int j = 0; j < n; j++) {
      cin >> v[j];
    }

    double expectedValue = 0.0;
    double lastExpectedValue = accumulate(v.begin(), v.end(), 0.0) / n;

    if (k == 0) {
      expectedValue = lastExpectedValue;
    } else {
      for (int j = 1; j <= k; j++) {
        expectedValue = 0.0;

        for (int k = 0; k < n; k++) {
          expectedValue += max((double) v[k], lastExpectedValue) / n;
        }

        lastExpectedValue = expectedValue;
      }
    }

    printf("Case #%d: %f\n", i, expectedValue);
  }

  return 0;
}
