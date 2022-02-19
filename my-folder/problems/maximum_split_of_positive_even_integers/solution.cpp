class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> v;
        long long sum = 0;
        if(finalSum%2==1)
        {
            return v;
        }
        for(long long i=2;i<=finalSum;i+=2)
        {
            if(sum+i>finalSum)
            {
                v[v.size()-1]=v[v.size()-1]+finalSum-sum;
                break;
            }
            else
            {
                v.push_back(i);
            }
            sum=sum+i;
        }
        return v;
    }
};