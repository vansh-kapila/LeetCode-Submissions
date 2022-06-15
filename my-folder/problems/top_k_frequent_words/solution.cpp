class Solution {
public:
    static bool comp(pair<int,string> x,pair<int,string> y)
    {
        if(x.first==y.first)
        {
            return x.second<y.second;
        }
        return x.first>y.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> v;
        map<string,int> m;
        for(auto i:words)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),comp);
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};