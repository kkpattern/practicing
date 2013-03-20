250 points
==========

Problem Statement
-----------------
    
A histogram of a given collection of numbers graphically represents the frequency of each value in the collection. We are given several numbers ranging from 0 to 9 as a vector <int> values. The goal is to build their histogram according to the following rules.  1) The width of the histogram should be exactly 10.  2) The height of the histogram should equal to H+1, where H is the number of times the most frequent element occurs in values.  3) The i-th (0-based) column of the histogram corresponds to the value i. Let X(i) be the frequency of value i in values. Then the last X(i) characters in the column should be 'X's and the other ones should be '.'s. For example, if value i was not present in values, the column should be filled with '.' characters. If i was present once, the last element of the column should be 'X' and and the other ones should be '.'s. If i was present twice, the last two elements should be 'X's and and the other ones should be '.'s, and so on.  Build the histogram and return it as a vector <string>.

Definition
----------
    
- Class: ValueHistogram
- Method: build
- Parameters: vector <int>
- Returns: vector <string>
- Method signature: vector <string> build(vector <int> values)
(be sure your method is public)
    

Constraints
-----------

- values will contain between 1 and 50 elements, inclusive.
- Each element of values will be between 0 and 9, inclusive.


500 points
==========

Problem Statement
-----------------
    
Manao is traversing a valley inhabited by monsters. During his journey, he will encounter several monsters one by one. The scariness of each monster is a positive integer. Some monsters may be scarier than others. The i-th (0-based index) monster Manao will meet has scariness equal to dread[i].  Manao is not going to fight the monsters. Instead, he will bribe some of them and make them join him. To bribe the i-th monster, Manao needs price[i] gold coins. The monsters are not too greedy, therefore each value in price will be either 1 or 2.  At the beginning, Manao travels alone. Each time he meets a monster, he first has the option to bribe it, and then the monster may decide to attack him. A monster will attack Manao if and only if he did not bribe it and its scariness is strictly greater than the total scariness of all monsters in Manao's party. In other words, whenever Manao encounters a monster that would attack him, he has to bribe it. If he encounters a monster that would not attack him, he may either bribe it, or simply walk past the monster.     Consider this example: Manao is traversing the valley inhabited by the Dragon, the Hydra and the Killer Rabbit. When he encounters the Dragon, he has no choice but to bribe him, spending 1 gold coin (in each test case, Manao has to bribe the first monster he meets, because when he travels alone, the total scariness of monsters in his party is zero). When they come by the Hydra, Manao can either pass or bribe her. In the end, he needs to get past the Killer Rabbit. If Manao bribed the Hydra, the total scariness of his party exceeds the Rabbit's, so they will pass. Otherwise, the Rabbit has to be bribed for two gold coins. Therefore, the optimal choice is to bribe the Hydra and then to walk past the Killer Rabbit. The total cost of getting through the valley this way is 2 gold coins.  You are given the vector <int>s dread and price. Compute the minimum price Manao will pay to safely pass the valley.

Definition
----------
    
- Class: MonstersValley2
- Method: minimumPrice
- Parameters: vector <int>, vector <int>
- Returns: int
- Method signature: int minimumPrice(vector <int> dread, vector <int> price)
(be sure your method is public)
    

Constraints
-----------

- dread will contain between 1 and 20 elements, inclusive.
- Each element of dread will be between 1 and 2,000,000,000, inclusive.
- price will contain between the same number of elements as dread.
- Each element of price will be either 1 or 2.
