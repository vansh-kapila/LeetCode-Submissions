class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++)
        {
            vector<int> v(26,0);
            for(auto j:strs[i])
            {
                v[(j-'a')]++;
            }
            mp[v].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto i:mp)
        {
            vector<string> v;
            for(auto j:i.second)
            {
                v.push_back(j);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};