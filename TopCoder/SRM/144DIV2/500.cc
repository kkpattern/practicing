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

class BinaryCode {
 public:
  vector<string> decode(string message) {
    vector<string> result;
    for (int i = 0; i < 2; ++i) {
      string raw = "0"; // create raw message with leading 0
      raw.push_back('0'+i);
      for (int j = 0; j < message.size(); ++j) {
        int t = message[j]-raw[j+1]-raw[j]+'0';
        if (t < 0 || t > 1) {
          raw = string("NONE");
          break;
        } else {
          raw.push_back('0'+t);
        }
      }
      if (raw[raw.length()-1] != '0') result.push_back(string("NONE"));
      else result.push_back(raw.substr(1, raw.size()-2));
    }
    return result;
  }
};

int main() {
  return 0;
}
