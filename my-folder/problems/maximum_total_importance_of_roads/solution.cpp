class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> m;
        for(auto &i:roads)
        {
            m[i[0]]++;
            m[i[1]]++;
        }
         
        vector<long long> v;
        for(auto i:m)
        {
            v.push_back(i.second);
        }
        long long ans = 0;
        sort(v.begin(),v.end(),greater<int>());
        long long x = n;
        for(auto i:v)
        {
            ans=ans+x*i;
            x--;
        }
        return ans;
    }
};