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

class PeopleCircle {
 public:
  string order(int numMales, int numFemales, int K) {
    int total = numMales+numFemales;
    string ans(total, 'M');
    int p = -1;
    for (int count = 0; count < numFemales; ) {
      int ki = 0;
      while (ki < K) {
        p = (p+1)%total;
        if (ans[p] == 'M')
          ++ki;
      }
      ans[p] = 'F';
      ++count;
    }
    return ans;
  }
};

int main() {
  PeopleCircle test;
  printf("%s\n", test.order(5, 5, 3).c_str());
  return 0;
}
