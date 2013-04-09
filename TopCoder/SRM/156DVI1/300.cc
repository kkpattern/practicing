/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 *
 * Problem Statement
 *     
 * The game of BombSweeper is a single-player game played on a rectangular grid.
 * Each square in the grid is either a bomb (represented by 'B') or empty space
 * (represented by '.'). The true identity of each square is hidden when the
 * game begins. The object of the game is to correctly determine both the number
 * of bombs on the board and their positions.
 * You are trying to write a program which predicts the percent likelihood that
 * you will win a given game of BombSweeper. You've recently become so good at
 * the game that your success or failure depends only on your first few moves.
 * To start, you pick a random square on the gameboard and uncover it. If the
 * square you uncover is a bomb, you lose the game. If the square is not a bomb,
 * but one or more of its horizontal, vertical, and diagonal neighbors is, you
 * are no better off than when you started and you must take another turn. If
 * the square is not a bomb, and none of its (up to) eight neighbors are bombs
 * either, then you win the game.
 * Given a vector <string> board, representing the game board, return a number
 * between 0.0 and 100.0, inclusive, representing the percent likelihood of you
 * winning the game.
 *
 * Definition
 *     
 * Class:
 * BombSweeper
 * Method:
 * winPercentage
 * Parameters:
 * vector <string>
 * Returns:
 * double
 * Method signature:
 * double winPercentage(vector <string> board)
 * (be sure your method is public)
 *     
 *
 * Notes
 * - In calculating the probability, let wins be the number of non-bomb squares
 * which have no bomb neighbors, and let losses be the number of bombs on the
 * board. The odds of winning are then (wins / (wins + losses)), which returns
 * a number between 0.0 and 1.0, inclusive.
 * - As long as you calculate wins and losses correctly, you need not worry about
 * minor double imprecisions.
 * - Your solution need only be accurate to 1e-9 (relative or absolute). Thus, if
 * your result is within 1e-9 (relative or absolute) of the result shown, your
 * result will be judged correct.
 *
 * Constraints
 * - board will contain between 1 and 50 elements, inclusive.
 * - Each element of board will contain between 1 and 50 characters, inclusive.
 * - Each element of board will contain the same number of characters.
 * - Each character in board will be either '.' or 'B'.
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

// const int IINF = numeric_limits<int>::max();
// const long long LLINF = numeric_limits<long long>::max();

int rd[] = {1, 1, 0, -1, -1, -1, 0, 1};
int cd[] = {0, 1, 1, 1, 0, -1, -1, -1};

class BombSweeper {
 public:
  double winPercentage(vector <string> board) {
    int row_size = board.size();
    int column_size = board[0].size();
    int wins = 0;
    int loses = 0;
    for (int ri = 0; ri < row_size; ++ri) {
      for (int ci = 0; ci < column_size; ++ci) {
        if ('B' == board[ri][ci]) {
          ++loses;
        } else {
          bool no_bomb = true;
          for (int i = 0; i < 8; ++i) {
            int nri = ri+rd[i];
            int nci = ci+cd[i];
            if (nri < row_size && nri >= 0 &&
                nci < column_size && nci >= 0 &&
                board[nri][nci] == 'B') {
              no_bomb = false;
              break;
            }
          }
          if (no_bomb) ++wins;
        }
      }
    }
    return (double)wins/(wins+loses)*100.0;
  }
};

int main() {
  return 0;
}
