class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int ans = 0;
        map<int,int> m;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==key)
            {
                m[nums[i+1]]++;
            }
        }
        int f = 0;
        for(auto i:m)
        {
            if(i.second>f)
            {
                ans = i.first;
                f=i.second;
            }
            if(i.second==f)
            {
                ans = max(i.first,ans);
            }
        }
        return ans;
    }
};