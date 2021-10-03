class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
        {
            return true;
        }
        int r = num-1;
        int l = 1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(mid>sqrt(INT_MAX))
            {
                r = mid-1;
            }
            else if(mid*mid==num)
            {
                return true;
            }
            else if(mid*mid>num)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return false;
    }
};