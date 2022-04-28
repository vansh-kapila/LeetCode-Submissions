class Solution {
public:
    int countHomogenous(string s) { 
        long long x = 1;
        long long ans = 0;
        int mod = 1e9+7;
        for(int i=0;i<s.length();i++)
        {
            while(i+1<s.length() and s[i]==s[i+1])
            {
                x++;
                i++;
            }       
            ans=(ans+(x)*(x+1)/2)%mod;
            x=1;
        } 
        return ans;
    }
};