class Solution {
public:
    
      string helper(int num)
    {
        if(num==0)return "";
        
        else if(num<20)return lessthan20[num] +" ";
        
        else if(num<100)return tens[num/10]+" "+helper(num%10);
        else
            return lessthan20[num/100]+" Hundred "+helper(num%100);
        
    }
    
    string lessthan20[20]={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        
     string tens[10]={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4]={"","Thousand","Million","Billion"};
                           
                           
    string numberToWords(int num) {
        
        
        if(num==0)
            return "Zero";
        
        string words;
        int i=0;
        while(num>0)
        {
            if(num%1000!=0)
            {
                words = helper(num%1000)+thousands[i]+" "+words;
            }
            num/=1000;
            i++;
        }
        
       auto end = words.find_last_not_of(" \t\n\r");

       return words.substr(0, end - 0 + 1);
        
    }
};