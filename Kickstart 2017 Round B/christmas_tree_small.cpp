#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Grid;

int countGreen(const Grid &grid, int r, int c, int h) {
  int count = 0;

  for (int i = 0; i < h; i++) {
    for (int j = c - i; j <= c + i; j++) {
      if (grid[r + i][j] == '#') {
        count++;
      } else {
        return -1;
      }
    }
  }

  return count;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, m, k;
    cin >> n >> m >> k;

    Grid grid(n);
    for (int j = 0; j < n; j++) {
      vector<char> row(m);
      for (int k = 0; k < m; k++) {
        cin >> row[k];
      }
      grid[j] = row;
    }

    int greens = 0;

    for (int h = 1; h <= n; h++) {
      bool hasHeightH = false;

      for (int j = 0; j < n - h + 1; j++) {
        for (int k = h - 1; k < m - h + 1; k++) {
          int count = countGreen(grid, j, k, h);

          if (count > greens) {
            greens = count;

            hasHeightH = true;
            break;
          }
        }

        if (hasHeightH) {
          break;
        }
      }
    }

    cout << "Case #" << i << ": " << greens << endl;
  }

  return 0;
}
