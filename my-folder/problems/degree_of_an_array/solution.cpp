class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 1;
        }
        if(nums.size()==2)
        {
            if(nums[0]==nums[1])
            {
                return 2;
            }
            return 1;
        }
        int arr[50000];
        for(int i=0;i<50000;i++)arr[i]=0;
        map<int,int> in;
        map<int,int> la;
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]++;
            if(in[nums[i]]==0){
            in[nums[i]]=i+1;}
            else{
            la[nums[i]]=i+1;}
        }
        int maxx = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxx = max(maxx,arr[nums[i]]);
        }
        
        int ans = 1000000007;
        for(int i=0;i<nums.size();i++)
        {   if(arr[nums[i]]==maxx){
            ans = min(ans,la[nums[i]]-in[nums[i]]);}
        }
        if(ans==1000000007 or ans<=0)
        {
            return 1;
        }
        return ans+1;
    }
};