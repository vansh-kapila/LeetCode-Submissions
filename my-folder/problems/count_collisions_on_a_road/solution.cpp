class Solution {
public:
    int countCollisions(string directions) {
        int l = 0,r = 0,s=0;
        int count = 0;
        for(auto i:directions)
        {
            if(i=='S' and r>0)
            {
                count+=r;
                s+=r;
                r=0;
            } 
            else if(i=='S')
            {
                s++;
            }
            else if(i=='R')
            {
                r++;
            }
            else if(i=='L' and r>0)
            {
                count+=2;
                s+=2;
                r--;
                count+=r;
                r=0;
            }
            else if(i=='L' and s>0)
            {
                count++;
                s++;
            }
            else if(i=='L')
            {
                l++;
            }
        }
        return count;
    }
};