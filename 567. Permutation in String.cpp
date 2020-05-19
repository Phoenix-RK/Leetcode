//Phoenix_RK

/*

https://leetcode.com/problems/permutation-in-string/

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        int size1=s1.size();
        int size2=s2.size();
        
        int left=0,right=0;
        if(size1>size2)
            return false;
        while(right<size1)
        {
            hash1[s1[right]-'a']+=1;
            hash2[s2[right]-'a']+=1;
            
            right+=1;           
            
        }
        right-=1;
      while(right<size2)
      {
          if(hash1==hash2)
            return true;
          
          right=right+1;
          
          if(right!=size2)
              hash2[s2[right]-'a']+=1;
          
          hash2[s2[left]-'a']-=1;
          
          
          left=left+1;
          
      }
        
        
        return false;
        
    }
};
