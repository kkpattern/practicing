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

class CityMap {
 public:
  string getLegend(vector <string> cityMap, vector <int> POIs) {
    map<char, int> sign_to_n;
    for (int i = 0; i < cityMap.size(); ++i) {
      for (int j = 0; j < cityMap[i].size(); ++j) {
        char sign = cityMap[i][j];
        if (sign != '.')
          ++sign_to_n[sign];
      }
    }
    string result;
    for (int i = 0; i < POIs.size(); ++i) {
      for (map<char, int>::const_iterator j = sign_to_n.begin();
           j != sign_to_n.end();
           ++j) {
        if (j->second == POIs[i]) {
          result.push_back(j->first);
          break;
        }
      }
    }
    return result;
  }
};

int main() {
  return 0;
}
