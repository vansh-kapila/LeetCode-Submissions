class Solution {
public:
    long long appealSum(string s) {
        
        vector<int> last(26,-1);
        long long ans = 0;
        for(int i=0;i<s.length();i++)
        {
            ans = ans+(long long)((s.length()-i)*(i-last[s[i]-'a']));
            last[s[i]-'a']=i;
        }
        return ans;
    }
};