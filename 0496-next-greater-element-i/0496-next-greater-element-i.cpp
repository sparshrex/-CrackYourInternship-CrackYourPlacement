class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n= nums2.size();
        unordered_map<int,int>m;
        vector<int>nge(n);
        stack<int>st;
        vector<int>ans;
        for(int i =n-1;i>=0;i--)
        {
            while(!st.empty() &&nums2[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                m[nums2[i]]=-1;
            }
            else{
                m[nums2[i]]=st.top();
            }
           st.push(nums2[i]);
        }

       for(int i=0;i<nums1.size();i++)
       {
            int ele = nums1[i];
           if(m.find(ele)!=m.end())
           {
               ans.push_back(m[ele]);
           }
       }

        return ans;
    }
};