#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

bool allEvenDigits(long long n) {
  while (n > 0) {
    if (n % 2 == 1) {
      return false;
    }

    n /= 10;
  }

  return true;
}

long long countPresses(long long n, int i) {
  if (allEvenDigits(n)) {
    return 0;
  }

  int totalDigits = floor(log10(n)) + 1;

  int firstOddDigit = 1;

  while (firstOddDigit <= totalDigits) {
    long long leftDigits = n / (long long) (pow(10, totalDigits - firstOddDigit));

    if (leftDigits % 2 == 1) {
      if (i == 1) {
        if (leftDigits % 10 != 9) {
          return ((leftDigits + 1) * pow(10, totalDigits - firstOddDigit)) - n;
        } else {
          if (leftDigits % 100 != 89) {
            return ((leftDigits + 11) * pow(10, totalDigits - firstOddDigit)) - n;
          } else {
            long long leftDigitsUntil8 = leftDigits / 10;
            while (leftDigitsUntil8 % 10 == 8) {
              leftDigitsUntil8 /= 10;
            }

            return ((leftDigitsUntil8 + 2) * pow(10, firstOddDigit - floor(log10(leftDigitsUntil8)) - 1) * pow(10, totalDigits - firstOddDigit)) - n;
          }
        }
      } else if (i == -1) {
        long long smallerN = (leftDigits - 1) * pow(10, totalDigits - firstOddDigit);
        for (int j = totalDigits - firstOddDigit - 1; j >= 0; j--) {
          smallerN += 8 * pow(10, j);
        }
        return n - smallerN;
      }
    }

    firstOddDigit++;
  }

  return -1;
}

long long countPresses(const string n, int i) {
  int totalDigits = n.length();

  int firstOddDigit = -1;
  for (int j = 0; j < totalDigits; j++) {
    if (n[j] == '1' || n[j] == '3' || n[j] == '5' || n[j] == '7' || n[j] == '9') {
      firstOddDigit = j;
      break;
    }
  }

  if (firstOddDigit == -1) {
    return 0;
  }

  if (i == 1) {
    string largerN = n;

    if (n[firstOddDigit] != '9') {
      largerN[firstOddDigit] += 1;
    } else {
      largerN[firstOddDigit] = '0';
    }
    for (int j = firstOddDigit + 1; j < totalDigits; j++) {
      largerN[j] = '0';
    }

    if (n[firstOddDigit] == '9') {
      if (firstOddDigit == 0) {
        largerN = '2' + largerN;
      } else {
        if (n[firstOddDigit - 1] != '8') {
          largerN[firstOddDigit - 1] += 2;
        } else {
          if (firstOddDigit - 1 == 0) {
            largerN[firstOddDigit - 1] = '0';
            largerN = '2' + largerN;
          } else {
            for (int j = firstOddDigit - 1; j >= 0; j--) {
              if (n[j] == '8') {
                largerN[j] = '0';
              } else {
                largerN[j] += 2;
                break;
              }
            }
          }
        }
      }
    }

    return stoll(largerN) - stoll(n);
  } else if (i == -1) {
    string smallerN = n;

    smallerN[firstOddDigit] -= 1;
    for (int j = firstOddDigit + 1; j < totalDigits; j++) {
      smallerN[j] = '8';
    }

    return stoll(n) - stoll(smallerN);
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    string n;
    cin >> n;

    cout << "Case #" << i << ": " << min(countPresses(n, 1), countPresses(n, -1)) << endl;
  }

  return 0;
}
