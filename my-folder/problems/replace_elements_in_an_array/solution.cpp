class Solution {
public:
 
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        map<int,int> m;
        for(int i=operations.size()-1;i>=0;i--)
        {
            if(m[operations[i][1]]==0)
            {
                m[operations[i][0]]=operations[i][1];
            }
            else
            {
                m[operations[i][0]]=m[operations[i][1]];
            }
        }
        for(auto &i:nums)
        {
            if(m[i]!=0)
            {
                i=m[i];
            }
        }
        return nums;
    }
};