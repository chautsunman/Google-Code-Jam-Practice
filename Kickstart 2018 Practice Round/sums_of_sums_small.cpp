#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }

    vector<long long> sumArr(n * (n + 1) / 2);
    int j = 0;
    for (int l = 1; l <= n; l++) {
      for (int k = 0; k <= n - l; k++) {
        long long sum = 0;
        for (int m = k; m < k + l; m++) {
          sum += arr[m];
        }
        sumArr[j++] = sum;
      }
    }
    sort(sumArr.begin(), sumArr.end());

    cout << "Case #" << i << ":" << endl;
    for (int j = 0; j < q; j++) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      long long sum = 0;
      for (int k = l; k <= r; k++) {
        sum += sumArr[k];
      }

      cout << sum << endl;
    }
  }
}
