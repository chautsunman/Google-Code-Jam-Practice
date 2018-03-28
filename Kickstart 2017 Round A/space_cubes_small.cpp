#include <iostream>
using namespace std;

struct Star {
  int x;
  int y;
  int z;
  int radius;
};

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    Star* stars = new Star[n];

    for (int j = 0; j < n; j++) {
      cin >> stars[j].x >> stars[j].y >> stars[j].z >> stars[j].radius;
    }

    cout << "Case #" << i << ": " << n << endl;
  }

  return 0;
}

