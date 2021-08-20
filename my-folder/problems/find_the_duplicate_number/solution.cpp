class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        unordered_set<int> s;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
                continue;
            }
                else{
                ans =  nums[i];
                    break;}
            
        }
        
        
        return ans;
        
    }
};