class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> m;
        map<char,int> m2;
        for(auto i:s)
        {
            m[i]++;
        }
        int ans = 10000000;
        for(auto i:target)
        {
            m2[i]++;
        }
        
        for(auto i:target)
        {
            ans = min(ans,m[i]/m2[i]);
        }
        return ans;
    }
};