class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        map<int,unordered_set<int>> mp;
        map<int,vector<int>> mp2;
        sort(passengers.begin(),passengers.end(),greater<int>());
        int lastboarded = -1;
        vector<pair<int,int>> v;
        set<int> s(passengers.begin(),passengers.end());
        sort(buses.begin(),buses.end());
        for(auto i:buses)
        { 
            for(int j=0;j<capacity;j++)
            {
                if(!passengers.empty() and passengers.back()<=i)
                {
                   // cout<<passengers.back()<<' '<<i<<endl;
                    mp[i].insert(passengers.back());
                    mp2[i].push_back(passengers.back());
                    passengers.pop_back();
                }
                else
                {
                    break;
                }
            }
        }
        
        int ans = 0;
        for(auto i:buses)
        { 
            auto j = mp[i];
            //cout<<i<<' '<<j.size()<<endl;
            if(j.size()<capacity)
            { 
                int t = i;
                for(int k=t;k>=0;k--)
                {
                    if(j.find(k)==j.end() and s.find(k)== s.end())
                    {
                        ans = max(ans,k);
                        break;
                    }
                } 
            }
            else
            {
                int t = mp2[i][capacity-1];
                for(int k=t;k>=0;k--)
                {
                    if(j.find(k)==j.end() and s.find(k)== s.end())
                    {
                        ans = max(ans,k);
                        break;
                    }
                } 
            }
        }
        return ans;
    }
};