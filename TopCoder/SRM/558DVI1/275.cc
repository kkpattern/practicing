/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 *
 * Problem Statement
 *     
 * Little Fox Jiro has a rectangular board. On the board there is a row of N
 * unit cells. The cells are numbered 0 through N-1 from the left to the right.
 * Initially, the cells are not colored. Jiro must color each of the cells red,
 * green, or blue.
 *
 * You are given a string desiredColor with N characters. For each i, character
 * i of desiredColor represents the color Jiro must use for cell i. If a
 * character is one of 'R' (as red), 'G' (as green), and 'B' (as blue), it means
 * that Jiro must use that particular color. If a character is '*', Jiro may use
 * any of the three colors for the particular cell.
 *
 * You are also given the ints stampCost and pushCost that describe the cost of
 * the coloring process. The coloring process consists of two phases. In the
 * first phase, Jiro must pick a single stamp he will then use to color all the
 * cells. The length L of the stamp can be any integer between 1 and N,
 * inclusive. A stamp of length L costs L*stampCost.
 *
 * In the second phase, Jiro must repeatedly use the stamp to color the cells.
 * Each use of the stamp works as follows:
 * Jiro picks one of the three colors and pushes the stamp into ink of the
 * chosen color C.
 * Jiro picks a segment of L contiguous cells such that each of them is either
 * uncolored or already has the color C. The segment must be completely inside
 * the board. That is, the leftmost cell of the segment must be one of the cells
 * 0 through N-L.
 * Jiro pushes the stamp onto the chosen segment of cells. All the cells now
 * have color C.
 * Each use of the stamp costs pushCost.
 *
 * Return the smallest possible total cost of coloring all the cells using the
 * above process.
 * Definition
 *     
 * Class:
 * Stamp
 * Method:
 * getMinimumCost
 * Parameters:
 * string, int, int
 * Returns:
 * int
 * Method signature:
 * int getMinimumCost(string desiredColor, int stampCost, int pushCost)
 * (be sure your method is public)
 *     
 *
 * Constraints
 * - desiredColor will contain between 1 and 50 characters, inclusive.
 * - Each character of desiredColor will be either 'R' or 'G' or 'B' or '*'.
 * - stampCost will be between 1 and 100,000, inclusive.
 * - pushCost will be between 1 and 100,000, inclusive.
 */
#include <stdio.h>

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int INF = 1000000000;
int push_count_table[51][51][51] = {};

class Stamp {
 public:
  int getPushCount(const string &desiredColor, int length, int begin, int end) {
    int push_count = 0;
    if ((push_count = push_count_table[length][begin][end]) != 0) {
      return push_count;
    }
    if ((end-begin) < length) {
      push_count = INF;
    } else {
      char color = desiredColor[begin];
      bool found = true;
      set<char> colors;
      for (int i = begin; i < end; ++i) {
        if (desiredColor[i] != '*') {
          colors.insert(desiredColor[i]);
        }
      }
      if (colors.size() <= 1) {
        if ((end-begin) % length == 0) push_count = (end-begin)/length;
        else push_count = (end-begin)/length+1;
      } else {
        push_count = INF;
        for (int i = begin+1; i < end-1; ++i) {
          int left_count = getPushCount(desiredColor, length, begin, i);
          int right_count = getPushCount(desiredColor, length, i, end);
          if (left_count != INF &&
              right_count != INF &&
              (left_count+right_count)<push_count) {
            push_count = left_count+right_count;
          }
        }
      }
    }
    push_count_table[length][begin][end] = push_count;
    return push_count;
  }

  int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    int size = desiredColor.size();
    int ans = stampCost + size*pushCost; // use stamp of length 1
    for (int i = 2; i <= size; ++i) {
      int pushCount = getPushCount(desiredColor, i, 0, size);
      if (pushCount != INF) {
        int tmp = stampCost*i+pushCost*pushCount;
        if (tmp < ans) ans = tmp;
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
