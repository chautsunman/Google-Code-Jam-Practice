#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Flight {
  public:
    string src;
    string dest;
    int next;
    int last;

    Flight(string src, string dest) : src(src), dest(dest), next(-1), last(-1) {}
};

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<Flight> itinerary;
    unordered_map<string, int> srcIndexMap;
    unordered_map<string, int> destIndexMap;
    int firstFlightIndex = 0;

    for (int j = 0; j < n; j++) {
      string src, dest;
      cin >> src >> dest;

      Flight flight(src, dest);

      unordered_map<string, int>::const_iterator srcIndexFound = srcIndexMap.find(dest);
      if (srcIndexFound != srcIndexMap.end()) {
        flight.next = srcIndexFound->second;
        itinerary[srcIndexFound->second].last = j;

        if (srcIndexFound->second == firstFlightIndex) {
          firstFlightIndex = j;
        }
      }
      unordered_map<string, int>::const_iterator destIndexFound = destIndexMap.find(src);
      if (destIndexFound != destIndexMap.end()) {
        itinerary[destIndexFound->second].next = j;
        flight.last = destIndexFound->second;

        if (firstFlightIndex == j) {
          int lastIndex = flight.last;
          int currentIndex = j;
          while (lastIndex != -1) {
            currentIndex = lastIndex;
            lastIndex = itinerary[lastIndex].last;
          }
          firstFlightIndex = currentIndex;
        }
      }

      itinerary.push_back(flight);
      srcIndexMap[src] = j;
      destIndexMap[dest] = j;
    }

    cout << "Case #" << i << ":";
    int j = firstFlightIndex;
    while (j != -1) {
      cout << " " << itinerary[j].src << "-" << itinerary[j].dest;

      j = itinerary[j].next;
    }
    cout << endl;
  }

  return 0;
}
