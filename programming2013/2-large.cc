#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans_count[50000] = {};

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ++ti) {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    vector<vector<int> > positions(26);
    fill_n(&ans_count[0], sizeof(ans_count)/sizeof(ans_count[0]), 0);
    for (int i = 0; i < s2.size(); ++i) {
      positions[s2[i]-'a'].push_back(i);
    }
    for (int i = 0; i < s1.size(); ++i) {
      int ci = s1[i]-'a';
      for (int j = 0; j < positions[ci].size(); ++j) {
        if (positions[ci][j] > i) break;
        ++ans_count[i-positions[ci][j]];
      }
    }
    int ans = 0;
    for (int i = 0; i < s1.size(); ++i) {
      ans = max(ans, ans_count[i]);
    }
    printf("Case #%d: %d\n", ti+1, s2.size()-ans);
  }
  return 0;
}
