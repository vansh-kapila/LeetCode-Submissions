class Solution {
public:
    static bool second(pair<int,int> x,pair<int,int> y)
    {
        if(x.second<y.second)
        {
            return true;
        }
        if(x.second==y.second)
        {
            return x.first<y.first;
        }
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>> v;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(arr[i],__builtin_popcount(arr[i])));
        }
        
        sort(v.begin(),v.end(),second);
        
        for(int i=0;i<n;i++)
        {
            arr[i]=v[i].first;
        }
        
        return arr;
        
    }
};