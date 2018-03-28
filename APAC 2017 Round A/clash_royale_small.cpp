#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> maxLevel;
vector< vector<int> > attackPower;
vector< vector<int> > cost;

int totalPower(vector<int> const &cards) {
  int power = 0;
  for (int i = 0; i < n; i++) {
    power += attackPower[i][cards[i] - 1];
  }
  return power;
}

int maxTotalPowerRecursive(int coins, vector<int> const &cards) {
  if (coins <= 0) {
    return totalPower(cards);
  }

  vector<int> powers;

  for (int i = 0; i < n; i++) {
    if (cards[i] >= maxLevel[i]) {
      continue;
    }

    if (cost[i][cards[i] - 1] > coins) {
      continue;
    }

    vector<int> cardsCopy(cards);
    cardsCopy[i] += 1;
    powers.push_back(maxTotalPowerRecursive(coins - cost[i][cards[i] - 1], cardsCopy));
  }

  return (powers.size() == 0) ? totalPower(cards) : *max_element(powers.begin(), powers.end());
}

int maxTotalPower(int coins, vector<int> const cards) {
  return maxTotalPowerRecursive(coins, cards);
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int m;
    cin >> m >> n;

    vector<int> currentLevel(n);
    for (int j = 0; j < n; j++) {
      int cardMaxLevel;
      cin >> cardMaxLevel >> currentLevel[j];
      maxLevel.push_back(cardMaxLevel);

      vector<int> cardAttackPower(cardMaxLevel);
      for (int k = 0; k < cardMaxLevel; k++) {
        cin >> cardAttackPower[k];
      }
      attackPower.push_back(cardAttackPower);

      vector<int> cardCost(cardMaxLevel - 1);
      for (int k = 0; k < cardMaxLevel - 1; k++) {
        cin >> cardCost[k];
      }
      cost.push_back(cardCost);
    }

    cout << "Case #" << i << ": " << maxTotalPower(m, currentLevel) << endl;
  }

  return 0;
}
