#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Bus {
  int s;
  int f;
  int d;
};

int ts;
vector<Bus> buses;

int nextBusTime(int city, int currentTime) {
  Bus bus = buses[city - 1];

  if (currentTime <= bus.s) {
    return bus.s;
  } else if (currentTime <= bus.s + bus.f) {
    return bus.s + bus.f;
  } else {
    return bus.s + bus.f * ceil(1.0 * (currentTime - bus.s) / bus.f);
  }
}

int lastBusTime(int city, int currentTime) {
  Bus bus = buses[city - 1];

  if (currentTime < bus.s) {
    return -1;
  } else if (currentTime < bus.s + bus.f) {
    return bus.s;
  } else {
    return bus.s + bus.f * floor(1.0 * (currentTime - bus.s) / bus.f);
  }
}

int latestBusTime(int nextCity, int currentTime) {
  return lastBusTime(nextCity - 1, currentTime - buses[nextCity - 2].d);
}

int maxSightseeing(int city, int latestTime) {
  if (city == 2) {
    if (buses[0].s + buses[0].d > latestTime) {
      return -1;
    }

    if (nextBusTime(1, ts) + buses[0].d <= latestTime) {
      return 1;
    } else {
      return 0;
    }
  }

  int latestLastCityBusTime = latestBusTime(city, latestTime);

  if (latestLastCityBusTime == -1) {
    return -1;
  }

  int maxCityWithoutSightseeing = maxSightseeing(city - 1, latestLastCityBusTime);

  if (maxCityWithoutSightseeing == -1) {
    return -1;
  }

  int maxCityWithSightseeing = maxSightseeing(city - 1, latestLastCityBusTime - ts);

  return max(maxCityWithoutSightseeing, 1 + maxCityWithSightseeing);
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, tf;
    cin >> n >> ts >> tf;

    buses.clear();
    for (int j = 0; j < n - 1; j++) {
      Bus bus;
      cin >> bus.s >> bus.f >> bus.d;
      buses.push_back(bus);
    }

    int maxCity = maxSightseeing(n, tf);

    if (maxCity != -1) {
      cout << "Case #" << i << ": " << maxCity << endl;
    } else {
      cout << "Case #" << i << ": IMPOSSIBLE" << endl;
    }
  }

  return 0;
}
