//Phoenix_RK

/*

https://leetcode.com/problems/plus-one/

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        if(digits[digits.size()-1]+1<=9)
        {
            digits[digits.size()-1]+=1;
           
        }
        else
        {
          int i=digits.size()-1;
            while(i>=0 && digits[i]+1>9)
            {
                digits[i]=0;
                i--;                
            }
            if(i<0)
            {
                digits.insert(digits.begin(),1);
            }
            else
            {
                digits[i]+=1;
            }
            
        }
        
        return digits;
    }
};
