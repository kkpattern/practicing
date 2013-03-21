/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>

#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>

using std::list;
using std::map;
using std::pair;
using std::string;
using std::vector;

class NinjaTurtles {
 public:
  int countOpponents(int P, int K) {
    int result = -1;
    for (int i = 1; true; ++i) {
      int pc = 3*(i/K)+i/3;
      if (pc == P) {
        result = i;
        break;
      } else if (pc > P) {
        break;
      }
    }
    return result;
  }
};

int main() {
  return 0;
}
