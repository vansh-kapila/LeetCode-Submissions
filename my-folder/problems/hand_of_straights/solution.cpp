class Solution
{
    public:
        bool isNStraightHand(vector<int> &hand, int groupSize)
        {
            multiset<int> s(hand.begin(), hand.end());
            while (s.size() >= groupSize)
            {
                int x = *s.begin();
                for (int i = x; i <= x + groupSize - 1; i++)
                {
                    if (s.find(i) == s.end())
                    {
                        return false;
                    }
                    else
                    {
                        s.erase(s.find(i));
                    }
                }
            }
            return s.size() == 0;
        }
};