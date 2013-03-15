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
