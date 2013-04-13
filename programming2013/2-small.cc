/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int IINF = numeric_limits<int>::max()-2;

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ++ti) {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int ans = IINF;
    for (int i = 0; s1.size()-i>=s2.size(); ++i) {
      int tmp = 0;
      for (int j = 0; j < s2.size(); ++j) {
        if (s1[i+j] != s2[j]) ++tmp;
        if (tmp > ans) break;
      }
      ans = min(tmp, ans);
    }
    printf("Case #%d: %d\n", ti+1, ans);
  }
  return 0;
}
