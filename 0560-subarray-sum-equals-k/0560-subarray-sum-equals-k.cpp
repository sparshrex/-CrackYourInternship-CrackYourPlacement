class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
         unordered_map<int,int> mp;
         int n = a.size();
       int prefixsum =0;
       int cnt = 0;

       mp[0]=1;

       for(int i =0;i<n;i++)
       {
           prefixsum+=a[i];
           cnt+=mp[prefixsum-k];
           mp[prefixsum]++;
       }
       return cnt;
    }
};