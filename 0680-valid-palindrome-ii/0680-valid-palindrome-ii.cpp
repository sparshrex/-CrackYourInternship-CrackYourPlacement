class Solution {
public:
    bool validPalindrome(string s) {
        int n =s.size();
        int i =0,j =n-1;
        int cnt =0;
        int cnt2=0;
        int ans= 0;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                
                if(s[j-1]==s[i])
                {
                    j--;
                }
                else
                {
                    i++;
                }
                cnt++;
            }
        }
        i =0,j = n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                
                if(s[j-1]==s[i])
                {
                    i++;
                }
                else
                {
                    j--;
                }
                cnt2++;
            }
        }
        ans = min(cnt,cnt2);
        if(ans<=1)return true;
        return false;
    }
};