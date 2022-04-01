class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> v;
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        string ans;
        for(auto i:v)
        {
            for(int j=0;j<i.first;j++)
            {
                ans.push_back(i.second);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};