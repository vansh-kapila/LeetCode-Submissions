class Solution {
public:
    int numSub(string s) {
        int ans = 0;
        int count = 1;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ans=(ans+(count++))%1000000007;
            }
            else
            {
                count=1;
            }
        }
        return ans;
    }
};