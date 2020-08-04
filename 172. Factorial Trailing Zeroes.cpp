//Phoenix_RK

/*
https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.


*********************************************************************

The idea is that trailing zero is the number of 10s(product of 2 n 5) in the factorial. So, we need to calculate the no of 2 n 5 pairs in the prime factorization of factorial.

If careful attention is given, one could observe that 2 occurs once for every 2 numbers, whereas 5 occurs once in every 5 numbers. Therefore, for any factorial no of 2s outnumbers no of 5s.

So, it is enough to find the no of 5s in the prime factorisation of the factorial.

it can be found by floor(n/5)

Eg:
1) 7! = 7 * 6 * 5 * 4 * 3 * 2

floor(7/5) = floor(1.4) = 1 
Therefore one trailing zero.

2) 28!

floor(28/5)= floor(5.6) = 5

But,there are 6 5s in 28!
5 -> 1
10 ->1
15 ->1
20 ->1
25 ->2
--------
     6
--------

 Therefore, the extra 5 in 25 can be included by calculating floor(n/25)

3) 128!

similarly, 1 extra 5 in 125 will be missed if we calculate floor(n/5) + floor(n/25)
This could be included by calculating floor(n/125)

Therefore,
no of trailing zeroes = floor(n/5)+floor(n/25) + floor(n/125)+ ......+ floor(n/5^k)
where floor(n/5^k) =1
which means=> n = 5^k 
	k= log5(n) (Time complexity)


*/

class Solution {
public:
    int trailingZeroes(int n) {
        
        int ans=0;
        
        while(n)
        {
            ans+=floor(n/5);
            n=n/5;
        }
        return ans;
    }
};
