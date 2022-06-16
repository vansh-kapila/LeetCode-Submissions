class Solution
{
    public:
        string reverseWords(string &s)
        {
            vector<string> store;
            string x;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != ' ')
                {
                    x.push_back(s[i]);
                }
                else
                {
                    if (!x.empty())
                    {
                        store.push_back(x);
                        x.clear();
                    }
                }
            }
            if (!x.empty())
            {
                store.push_back(x);
            }
            reverse(store.begin(), store.end());

            string ans;
            for (auto i: store)
            {
                ans.append(i);
                ans.push_back(' ');
            }
            ans.pop_back();
            return ans;
        }
};