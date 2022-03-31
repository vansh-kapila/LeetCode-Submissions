class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]=i;
        }
        int ans = 0;
        vector<int> anss;
        int prev = 0;
        for(int i=0;i<s.length();i++)
        {
            ans = max(ans,m[s[i]]);
            if(ans==i)
            {
                anss.push_back(ans+1-prev);
                prev = ans+1;
                continue;
            }
        }
        return anss;
    }
};