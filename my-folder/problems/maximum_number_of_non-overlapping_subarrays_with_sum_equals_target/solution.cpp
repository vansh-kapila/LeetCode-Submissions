class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> sum;
        int count = 0;
        int s = 0;  
        for(int i=0;i<nums.size();i++)
        {   s=s+nums[i];
            if(sum[s-target]>0)
            {
                sum.clear();
                count++;
                s=0; 
            }
            else if(s==target)
            {
                sum.clear();
                count++;
                s=0;
            }
            else
            { 
             sum[s]++;
            }
        }
        return count;
    }
};