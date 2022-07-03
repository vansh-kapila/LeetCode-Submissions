class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> mp;
        int j = 0;
        set<char> st;
        for(int i=0;i<key.size();i++)
        {
            if(st.find(key[i])==st.end() and key[i]!=' ')
            {
                mp[key[i]]=j+'a';
                j++;
                st.insert(key[i]);
            }
        }
        string ans;
        for(auto i:message)
        {
            if(i!=' ')
            {
                ans.push_back(mp[i]);
                continue;
            }
            ans.push_back(' ');
        }
        return ans;
    }
};