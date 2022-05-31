class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre;
        pre.push_back(0);
        for(auto i:arr)
        {
            pre.push_back((pre.back()^i));
        }
        
        vector<int> ans;
        for(auto i:queries)
        {
            ans.push_back(pre[i[0]]^pre[i[1]+1]);
        }
        return ans;
    }
};