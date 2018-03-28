#include <iostream>
#include <vector>
using namespace std;

struct Monster {
  int r;
  int c;
};

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int r, c, k;
    cin >> r >> c >> k;

    vector<Monster> monsters(k);
    for (int j = 0; j < k; j++) {
      cin >> monsters[j].r >> monsters[j].c;
    }

    int safe = 0;

    int width = (r <= c) ? r : c;
    for (int d = 1; d <= width; d++) {
      for (int j = 0; j < r - d + 1; j++) {
        for (int k = 0; k < c - d + 1; k++) {
          bool containMonster = false;

          for (vector<Monster>::iterator it = monsters.begin(); it != monsters.end(); it++) {
            if (it->r >= j && it->r <= j + d - 1 && it->c >= k && it->c <= k + d - 1) {
              containMonster = true;
              break;
            }
          }

          if (!containMonster) {
            safe++;
          }
        }
      }
    }

    cout << "Case #" << i << ": " << safe << endl;
  }

  return 0;
}
