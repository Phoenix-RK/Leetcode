//Phoneix_RK

/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
*/
 
class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int dpG[rating.size()],dpL[rating.size()];
        
        int res=0;
        //keep track of how many elements are smaller than this number
        for(int i=0;i<rating.size();i++)
        {
            dpG[i]=0;
            for(int j=0;j<i;j++)
            {
                if(rating[i]>rating[j])
                {
                    dpG[i]++;
                    res=res+dpG[j]; // team is considered when the middle element is found
                }
            }
        }
        
/*        for(int i=0;i<rating.size();i++)
            cout<<dpG[i]<<" ";
        cout<<endl;
  */      
        //keeps tracks of larger than this number 
         for(int i=0;i<rating.size();i++)
        {
             dpL[i]=0;
            for(int j=0;j<i;j++)
            {
                if(rating[i]<rating[j])
                {
                    dpL[i]++;
                    res=res+dpL[j];
                }
            }
        }
        
          
     /*   for(int i=0;i<rating.size();i++)
            cout<<dpL[i]<<" ";
        cout<<endl;
       */ 
        return res;
    }
};
