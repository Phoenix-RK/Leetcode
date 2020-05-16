//Phoenix_RK
/*
https://leetcode.com/problems/queens-that-can-attack-the-king/


On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.



*/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<int>> result;
        bool position[8][8];
        
        for(int i=0;i<8;i++)
        {
        
            for(int j=0;j<8;j++)
                position[i][j]=false;
        
        }
        
        
        for(int i=0;i<queens.size();i++)
        {
            position[queens[i][0]][queens[i][1]]=true;            
            
        }
        
        int directions[3]={-1,0,1};
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(directions[i]==0 && directions[j]==0)
                    continue;
                
                 int x=king[0];
                 int y=king[1];
                
               while(x+directions[i]>=0 && x+directions[i]<8 && y+directions[j]>=0 && y+directions[j]<8)
               {
                   x=x+directions[i];
                   y=y+directions[j];
                   
                   if(position[x][y]==true)
                   {
                       result.insert(result.begin(),{x,y});
                       break;
                   }
                   
               }   

                
            }
        }
        return result;
    
    }
};
        
   
