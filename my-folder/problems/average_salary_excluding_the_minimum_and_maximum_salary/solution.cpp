class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        salary.pop_back();
        double sum = 0;
        sum = accumulate(salary.begin()+1,salary.end(),sum);
        
        return (double)sum/(salary.size()-1);
    }
};