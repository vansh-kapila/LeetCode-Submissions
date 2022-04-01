class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=v.size()-1;ans.size()!=k;i--)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};