#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<long long> sticks(n);
    for (int j = 0; j < n; j++) {
      cin >> sticks[j];
    }

    int sets = 0;

    for (int j = 0; j < n - 3; j++) {
      for (int k = j + 1; k < n - 2; k++) {
        for (int l = k + 1; l < n - 1; l++) {
          for (int m = l + 1; m < n; m++) {
            vector<long long> sticksSet = {sticks[j], sticks[k], sticks[l], sticks[m]};

            unordered_map<long long, int> stickLengthCountMap;
            for (vector<long long>::iterator it = sticksSet.begin(); it != sticksSet.end(); it++) {
              if (!stickLengthCountMap.count(*it)) {
                stickLengthCountMap[*it] = 1;
              } else {
                stickLengthCountMap[*it]++;
              }
            }

            if (stickLengthCountMap.size() == 4 || stickLengthCountMap.size() == 1) {
              continue;
            } else if (stickLengthCountMap.size() == 2) {
              bool rectangle = false;
              for (unordered_map<long long, int>::iterator it = stickLengthCountMap.begin(); it != stickLengthCountMap.end(); it++) {
                if (it->second == 2) {
                  rectangle = true;
                  break;
                }
              }
              if (rectangle) {
                continue;
              }
            }

            long long topStick = -1, bottomStick = -1, sideStick = -1;
            if (stickLengthCountMap.size() == 3) {
              for (unordered_map<long long, int>::iterator it = stickLengthCountMap.begin(); it != stickLengthCountMap.end(); it++) {
                if (it->second == 2) {
                  sideStick = it->first;
                } else {
                  if (topStick == -1) {
                    topStick = it->first;
                  } else {
                    bottomStick = it->first;
                  }
                }
              }
            } else if (stickLengthCountMap.size() == 2) {
              for (unordered_map<long long, int>::iterator it = stickLengthCountMap.begin(); it != stickLengthCountMap.end(); it++) {
                if (it->second == 3) {
                  sideStick = it->first;
                }
                if (topStick = -1) {
                  topStick = it->first;
                } else {
                  bottomStick = it->first;
                }
              }
            }
            if (topStick > bottomStick) {
              long long tempStick = topStick;
              topStick = bottomStick;
              bottomStick = tempStick;
            }

            if (sideStick * 2 + topStick > bottomStick) {
              sets++;
            }
          }
        }
      }
    }

    cout << "Case #" << i << ": " << sets << endl;
  }

  return 0;
}
