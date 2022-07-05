class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    for(int m=k+1;m<nums.size();m++)
                    {
                        if(nums[m]==nums[i]+nums[j]+nums[k])
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};