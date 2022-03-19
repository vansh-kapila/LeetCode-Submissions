class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            pq.push((double)nums[i]);
            sum = sum+(double)nums[i];
        }
        double x = sum/2.0;
        int count = 0;
        while(x<sum)
        {   
            double xx = pq.top();
            sum = sum-xx/2.0;
            pq.pop();
            pq.push(xx/2.0);
            count++;
        }
        return count;
    }
};