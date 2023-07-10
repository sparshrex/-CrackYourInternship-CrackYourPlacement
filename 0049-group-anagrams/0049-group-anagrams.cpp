class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
       map<string,vector<string>>m;
        
      for(int i =0;i<strs.size();i++)
      {
          string t = strs[i];
        sort(t.begin(),t.end());
          if(m.find(t)!=m.end())
          {
             m[t].push_back(strs[i]);
          }
          else
          {
            vector<string>newv;
            newv.push_back(strs[i]);
            m[t]= newv;
          }
      }
    //  vector<vector<string>>ans;
     for(auto it:m)
     {
       ans.push_back(m[it.first]);
     }
      


      return ans;

    }
};