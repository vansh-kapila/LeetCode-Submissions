class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int arr[nums.size()];
        int brr[nums.size()];
        int x = 1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            x = x*nums[i];
            arr[i]=x;
        }
        
        x = 1;
        for(int i=n-1;i>=0;i--)
        {
            x = x*nums[i];
            brr[i]=x;
        }
        nums[0]=brr[1];
        nums[nums.size()-1] = arr[nums.size()-2];
        for(int i=1;i<n-1;i++)
        {
            nums[i]=arr[i-1]*brr[i+1];
        }
        return nums;
        
    }
};