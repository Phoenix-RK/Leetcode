//Phoenix_RK

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*****************************************************************************
Sample testcase:

[100,4,200,1,3,2]
[0]
[]
[0,1,2,1]
[0,0]

Output:
4
1
0
3
1

******************************************************************************
Idea1:

1) sort the vector
2) iterate for every element in the array
	* if the next element is consecutive element of ith element, check further if the following elements are also consecutive. Keep increasing the length of the consecutive element array
	* if the length is greater than the length calculated starting from previous ith elements, then store the max of those

*************************************
Idea2:


Use hash map to store the no of consecutive elements 

for any i,

1) if i-1 and i+1 is not found, then the ith element is just a single element

2) if i-1 is alone found, then extend the m[i] and m[i-1] to each other (ie) m[i] + m[i - m[i-1]] +1 

3) if i+1 is alone found, then extend the m[i] and m[i+1] to each other (ie) m[i] + m[i + m[i+1]] +1

4) if both i-1 and i+1 are found, extend them to each other (ie) m[i] = m[i-1] = m[i+1] = 1+m[i-m[i-1] + m[i+m[i+1]] 
 
*****************************

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        sort(nums.begin(),nums.end());
        int len=INT_MIN,len_so_far=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            int k=i;
            len_so_far=1;
            for(int j=i+1;j<nums.size();j++)
            { 
                
                if(nums[j]==nums[k]+1)
                {
                    len_so_far++;
                    k=j;
                }
                else
                    break;
                while(j+1<nums.size() && nums[j]==nums[j+1])
                    j++;
            }
            len=max(len,len_so_far);
        }
        return len;
    }
};
