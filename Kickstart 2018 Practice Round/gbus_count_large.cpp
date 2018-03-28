#include <iostream>
#include <vector>
using namespace std;

struct Bus {
  int a;
  int b;
};

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<Bus> buses(n);

    for (int j = 0; j < n; j++) {
      cin >> buses[j].a >> buses[j].b;
    }

    int p;
    cin >> p;

    cout << "Case #" << i << ":";
    for (int j = 0; j < p; j++) {
      int city;
      cin >> city;

      int count = 0;

      for (int k = 0; k < n; k++) {
        if (city >= buses[k].a && city <= buses[k].b) {
          count++;
        }
      }

      cout << " " << count;
    }
    cout << endl;
  }

  return 0;
}
