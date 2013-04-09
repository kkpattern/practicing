/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 *
 * Problem Statement
 *     
 * You have been put in charge of writing the sofware that powers an elevator in
 * a very tall office building. Because there is only one elevator in the
 * building, and many floors, the designers of the elevator gave it the capacity
 * to remember past usage history. By assuming that the employees will probably
 * use the elevator in the same ways and at the same times each day (arriving at
 * work, going to the cafeteria, leaving for the day), the software can be a
 * much better judge of where to travel and when. For example, if it's currently
 * on the fifth floor, and it knows that the next employee to use the elevator
 * will be on the third floor, it can travel there early so that the employee
 * will not have to spend any time waiting.
 * Given the arrival times, starting floors, and destination floors of each
 * employee for the day, determine the fastest time in which the elevator can
 * get each employee to his or her destination. The elevator starts on floor 1
 * at time 0. Travelling from floor p to floor q takes (abs(p - q)) units of
 * time. Also, the elevator may stand still for any length of time, if that is
 * optimal. Assume that it takes no time for employees to enter or exit the
 * elevator. Your method should return the minimal value of T such that, at time
 * T, all employees have arrived at their destinations. Employee i corresponds
 * to the ith element of each input parameter.
 * Definition
 *     
 * Class:
 * SmartElevator
 * Method:
 * timeWaiting
 * Parameters:
 * vector <int>, vector <int>, vector <int>
 * Returns:
 * int
 * Method signature:
 * int timeWaiting(vector <int> arrivalTime, vector <int> startingFloor, vector
 * <int> destinationFloor)
 * (be sure your method is public)
 *     
 *
 * Constraints
 * - arrivalTime will contain between 1 and 5 elements, inclusive.
 * - arrivalTime, startingFloor, and destinationFloor will all contain the same 
 *   number of elements.
 * - Each element in arrivalTime will be between 1 and 1000000, inclusive.
 * - Each element in startingFloor will be between 1 and 1000000, inclusive.
 * - Each element in destinationFloor will be between 1 and 1000000, inclusive.
 * - For all valid i, startingFloor[i] will never be equal to
 *   destinationFloor[i].
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

const int IINF = numeric_limits<int>::max();
// const long long LLINF = numeric_limits<long long>::max();

class SmartElevator {
 public:
  void recv(const vector<int> &arrivalTime,
            const vector<int> &startingFloor,
            const vector<int> &destinationFloor) {
    if (wait2dropcount_ == 0 && wait2pickcount_ == 0) {
      min_time_ = min(min_time_, time_);
    }
    int old_time = time_;
    int old_floor = floor_;
    for (int i = 0; i < arrivalTime.size(); ++i) {
      // try drop one
      if (wait2drop_[i] == 1) {
        int dropi = i;
        int dest = destinationFloor[dropi];
        time_ += abs(dest-floor_);
        floor_ = dest;
        wait2drop_[i] = 0;
        --wait2dropcount_;
        recv(arrivalTime, startingFloor, destinationFloor);
        ++wait2dropcount_;
        wait2drop_[i] = 1;
        floor_ = old_floor;
        time_ = old_time;
      }
    }
    for (int i = 0; i < wait2pick_.size(); ++i) {
      // try pick one
      if (wait2pick_[i] == 1) {
        int picki = i;
        int dest = startingFloor[picki];
        time_ = max(arrivalTime[i], time_+abs(dest-floor_));
        floor_ = dest;
        wait2drop_[i] = 1;
        ++wait2dropcount_;
        wait2pick_[i] = 0;
        --wait2pickcount_;
        recv(arrivalTime, startingFloor, destinationFloor);
        ++wait2pickcount_;
        wait2pick_[i] = 1;
        --wait2dropcount_;
        wait2drop_[i] = 0;
        floor_ = old_floor;
        time_ = old_time;
      }
    }
  }
  int timeWaiting(vector <int> arrivalTime, vector <int> startingFloor, vector <int> destinationFloor) {
    wait2drop_.resize(arrivalTime.size());
    wait2pick_.resize(arrivalTime.size());
    fill(wait2drop_.begin(), wait2drop_.end(), 0);
    fill(wait2pick_.begin(), wait2pick_.end(), 1);
    floor_ = 1;
    time_ = 0;
    min_time_ = IINF;
    wait2pickcount_ = arrivalTime.size();
    recv(arrivalTime, startingFloor, destinationFloor);
    return min_time_;
  }
 private:
  vector<int> wait2drop_;
  vector<int> wait2pick_;
  int wait2dropcount_;
  int wait2pickcount_;
  int floor_;
  int time_;
  int min_time_;
};

int main() {
  return 0;
}
