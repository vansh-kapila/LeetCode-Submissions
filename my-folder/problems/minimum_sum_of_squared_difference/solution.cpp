class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> v(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            v[i]=abs(nums1[i]-nums2[i]);
        }
        map<int,int> mp;
        for(auto i:v)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:mp)
        {
            pq.push({i.first,i.second});
        }
        int x = k1+k2;
        while(x!=0)
        {
            if(pq.top().first<=0)
            {
                break;
            }
            auto it = pq.top();
            pq.pop();
            if(x>=it.second)
            {
                x = x-it.second;
                it.first--;
                if(!pq.empty() and pq.top().first==it.first)
                {
                    auto it2 = pq.top();
                    pq.pop();
                    it2.second+=it.second;
                    pq.push(it2);
                }
                else
                {
                    pq.push(it);
                }
            }
            else
            {
                pq.push({it.first,it.second-x});
                pq.push({it.first-1,x});
                x = 0;
            }
        }
        long long ans = 0;
        while(!pq.empty())
        { 
            ans = ans + (long long)pq.top().first*pq.top().first*(long long)pq.top().second;
            pq.pop();
        }
        return ans;
    }
};