class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            vector<int> maxleft(n);
            vector<int> maxright(n);
            maxleft[0] = height[0];
            for (int i = 1; i < n; i++)
            {
                maxleft[i] = max(maxleft[i - 1], height[i]);
            }
            maxright[n - 1] = height[n-1];
            for (int i = n - 2; i >= 0; i--)
            {
                maxright[i] = max(maxright[i + 1], height[i]);
            }

            int ans = 0;
            for (int i = 1; i < n - 1; i++)
            {
                int incr = min(maxright[i + 1], maxleft[i - 1])-height[i];
                if(incr>0)
                {
                    ans+=incr;
                }
            }
            return ans;
        }
};