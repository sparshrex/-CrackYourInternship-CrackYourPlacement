class Solution {
public:

    bool search(int i,int j ,int m,int n,vector<vector<char>>& board,string word,   int k )
    {
        if(k==word.size())return true;
        if(i<0 or j<0 or i==m or j==n or board[i][j]!=word[k])return false;

        int x[]={1,-1,0,0};
        int y[] ={0,0,-1,1};
        board[i][j]='.';
        bool temp =false;
        for(int idx =0;idx<4;idx++)
        {
           temp = temp or search(i+x[idx],j+y[idx],m,n,board,word,k+1);
        }

        board[i][j]=word[k];

        return temp;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(search(i,j,m,n,board,word,0))return true;
                }
            }
        }
        return false;
    }
};