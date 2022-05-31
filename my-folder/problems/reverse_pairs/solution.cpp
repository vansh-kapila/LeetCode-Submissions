class Solution {
public:
    int count = 0;
    void merge(vector<int> &nums, int l,int mid,int r)
    {
        int x = l,y = mid+1;
        
        while(x<=mid and y<=r)
        {
            if((long)nums[x]>(long)2*nums[y])
            {
                count+=(mid-x+1);
                y++;
            } 
            else
            {
                x++;
            }
        }
        sort(nums.begin()+l,nums.begin()+r+1);
    }
    
    void mergesort(vector<int> &nums,int l,int r)
    {
        if(l==r)
        {
            return ;
        }
        
        int mid = (l+r)/2;
        
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    
    int reversePairs(vector<int>& nums) { 
        mergesort(nums,0,nums.size()-1);
        return count;
    }
};