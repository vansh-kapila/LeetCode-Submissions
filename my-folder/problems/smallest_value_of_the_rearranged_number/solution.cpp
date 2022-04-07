class Solution
{
    public:
        long long smallestNumber(long long num)
        {
            vector<int> v;
            for(int i=0;i<10;i++)
            {
                v.push_back(0);
            }
            long long dup = abs(num);
            while (dup != 0)
            {
                v[(dup % 10)]++;
                dup = dup / 10;
            }
            long long ans = 0;
            if (num < 0)
            {
                for (int i = 9; i >= 0; i--)
                {
                    while (v[i] > 0)
                    {
                        ans = ans *10 + i;
                        v[i]--;
                    }
                }
                return -1 * ans;
            }
            for (int i = 1; i < 10; i++)
            {
                while (v[i] > 0)
                {
                    ans = ans *10 + i;
                    v[i]--;
                    if (ans > 0)
                    {
                        while (v[0] > 0)
                        {
                            ans = ans * 10;
                            v[0]--;
                        }
                    }
                }
            }
            return ans;
        }
};