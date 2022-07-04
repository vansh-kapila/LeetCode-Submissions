class Solution {
public:
    bool check(vector<int> &weights,int mid,int days)
    {
        int count = 0;
        int sum = 0;
        for(auto i:weights)
        {
            sum = sum + i;
            if(sum>mid)
            {
                sum = i;
                count++;
            }
            else
            {
                continue;
            }
        }
        if(sum!=0)
        {
            count++;
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = 0;
        r = accumulate(weights.begin(),weights.end(),r);
        
        while(l<r)
        {
            int mid = (l+r)/2;
            if(check(weights,mid,days))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return r;
    }
};