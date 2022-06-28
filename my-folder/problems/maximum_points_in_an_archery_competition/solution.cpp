class Solution {
public:
    vector<int> ans;
    int maxx = 0;
    int answer(vector<int> &v)
    {
        int ans = 0;
        for(int i=0;i<12;i++)
        {
            if(v[i]!=0)
            {
                ans = ans+i;
            }
        }
        return ans;
    }
    void solve(int arrows,vector<int> &arr,int i,vector<int> &ret)
    {
        if(i==12)
        {
            
            if(answer(ret)>maxx)
            {
                ans = ret;
                maxx = answer(ret);
                if(arrows>0)
            {
                ans[0]=ans[0]+arrows;
            }
            } 
            return;
        } 
        if(arrows>arr[i])
        {
            ret[i]=ret[i]+arr[i]+1;
            solve(arrows-arr[i]-1,arr,i+1,ret);
            ret[i]=ret[i]-arr[i]-1;
        }
        solve(arrows,arr,i+1,ret);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ret(12,0);
        solve(numArrows,aliceArrows,0,ret);  
        return ans;
    }
};