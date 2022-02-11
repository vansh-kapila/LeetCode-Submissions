class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
        {
            vector<int> ans;
            return ans;
        }
        vector<int> s1(26,0);
        vector<int> s2(26,0);
        vector<int> ans;
        for(int i=0;i<p.size();i++)
        {
            s1[s[i]-'a']++;
            s2[p[i]-'a']++;
        }
        if(s1==s2)
        {
            ans.push_back(0);
        }
        for(int i=p.size();i<s.size();i++)
        {
            s1[s[i-p.size()]-'a']--;
            s1[s[i]-'a']++;
            if(s1==s2)
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};