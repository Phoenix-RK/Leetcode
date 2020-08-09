//Phoenix_RK

/*


https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


*/


class Solution {
public:
     void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
  
    
    //inplace
    string reverseWords(string s) {
 
        int i=0,j=0,l=0;
        int len=s.size();
        int words=0;
        while(true)
        {
            while(i<len && s[i]==' ')
                i++;
            if(i==len)
                break;
          
            if(words)
                s[j++]=' ';
            l=j;
            while(i<len && s[i]!=' ')
            {
                s[j]=s[i];
                j++;
                i++;
            }
            reverseword(s,l,j-1); // reverse each words 
            words++;
            
        }
        s.resize(j);
        reverseword(s,0,j-1); //reverse whole string
        
        return s;
        
    }
};

