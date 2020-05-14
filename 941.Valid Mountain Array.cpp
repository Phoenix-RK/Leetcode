//Phoenix_RK

/*

https://leetcode.com/problems/valid-mountain-array/


Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

*/

class Solution {
public:
    int find_pivot(vector<int> A)
    {
        int max=INT_MIN,id;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>max)
            {
                id=i;
                max=A[i];
            }   
            
        }
        return id;
    }
    bool check_left(int l,int r,vector<int> A)
    {
        if(l==r)
            return true;
        for(int i=l;i<r;i++)
        {
            if(A[i]==A[i+1] || A[i]>A[i+1])
                return false;
        }
        return true;
    }
     bool check_right(int l,int r,vector<int> A)
    {
        if(l==r)
            return true;
        for(int i=l;i<r;i++)
        {
            if(A[i]==A[i+1] || A[i]<A[i+1])
                return false;
        }
         return true;
    }
    
    bool validMountainArray(vector<int>& A) {
        
       int ind=find_pivot(A);
        cout<<ind;
      if (A.size()==0 || ind==0 || ind==A.size()-1)
          return false;
       return( A[ind]>A[ind+1] && check_left(0,ind,A) && check_right(ind+1,A.size()-1,A));
  
      
        
    }
};
