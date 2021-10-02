#include <iostream>
#include <map>
#include <queue>

using namespace std;

bool check(int v1, int v2, int target) {
  map<pair<int, int>, bool> isChecked;
  queue<pair<int, int>> numbersToCheck;

  numbersToCheck.emplace(make_pair(0, v2));
  numbersToCheck.emplace(make_pair(v1, 0));

  while (!numbersToCheck.empty()) {
    auto currentNumbers = numbersToCheck.front();
    numbersToCheck.pop();

    if (isChecked[currentNumbers]) {
      continue;
    }

    int b1 = currentNumbers.first;
    int b2 = currentNumbers.second;

    if (b1 == target || b2 == target) {
      return true;
    }

    isChecked[currentNumbers] = true;

    // empty one of the buckets
    numbersToCheck.emplace(make_pair(0, b2));
    numbersToCheck.emplace(make_pair(b1, 0));
    // fill one of the buckets
    numbersToCheck.emplace(make_pair(v1, b2));
    numbersToCheck.emplace(make_pair(b1, v2));
    // pour water from bucket into other
    numbersToCheck.emplace(b1 + b2 <= v2 ? make_pair(0, b1 + b2) : make_pair(b1 + b2 - v2, v2));
    numbersToCheck.emplace(b1 + b2 <= v1 ? make_pair(b1 + b2, 0) : make_pair(v1, b1 + b2 - v1));
  }

  return false;
}

int main() {
  int n; cin >> n;

  while (n--) {
    int v1, v2, v3; cin >> v1 >> v2 >> v3;
    cout << (check(v1, v2, v3) ? "Да" : "Нет") << "\n";
  }

  return 0;
}