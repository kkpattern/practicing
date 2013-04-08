/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>
#include <math.h>

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

class PaternityTest {
 public:
  vector<int> matches(const string &a, const string &b) {
    vector<int> m;
    int length = a.length();
    for (int i = 0; i < length; ++i) {
      if (a[i] == b[i]) m.push_back(i);
    }
    return m;
  }
  int union_size(const vector<int> &a, const vector<int> &b) {
    int size = 0;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        if (a[i] == b[j]) ++size;
      }
    }
    return size;
  }
  vector<int> possibleFathers(string child, string mother, vector<string> men) {
    int size = men.size();
    vector<int> mm = matches(child, mother);
    vector<int> ans;
    for (int mi = 0; mi < size; ++mi) {
      vector<int> mf = matches(child, men[mi]);
      int mus = union_size(mm, mf);
      int mother_match_length = mm.size()-mus;
      int father_mathc_length = mf.size()-mus;
      for (int i = 0; i <= mus; ++i) {
        int mml = mother_match_length + i;
        int fml = father_mathc_length + mus-i;
        if (mml >= child.size()/2 && fml >= child.size()/2) {
          ans.push_back(mi);
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
