class Solution {
public:
    int findDuplicate(vector<int>& a) {
    //    int n = nums.size();
       int ans =-1;
        for(int i=0;i<a.size();i++)
        {
            int curr = abs(a[i]);


            if(a[curr]<0)
            {

            ans =curr;
            break;
            }
            a[curr]*=-1;

        }

        for(auto &num :a)
        {
            num = abs(num);
        }
        return ans;

    }
};