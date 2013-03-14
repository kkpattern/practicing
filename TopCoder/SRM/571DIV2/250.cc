#include <string>
#include <vector>

using std::string;
using std::vector;

class FoxAndGames {
 public:
  int countStars(vector<string> results) {
    int star_count = 0;
    for (vector<string>::const_iterator i = results.begin();
         i != results.end();
         ++i) {
      const string &result = *i;
      for (string::const_iterator j = result.begin();
           j != result.end();
           ++j) {
        if (*j != 'o') break;
        else ++star_count;
      }
    }
    return star_count;
  }
};
