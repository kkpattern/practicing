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

int cache[50][50];

class PenguinPals {
 public:
  int findMaximumMatching(string colors, int start, int end) {
    if (start >= end) return 0;
    if (cache[start][end] != -1) return cache[start][end];

    int length = colors.size();
    int max_matching = 0;
    for (int i = start+1; i < end; ++i) {
      if (colors[i] == colors[start]) {
        int matching = 1+findMaximumMatching(colors, start+1, i)
            +findMaximumMatching(colors, i+1, end);
        if (matching > max_matching) max_matching = matching;
      }
    }
    int matching = findMaximumMatching(colors, start+1, end);
    if (matching > max_matching) max_matching = matching;
    cache[start][end] = max_matching;
    return max_matching;
  }
  int findMaximumMatching(string colors) {
    std::fill_n(&cache[0][0], sizeof(cache)/sizeof(cache[0][0]), -1);
    return findMaximumMatching(colors, 0, colors.size());
  }
};

int main() {
  PenguinPals test;
  printf("%d\n", test.findMaximumMatching("RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRB"));
  printf("%d\n", test.findMaximumMatching("RBRBRBRBR"));
  return 0;
}
