class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        vector<string> v;
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                v.push_back(str);
                str.clear();
                continue;
            }
            str.push_back(s[i]);
        }
        v.push_back(str);
        map<string,char> mp2; 
        if(v.size()!=pattern.length())
        {
            return 0;
        }
        for(int i=0;i<v.size();i++)
        { 
            if(mp.find(pattern[i])==mp.end() and mp2.find(v[i])==mp2.end())
            {
                mp[pattern[i]]=v[i];
                mp2[v[i]]=pattern[i];
            }
            else if(mp[pattern[i]]!=v[i] or mp2[v[i]]!=pattern[i])
            {
                return 0;
            }
        }
        return 1;
    }
};