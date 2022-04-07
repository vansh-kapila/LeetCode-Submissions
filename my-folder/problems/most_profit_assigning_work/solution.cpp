class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v(difficulty.size());
        for(int i=0;i<difficulty.size();i++)
        {
            v[i].first = difficulty[i];
        }
        for(int i=0;i<profit.size();i++)
        {
            v[i].second = profit[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<difficulty.size();i++)
        {
            difficulty[i] = v[i].first;
        }
        for(int i=0;i<profit.size();i++)
        {
            profit[i]=v[i].second;
        }
        vector<int> maxx(profit.size());
        maxx[0]=profit[0];
        for(int i=1;i<profit.size();i++)
        {
            maxx[i]=max(maxx[i-1],profit[i]);
        }
        int ans = 0;
        for(int i=0;i<worker.size();i++)
        {
            auto it = upper_bound(difficulty.begin(),difficulty.end(),worker[i]);
            it--;
            int j = it-difficulty.begin(); 
            if(j!=-1){
            ans = ans+maxx[j];}
        }
        return ans;
    }
};