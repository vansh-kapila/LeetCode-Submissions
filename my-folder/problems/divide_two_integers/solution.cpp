class Solution
{
    public:
        int divide(int x, int y)
        {
            long long l = 0;
            long long r = pow(2,31) + 7;
            long long a = x, b = y;
            if (x == 0)
            {
                return 0;
            }
            x = abs(x);
            y = abs(y);
            long long ans = 0;
            while (l < r)
            {
                long long mid = (l + r) / 2;
                if (y * mid <= x and(y) *(mid + 1) > x)
                {
                    ans = mid;
                    break;
                }
                else if (y * mid > x)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            long long lb = -1*pow(2,31);
            long long ub = pow(2,31) - 1;
            ans = ans *(x / a) *(y / b);
                if (ans < lb)
                {
                    return lb;
                }
                if (ans > ub)
                {
                    return ub;
                }
                return ans;
            }
        };