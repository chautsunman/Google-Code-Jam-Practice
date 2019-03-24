#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int r, c;

    cin >> r >> c;

    vector< vector<bool> > world(r);
    vector< pair<short, short> > offices;

    for (int j = 0; j < r; j++) {
      vector<bool> row(c, false);
      world[j] = row;
    }

    char office;
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
        cin >> office;
        if (office == '1') {
          world[j][k] = true;
        }

        if (world[j][k]) {
          pair<short, short> office = make_pair<short, short>(j, k);
          offices.push_back(office);
        }
      }
    }

    int minTime = r * c;

    if (!(offices.size() >= (r * c - 1))) {
      int newTime;
      vector<int> times(r * c);
      short timesIdx;
      int squareTime = 0;
      int minSquareTime = 0;

      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          timesIdx = 0;

          for (int rowIdx = 0; rowIdx < r; rowIdx++) {
            for (int colIdx = 0; colIdx < c; colIdx++) {
              minSquareTime = abs(rowIdx - j) + abs(colIdx - k);

              for (int officeIdx = 0; officeIdx < offices.size(); officeIdx++) {
                squareTime = abs(rowIdx - offices[officeIdx].first) + abs(colIdx - offices[officeIdx].second);
                if (squareTime < minSquareTime) {
                  minSquareTime = squareTime;
                }
              }

              times[timesIdx] = minSquareTime;

              timesIdx++;
            }
          }

          newTime = *max_element(times.begin(), times.end());

          if (newTime < minTime) {
            minTime = newTime;
          }
        }
      }
    } else {
      minTime = 0;
    }

    cout << "Case #" << (i + 1) << ": " << minTime << endl;
  }
}
