class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int index = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                index = i;
                break;
            }
        }
        int count = 0;
        for(int i=index;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                count++;
            }
            else
            {
                break;
            }
        }
        
        return count;
    }
};