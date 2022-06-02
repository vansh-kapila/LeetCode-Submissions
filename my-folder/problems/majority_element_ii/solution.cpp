class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {   int n = nums.size();
            int ans1 = 987654321, ans2 = 987654321;
            int count1 = 0;
            int count2 = 0;
            for (auto i: nums)
            {
                if (i == ans1)
                {
                    count1++;
                }
                else if (i == ans2)
                {
                    count2++;
                }
                else if (count1 == 0) 
                {
                    ans1 = i;
                    count1++;
                }
                else if (count2 == 0) 
                {
                    ans2 = i;
                    count2++;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
            
            int check1 = 0,check2 = 0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==ans1)
                {
                    check1++;
                }
                if(nums[i]==ans2)
                {
                    check2++;
                }
            }
            
            if(check1>(n/3) and check2>n/3)
            {
                return {ans1,ans2};
            }
            if(check2>n/3)
            {
                return {ans2};
            }
            if(check1>(n/3))
            {
                return {ans1};
            }
            return {};
        }
};