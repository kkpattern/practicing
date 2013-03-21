250 points
==========

Problem Statement
-----------------
    
Two positive integers A and B are called similar if A <= 10*B and B <= 10*A. For example, 1 and 10 are similar, but 1 and 11 are not.  You are given ints lower and upper. You must select as many integers as possible so that:
each selected integer is between lower and upper, inclusive;
no two selected integers are similar.
Return the maximum number of selected integers.

Definition
----------
    
- Class: `TheSimilarNumbers`
- Method: `find`
- Parameters: `int`, `int`
- Returns: `int`
- Method signature: `int find(int lower, int upper)`
(be sure your method is public)
    

Constraints
-----------

- `upper` will be between 1 and 1,000,000, inclusive.
- `lower` will be between 1 and upper, inclusive.

500 points
==========

Problem Statement
-----------------
    
There are N boxes numbered from 0 to N-1, inclusive. For each i, box i contains red[i] red balls, green[i] green balls, and blue[i] blue balls.  Fox Ciel wants to separate the balls by colors. In each operation, she can pick a single ball from some box and put it into another box. She considers the balls to be separated if no box contains balls of more than one color.  Return the minimal number of operations required to separate the balls. If this is impossible, return -1.

Definition
----------
    
- Class: `BallsSeparating`
- Method: `minOperations`
- Parameters: `vector <int>`, `vector <int>`, `vector <int>`
- Returns: `int`
- Method signature: `int minOperations(vector <int> red, vector <int> green, vector <int> blue)`
(be sure your method is public)
    

Constraints
-----------

- `red`, `green` and `blue` will each contain between 1 and 50 elements, inclusive.
- `red`, `green` and `blue` will contain the same number of elements.
- Each element of `red`, `green` and `blue` will be between 1 and 1,000,000, inclusive.
