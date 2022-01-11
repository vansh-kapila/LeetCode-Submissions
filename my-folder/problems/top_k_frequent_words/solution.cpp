class Solution {
public:
    static bool comp(pair<int,string> p,pair<int,string> q)
    {
        if(p.first>q.first)
        {
            return true;
        }
        if(p.first==q.first)
        {
            return p.second<q.second;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> v;
        
        map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        
        for(auto i:m)
        {
            v.push_back(make_pair(i.second,i.first));
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