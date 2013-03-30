/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class RectangularGrid {
 public:
  long long countRectangles(int width, int height) {
    long long ans = 0;
    for (int w = 1; w <= width; ++w) {
      for (int h = 1; h <= height; ++h) {
        if (w != h) {
          ans += (width-w+1)*(height-h+1);
          // for (int x = 1; x+w-1 <= width; ++x) {
          //   for (int y = 1; y+h-1 <= height; ++y) {
          //     ++ans;
          //   }
          // }
        }
      }
    }
    return ans;
  }
};

int main() {
  RectangularGrid test;
  printf("%lld\n", test.countRectangles(10000, 10000));
  return 0;
}
