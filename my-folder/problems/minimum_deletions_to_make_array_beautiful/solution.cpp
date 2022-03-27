class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int op = 0;
        int count = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i%2==op and nums[i]==nums[i+1])
            {
                count++;
                op = (op^1);
            }
        }
        return count+(nums.size()-count)%2;
    }
};