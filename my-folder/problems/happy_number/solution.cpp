class Solution {
public:
    bool isHappy(int n)
    {
        int sum,m,x=n;
        set<int> s; 
        do
        {
            sum=0;
            while(x>0)
            {
                m=x%10;
                sum+=m*m;
                x=x/10;
            }
            if(sum==1)
            {
                return true;
            }
            else
            {  
                s.insert(x);
                x=sum;
            }
        }
        while(x==7 or (x<2 or x>=10));
        
        return false;
    }
};