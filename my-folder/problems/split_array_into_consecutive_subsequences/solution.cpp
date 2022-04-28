class Solution
{
    public:
        bool isPossible(vector<int> &nums)
        {
            multiset<int> ms(nums.begin(), nums.end());
            int x = *ms.rbegin(); 
            multiset<int> track;
            while (!ms.empty())
            {   
                x = *ms.rbegin(); 
                if(track.find(x)!=track.end())
                {
                    ms.erase(ms.find(x));
                    track.erase(track.find(x));
                    track.insert(x-1);
                }
                else if (ms.size() >= 3 and ms.find(x) != ms.end() and ms.find(x - 1) != ms.end() and ms.find(x - 2) != ms.end())
                {
                    ms.erase(ms.find(x));
                    ms.erase(ms.find(x - 1));
                    ms.erase(ms.find(x - 2)); 
                    track.insert(x-3);
                }
                else
                {
                    return false;
                }   
            }
            return ms.empty();
        }
};