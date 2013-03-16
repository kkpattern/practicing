/*
 * Problem Statement
 *     
 * Jakub is trying out a one-dimensional keyboard. It consists of a single row
 * of keys. The distance between any two adjacent keys is 1. Each key contains a
 * distinct letter of the English alphabet. Jakub uses only one finger to type
 * on the keyboard. He wonders what is the smallest total distance he will have
 * to move his finger while typing a given word.
 *  
 * For example, if the keyboard's only row is "qwertyuiop", and Jakub wants to
 * type the word "potter", he will have to move his finger from 'p' to 'o'
 * (distance 1), from 'o' to 't' (distance 4), from 't' to 't' (distance 0),
 * from 't' to 'e' (distance 2) and from 'e' to 'r' (distance 1), for a total
 * distance of 1 + 4 + 0 + 2 + 1 = 8.
 *  
 * You are given a string keyboard and a string word, describing the keyboard
 * and the word Jakub wants to write. Return the minimum distance he will have
 * to move his finger in order to type the word on the keyboard.
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

class TypingDistance {
 public:
  int minDistance(string keyboard, string word) {
    map<char, int> key_positions;
    for (int i = 0; i < keyboard.size(); ++i) {
      key_positions[keyboard[i]] = i;
    }
    int distance = 0;
    for (int i = 1; i < word.size(); ++i) {
      int from = key_positions[word[i-1]];
      int to = key_positions[word[i]];
      distance += std::abs(to-from);
    }
    return distance;
  }
};


int main() {
  return 0;
}
