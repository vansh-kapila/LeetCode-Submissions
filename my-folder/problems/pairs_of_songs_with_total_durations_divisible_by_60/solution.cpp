class Solution
{
    public:
        int numPairsDivisibleBy60(vector<int> &time)
        { 
            unordered_map<int,int> mp;
            for (int i = 0; i < time.size(); i++)
            {
                time[i] %= 60; 
                mp[time[i]]++;
            }
            int ans = 0;
            for (auto i: time)
            {
                if (i != 0 and mp[60-i]>0)
                {    
                    mp[i]--;
                    ans += mp[60-i];
                }
                else if(i==0 and mp[0]>0)
                {
                    ans += mp[0]-1; 
                    mp[0]--;
                } 
            }
            return ans;
        }
};