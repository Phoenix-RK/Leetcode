//Phoenix_RK


/*


https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/


Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 



*/

class Solution {
public:
    string removeDuplicates(string S) 
    {
        string s;
        int ind=0;
        for(int i=1;i<S.length();i++)
        {
            if(ind>=0 && S[ind]==S[i])
            {
                ind--;
            }
            else
            {
                S[++ind]=S[i];
            }
        }        
        return S.substr(0,ind+1);
    }
};
