//Phoenix_RK

/*


https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]



*/


class Solution {
public:
    
    void rev(vector<char>& s,int i,int j)
    {
        if(i>=j)
            return;
        rev(s,i+1,j-1);
        swap(s[i],s[j]);
    }
    void reverseString(vector<char>& s) {
        rev(s,0,s.size()-1);        
    }
};


class Solution {
public:
    
   
    void reverseString(vector<char>& s)
    {
        int left=0,right=s.size()-1;
        
        while(left<right)
        {
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            
            left++;
            right--;
        }
            
    }
};

