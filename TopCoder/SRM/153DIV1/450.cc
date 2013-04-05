/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 *
 * Problem Statement
 *     
 * You are working on the backend of a particular system in which you want to
 * assign a unique ID to each client. However, the system is distributed, and
 * there are a number of components, each of which must be able to assign IDs to
 * clients. In other words, you want to have each of the components assign the
 * IDs with as little communication between the components as possible. You have
 * decided that it is more important to keep the system distributed than it is
 * to ensure that all of the clients have unique IDs. Thus, you are considering
 * having each of the components independently assign IDs randomly from a large
 * pool of possible IDs, and synchronizing the assigned IDs at the end of each
 * day. In other words, each component will update its list of available IDs at
 * the end of each day, based on the IDs assigned by all of the components.
 * Now, there are two ways that you can do this. The first is to have each of
 * the components assign a random ID each time from the list of available IDs
 * obtained at the beginning of each day. In other words, have components
 * without any memory of which IDs they have assigned during the day, which may
 * assign the same ID more than once during the day. The second way to assign
 * the IDs is to have the components each remember which IDs they have assigned,
 * so that no component assigns the same ID more than once. This way, two
 * different components may assign the same ID, but no one component will assign
 * an ID more than once. Now, it turns out that the first system is slightly
 * cheaper to implement, but it will clearly result in more collisions (a
 * collision occurs when the same ID is assigned to multiple clients). So, to
 * help decide which system to implement, you want to run a simulation.  Your
 * task is to simulate both systems and figure out the probability that some ID
 * is assigned to more than one client in both of the systems, and then return
 * the difference in the two probabilities. You will be given an int, ids, which
 * represents the number of IDs in the pool of possible IDs that each component
 * may assign at the beginning of some day (all components draw IDs from the
 * same pool). You will also be given a vector <int>, assignments, each of whose
 * elements represents the number of IDs that some component assigns during the
 * day. You are to return a double representing the difference in the
 * probabilities between the two systems.
 * Definition
 *     
 * Class:
 * Collision
 * Method:
 * probability
 * Parameters:
 * vector <int>, int
 * Returns:
 * double
 * Method signature:
 * double probability(vector <int> assignments, int ids)
 * (be sure your method is public)
 *     
 *
 * Notes
 * - Your result need not be precisely the same as the result shown in the
 *   examples. As long as your result is within 1e-9 of the result in the
 *   example, your submission will be evaluated as correct.
 * - If more IDs are assigned than there are total IDs, return 0, since there
 *   must be a collision in this case.
 *
 * Constraints
 * - ids will be between 1000 and 2147483647, inclusive.
 * - assignments will contain between 2 and 50 elements, inclusive.
 * - Each element of assignments will be between 0 and 10,000, inclusive.
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

class Collision {
 public:
  double probability(vector <int> assignments, int ids) {
    int size = assignments.size();
    double p1 = 1;
    int left = ids;
    for (int i = 0; i < size; ++i) {
      double pi = 1;
      int ai = assignments[i];
      if (left < ai) {
        p1 = 0;
        break;
      }
      for (int d = 0; d < ai; ++d) {
        pi *= (double)(left-d)/(ids-d);
      }
      p1 *= pi;
      left -= ai;
    }

    double p2 = 1;
    left = ids;
    for (int i = 0; i < size; ++i) {
      double pi = 1;
      int ai = assignments[i];
      if (left < ai) {
        p2 = 0;
        break;
      }
      for (int d = 0; d < ai; ++d) {
        pi *= (double)(left-d)/(ids);
      }
      p2 *= pi;
      left -= ai;
    }
    return p1-p2;
  }
};

int main() {
  return 0;
}
