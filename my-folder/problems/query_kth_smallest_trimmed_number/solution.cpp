class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
         vector<vector<pair<string,int>>> v(nums[0].length()+1);
         for(int i = 0;i<nums.size();i++)
         { 
             int k = 0;
             for(int j=0;j<nums[i].length();j++)
             {
                 v[j].push_back({nums[i].substr(nums[i].length()-j-1,j+1),i});  
             }
         } 
        for(auto &i:v)
        {
            sort(i.begin(),i.end());
        } 
        vector<int> ans;
        for(auto i:queries)
        {
            ans.push_back(v[i[1]-1][i[0]-1].second);
        }
        return ans;
    }
};