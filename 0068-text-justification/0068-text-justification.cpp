class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string>ans;
    int n= words.size();
    for(int i=0;i<words.size();)
    {

        int j = i+1;
        int wc= words[i].size();

        int can = 0;
        while(j<n && wc + can+ words[j].size()+1<=maxWidth)
        {
            wc+=words[j].length();
            can++;
            j++;

        }
        int space = maxWidth-wc;

        int atleast = can==0?0: space/can;
        int extra = can==0 ?0:space %can;

        if(j==n)
        {
            atleast =1;
            extra =0;
        }

        string temp;

        for(int k=i;k<j;k++)
        {
            temp+=words[k];
            if(k==j-1)break;
            for(int e =0;e<atleast;e++)temp+=" ";
            if(extra>0)
            {
                temp+=" ";
                extra--;
            }

        }
        i=j;


        while(temp.size()<maxWidth)temp+=" ";


        ans.push_back(temp);
    }

    return ans;
    }
};