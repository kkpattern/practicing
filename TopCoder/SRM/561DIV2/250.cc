/*
 * Problem Statement
 *     
 * Fox Ciel is planning to visit the Tourist Kingdom for total days. This
 * kingdom is full of lovely cities. During her stay Ciel would like to visit as
 * many different cities as possible. She cannot visit more than one city on the
 * same day.   Additionally, different cities may require her to stay for a
 * different number of days. For each i, city i only counts as visited if Ciel
 * spends at least d[i] days in the city.   You are given the int total and the
 * vector <int> d. Return the maximal number of cities she can visit during her
 * vacation.
 */
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
