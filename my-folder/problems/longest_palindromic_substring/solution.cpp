class Solution
{
    public:
        string longestPalindrome(string s)
        {
           	//odd length palindrome
            int maxx = 0;
            string pal;
            for (int i = 0; i < s.length(); i++)
            {
                int j = 1;
                int ans = 1;
                while (i - j >= 0 and i + j < s.length())
                {
                    if (s[i - j] == s[i + j])
                    {
                        ans += 2;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (maxx < ans)
                {
                    maxx = ans;
                    pal = s.substr(i - j + 1, maxx);
                }
            }
           	//even length palindrome  
            for (int i = 0; i < s.length() - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    int j = 1;
                    int ans = 2;
                    while (i - j >= 0 and i + j + 1 < s.length())
                    {
                        if (s[i - j] == s[i + j + 1])
                        {
                            ans += 2;
                            j++;
                        }
                        else
                        { 
                            break;
                        }
                    }
                    if (maxx < ans)
                    {
                        maxx = ans;
                        pal = s.substr(i - j + 1, maxx);
                    }
                }
            }
            return pal;
        }
};