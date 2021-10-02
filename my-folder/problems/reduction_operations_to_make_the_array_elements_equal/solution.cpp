class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minnn = nums[0];
        int minn = nums[0];
        int count = 0;
        int k = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>minn)
            {   
                k++;
                count+=k;
                minn = nums[i];
            }
            else if(nums[i]==minn and nums[i]!=minnn)
            {
                count+=k;
            }
        }
        return count;
    }
};