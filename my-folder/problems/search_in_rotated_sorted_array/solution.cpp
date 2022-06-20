class Solution
{
    public:
        int binarysearch(vector<int> &nums, int l, int r, int target)
        { 
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] < target)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid;
                }
            }
            return -1;
        }
    int search(vector<int> &nums, int target)
    { 
       	//find first element where ai>ai+1
        int l = 0;
        if(nums[l]==target)
        {
            return l;
        }
        int r = nums.size() - 1;
        if(nums[r]==target)
        {
            return r;
        }
        int pivot = -1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[(mid + 1) % nums.size()])
            {
                pivot = (mid) % nums.size();
                break;
            }
            else if (nums[mid] < nums[0])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }  
        return max(binarysearch(nums, 0, pivot+1, target), binarysearch(nums, (pivot+1)%nums.size(), nums.size(), target));
    }
};