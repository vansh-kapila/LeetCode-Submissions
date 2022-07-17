class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdd = 0;
        for(auto i:numsDivide)
        {
            gcdd = __gcd(gcdd,i);
        }
        sort(nums.begin(),nums.end());
        int count = 0;
        for(auto i:nums)
        {
            if(gcdd%i==0)
            {
                return count;
            }
            else
            {
                count++;
            }
        }
        return -1;
    }
};