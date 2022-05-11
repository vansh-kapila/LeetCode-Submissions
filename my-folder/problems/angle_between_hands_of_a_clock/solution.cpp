class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min({abs(30.0*(hour+(double)minutes/60.0-(double)minutes/5.0)),abs(30.0*(12-hour+(double)(-1)*minutes/60.0+(double)minutes/5.0)),abs(360.0-abs(30.0*(hour+(double)minutes/60.0-(double)minutes/5.0))),abs(360.0-abs(30.0*(12-hour+(double)(-1)*minutes/60.0+(double)minutes/5.0)))});
    }
};