class Solution {
public:
    int earliestFullBloom(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({brr[i],arr[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int ans = 0;
        int time = 0;
        for(auto i:v)
        {
            time =  time + i.second;
            ans = max(ans,max(time,time+i.first));
        }
        return ans;
    }
};