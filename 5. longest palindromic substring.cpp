//Phoenix_RK

/*
https://leetcode.com/problems/longest-palindromic-substring/


Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"



****************************************************************************
Idea:
Iterate through every char of the string
	1)check if this char is the middle element of the palindrome
	2)Expand on both sides and as expanding check if the elements of the boundary are same 
	3) return the length of the palindrome obtained by expanding.
	4)store the start and end of the palindrome which is the longest among all those obtained through iteration.

return the substring in the index of start and end.

**************
racecar
ababd
*/

class Solution {
public:
    int max(int a ,int b)
    {
        return a>b?a:b;
    }
    string longestPalindrome(string s) {
        if(s.length()<1) return"";
        int start=0;
        int end=0;
        
       // "babad"
      //  b
        //bab
        //aba
        
        for(int i=0;i<s.length();i++)
        {
            int len1 = leng(s,i,i);
            int len2 = leng(s,i,i+1);
            int l= max(len1,len2);
            //setting new boundary for the string
            if (l > end-start+1) // if many no of palindromes occur of same length, end-start-1 helps to store the first of those longest palindromes
            {
                start = i-((l-1)/2);       //i is the index of the middle element..from that setting start               
                 end  = i+ (l/2);      // similarly setting end
                
            }           
            
        }
        return s.substr(start,end-start+1);
        
        
    }
    
    int leng(string s,int i,int j){
        
        if(s.length()==0 || i>j) return 0;
        
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return j-i-1;
/*
j - i -1 because when the while loop terminates left is decremented and right is incremented more than necessary ..so in calculation we need to have as (j-1)-(i+1)-1=j-1-i-1+1 = j -i-1;

e.g. racecar (length = 7. Simple math to calculate this would be  R - L  + 1  ( where L= 0 , R=6 )), considering start index is '0'.
Now, in this example ( 'racecar' ) when loop goes into final iteration, that time we have just hit L =0, R =6 (ie. length -1)
but before exiting the loop, we are also decrementing L by L - -  , and incrementing R by R ++ for the final time, which will make L and R as  ( L = -1, R = 7 )
Now, after exiting the loop,  if you apply the same formula for length calculation as 'R - L +1', it would return you 7 -( - 1 )+1 = 9 which is wrong, but point to note is it gives you length increased by 2 units than the correct length which is 7.
So the correct calculation of length would be when you adjust your R and L . to do that you would need to decrease R by 1 unit as it was increased by 1 unit before exiting the loop , and increase L by 1 unit as it was decreased by 1 unit just before exiting the loop.
lets calculate the length with adjusted R and L

(R-1)-(L+1)-1
= R-1-L-1+1 
= R -L -1;
*/


    }
};
