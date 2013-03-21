/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::list;
using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

class TheSimilarNumbers {
 public:
  int find(int lower, int upper) {
    int result = 0;
    int i = lower;
    while (i <= upper) {
      ++result;
      i = i*10+1;
    }
    return result;
  }
};

int main() {
  TheSimilarNumbers test;
  printf("%d\n", test.find(1, 10));
  printf("%d\n", test.find(5, 511));
  printf("%d\n", test.find(5, 4747));
  printf("%d\n", test.find(1, 1000000));
  return 0;
}
