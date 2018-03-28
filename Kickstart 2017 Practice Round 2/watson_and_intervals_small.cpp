#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
  public:
    long long l;
    long long r;

    Interval() : l(0), r(0) {}
    Interval(long long l, long long r) : l(l), r(r) {}
};

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    long long l1, r1, a, b, c1, c2, m;
    cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m;

    vector<Interval> intervals(n);

    Interval interval1(l1, r1);
    intervals[0] = interval1;
    long long x = l1, y = r1, xLast = l1, yLast = r1;
    for (int j = 1; j < n; j++) {
      x = (a * xLast + b * yLast + c1) % m;
      y = (a * yLast + b * xLast + c2) % m;
      xLast = x;
      yLast = y;

      Interval interval(min(x, y), max(x, y));
      intervals[j] = interval;
    }

    for (int j = 0; j < n; j++) {
      cout << intervals[j].l << " " << intervals[j].r << endl;
    }

    cout << "Case #" << i << endl;
  }

  return 0;
}
