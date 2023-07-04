class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int>prefix(n+1,0);
        vector<int>suffix(n+1,0);
        int sum =0;
       for(int i=0;i<n;i++)
       {
           sum+=a[i];
           prefix[i+1]=sum;
       }
        sum =0;
       for(int i =n-1;i>=0;i--)
       {
           sum+=a[i];
           suffix[i]=sum;
       }
        int maxi =0;
       for(int i =k;i>=0;i--)
       {
           maxi =max(maxi,prefix[i]+suffix[n-(-i+k)]);
       }

       return maxi;
    }
};