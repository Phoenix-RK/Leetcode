//Phoenix_RK

/*
https://leetcode.com/problems/excel-sheet-column-number/
https://practice.geeksforgeeks.org/problems/excel-sheet-part-2/0

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701



*********************************************************************************************
Idea:
This problem is similar to basic numbers 
What is 321 = 3*10*10 + 2*10 + 1
In similar way, We could calculate for AAB.
The difference between the two is that
	1) in the number system, the base is 10. Whereas, in the alphabets the base is 26
	2) in the number system, we take the value of integers as such, but here we need to calculate the value of each character using ASCII
Example:
AAB
Result = Result*26
Result = Result + s[i]-'A' + 1
A =>  0*26 = 0 
      0 + 0 + 1 =1
A =>  1*26 = 26
      26 + 0 + 1 = 27
B =>  27*26 = 702
      702 + 1 + 1 = 704 
  


*/


class Solution {
public:
    int titleToNumber(string s) {
        
        long long int result =0;
        for(int i=0;i<s.size();i++)
        {
            result = result * 26;
            result = result + s[i] - 'A' + 1;
        }
     
        return result ;
    }
};
