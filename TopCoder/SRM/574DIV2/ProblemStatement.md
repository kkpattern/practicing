250 points
==========

Problem Statement
-----------------
    
Manao arrived to a city he's never been to. He bought a city map that depicts the city as a grid H squares high and W squares wide. Each square in this grid can either contain a street segment or a single point of interest of some type.

It was later when Manao noticed that the map lacked a legend. The map legend is the list of all types of points of interest (further referred to as POIs) present on the map. Each POI type is coupled with the corresponding symbol denoting this type on the map. For example, you might have seen an 'M' sign denoting a metro station or a fork-and-spoon sign denoting a restaurant on a city map.

Fortunately, not all is lost: the map contains a legend summary. The summary states how many POIs of each type are there on the map (for example, it could say: all in all, there are 9 restaurants and 4 metro stations on the map). Moreover, it turned out that all quantities are pairwise distinct. Manao realized that he could guess the signs using this information (for instance, if there were 4 triangle signs on the map Manao would know that triangle stands for a metro station).  

You are given a vector <string> cityMap containing H elements, each of them W characters long. Each character of cityMap designates the corresponding square on Manao's city map and is '.' if there is a street segment in that square or an uppercase letter if the square contains a POI. Different types of POIs are denoted by different letters, two POIs of the same type are always denoted with the same letter. As you see, the letters just stand for the different signs on the map.

You are also given a vector <int> POIs. POIs[i] is the number of occurences of the i-th type POIs on the map. It is guaranteed that the information given is consistent, i.e. there are exactly as many different letters in cityMap as elements in POIs and there exists a valid assignment of letters to POI types.

For each POI type, determine the letter with which it is denoted on the map. Return a string of as many characters as elements in POIs, where the character at the i-th position is the letter corresponding to the i-th POI type.

Definition
----------
    
- Class: `CityMap`
- Method: `getLegend`
- Parameters: `vector <string>`, `vector <int>`
- Returns: `string`
- Method signature: `string getLegend(vector <string> cityMap, vector <int> POIs)`
(be sure your method is public)
    

Constraints
-----------

- `cityMap` will contain between 1 and 50 elements, inclusive.
- Each element of `cityMap` will be between 1 and 50 characters long, inclusive.
- The elements of `cityMap` will be of the same length.
- Elements of `cityMap` will consist of '.' and 'A'-'Z' characters only.
- `POIs` will contain between 1 and 26 elements, inclusive.
- Each element of `POIs` will be between 1 and 2500, inclusive.
- All elements of `POIs` will be distinct.
- There will exist a valid assignment of letters in `cityMap` to POI types.

500 points
==========

Problem Statement
-----------------
    
Manao has recently invented a brand new single-player game called The Number Game.

The player starts with a number A. Also, another number B is chosen. Note that neither A nor B contain a zero digit in their base 10 representation.

The player's goal is to obtain B from A. In each move, the player can either reverse his current number, or he can divide it by 10 (using integer division). For example, if the current number is 12849, the player can either reverse it to obtain 94821, or he can divide it by 10 to obtain 1284. (Note that we always round down when using integer division.)

You are given two ints A and B. If it is possible to obtain B from A, return the minimum number of moves necessary to reach this goal. Otherwise, return -1.

Definition
----------
    
- Class: `TheNumberGameDiv2`
- Method: `minimumMoves`
- Parameters: `int`, `int`
- Returns: `int`
- Method signature: `int minimumMoves(int A, int B)`
(be sure your method is public)
    

Constraints
-----------

- `A` will be between 1 and 999,999,999, inclusive.
- `B` will be between 1 and 999,999,999, inclusive.
- `A` and `B` will not contain a zero digit in base 10 representation.
- `A` and `B` will be distinct.

