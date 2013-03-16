/*
 * Problem Statement
 *     
 * Fox Ciel is the owner of a ski resort. The ski resort has N places numbered 0
 * through N-1. You are given a vector <int> altitude. For each i, the i-th
 * element of altitude is the altitude of the place i.  The skiers would like to
 * follow the path (place 0) -> (place 1) -> ... -> (place N-1). The trip will
 * only be possible if the altitudes of the places are non-increasing. In order
 * to make the trip possible, Ciel now needs to decrease the altitudes of some
 * places. In other words, Ciel wants to decrease some of the altitudes so that
 * altitude[0] >= altitude[1] >= ... >= altitude[N-1] holds. It costs 1 unit of
 * money to decrease the altitude of one place by 1 unit of height.  Return the
 * minimal cost required for the change.
 */
#include <stdio.h>

#include <list>
#include <vector>

using std::list;
using std::vector;

class SkiResortsEasy {
 public:
  int minCost(vector<int> altitude)  {
    int cost = 0;
    int length = altitude.size();
    for (int i = 1; i < length; ++i) {
      if (altitude[i] > altitude[i-1]) {
        cost += altitude[i]-altitude[i-1];
        altitude[i] = altitude[i-1];
      }
    }
    return cost;
  }
};

int main() {
  return 0;
}
