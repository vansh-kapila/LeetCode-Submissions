class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]*((nums[i]&1)+1));
        }
        int ans = 10000000007;
        while((*s.rbegin()&1)==0)
        {   
            int x = *s.rbegin();
            s.erase(*s.rbegin());
            s.insert(x/2);
            ans = min(ans,*s.rbegin()-*s.begin());
        }
        return ans = min(ans,*s.rbegin()-*s.begin());
    }
};