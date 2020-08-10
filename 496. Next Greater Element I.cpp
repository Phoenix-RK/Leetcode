//Phoenix_RK


/*

https://leetcode.com/problems/next-greater-element-i/

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
************************************************************


1)iterate for every element in the array
	->if the stack is not empty and the top of stack is less than a[i],then a[i] is the next greater element of s.top(). Therfore store that in a map
	->push the element into the stack if the stack is empty or s.top()>a[i]

2)if stack is not empty, it means that , no element is greter than the element present in the stack. Therfore, in map, for the keys in the stack store the values as -1;
*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     
        map<int,int> m;
        stack<int> s;
        for(int i=0;i<nums2.size();i++)
        {
            while(!s.empty() && s.top()<nums2[i])
            {
                m[s.top()]=nums2[i];
                s.pop();
            }
            
            s.push(nums2[i]);            
        }
        
        while(!s.empty())
        {
            m[s.top()]=-1;
            s.pop();
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};
