#include <stdio.h>

#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>

using std::list;
using std::map;
using std::string;
using std::vector;

const char *_names[] = {"RED", "GREEN", "BLUE"};

class AlternateColors {
 public:
  string getColor(long long r, long long g, long long b, long long k) {
    balls_[0] = r;
    balls_[1] = g;
    balls_[2] = b;
    vector<string> names(&_names[0], &_names[0]+3);
    int t = 3;
    while (t > 1) {
      long long m = balls_[0];
      for (int i = 0; i < t; ++i) {
        m = std::min(m, balls_[i]);
      }
      if (k <= m*t) {
        return names[(int)((k-1)%t)];
      }
      k -= m*t;
      int oldt = t;
      t = 0;
      for (int i = 0; i < oldt; ++i) {
        if (balls_[i] - m > 0) {
          balls_[t] = balls_[i]-m;
          names[t++] = names[i];
        }
      }
    }
    return names[0];
  }
 private:
  int leftColorCount() {
    int color_count = 0;
    for (int i = 0; i < 3; ++i) {
      if (balls_[i] > 0) ++color_count;
    }
    return color_count;
  }
  long long balls_[3];
};

int main() {
  return 0;
}
