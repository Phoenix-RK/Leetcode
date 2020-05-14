//Phoenix_RK
//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
/*
Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
    
        int great=*max_element(candies.begin(),candies.end());
        vector<bool> possible;
       
        for(auto it=candies.begin();it!=candies.end();it++)
        {
            if(*it+extraCandies<great)
                possible.push_back(false);
            else
                possible.push_back(true);
        }
        return possible;
    }
};
