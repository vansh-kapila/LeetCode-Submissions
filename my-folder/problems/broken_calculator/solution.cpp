class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int x = startValue;
        int y = target;
        return  x>=y ? x - y : (1 + brokenCalc(x, y%2 ? y+1 : y/2));
    }
};