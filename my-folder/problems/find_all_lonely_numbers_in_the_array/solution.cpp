class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        set<int> ms;
        map<int,int> mp;
        for(auto i:nums)
        {
            ms.insert(i);
            mp[i]++;
        }
        vector<int> v;
        for(auto i:ms)
        {
            if(ms.find(i-1)!=ms.end() or ms.find(i+1)!=ms.end() or mp[i]>1)
            {
                continue;
            }
            else
            {
                v.push_back(i);
            }
        }
        return v;
    }
};