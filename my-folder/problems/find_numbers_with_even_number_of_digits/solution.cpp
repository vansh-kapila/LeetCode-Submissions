class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto i:nums)
        {
            count=count+(int)log10(i)%2;
        }
        return count;
    }
};