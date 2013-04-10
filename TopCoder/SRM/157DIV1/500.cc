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

class Table {
 public:
  vector <string> layout(vector <string> tbl) {
    int row_size = tbl.size();
    vector<string> ans(row_size, string(""));
    for (int ri = 0; ri < row_size; ++ri) {
      stringstream ss(tbl[ri]);
      int rs, cs;
      char o, content;

      int col_size = 0;
      while (ss>>o>>cs>>o>>rs>>o>>content>>o) {
        col_size += cs;
        if (ans[0].size() < col_size) {
          for (int i = 0; i < row_size; ++i) {
            ans[i].resize(col_size, '.');
          }
        }
        int ci = 0;
        for (; ans[ri][ci] != '.'; ++ci) {
        }
        for (int rri = ri; rri < ri+rs; ++rri) {
          for (int cci = ci; cci < ci+cs; ++cci) {
            ans[rri][cci] = content;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
