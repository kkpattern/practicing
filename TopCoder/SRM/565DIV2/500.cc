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

class MonstersValley2 {
 public:
  int backTracing(int i) {
    if (i >= monster_count_) return 0;

    long long old_scar = scar_;
    int min_price = 0;
    if (scar_ < dread_[i]) {
      scar_ += dread_[i];
      min_price = price_[i]+backTracing(i+1);
    } else {
      // try bride
      scar_ += dread_[i];
      int bride_price = price_[i]+backTracing(i+1);
      // try not bride
      scar_ -= dread_[i];
      int not_bride_price = backTracing(i+1);
      min_price = std::min(bride_price, not_bride_price);
    }
    scar_ = old_scar;
    return min_price;
  }
  int minimumPrice(vector <int> dread, vector <int> price) {
    monster_count_ = dread.size();
    scar_ = 0;
    dread_ = dread;
    price_ = price;
    return backTracing(0);
  }
 private:
  int monster_count_;
  vector<int> dread_;
  vector<int> price_;
  long long scar_;
};

int main() {
  return 0;
}
