class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre;
        pre.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            pre.push_back(nums[i]+pre.back());
        } 
        
        map<int,int> m;
        int count = 0;
        for(int i=0;i<pre.size();i++)
        {
            count = count+m[pre[i]-k];          
            m[pre[i]]++;
        }
         
        return count;
    }
};