class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //by pigeonhole maximum length possible is 26
        map<char,int> freq;
        int j = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
           if(freq[s[i]]==1)
           {
               while(freq[s[i]]==1)
               {
                   freq[s[j]]--;
                   j++;
               }
           }
           freq[s[i]]++;
           ans = max(ans,i-j+1);
        }
        return ans;
    }
};