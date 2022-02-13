class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        if(num1==0 or num2==0)
        {
            return 0;
        }
        if(num1==num2)
        {
            return 1;
        }
        while(num1!=num2)
        {
            if(num1>num2)
            {
                num1=num1-num2;
            }
            else
            {
                num2=num2-num1;
            }
            count++;
        }
        return count+1;
    }
};