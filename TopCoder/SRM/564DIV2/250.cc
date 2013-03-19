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

class FauxPalindromes {
 public:
  bool checkPalindrome(string word) {
    bool palindrome = true;
    int i = 0;
    int j = word.length()-1;
    while (i <= j) {
      if (word[i] != word[j]) return false;
      ++i;
      --j;
    }
    return true;
  }

  string classifyIt(string word) {
    int word_length = word.length();
    bool palindrome = true;
    if (checkPalindrome(word)) {
      return string("PALINDROME");
    } else {
      char pre = '\0';
      string new_word;
      for (int i = 0; i < word_length; ++i) {
        if (word[i] != pre) {
          new_word.push_back(word[i]);
          pre = word[i];
        }
      }
      if (checkPalindrome(new_word)) {
        return string("FAUX");
      } else {
        return string("NOT EVEN FAUX");
      }
    }
  }
};

int main() {
  return 0;
}
