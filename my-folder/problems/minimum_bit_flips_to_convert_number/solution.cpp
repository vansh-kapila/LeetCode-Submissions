class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip = 0;
        for(int i=0;i<32;i++)
        {
            int x = 1<<i;
            if((start&x)!=(goal&x))
            {
                flip++;
            }
        }
        return flip;
    }
};