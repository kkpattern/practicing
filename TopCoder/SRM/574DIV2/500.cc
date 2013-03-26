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

class TheNumberGameDiv2 {
 public:
  int min(string a, const string &b, int n, bool reverse) {
    printf("%s %s %d\n", a.c_str(), b.c_str(), n);
    if (a.length() < b.length()) return -1;
    if (a == b) {
      results_[a] = n;
      return n;
    } else {
      // try reverse
      int re = -1;
      if (reverse) 
        re = min(reverse_string(a), b, n+1, false);
      // try division
      int di = min(a.substr(0, a.size()-1), b, n+1, true);
      if (re == -1 && di == -1) {
        results_[a] = -1;
        return -1;
      } else {
        int real = 0;
        if (re == -1) real = di;
        else if (di == -1) real = re;
        else real = std::min(di, re);
        results_[a] = real;
        return real;
      }
    }
  }

  int minimumMoves(int A, int B) {
    string a = n_to_string(A);
    string b = n_to_string(B);
    return min(a, b, 0, true);
  }
  string n_to_string(int n) {
    string s;
    while (n > 0) {
      s.insert(0, 1, n%10+'0');
      n /= 10;
    }
    return s;
  }
  string reverse_string(const string &a) {
    string re;
    for (int i = 0; i < a.size(); ++i) {
      re.insert(0, 1, a[i]);
    }
    return re;
  }
 private:
  map<string, int> results_;
  map<string, int> reversed_;
};

int main() {
  return 0;
}
