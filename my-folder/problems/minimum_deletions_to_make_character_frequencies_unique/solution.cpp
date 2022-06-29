class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        unordered_map<int,int> mp;
        for(auto i:s)
        {
            v[i-'a']++; 
        }
        
        sort(v.begin(),v.end());
        for(auto i:v)
        {
            mp[i]++;  
        }
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            while(v[i]>=1 and mp[v[i]]>=2)
            {
                mp[v[i]]--;
                v[i]--;
                mp[v[i]]++;
                ans++;
            }
        }
        return ans;
    }
};