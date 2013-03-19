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

class ValueHistogram {
 public:
  vector <string> build(vector <int> values) {
    int count[10] = {};
    for (int i = 0; i < values.size(); ++i) {
      ++count[values[i]];
    }
    int max_h = 0;
    for (int i = 0; i < 10; ++i) {
      if (count[i] > max_h) max_h = count[i];
    }
    int h = max_h+1;
    vector<string> graph;
    for (int i = h; i > 0; --i) {
      graph.push_back(string());
      for (int j = 0; j < 10; ++j) {
        if (count[j] >= i) graph[h-i].push_back('X');
        else graph[h-i].push_back('.');
      }
    }
    return graph;
  }
};

int main() {
  return 0;
}
