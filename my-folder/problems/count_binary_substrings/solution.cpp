class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, pre = 0, cur = 1;
        for (int i = 1; i < s.length(); i++) 
        {
            if (s[i-1] != s[i]) 
            {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            } 
            else 
            {
                cur++;
            }
        }
        ans+=min(pre,cur);
        return ans;
    }
};