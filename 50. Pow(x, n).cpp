//Phoenix_RK


/*

https://leetcode.com/problems/powx-n/


Implement pow(x, n), which calculates x raised to the power n (xn).

*/


class Solution {
public:
    /*
    for odd  n x^n = x* (x^(n/2)) * (x^(n/2))
    for even n x^n = (x^(n/2)) * (x^(n/2))
    if n<0 & odd then (1/x) *  (x^(n/2)) * (x^(n/2))
    
    */
    double myPow(double x, int n) {
        
        if(n==0)
            return 1;
               
        double partial =myPow(x,n/2);
        double base;
        
        if(n<0)
            base=1/x;
        else
            base=x;
        
        
        return n%2==0 ? partial*partial : base*partial*partial;
    }
};
