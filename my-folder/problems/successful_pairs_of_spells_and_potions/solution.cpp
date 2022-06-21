class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        vector<long long> factor;
        for(int i=0;i<potions.size();i++)
        {
            factor.push_back((success+potions[i]-1)/potions[i]);
        }
        sort(factor.begin(),factor.end());
        for(auto i:spells)
        {
            ans.push_back((upper_bound(factor.begin(),factor.end(),i)-factor.begin()));
        }
        return ans;
    }
};