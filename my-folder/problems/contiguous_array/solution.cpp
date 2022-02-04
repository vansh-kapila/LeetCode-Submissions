class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int arr[nums.size()+1];
        arr[0]=0; 
        for(int i=1;i<nums.size()+1;i++)
        {
            arr[i]=arr[i-1]-1+2*nums[i-1];
        }
        unordered_map<int,int> lastoc; 
        for(int i=0;i<nums.size()+1;i++)
        {
            lastoc[arr[i]]=i;
        }
        int ans = 0;
        for(int i=0;i<nums.size()+1;i++)
        {
            if(lastoc.find(arr[i])!=lastoc.end())
            {
                ans = max(ans,lastoc[arr[i]]-i);
            }
        }
        return ans;
    }
};