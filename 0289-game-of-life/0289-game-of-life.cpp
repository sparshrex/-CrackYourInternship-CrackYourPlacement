class Solution {
public:
    
    bool valid(int i,int j,int m,int n)
    {
        if(i<0 || j<0 || j>=n || i>=m)return false;
      return true;
        
    }

 


    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(),n= board[0].size();
         int x[]={0,0,-1,1,1,-1,1,-1};
        int y[]={1,-1,0,0,1,-1,-1,1};
       for(int i =0;i<m;i++)
       {
           for(int j =0;j<n;j++)
           {
               int live =0;
            for(int index = 0;index<8;index++)
            {

            if(valid(i+x[index],j+y[index],m,n) && abs(board[i+x[index]][j+y[index]])==1){
            live++;
            }
            
            }

            if(board[i][j]==1 && (live < 2 || live >3))
            {
                board[i][j]=-1;
            }
            if(board[i][j]==0 && live==3)
            {
                board[i][j]=2;
            }
           }
       }

       for(int i=0;i<m;i++)
       {
           for(int j =0;j<n;j++)
           {
               if(board[i][j]<=0)board[i][j]=0;
               else
               board[i][j] = 1;
           }
       }
       
       
    }
};