class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0; 
        m[ans]++;
        int ret = 0;
        for(auto i:nums)
        { 
            ans+=(i+k*1000);
            ans%=k; 
            m[ans]++;
            ret+=m[ans]-1;
        }
        return ret;
    }
};