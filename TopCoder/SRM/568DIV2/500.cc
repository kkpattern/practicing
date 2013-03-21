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

const int INF = 50000000;

class BallsSeparating {
 public:
  int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
    vector<int> *boxes[3];
    boxes[0] = &red;
    boxes[1] = &green;
    boxes[2] = &blue;
    int length = red.size();
    vector<int> color(length, 0);
    vector<int> left_balls(length, 0);
    int rtotal[3] = {};
    int rbox[3] = {};
    int rechoice_cost[3][50] = {};
    for (int i = 0; i < length; ++i) {
      for (int j = 0; j < 3; ++j) {
        if ((*boxes[j])[i] > left_balls[i]) {
          left_balls[i] = (*boxes[j])[i];
          color[i] = j;
        }
        rtotal[j] += (*boxes[j])[i];
      }
      rbox[color[i]] += 1;
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < length; ++j) {
        rechoice_cost[i][j] = left_balls[j]-(*boxes[i])[j];
      }
    }
    int operation = 0;
    for (int i = 0; i < length; ++i) {
      int sum = 0;
      for (int j = 0; j < 3; ++j) {
        sum += (*boxes[j])[i];
      }
      operation += (sum-left_balls[i]);
    }
    int rechoice = INF;
    for (int i = 0; i < length; ++i) {
      for (int j = 0; j < length; ++j) {
        for (int k = 0; k < length; ++k) {
          if (i != j && i != k && j != k) {
            int tmp = rechoice_cost[0][i]+rechoice_cost[1][j]+rechoice_cost[2][k];
            if (tmp < rechoice) rechoice = tmp;
          }
        }
      }
    }
    if (rechoice == INF) return -1;
    else return operation+rechoice;
  }
};

int main() {
  return 0;
}
