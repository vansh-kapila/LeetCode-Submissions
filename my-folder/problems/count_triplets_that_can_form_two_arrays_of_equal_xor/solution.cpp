class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int,vector<int>> mp;
        mp[0].push_back(0);
        int x = 0;
        int j = 1;
        for(auto i:arr)
        {
            x=(x^i);
            mp[x].push_back(j++);
        }
        int ans = 0;
        for(auto &i:mp)
        {
            for(int j=0;j<i.second.size();j++)
            {
                for(int k=j+1;k<i.second.size();k++)
                {
                    ans = ans + i.second[k] - i.second[j] - 1;
                }
            }
        }
        return ans;
    }
};