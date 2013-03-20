/*
 * Problem Statement
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

int avaiable[50];
int arrange[1000];

class TomekPhone {
 public:
  int minKeystrokes(vector<int> frequencies, vector <int> keySizes) {
    int total_key_avaiable = 0;
    for (int i = 0; i < keySizes.size(); ++i) {
      int size = keySizes[i];
      total_key_avaiable += size;
      for (int j = 0; j < size; ++j) {
        ++avaiable[j];
      }
    }
    if (total_key_avaiable < frequencies.size()) return -1;
    std::sort(frequencies.begin(), frequencies.end());
    for (int i = frequencies.size()-1; i >= 0; --i) {
      for (int j = 0; j < 50; ++j) {
        if (avaiable[j] > 0) {
          --avaiable[j];
          arrange[i] = j+1;
          break;
        }
      }
    }
    int result = 0;
    for (int i = frequencies.size()-1; i >= 0; --i) {
      result += arrange[i]*frequencies[i];
    }
    return result;
  }
}

int main() {
  return 0;
}
