class Solution {
public:
    const long long mod = 1e9+7;
    int distinctSubseqII(string s) {
        unordered_map<char,long long> mp;
        long long ans = 0;
        long long prev = 0;
        for(int i=0;i<s.length();i++)
        {
            ans = (2*prev+1-mp[s[i]]+mod)%mod;
            mp[s[i]]=(mp[s[i]]+ans-prev)%mod;
            prev = ans;
        }
        return ans;
    }
};