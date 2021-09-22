class Solution {
public:
    int climbStairs(int n) {
       int arr[45];
        arr[0]=1;
        arr[1]=2;
        
        for(int i=2;i<45;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n-1];
        
    }
};