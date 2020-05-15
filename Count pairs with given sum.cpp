//Phoenix_RK
/*
Given an array of integers, and an integer  ‘K’ , find the count of pairs of elements in the array whose sum is equal to 'K'.


Input
2
4 6
1  5  7 1
4 2
1 1 1 1
Output
2
6

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
     int T,n;
	cin>>T;
	while(T--)
	{
	    int sum;
	    cin>>n>>sum;
	    int a[n],count=0;
	    map<int,int> m;
	    
	    for(int i=0;i<n;i++)
	   {
	       cin>>a[i];
	        m[a[i]]++;
	   }
	   
	   for(int i=0;i<n;i++)
	   {
	       count+=m[sum-a[i]];
	        
	       if(sum-a[i]==a[i])
	          count--;
	   }
	   
	   cout<<count/2<<endl;
	
	}
	return 0;
}
