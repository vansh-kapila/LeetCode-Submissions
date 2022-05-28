class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            map<string, vector < string>> m;
            for (auto &it: strs)
            {
                string temp = it;
                sort(temp.begin(), temp.end());
                m[temp].push_back(it);
            }
            vector<vector < string>> ans(m.size());
            
            int j = 0;
            for (auto &it: m)
            {
                for (int i = 0; i < it.second.size(); i++)
                {
                    ans[j].push_back(it.second[i]);
                }
                j++;
            }
            return ans;
        }
};