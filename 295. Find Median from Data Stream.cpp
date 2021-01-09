//Phoenix_RK


/*


https://leetcode.com/problems/find-median-from-data-stream/


Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?




*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    
         priority_queue<int> maxH;
       priority_queue<int,vector<int>,greater<int>> minH;
 
    MedianFinder() {
     
    }
    
    void addNum(int x) {
        
        if(maxH.size()==0)
        {
             maxH.push(x);
             return ;            
        }  
        if(maxH.size()>minH.size())
        {
            if(x>maxH.top())
            {
                minH.push(x);
            }
            else
            {
                maxH.push(x);
                minH.push(maxH.top());
                maxH.pop();
            }
        }
        else
        {
            if(x<maxH.top())
                maxH.push(x);
            else
            {
                minH.push(x);
                maxH.push(minH.top());
                minH.pop();
                    
            }
        }
    
            
    }
    
    double findMedian() {
         if(maxH.size()>minH.size())
            return maxH.top()/1.0;
        else 
            return(maxH.top()+minH.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
