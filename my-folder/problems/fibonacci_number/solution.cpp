class Solution {
public:
    int fib(int n) {
        int arr[31];
        arr[0]=0;
        arr[1]=1;
        arr[2]=1;
        
        for(int i=2;i<31;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
        
    }
};