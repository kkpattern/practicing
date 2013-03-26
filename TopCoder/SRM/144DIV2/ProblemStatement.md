250points
=========

Problem Statement
-----------------
    
Computers tend to store dates and times as single numbers which represent the number of seconds or milliseconds since a particular date. Your task in this problem is to write a method whatTime, which takes an int, seconds, representing the number of seconds since midnight on some day, and returns a string formatted as "<H>:<M>:<S>". Here, <H> represents the number of complete hours since midnight, <M> represents the number of complete minutes since the last complete hour ended, and <S> represents the number of seconds since the last complete minute ended. Each of <H>, <M>, and <S> should be an integer, with no extra leading 0's. Thus, if seconds is 0, you should return "0:0:0", while if seconds is 3661, you should return "1:1:1".

Definition
----------
    
- Class: `Time`
- Method: `whatTime`
- Parameters: `int`
- Returns: `string`
- Method signature: `string whatTime(int seconds)`
(be sure your method is public)
    

Constraints
-----------

- `seconds` will be between 0 and 24*60*60 - 1 = 86399, inclusive.

500points
=========

Problem Statement
-----------------
    
Let's say you have a binary string such as the following:
011100011
One way to encrypt this string is to add to each digit the sum of its adjacent digits. For example, the above string would become:
123210122
In particular, if P is the original string, and Q is the encrypted string, then Q[i] = P[i-1] + P[i] + P[i+1] for all digit positions i. Characters off the left and right edges of the string are treated as zeroes.
An encrypted string given to you in this format can be decoded as follows (using 123210122 as an example):
1.Assume P[0] = 0.
2.Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P[1] = 1.
3.Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we know that P[2] = 1.
4.Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we know that P[3] = 1.
5.Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 0, P[7] = 1, and P[8] = 1.
We check our work by noting that Q[8] = P[7] + P[8] = 1 + 1 = 2. Since this equation works out, we are finished, and we have recovered one possible original string.
Now we repeat the process, assuming the opposite about P[0]:
1.Assume P[0] = 1.
2.Because Q[0] = P[0] + P[1] = 1 + P[1] = 0, we know that P[1] = 0.
3.Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we know that P[2] = 1.
4.Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 3, which leads us to the conclusion that P[3] = 2. However, this violates the fact that each character in the original string must be '0' or '1'. Therefore, there exists no such original string P where the first digit is '1'.
Note that this algorithm produces at most two decodings for any given encrypted string. There can never be more than one possible way to decode a string once the first binary digit is set.
Given a string message, containing the encrypted string, return a vector <string> with exactly two elements. The first element should contain the decrypted string assuming the first character is '0'; the second element should assume the first character is '1'. If one of the tests fails, return the string "NONE" in its place. For the above example, you should return {"011100011", "NONE"}.

Definition
----------
    
- Class: `BinaryCode`
- Method: `decode`
- Parameters: `string`
- Returns: `vector <string>`
- Method signature: `vector <string> decode(string message)`
(be sure your method is public)
    

Constraints
-----------

- `message` will contain between 1 and 50 characters, inclusive.
- Each character in `message` will be either '0', '1', '2', or '3'.