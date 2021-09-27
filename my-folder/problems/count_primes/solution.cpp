class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        for(int i=0;i<n+1;i++)
        {
            prime[i]=true;
            if(i%2==0 and i>2)
            {
                prime[i]=false;
            }
            if(i%3==0 and i>3)
            {
                prime[i]=false;
            }
        }
        for(int i=5;i<=sqrt(n);i++)
        {  if(prime[i]==true){
           for(int j=i*i;j<n;j+=i)
           {
               prime[j]=false;
           }
        }
        }
        int count = 0;
        for(int i =2;i<n;i++)
        {
            if(prime[i]==true)
            {
                count++;
            }
        }
        return count;
    }
};