//Phoenix_RK


/*

https://leetcode.com/problems/reorganize-string/


Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].





*/


typedef pair<char,int> pd;
class compare
{
public:
    bool operator() (pair<char,int>  a, pair<char,int> b)
    {
        return a.second<b.second;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        map<char,int> m;
        string res="";
        
        for(auto i : S)
            m[i]++;
        
        priority_queue<pd,vector<pd>,compare> pq; 
        
        for(auto i : m)
        {
            pq.push({i.first,i.second});
        }
        
        while(pq.size()>1)
        {
            pd curr = pq.top();
            pq.pop();
            pd next = pq.top();
            pq.pop();
            res=res+curr.first+next.first; 
            
        
            m[curr.first]=curr.second-1;
            m[next.first]=next.second-1;
              
            if(m[curr.first]>0)
                pq.push({curr.first,m[curr.first]});
            if(m[next.first]>0)
                pq.push({next.first,m[next.first]});
            
        }
        if(!pq.empty())
        {
            pd curr = pq.top();
            pq.pop();
            if(curr.second>1)
                return "";
            res=res+curr.first;
        }
        return res;
    }
};
