class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            string str, ptr;
            int count = 0;
            for (int i = s.length(); i >= 0; i--)
            {
                if (s[i] == '#')
                {
                    count++;
                }
                else if (count > 0)
                {
                    count--;
                    continue;
                }
                else
                {
                    str.push_back(s[i]);
                }
            }
            count = 0;
            for (int i = t.length(); i >= 0; i--)
            {
                if (t[i] == '#')
                {
                    count++;
                }
                else if (count > 0)
                {
                    count--;
                    continue;
                }
                else
                {
                    ptr.push_back(t[i]);
                }
            }
            return str == ptr;
        }
};