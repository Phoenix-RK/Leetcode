//Phoenix_RK


/*

https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/


Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]

*/


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
     
        int max_ele=arr[arr.size()-1];
        arr[arr.size()-1]=-1;

        for(int i=arr.size()-2;i>=0;i--)
        {
          int curr_max=max_ele;
            max_ele=max(max_ele,arr[i]);
            arr[i]=curr_max;            
            
        }
  
        return arr;
    }
};
