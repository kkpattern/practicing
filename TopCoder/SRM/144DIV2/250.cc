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

class Time {
 public:
  string whatTime(int seconds) {
    int time_seconds = seconds % 60;
    seconds /= 60;
    int time_minutes = seconds % 60;
    seconds /= 60;
    int time_hours = seconds % 24;
    char buf[10000] = {};
    sprintf(buf, "%d:%d:%d", time_hours, time_minutes, time_seconds);
    return string(buf);
  }
};

int main() {
  return 0;
}
