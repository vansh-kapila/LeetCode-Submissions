class Solution {
public:
    int minimumSum(int num) {
        
         int arr[] = {num%10,(num/10)%10,(num/100)%10,(num/1000)%10};
        
         sort(arr,arr+4);
         
        return arr[0]*10+arr[1]*10+arr[2]+arr[3];
    }
};