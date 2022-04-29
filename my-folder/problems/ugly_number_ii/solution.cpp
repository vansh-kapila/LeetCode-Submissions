class Solution
{
    public:
        int nthUglyNumber(int n)
        {
            set<int> s;
            for (int i = 0; i < 31; i++)
            {
                s.insert((int)pow(2, i));
            }
            for (int j = 0; j < 20; j++)
            {
                for (auto i: s)
                {
                    if ((long long)(i* pow(3, j)) > INT_MAX)
                    {
                        break;
                    }
                    s.insert(i *(long long) pow(3, j));     
                }
            }
            for (int j = 0; j < 14; j++)
            {
                for (auto i: s)
                {
                    if ((long long)(i* pow(5, j)) > INT_MAX)
                    {
                        break;
                    }
                    s.insert(i *(long long) pow(5, j)); 
                }
            }
            vector<int> v(s.begin(), s.end());
            return v[n - 1];
        }
};