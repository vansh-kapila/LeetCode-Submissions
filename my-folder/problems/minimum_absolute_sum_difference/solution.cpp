class Solution {
public:
    const long long mod = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        //find nearest element for every element of nums2
        long long ans = 0;
        vector<int> store(nums1.size());
        long long decrement = 0;
        for(int i=0;i<nums1.size();i++)
        {
            ans = ans + abs(nums1[i]-nums2[i]);
            store[i]=abs(nums1[i]-nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++)
        { 
            auto it2 = lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin(); 
            int closest1 = 1e9;
            if(it2!=nums1.size())
            {
                decrement = max(decrement,(long long)store[i]-abs(nums1[it2]-nums2[i]));
            } 
            it2--;
            if(it2>=0)
            {
                decrement = max(decrement,(long long)store[i]-abs(nums1[it2]-nums2[i]));
            }  
        } 
        return (ans-decrement+mod)%mod;
    }
};