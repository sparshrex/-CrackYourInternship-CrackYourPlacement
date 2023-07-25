class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1);
        stringstream s1(version2);
        string token,token1;

        vector<int>v1,v2;

        while(getline(ss,token,'.'))
        {
            int x = stoi(token);
           v1.push_back(x);
        
        }

        while(getline(s1,token1,'.'))
        {

            int y = stoi(token1);
          v2.push_back(y);
        }

    

        int n = v1.size()<v2.size()? v1.size():v2.size();
        int m = v1.size()>v2.size()? v1.size():v2.size();

       if(n==v1.size())
       {
           for(int i =n;i<m;i++)
           v1.push_back(0);
       }
       if(n==v2.size())
       {
           for(int i =n;i<m;i++)
           v2.push_back(0);
       }

        for(int i=0;i<m;i++)
        {
            if(v1[i]<v2[i])return -1;
            else if(v2[i]<v1[i])return 1;
        }


        return 0;

    
    }
};