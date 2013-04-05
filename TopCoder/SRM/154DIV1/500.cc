/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 */
#include <stdio.h>
#include <math.h>

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Group {
  string name;
  vector<double> scores;
  int ranks;
  double total_score;
};

class CompareGroup {
 public:
  CompareGroup(int i) : i_(i) {}
  bool operator()(const Group &ga, const Group&gb) {
    return ga.scores[i_] > gb.scores[i_];
  }
 private:
  int i_;
};

class FinalCompare {
 public:
  bool operator()(const Group &ga, const Group &gb) {
    if (ga.ranks != gb.ranks) return ga.ranks < gb.ranks;
    if (fabs(ga.total_score-gb.total_score)<0.000000001) return ga.total_score > gb.total_score;
    return ga.name < gb.name;
  }
};

class ContestScore {
 public:
  vector <string> sortResults(vector <string> data) {
    vector<Group> groups;
    for (int di = 0; di < data.size(); ++di) {
      Group tmp;
      stringstream ss(data[di]);
      ss >> tmp.name;
      tmp.ranks = 0;
      while (!ss.eof()) {
        double ts = 0.0;
        ss >> ts;
        tmp.scores.push_back(ts);
      }
      groups.push_back(tmp);
    }
    int score_count = 0;
    if (data.size() > 0) {
      score_count = groups[0].scores.size();
      if (score_count > 0) {
        for (int i = 0; i < score_count; ++i) {
          sort(groups.begin(), groups.end(), CompareGroup(i));
          int rank = 1;
          int rank_count = 1;
          groups[0].ranks += rank;
          for (int j = 1; j < groups.size(); ++j) {
            if (groups[j].scores[i] == groups[j-1].scores[i]) {
              ++rank_count;
            } else {
              rank += rank_count;
              rank_count = 1;
            }
            groups[j].ranks += rank;
          }
        }
      }
    }
    for (int i = 0; i < groups.size(); ++i) {
      double tmp = 0;
      for (int j = 0; j < score_count; ++j) {
        tmp += groups[i].scores[j];
      }
      groups[i].total_score = tmp;
    }
    sort(groups.begin(), groups.end(), FinalCompare());
    vector<string> ans;
    for (int i = 0; i < groups.size(); ++i) {
      char buf[500] = {};
      sprintf(buf, "%s %d %.1f", groups[i].name.c_str(), groups[i].ranks, groups[i].total_score);
      ans.push_back(string(buf));
    }
    return ans;
  }
};

int main() {
  return 0;
}
