/*
 * Problem Statement
 *     
 * Fox Ciel has a new favorite string operation that works as follows: She takes
 * two copies of some string X, and inserts one copy somewhere into the other
 * copy of the same string. (She can also insert it at the beginning or,
 * equivalently, at the end.) This operation is called expansion of the string
 * X. For example, if X = "Ciel", she can expand it to "CielCiel", "CCieliel",
 * "CiCielel", or "CieCiell".   You are given two strings: S and T. Return "Yes"
 * (quotes for clarity) if T can be obtained by expanding S exactly once.
 * Otherwise, return "No".
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

class FoxAndHandleEasy {
 public:
  string isPossible(string S, string T) {
    for (int i = 0; i < S.size(); ++i) {
      string new_s = S;
      new_s.insert(i, S);
      if (0 == new_s.compare(T)) return "Yes";
    }
    return "No";
  }
};

int main() {
  return 0;
}
