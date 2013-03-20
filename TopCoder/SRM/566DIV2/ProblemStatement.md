250 points
==========

Problem Statement
-----------------
    
Percy has just received a new game called Penguin Tiles. The game is played on a rectangular grid. Except for one square, each square of the grid contains a tile with a part of an image of a penguin. The one remaining square is empty, and it is called the open square. The player is allowed to slide one of the tiles adjacent to the open square onto the open square. After several moves the tile game is supposed to form a picture with the bottom right corner containing the open square.
 
Percy's version of Penguin Tiles is a misprint. Instead of each tile containing a different part of a penguin all tiles contain an image of the same penguin. In other words each pair of tiles in Percy's Penguin Tiles is indistinguishable.
 
Percy has decided to play with the game anyway but instead of moving just one tile at a time he has decided to move several tiles at once. In one move, Percy can either move some consecutive vertical tiles one square vertically, or some consecutive horizontal tiles one square horizontally. Of course, one of the tiles has to be moved onto the open square. (In other words, instead of moving several tiles one at a time, Percy may move them all at once, if they all lie in the same row or in the same column.)
    
You are given a vector <string> tiles representing the game. The j-th character of the i-th element of tiles is 'P' if the square at row i, column j contains a tile, and it is '.' (a period) for the open square. Return the minimum number of moves to complete Percy's game.

Definition
----------
    
- Class: `PenguinTiles`
- Method: `minMoves`
- Parameters: `vector <string>`
- Returns: `int`
- Method signature: `int minMoves(vector <string> tiles)`
(be sure your method is public)
    

Constraints
-----------

- `tiles` will contain between 2 and 50 elements, inclusive.
- Each element of `tiles` will contain between 2 and 50 characters, inclusive.
- Each element of `tiles` will contain the same number of characters.
- Each character of each element of `tiles` will be either 'P' or '.'.
- `tiles` will contain exactly 1 occurrence of the character '.'.

500 points
==========

Problem Statement
-----------------
    
Penguin Pals is a match making service that matches penguins to new friends, using the following procedure:
Each penguin is asked a single question: "Do you prefer the color blue, or the color red?"
All penguins are arranged so that they stand on a circle, equally spaced.
The organizers draw some straight lines, connecting some pairs of penguins. Each penguin may only be connected to at most one other penguin. Two penguins cannot be connected if they prefer a different color.
Each penguin who is connected to some other penguin follows the line to find their match.
 
The only problem with the above system was that it allowed penguins to collide if two lines crossed each other. Therefore, a new additional rule was adopted: no two lines may cross. Penguin Pals now has some penguins arranged on a circle (after step 2 of the above procedure). They need to know the maximum number of pairs of penguins they can create.
 
You are given a string colors whose i-th character represents the prefered color of the i-th penguin (0-based index) in the circular arrangement. The i-th character is 'R' if the i-th penguin prefers red and 'B' if the i-th penguin prefers blue. Return the maximum number of matched pairs that can be formed.

Definition
----------
    
- Class: `PenguinPals`
- Method: `findMaximumMatching`
- Parameters: `string`
- Returns: `int`
- Method signature: `int findMaximumMatching(string colors)`
(be sure your method is public)
    

Constraints
-----------

- `colors` will contain between 1 and 50 characters, inclusive.
- Each character of `colors` will be either 'R' or 'B'. 
