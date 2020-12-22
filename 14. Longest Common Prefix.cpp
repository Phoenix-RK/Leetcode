//Phoenix_RK


/*


https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        if(strs.size()==0)
            return s;
        
        string str=strs[0];
      
        int flag=1;
        for(int x=0;x<str.length() && flag ;x++)
        {
            for(int i=1;i<strs.size();i++)
            {
                if(str[x]!=strs[i][x])
                {
                    flag=0;
                    break;
                }

            }
            if(flag)
                s=s+str[x];
        }
        return s;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        if(strs.size()==0)
            return s;
        
        string str=strs[0];
      
        int flag=1;
      
            for(int i=1;i<strs.size();i++)
            {
                
                while(strs[i].find(str)!=0)
                {
                    str=str.substr(0,str.length()-1);
                }
            }
          
        return str;
    }
};

