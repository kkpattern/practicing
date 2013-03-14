#include <stdio.h>

#include <list>
#include <string>
#include <vector>

using std::list;
using std::string;
using std::vector;

class FoxAndMp3Easy {
 public:
  vector<string> playList(int n) {
    max_ = n;
    int x = 1;
    vector<string> list;
    for (int i = 0; i < 50 && i < n; ++i) {
      char buf[500];
      sprintf(buf, "%d.mp3", x);
      x = next(x);
      list.push_back(string(buf));
    }
    return list;
  }
 private:
  int next(int n) {
    if (n*10 <= max_) {
      return n*10;
    } else {
      ++n;
      if (n % 10 == 0) {
        return n / 10;
      } else if (n <= max_) {
        return n;
      } else {
        return (n-1)/10+1;
      }
    }
    return 0;
  }
  int max_;
};

int main() {
  FoxAndMp3Easy test;
  vector<string> list = test.playList(10);
  for (vector<string>::const_iterator i = list.begin();
       i != list.end();
       ++i) {
    printf("%s\n", i->c_str());
  }
  return 0;
}
