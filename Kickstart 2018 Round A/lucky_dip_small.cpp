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
    double avg = accumulate(v.begin(), v.end(), 0.0) / n;

    if (k == 0) {
      expectedValue = avg;
    } else if (k == 1) {
      for (int j = 0; j < n; j++) {
        expectedValue += max((double) v[j], avg) / n;
      }
    }

    printf("Case #%d: %f\n", i, expectedValue);
  }

  return 0;
}
