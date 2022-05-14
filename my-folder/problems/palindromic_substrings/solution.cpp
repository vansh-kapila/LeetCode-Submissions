class Solution
{
    public:
        int countSubstrings(string s)
        {
            int ans = 0;
            for (int i = 0; i < s.length(); i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (i >= j and i + j < s.length() and s[i + j] == s[i - j])
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for (int i = 0; i < s.length(); i++)
            {
                for (int j = 1; j <= i+1; j++)
                {
                    if (i-j+1>=0 and i-j+1<s.length() and i + j < s.length() and s[i + j] == s[i - j + 1])
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return ans;
        }
};