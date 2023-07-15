class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    int mod = pow(10,9)+7;
    int  n = arr.size();
    stack<int>st;
    vector<int>pse(n);
    vector<int>nse(n);


    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        pse[i]=0;
        else
        pse[i]=st.top()+1;

        st.push(i);
    }

        //empty the stack
        while (!st.empty())
        st.pop();

        for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty())
        nse[i]=n-1;
        else
        nse[i]=st.top()-1;

        st.push(i);
    }
        
        
    long long ans =0;
        
        for(int i=0;i<n;i++)
        {
            
            long long int k = (i-pse[i])+(nse[i]-i)+1;
            
            long long int p=    (long long) (i-pse[i])*(long long)(nse[i]-i);
            k+=p;
            
            ans+=(arr[i]*k)%mod;
            ans= ans%mod;
        }
        
        
        return ans;
    }
};