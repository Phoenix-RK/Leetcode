//Phoenix_RK
/*
Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:

In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
Return an array containing the result for the given queries.



*/


class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> res;
        map<int,int> ind;
        for(int i=1;i<=m;i++)
            ind[i]=i-1;
        
       
        for(int it=0;it<queries.size();it++)
        {
            int currindex=ind[queries[it]];
            
            
            for(int i=1;i<=m;i++)
            {
                if(i==queries[it])
                {
                    res.push_back(currindex);
                    ind[queries[it]]=0; 
                }
                
               else if(ind[i]<currindex)
                    ind[i]++;
                
            }       
      /*      for(int i=1;i<=m;i++)
                cout<<i<<" ";
            
            cout<<endl;
            
            for(int i=1;i<=m;i++)
                cout<<ind[i]<<" ";
            
            cout<<endl<<endl;
        */    
            
        }
     
    return res;
    }
};


/*       1 2 3 4 5
        0 3 1 4 5
       
         3 1 2 1
    res  2 1
    
    
    map    1 2 3 4 5 6 7 8
           4 0 5 1 6 7 2 3
      
      
            8 7 4 2 8 1 7 7       
      res   7 7 5 4 
      
   */ 
