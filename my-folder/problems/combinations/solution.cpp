class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void solve(int i,int k,int n,vector<int> temp)
    {
        if(i==n and k==0)
        {
            ans.push_back(temp);
            return;
        }
        if((i==n and k!=0) or n-i<k)
        {
            return;
        }
        solve(i+1,k,n,temp);
        temp.push_back(v[i]);
        solve(i+1,k-1,n,temp);
    }
    vector<vector<int>> combine(int n, int k) {
         
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        vector<int> temp;
        solve(0,k,n,temp);
        return ans;
    }
};