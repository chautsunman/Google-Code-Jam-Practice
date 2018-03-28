#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<int> cities(500, 0);

    for (int j = 0; j < n; j++) {
      int a, b;
      cin >> a >> b;

      for (int k = a; k <= b; k++) {
        cities[k] += 1;
      }
    }

    int p;
    cin >> p;

    cout << "Case #" << i << ":";
    for (int j = 0; j < p; j++) {
      int city;
      cin >> city;

      cout << " " << cities[city];
    }
    cout << endl;
  }

  return 0;
}
