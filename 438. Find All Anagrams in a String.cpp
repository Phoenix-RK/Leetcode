//Phoenix_RK

/*

https://leetcode.com/problems/find-all-anagrams-in-a-string/

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.


Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


*/

//Sliding window technique

class Solution {
public:
    bool check(int a[],int b[])
    {
        for(int i=0;i<25;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int hash1[26];
        int hash2[26];
        memset(hash1,0,sizeof(hash1));
        memset(hash2,0,sizeof(hash2));
        int size1=s.size();
        int size2=p.size();
        
        vector<int> result;
      
        if(size1<size2)
            return result;
        
        
        int left=0,right=0;
        
        while(right<size2)
        {
            hash1[s[right]-'a']+=1;
            hash2[p[right]-'a']+=1;
            
            right+=1;           
            
        }
        
      right-=1;

      while(right<size1)
      {
          if(check(hash1,hash2))
            result.push_back(left);
          
          right=right+1;
          
          if(right!=size1)
              hash1[s[right]-'a']+=1;
          
          hash1[s[left]-'a']-=1;
          
          
          left=left+1;
          
      }
        
        return result;
        
    }
};
