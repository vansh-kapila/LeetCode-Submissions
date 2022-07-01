class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start;
        vector<int> endd;
        for(auto i:flowers)
        {
            start.push_back(i[0]);
            endd.push_back(i[1]);
        }
        //answer is number of elements less than i in start - number of elements less than i in end.
        sort(start.begin(),start.end());
        sort(endd.begin(),endd.end());
        vector<int> ans;
        for(auto i:persons)
        {
            auto it = upper_bound(start.begin(),start.end(),i)-start.begin();
            auto it2 = lower_bound(endd.begin(),endd.end(),i)-endd.begin();
            ans.push_back(it-it2);
        }
        return ans;
    }
};