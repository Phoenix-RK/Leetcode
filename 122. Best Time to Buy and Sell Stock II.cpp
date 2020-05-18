//Phoenix_RK


/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

//use peak valley approach


class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        
     //   int profit[prices.size()][prices.size()];
        //memset(profit,0,sizeof(profit));
        
      int profit=0,p=0;  
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                profit+=prices[i]-prices[i-1];
            
        }
        
        return profit;
        
    }
};
