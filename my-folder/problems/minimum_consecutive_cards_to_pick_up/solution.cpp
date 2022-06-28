class Solution {
public: 
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> mp;
        int ans = 1e9+7;
        int j = 0;
        for(auto i:cards)
        {
            if(mp.find(i)==mp.end())
            {
                mp[i]=j;
            }
            else
            {
                ans = min(ans,j-mp[i]+1);
                mp[i]=j;
            }
            j++;
        }
        if(ans==1e9+7)
        {
            ans = -1;
        }
        return ans;
    }
};