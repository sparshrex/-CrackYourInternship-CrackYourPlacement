class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
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
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        nse[i]=n-1;
        else
        nse[i]=st.top()-1;

        st.push(i);
    }

    int area =0;

    for(int i=0;i<n;i++)
    {
        area=max(area,arr[i]*(nse[i]-pse[i]+1));
    }

    return area;
    }
};