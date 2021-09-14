class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set <char> set;
         int k = 0;
         int ans = 0;
        for(int i=0;i<s.length();i++)
        {  
           if(set.find(s[i])==set.end())
           {   
               
               set.insert(s[i]);
               ans = max(ans,i-k+1);
           }
           else
           {
               set.erase(s[k++]);
               i--;
           }
        }
        
        return ans;
    }
};