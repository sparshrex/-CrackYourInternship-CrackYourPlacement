class Solution {
public:
    bool isNumber(string s) {
      bool digitseen = false,eseen = false,dotseen= false;
      int cntplusminus=0;

      for(int i=0;i<s.size();i++)
      {
          char ch= s[i];
            
        //digit
        
        if(isdigit(ch))digitseen = true;


        //minus/plus <2
        else if(ch=='+'|| ch=='-') 
        {
            if(cntplusminus==2)return false;
            if(i>0 && (s[i-1]!='e' && s[i-1]!='E')) return false; 

            if(i==s.size()-1)return false;
            
            cntplusminus++;
        }

        //dot 
        else if(ch=='.'){
            if(eseen || dotseen)return false;

             if(i==s.length()-1 && !digitseen)
             return false;

             dotseen = true;
        }


        //e/E    //not valide 2e/ , e at last, e3

        else if (ch=='e'  || ch =='E')
        {
            if(eseen || !digitseen || i==s.size()-1)return false;
            
            eseen = true;
        }
        else
        {
            return false;
        }



      }
      return true;

    }
};