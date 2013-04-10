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

const int IINF = numeric_limits<int>::max();
// const long long LLINF = numeric_limits<long long>::max();

class StampPads {
 public:
  int dynamic(const vector<string> &pads, int pi, const string &wish) {
    if (wish == "") return 0;
    if (pi < 0) return IINF;
    pair<int, string> key = make_pair(pi, wish);
    if (ans_.end() != ans_.find(key)) return ans_[key];

    string rest_wish;
    stringstream ss(wish);
    string color;
    while (ss >> color) {
      string color_key = " "+color+" ";
      if (string::npos == pads[pi].find(color_key)) {
        rest_wish += color;
        rest_wish += " ";
      }
    }
    int cost = dynamic(pads, pi-1, rest_wish);
    if (cost != IINF) cost += 1;
    cost = min(cost, dynamic(pads, pi-1, wish));
    ans_[key] = cost;
    return cost;
  }
  int bestCombo(vector <string> pads, vector <string> wishlist) {
    string wish;
    for (int i = 0; i < pads.size(); ++i) {
      pads[i].insert(0, 1, ' ');
      pads[i].push_back(' ');
    }
    for (int i = 0; i < wishlist.size(); ++i) {
      wish += wishlist[i];
      wish += " ";
    }
    int min_cost = dynamic(pads, pads.size()-1, wish);
    return min_cost == IINF ? -1 : min_cost;
  }
 private:
  map<pair<int, string>, int> ans_;
};

int main() {
  return 0;
}
