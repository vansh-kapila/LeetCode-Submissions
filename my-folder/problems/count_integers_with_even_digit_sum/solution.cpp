class Solution {
public:
    int countEven(int num) {
         int sum = 0;
         for(int i=1;i<=num;i++)
         {
             int x = 0;
             int y = i;
             while(y!=0)
             {
                 x=x+y%10;
                 y=y/10;
             }
             if(x%2==0)
             {
                 sum++;
             }
         }
        
        return sum;
    }
};