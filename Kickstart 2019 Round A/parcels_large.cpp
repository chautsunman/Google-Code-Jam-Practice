#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void updateDistance(vector< vector<int> > &distance, int r, int c, const pair<int, int> &office) {
  int officeDistance;
  for (int rowIdx = 0; rowIdx < r; rowIdx++) {
    for (int colIdx = 0; colIdx < c; colIdx++) {
      officeDistance = abs(rowIdx - office.first) + abs(colIdx - office.second);
      if (officeDistance < distance[rowIdx][colIdx]) {
        distance[rowIdx][colIdx] = officeDistance;
      }
    }
  }
}

int main() {
  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int r, c;

    cin >> r >> c;

    vector< pair<int, int> > offices;

    char office;
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
        cin >> office;

        if (office == '1') {
          pair<int, int> office = make_pair(j, k);
          offices.push_back(office);
        }
      }
    }

    int overallTime = 0;

    if (!(offices.size() >= (r * c - 1))) {
      vector< vector<int> > distance(r);
      for (int j = 0; j < r; j++) {
        vector<int> row(c, r * c);
        distance[j] = row;
      }

      for (int officeIdx = 0; officeIdx < offices.size(); officeIdx++) {
        updateDistance(distance, r, c, offices[officeIdx]);
      }

      pair<int, int> newOffice = make_pair(-1, -1);
      int maxDistance = 0;
      for (int rowIdx = 0; rowIdx < r; rowIdx++) {
        for (int colIdx = 0; colIdx < c; colIdx++) {
          if (distance[rowIdx][colIdx] > maxDistance) {
            newOffice.first = rowIdx;
            newOffice.second = colIdx;
            maxDistance = distance[rowIdx][colIdx];
          }
        }
      }

      updateDistance(distance, r, c, newOffice);

      for (int rowIdx = 0; rowIdx < r; rowIdx++) {
        for (int colIdx = 0; colIdx < c; colIdx++) {
          if (distance[rowIdx][colIdx] > overallTime) {
            overallTime = distance[rowIdx][colIdx];
          }
        }
      }
    }

    cout << "Case #" << (i + 1) << ": " << overallTime << endl;
  }
}
