class Solution {
public:
    static bool func(string a,string b)
    { 
       return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string> str;
        
        for(int i=0;i<nums.size();i++)
        {
            str.push_back(to_string(nums[i]));
        }
        
        sort(str.begin(),str.end(),func);
        
        string ans;
        
        for(int i=0;i<nums.size();i++)
        {
            ans+=str[i];
            if(ans=="0")
            {
                return ans;
            }
        }
        
        return ans;
        
    }
};