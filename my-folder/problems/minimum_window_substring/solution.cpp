class Solution
{
    public:
    unordered_map<char, int> mp;
    unordered_map<char, int> freq;
    bool check()
    {
        for (auto i: freq)
        {
            if (mp[i.first] < freq[i.first])
            {
                return 0;
            }
        }
        return 1;
    }
    string minWindow(string s, string t)
    {
        int j = 0;
        for (auto i: t)
        {
            freq[i]++;
        }
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            while (j < s.length() and check())
            {
                if (ans.empty() or i - j + 1 < ans.length())
                {
                    ans = s.substr(j, i - j + 1);
                }
                mp[s[j]]--;
                j++;
            }
        }
        return ans;
    }
};