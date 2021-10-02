// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int ans = 0;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            
            if(isBadVersion(mid))
            {
                ans = mid;
                right=mid-1;
            }
            else if(!isBadVersion(mid))
            {
                left = mid+1;
            }
            
        }
        return ans;
        
    }
};