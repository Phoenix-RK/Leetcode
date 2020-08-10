//Phoenix_RK

/*

https://leetcode.com/problems/permutations/
https://www.youtube.com/watch?v=nYFd7VHKyWQ

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


*/


class Solution {
public:
    void permutation(int* key,int* count,int index,int level,vector<vector<int>> &x,vector<int> sub_res)
    {
     
        if(level == sub_res.size())
        {
            x.push_back(sub_res); 
            cout<<endl;
            return;
        }
        
        for(int i=0;i<index;i++)
        {
            if(count[i]==0)
                continue;
            
            sub_res[level]= key[i];
            count[i]--;
            permutation(key,count,index,level+1,x,sub_res);
            count[i]++;
            
        }
        
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
                m[nums[i]]=1;
            else
                m[nums[i]]++;
        }
        int* key = new int[m.size()];
        int* count=new int[m.size()];
        int index=0;      
        for(auto it=m.begin();it!=m.end();it++)
        {
           
            key[index]= it->first;
            count[index] = it->second;
            index++;
        }
                  
      for(int i=0;i<index;i++)
        {
            cout<<key[i]<<" "<<count[i]<<endl;

        }
        vector<vector<int>> x;
        vector<int> sub_res(nums.size());
       
        int level=0;
        permutation(key,count,index,level,x,sub_res);
        
        return x;
        
    }
};
