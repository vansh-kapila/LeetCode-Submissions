class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        int ans = 0;
        if(nums.size()<3 or nums[nums.size()-1]==0)
        {
            return 0;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==0 or nums[j]==0)
                {
                    continue;
                }
         int x=upper_bound(nums.begin(),nums.end(),nums[i]+nums[j]-1)-nums.begin()-j-1;
               // cout<<nums[i]<<' '<<nums[j]<<' '<<x<<endl;
                ans = ans+x;
            }
        }
        return ans;
    }
};