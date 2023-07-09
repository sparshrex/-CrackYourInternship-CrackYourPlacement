class Solution {
public:
int strStr(string haystack, string needle) {
int  i= haystack.size(),j = needle.size();


int pos = haystack.find(needle,0);

if(pos!=string::npos)
return pos;

return -1;

}
};