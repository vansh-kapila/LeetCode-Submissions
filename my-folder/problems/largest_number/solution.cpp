class Solution {
public:
    static bool comp(string &x,string &y)
    {
        return x+y>y+x;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> cast;
        for(auto i:nums)
        {
            cast.push_back(to_string(i));
        }
        
        string ans;
        sort(cast.begin(),cast.end(),comp);
        for(auto &i:cast)
        {
            ans.append(i);
        }
        if(ans[0]=='0')
        {
            return "0";
        }
        return ans;
    }
};