class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s(nums.begin(),nums.end());
        while(1)
        {
            if(s.find(original)==s.end())
            {
                return original;
            }
            original = original*2;
        }
        return -1;
    }
};