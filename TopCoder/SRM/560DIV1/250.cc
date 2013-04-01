/*
 * Author: Kai Zhang
 * Email: kylerzhang11@gmail.com
 *
 * Problem Statement
 * -----------------
 *     
 * Tomek thinks that smartphones are overrated. He plans to release a new
 * cellphone with an old-school keyboard, which may require you to tap a key
 * multiple times to type a single letter. For example, if the keyboard has two
 * keys, one with the letters "adef" and the other one with the letters "zyx",
 * then typing 'a' requires one keystroke, typing 'f' requires four keystrokes,
 * typing 'y' requires two keystrokes, and so on.
 *  
 * Tomek has already designed the keyboard's layout. That is, he already knows
 * the number of keys on the keyboard, and for each key he knows the maximum
 * number of letters it may hold. He now wants to create a specific keyboard
 * for a language that uses N different letters. He has a large body of text in
 * this language, and he already analyzed it to find the frequencies of all N
 * letters of its alphabet.
 *  
 * You are given a vector <int> frequencies with N elements. Each element of
 * frequencies is the number of times one of the letters in Tomek's alphabet
 * appears in the text he has. Each element of frequencies will be strictly
 * positive. (I.e., each of the N letters occurs at least once in Tomek's
 * text.)
 *  
 * You are also given a vector <int> keySize. The number of elements of
 * keySize is the number of keys on Tomek's keyboard. Each element of keySize
 * gives the maximal number of letters on one of the keys.
 *  
 * Find an assignment of letters to keys that minimizes the number of
 * keystrokes needed to type Tomek's entire text. Return that minimum number
 * of keystrokes. If there is not enough room on the keys and some letters
 * of the alphabet won't fit, return -1 instead.
 *
 * Definition
 * ----------
 *     
 * Class:            TomekPhone
 * Method:           minKeystrokes
 * Parameters:       vector <int>, vector <int>
 * Returns:          int
 * Method signature: int minKeystrokes(vector <int> frequencies, vector <int> keySizes)
 * (be sure your method is public)
 *     
 *
 * Constraints
 * -----------
 * 
 * - frequencies will contain between 1 and 50 elements, inclusive.
 * - Each element of frequencies will be between 1 and 1,000, inclusive.
 * - keySizes will contain between 1 and 50 elements, inclusive.
 * - Each element of keySizes will be between 1 and 50, inclusive.
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

const int kMaxKeySize = 100;

class TomekPhone {
 public:
  int minKeystrokes(vector <int> frequencies, vector <int> keySizes) {
    int key_count = keySizes.size();
    vector<int> keyUsed(key_count, 0);
    int alpha_count = frequencies.size();
    int ans = 0;
    sort(frequencies.begin(), frequencies.end());
    for (int ai = alpha_count-1; ai >= 0; --ai) {
      int min_key_used = kMaxKeySize;
      int key = 0;
      for (int ki = 0; ki < key_count; ++ki) {
        if (keyUsed[ki] < keySizes[ki] && keyUsed[ki] < min_key_used) {
          min_key_used = keyUsed[ki];
          key = ki;
        }
      }
      if (min_key_used == kMaxKeySize) {
        return -1;
      } else {
        ans += frequencies[ai]*(min_key_used+1);
        ++keyUsed[key];
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
