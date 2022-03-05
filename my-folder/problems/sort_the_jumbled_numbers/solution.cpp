class Solution {
public:
    static bool comp(pair<int,int> x,pair<int,int> y)
    {
        if(x.first<y.first)
        {
            return true;
        }
        else if(x.first==y.first)
        {
            return false;
        }
        return false;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i];
            int y = 0;
            if(x==0)
            {
                y=mapping[0];
            }
            int j = 0;
            while(x!=0)
            {
                y=y+(int)pow(10,j++)*mapping[x%10];
                x=x/10;
            }  
            v.push_back(make_pair(y,nums[i]));
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};