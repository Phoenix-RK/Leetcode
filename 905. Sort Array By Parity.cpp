//Phoneix_RK


/*

https://leetcode.com/problems/sort-array-by-parity/


Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

*/


class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0,j=A.size()-1;

        int temp;
        while(i<j)
        { 
           
            if(A[i]%2>A[j]%2)
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;   
            }                       

                
            while(A[i]%2==0 && i<j)
                i++;
            while(A[j]%2==1 && i<j)
                j--;
            
        }
        
     return A;   
    }
};

   
