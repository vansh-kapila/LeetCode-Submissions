class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        for(int i=0;i<haystack.length();i++)
        {
            if(needle[j]==haystack[i])
            {
                j++;
            }
            else
            {
                i=i-j;
                j=0; 
            }
            
            if(j==needle.length())
            {
                return i-j+1;
            }
        }
        return -1;
    }
};