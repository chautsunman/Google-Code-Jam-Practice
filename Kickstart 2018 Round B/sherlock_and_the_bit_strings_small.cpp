#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Constraint {
  int a, b, c;
};

int nextNotFixedBit(const string &bitString, const vector<bool> &bitFixed, int start) {
  for (; start >= 0; start--) {
    if (!bitFixed[start]) {
      return start;
    }
  }

  return -1;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, k;
    long long p;
    cin >> n >> k >> p;

    vector<Constraint> constraints(k);
    for (int j = 0; j < k; j++) {
      cin >> constraints[j].a >> constraints[j].b >> constraints[j].c;
    }

    string bitString = "";
    vector<bool> bitFixed(n);

    for (int j = 0; j < n; j++) {
      bitString += '0';
      bitFixed[j] = false;
    }

    for (int j = 0; j < k; j++) {
      if (constraints[j].c) {
        bitString[constraints[j].a - 1] = '1';
      }

      bitFixed[constraints[j].a - 1] = true;
    }

    string pBinary = "";
    p--;
    while (p > 0) {
      pBinary += (p % 2 == 0) ? '0' : '1';
      p /= 2;
    }

    int l = nextNotFixedBit(bitString, bitFixed, n - 1);
    for (int j = 0; j < pBinary.length(); j++) {
      bitString[l] = pBinary[j];
      l = nextNotFixedBit(bitString, bitFixed, l - 1);
    }

    cout << "Case #" << i << ": " << bitString << endl;
  }

  return 0;
}
