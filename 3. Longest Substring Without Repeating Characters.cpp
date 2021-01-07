//Phoenix_RK


/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/


Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/


class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int lengthOfLongestSubstring(string s) {
        
        int i=0,j=0;
        
        map<char,int> m;
        int max_len=0;
         while(j<s.length())
         {
             if(m.find(s[j])==m.end())
             {
                 m[s[j]]++;                
                 j++;
                 max_len=max(m.size(),max_len);
             }
             else
             {
                 m.erase(s[i]);
                 i++;
             }

         }
        
        return max_len;
    }
};



