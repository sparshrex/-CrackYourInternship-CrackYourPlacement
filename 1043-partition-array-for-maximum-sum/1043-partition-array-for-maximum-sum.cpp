class Solution {
public:

    int f(int i ,vector<int>&arr,int k,vector<int>&dp)
    {   int n = arr.size();
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=INT_MIN;
        int len =0;
        int maxsum = INT_MIN;
        for(int j=i;j<min(n,i+k);j++)
        {   len++;
            maxi= max(maxi,arr[j]);
            int sum =len*maxi+f(j+1,arr,k,dp);
            maxsum = max(sum,maxsum);
        }
        return dp[i]=maxsum;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
       return f(0,arr,k,dp);
    }
};