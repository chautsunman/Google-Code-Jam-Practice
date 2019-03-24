#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareOrder(const pair<int, int> o1, const pair<int, int> o2) {
  return o1.second - o1.first < o2.second - o2.first;
}

bool occupiedEmptySeats(const pair<int, int> emptySeat) {
  return emptySeat.first == -1;
}

void updateEmptySeats(vector< pair<int, int> > &emptySeats, const pair<int, int> order) {
  for (int i = 0; i < emptySeats.size(); i++) {
    if (order.first <= emptySeats[i].first) {
      if (order.second >= emptySeats[i].second) {
        emptySeats[i].first = -1;
      } else {
        emptySeats[i].first = order.second + 1;
      }
    } else {
      if (order.second >= emptySeats[i].second) {
        emptySeats[i].second = order.first - 1;
      } else {
        emptySeats.push_back(make_pair(emptySeats[i].first, order.first - 1));
        emptySeats.push_back(make_pair(order.second + 1, emptySeats[i].second));
        emptySeats[i].first = -1;
      }
    }
  }

  remove_if(emptySeats.begin(), emptySeats.end(), occupiedEmptySeats);
}

int orderSeats(vector< pair<int, int> > &emptySeats, const pair<int, int> order) {
  int seats = 0;

  for (int i = 0; i < emptySeats.size(); i++) {
    if (order.first <= emptySeats[i].first) {
      if (order.second >= emptySeats[i].second) {
        seats += emptySeats[i].second - emptySeats[i].first + 1;
      } else {
        seats += order.second - emptySeats[i].first + 1;
      }
    } else {
      if (order.second >= emptySeats[i].second) {
        seats += emptySeats[i].second - order.first + 1;
      } else {
        seats += order.second - order.first + 1;
      }
    }
  }

  updateEmptySeats(emptySeats, order);

  return seats;
}

int main() {
  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, q;

    cin >> n >> q;

    vector< pair<int, int> > orders(q);

    for (int j = 0; j < q; j++) {
      pair<int, int> order;
      cin >> order.first >> order.second;
      orders[j] = order;
    }

    sort(orders.begin(), orders.end(), compareOrder);

    vector<int> orderedSeats(q, 0);

    vector< pair<int, int> > emptySeats;
    emptySeats.push_back(make_pair(1, n));

    for (int j = 0; j < q; j++) {
      orderedSeats[j] = orderSeats(emptySeats, orders[j]);
    }

    cout << "Case #" << (i + 1) << ": " << *max_element(orderedSeats.begin(), orderedSeats.end()) << endl;
  }
}
