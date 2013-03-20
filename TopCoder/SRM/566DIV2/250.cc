/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
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

class PenguinTiles {
 public:
  int minMoves(vector<string> tiles) {
    int row_size = tiles.size();
    int column_size = tiles[0].size();
    int x = 0;
    int y = 0;
    for (int i = 0; i < row_size; ++i) {
      for (int j = 0; j < column_size; ++j) {
        if (tiles[i][j] == '.') {
          x = i;
          y = j;
        }
      }
    }
    int moves = 0;
    if (x < row_size-1) ++moves;
    if (y < column_size-1) ++moves;
    return moves;
  }
};

int main() {
  return 0;
}
