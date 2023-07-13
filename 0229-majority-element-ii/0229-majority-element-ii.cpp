class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
  int cnt1=0 ,ele1=0,cnt2=0,ele2=0;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(cnt1==0  && ele2 !=nums[i])
            {
                ele1 = nums[i];
                cnt1=1;
                
            }            

             else if(cnt2==0  && ele1 !=nums[i])
            {
                ele2 = nums[i];
                   cnt2=1;
                
            }
            else if(ele1==nums[i])cnt1++;
            else if(ele2 ==nums[i])cnt2++;
            else
            {
                cnt2--;
                cnt1--;
            }
        }
        int fcnt1=0,fcnt2=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i])
                fcnt1++;
            else if(ele2==nums[i])
                fcnt2++;
            
           
        }
         if(fcnt1>n/3)
         ans.push_back(ele1);
            
            if(fcnt2>n/3)ans.push_back(ele2);
        
        return ans;
    }
};