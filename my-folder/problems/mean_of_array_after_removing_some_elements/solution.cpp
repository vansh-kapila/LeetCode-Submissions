class Solution {
public:
    double trimMean(vector<int>& arr) {
        double sum = 0;
        sort(arr.begin(),arr.end());
        sum = accumulate(arr.begin()+arr.size()/20,arr.end()-arr.size()/20,sum);
        return (double)sum/(double)(arr.size()-arr.size()/10);
    }
};