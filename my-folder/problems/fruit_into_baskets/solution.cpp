class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int j = 0;
        int ans = 0;
        for(int i=0;i<fruits.size();i++)
        {
            mp[fruits[i]]++;
            if(mp.size()>=3)
            {
                while(j<fruits.size() and mp.size()>2)
                {
                    mp[fruits[j]]--;
                    if(mp[fruits[j]]==0)
                    {
                        mp.erase(mp.find(fruits[j]));
                    }
                    j++;
                }
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};