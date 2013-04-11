/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>

#include <algorithm>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// const int IINF = numeric_limits<int>::max();
// const long long LLINF = numeric_limits<long long>::max();
//
class TheBrickTowerEasyDivOne {
 public:
  int find(int redCount, int redHeight, int blueCount, int blueHeight) {
    int ans = 0;
    if (redHeight != blueHeight) {
      int min_count = min(redCount, blueCount);
      ans += 3*min_count;
      if (redCount > min_count) ++ans;
      if (blueCount > min_count) ++ans;
    } else {
      ans = 2*min(redCount, blueCount);
      if (blueCount != redCount) ++ans;
    }
    return ans;
  }
};

int main() {
  TheBrickTowerEasyDivOne test;
  printf("%d\n", test.find(4, 4, 4, 7));
  return 0;
}
