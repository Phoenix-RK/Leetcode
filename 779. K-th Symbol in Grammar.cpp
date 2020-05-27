//Phoenix_RK
/*


https://leetcode.com/problems/k-th-symbol-in-grammar/

On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).


01101001
*/

class Solution {
public:
    
    int kthGrammar(int N, int K) 
    {
        long num=pow(2,N-1),flips=0;
        
        while(num>2)
        {
             if(K>num/2)
             {
                 K=K-num/2;
                 flips++;
             }
            
            num= num/2;
        }
        
        K--;
       
        return (flips%2==0)? K : 1-K;

        
    }
};
