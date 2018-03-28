#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, m;
    cin >> n >> m;

    int totalVotes = n + m;
    int totalCombinations = 1;
    for (int j = totalVotes; j >= 1; j--) {
      totalCombinations *= j;
    }



    double p = 0;

    cout << "Case #" << i << ": " << p << endl;
  }

  return 0;
}
