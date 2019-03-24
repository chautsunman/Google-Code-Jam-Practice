#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, p;

    cin >> n >> p;

    vector<int> skills(n);

    for (int j = 0; j < n; j++) {
      cin >> skills[j];
    }

    int hours = 0;

    sort(skills.begin(), skills.end());

    int minSkill = skills[p - 1];

    for (int j = 0; j < p - 1; j++) {
      hours += minSkill - skills[j];
    }

    if (hours > 0) {
      int newHours = hours;

      for (int j = p; j < n; j++) {
        newHours = newHours - (minSkill - skills[j - p]) + (skills[j] - minSkill) * (p - 1);
        minSkill = skills[j];

        if (newHours < hours) {
          hours = newHours;
        }
      }
    }

    cout << "Case #" << (i + 1) << ": " << hours << endl;
  }
}
