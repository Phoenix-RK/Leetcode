//Phoenix_RK
/*

https://leetcode.com/problems/can-place-flowers/



Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.


Input: flowerbed = [1,0,0,0,1], n = 2
Output: False


1,0,0,0,0,0,1

2
*/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if(n>flowerbed.size())
          return false;
        
        for(int i=0;i<flowerbed.size() && n>0;)
        {
             if(flowerbed[i]!=1 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0))
             {
                 n--;
                 flowerbed[i]=1;        
                 i=i+2;
             }
            else
                i++;
        }
  
        if(n>0)
            return false;
       return true;
    }
};
