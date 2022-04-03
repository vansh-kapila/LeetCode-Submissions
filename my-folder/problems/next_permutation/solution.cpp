class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        multiset<int> s;
        for(int i=nums.size()-1;i>=0;i--)
        {
            s.insert(nums[i]);
            auto it = s.upper_bound(nums[i]);
            if(it!=s.end())
            {   nums[i]=*it;
                s.erase(it);
                for(int j=i+1;j<nums.size();j++)
                {
                    nums[j] = *s.begin();
                    s.erase(s.begin());
                }
                break;
            }
        }
        if(!s.empty())
        {
            sort(nums.begin(),nums.end());
        }
    }
};