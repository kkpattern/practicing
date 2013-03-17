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

class FoxAndVacation {
 public:
  int maxCities(int total, vector <int> d) {
    std::sort(d.begin(), d.end());
    int visited_cities = 0;
    for (vector<int>::const_iterator i = d.begin();
         i != d.end();
         ++i) {
      int required_days = *i;
      if (required_days > total) {
        break;
      } else {
        visited_cities += 1;
        total -= required_days;
      }
    }
    return visited_cities;
  }
};

int main() {
  return 0;
}
