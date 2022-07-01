class Solution {
public:
     
    void merge(vector<pair<int,int>> &nums,int l,int mid,int r,vector<int> &count)
    {
        int x = l,y = mid+1;
        vector<pair<int,int>> store;
        vector<int> v(mid-l+1,0);
        while(x<=mid and y<=r)
        {
            if(nums[x].first<=nums[y].first)
            {
                store.push_back(nums[x++]);
            }
            else if(nums[y].first<nums[x].first)
            { 
                v[x-l]++;
                store.push_back(nums[y++]);
            }
        }
        while(x<=mid)
        {
            store.push_back(nums[x++]);
        }
        while(y<=r)
        {
            store.push_back(nums[y++]);
        }
        for(int i=1;i<v.size();i++)
        {
            v[i]=v[i]+v[i-1];
        }
        for(int i=l;i<=mid;i++)
        {
            count[nums[i].second]+=v[i-l];
        }
        for(int i=l;i<=r;i++)
        {
            nums[i] = store[i-l];
        }
    }
    void mergesort(vector<pair<int,int>> &nums,int l,int r,vector<int> &count)
    {
        if(l>=r)
        {
            return;
        }
        int mid = l+(r-l)/2;
        
        mergesort(nums,l,mid,count);
        mergesort(nums,mid+1,r,count);
        merge(nums,l,mid,r,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<pair<int,int>> v(nums.size());
        vector<int> count(nums.size(),0);
        //vector v conserves the order.
        for(int i=0;i<nums.size();i++)
        {
            v[i].first = nums[i];
            v[i].second = i;
        }
        mergesort(v,0,v.size()-1,count);
        return count;
    }
};