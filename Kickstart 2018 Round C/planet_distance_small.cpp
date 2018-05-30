#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Tube {
  public:
    int x, y;

    Tube(int x = 0, int y = 0) {
      if (x <= y) {
        this->x = x;
        this->y = y;
      } else {
        this->x = y;
        this->y = x;
      }
    }
};

void findCycle(unordered_set<int>& cycle, const vector<Tube>& tubes, int n) {
  int cycleStart, cycleEnd;
  int connectCycleTubeIndex;
  for (int i = 0; i < n; i++) {
    if (cycle.count(tubes[i].x) && cycle.count(tubes[i].y)) {
      cycleStart = tubes[i].x;
      cycleEnd = tubes[i].y;
      connectCycleTubeIndex = i;
      break;
    } else {
      cycle.insert(tubes[i].x);
      cycle.insert(tubes[i].y);
    }
  }

  /* cout << "cycleStart = " << cycleStart << ", cycleEnd = " << cycleEnd << ", connectCycleTubeIndex = " << connectCycleTubeIndex << endl; */

  unordered_map< int, vector<int> > planetGraph;
  for (int i = 0; i < n; i++) {
    if (i != connectCycleTubeIndex) {
      if (!planetGraph.count(tubes[i].x)) {
        planetGraph[tubes[i].x] = vector<int>();
      }
      planetGraph[tubes[i].x].push_back(tubes[i].y);
      if (!planetGraph.count(tubes[i].y)) {
        planetGraph[tubes[i].y] = vector<int>();
      }
      planetGraph[tubes[i].y].push_back(tubes[i].x);
    }
  }

  /* cout << "planetGraph:";
  for (unordered_map< int, vector<int> >::iterator it = planetGraph.begin(); it != planetGraph.end(); it++) {
    cout << " {" << it->first << ":";
    for (int j = 0; j < it->second.size(); j++) {
      cout << " " << it->second[j];
    }
    cout << "}";
  }
  cout << endl; */

  queue<int> fringe;
  fringe.push(cycleStart);
  vector<int> parent(n, 0);
  parent[cycleStart - 1] = cycleStart;
  while (!fringe.empty()) {
    int planet = fringe.front();
    fringe.pop();
    if (planet == cycleEnd) {
      break;
    }
    for (int j = 0; j < planetGraph[planet].size(); j++) {
      if (!parent[planetGraph[planet][j] - 1]) {
        fringe.push(planetGraph[planet][j]);
        parent[planetGraph[planet][j] - 1] = planet;
      }
    }
  }

  cycle.clear();
  cycle.insert(cycleStart);
  cycle.insert(cycleEnd);
  int planet = cycleEnd;
  while (parent[planet - 1] != cycleStart) {
    cycle.insert(parent[planet - 1]);
    planet = parent[planet - 1];
  }

  /* cout << "Cycle:";
  for (unordered_set<int>::iterator it = cycle.begin(); it != cycle.end(); it++) {
    cout << " " << *it;
  }
  cout << endl; */
}

void calculateBranchDistances(vector<int>& distances, vector<bool>& planetCalculated, const unordered_map< int, vector<int> >& unConnectedPlanetSourceMap, int lastConnection, int lastDistance) {
  if (unConnectedPlanetSourceMap.count(lastConnection)) {
    for (int i = 0; i < unConnectedPlanetSourceMap.at(lastConnection).size(); i++) {
      if (!planetCalculated[unConnectedPlanetSourceMap.at(lastConnection)[i] - 1]) {
        distances[unConnectedPlanetSourceMap.at(lastConnection)[i] - 1] = lastDistance + 1;
        planetCalculated[unConnectedPlanetSourceMap.at(lastConnection)[i] - 1] = true;
        calculateBranchDistances(distances, planetCalculated, unConnectedPlanetSourceMap, unConnectedPlanetSourceMap.at(lastConnection)[i], lastDistance + 1);
      }
    }
  }
}

void calculateDistances(vector<int>& distances, const vector<Tube>& tubes, int n, const unordered_set<int>& cycle) {
  vector<bool> planetCalculated(n, false);

  for (unordered_set<int>::const_iterator it = cycle.begin(); it != cycle.end(); it++) {
    planetCalculated[*it - 1] = true;
  }

  vector<int> firstConnections;
  unordered_map< int, vector<int> > unConnectedPlanetSourceMap;
  for (int i = 0; i < n; i++) {
    if (cycle.count(tubes[i].x) && cycle.count(tubes[i].y)) {
      continue;
    }

    if (cycle.count(tubes[i].x)) {
      distances[tubes[i].y - 1] = 1;
      planetCalculated[tubes[i].y - 1] = true;
      firstConnections.push_back(tubes[i].y);
      continue;
    }

    if (cycle.count(tubes[i].y)) {
      distances[tubes[i].x - 1] = 1;
      planetCalculated[tubes[i].x - 1] = true;
      firstConnections.push_back(tubes[i].x);
      continue;
    }

    if (!unConnectedPlanetSourceMap.count(tubes[i].x)) {
      unConnectedPlanetSourceMap[tubes[i].x] = vector<int>();
    }
    unConnectedPlanetSourceMap[tubes[i].x].push_back(tubes[i].y);
    if (!unConnectedPlanetSourceMap.count(tubes[i].y)) {
      unConnectedPlanetSourceMap[tubes[i].y] = vector<int>();
    }
    unConnectedPlanetSourceMap[tubes[i].y].push_back(tubes[i].x);
  }

  /* cout << "firstConnections:";
  for (int i = 0; i < firstConnections.size(); i++) {
    cout << " " << firstConnections[i];
  }
  cout << endl;
  cout << "unConnectedPlanetSourceMap:";
  for (unordered_map< int, vector<int> >::iterator it = unConnectedPlanetSourceMap.begin(); it != unConnectedPlanetSourceMap.end(); it++) {
    cout << " {" << it->first << ":";
    for (int j = 0; j < it->second.size(); j++) {
      cout << " " << it->second[j];
    }
    cout << "}";
  }
  cout << endl; */

  for (int i = 0; i < firstConnections.size(); i++) {
    calculateBranchDistances(distances, planetCalculated, unConnectedPlanetSourceMap, firstConnections[i], 1);
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<Tube> tubes(n);
    for (int j = 0; j < n; j++) {
      int x, y;
      cin >> x >> y;
      tubes[j] = Tube(x, y);
    }

    vector<int> distances(n, 0);

    unordered_set<int> cycle;
    findCycle(cycle, tubes, n);

    calculateDistances(distances, tubes, n, cycle);

    cout << "Case #" << i << ":";
    for (int j = 0; j < n; j++) {
      cout << " " << distances[j];
    }
    cout << endl;
  }
}
