/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 *
 * Problem Statement
 *     
 * Checking to to see if a player enters a valid cheat code in a game is not
 * just a simple matter of checking that the keypresses exactly line up with the
 * cheat code. It is possible that the player may hold down one key a little too
 * long and consequently it is read as two or more key presses. Ignoring
 * repeated key presses isn't an option either however, because a cheat code may
 * require a key to be used repeatedly. Also, the player may press any number of
 * keys before or after entering the cheat code.  You will be given a string
 * keyPresses which will contain the keys the player pressed. Each character in
 * keyPresses will correspond to one key pressed by the player. The order of
 * characters in keyPresses is the order in which the keys were entered. You
 * will also be given a vector <string> codes. Each String in codes will be one
 * possible valid cheat code. You are to create a class CheatCode with a method
 * matches which will return a sorted vector <int> containing the indexes of all
 * codes in codes which potentially match what the player entered. A cheat code
 * matches keyPresses if some substring of keyPresses is the same as the cheat
 * code, except that it may have more than one of the same character, where only
 * one was expected. So, if keyPresses where "ABBCC", it would match the cheat
 * codes "ABC", "BB" and "BC" (and others), but not "ABBB" or "BBCCD".  For
 * example, if keyPresses is "UUDDLRRLLRBASS" (quotes for clarity) and codes is
 * { "UUDDLRLRBA",
 *   "UUDUDLRLRABABSS",
 *   "DDUURLRLAB",
 *   "UUDDLRLRBASS",
 *   "UDLRRLLRBASS" }
 *
 * The code "UUDDLRLRBA" matches because the player may enter extra keys
 * after the code has been entered. Also notice that although there is
 * an extra 'R' and 'L' in the middle of keyPresses, the code still
 * matches because the computer may have accidentally detected repeated
 * keys while the player entering a code. The code "UUDUDLRLRABABSS"
 * stops matching at the 4th character, 'U'. The 2nd 'D' in keyPresses
 * is allowed because the player may have held it down too long.
 * However, the 'U' does not match the 'L', which is next in keyPresses.
 * The code "DDUURLRLAB" does not match. Remember though that the
 * beginning of keyPresses, "UU", is ignored here because the player may
 * have done another move before entering the code. The "DD" at the
 * beginning of the code does match with the first "DD" in keyPresses,
 * however next in keyPresses is an 'L' which does not match the 'U' in
 * the code. The code "UUDDLRLRBASS" matches. The code "UDLRRLLRBASS"
 * also matches.  Your program would return
 * { 0,  3,  4 }
 * for the 0th, 3rd, and 4th codes in codes which match keyPresses.
 * Definition
 *     
 * Class:
 * CheatCode
 * Method:
 * matches
 * Parameters:
 * string, vector <string>
 * Returns:
 * vector <int>
 * Method signature:
 * vector <int> matches(string keyPresses, vector <string> codes)
 * (be sure your method is public)
 *     
 *
 * Constraints
 * - keyPresses will be between 0 and 50 characters in length, inclusive.
 * - keyPresses will only contain uppercase letters ('A'-'Z').
 * - codes will contain between 0 and 50 elements, inclusive.
 * - Each string in codes will be between 1 and 50 characters in length,
 *   inclusive.
 * - Each string in codes will only contain uppercase letters ('A'-'Z').
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

class CheatCode {
 public:
  bool match(const string &key, const string &code) {
    int start = 0;
    vector<int> positions;
    for (int i = 0; i < code.size(); ++i) {
      char c = code[i];
      int j = start;
      for (; j < key.size(); ++j) {
        if (key[j] == c) {
          positions.push_back(j);
          start = j+1;
          break;
        }
      }
      if (j >= key.size()) return false;
    }

    for (int pi = 0; pi < positions.size()-1; ++pi) {
      char c = key[positions[pi]];
      for (int j = positions[pi]+1; j < positions[pi+1]; ++j) {
        if (c != key[j]) {
          return false;
        }
      }
    }
    return true;
  }
  vector <int> matches(string keyPresses, vector <string> codes) {
    vector<int> ans;
    for (int i = 0; i < codes.size(); ++i) {
      for (int j = 0; j < keyPresses.size(); ++j) {
        if (match(keyPresses.substr(j), codes[i])) {
          ans.push_back(i);
          break;
        }
      }
    }
    return ans;
  }
};
