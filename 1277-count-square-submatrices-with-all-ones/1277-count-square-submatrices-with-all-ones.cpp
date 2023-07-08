class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int m1 = m.size();
        int n = m[0].size();
        vector<vector<int>>dp(m1,vector<int>(n,0));
        for(int i =0;i<m1;i++)dp[i][0]=m[i][0];

        for(int j =0;j<n;j++)dp[0][j]=m[0][j];


        for(int i =1;i<m1;i++)
        {
            for(int j= 1;j<n;j++)
            {
                if(m[i][j]==0)dp[i][j]=0;
                else{
                    dp[i][j]= 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }

        int sum =0;

        for(auto &i:dp)
        {
            for(auto &j:i)
            {
                sum+=j;
            }
        }

        return sum;
    }
};