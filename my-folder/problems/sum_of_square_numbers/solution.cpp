class Solution
{
    public:
        bool judgeSquareSum(int c)
        {
            for (int i = 0; i <= sqrt(c); i++)
            {
                if (sqrt(c - i *i) == (int) sqrt(c - i *i))
                {
                    return true;
                }
            }
            return false;
        }
};