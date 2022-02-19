class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0)
        {
            vector<long long> v;
            return v;
        } 
            vector<long long> v;
            v.push_back(num/3-1);
            v.push_back(num/3);
            v.push_back(num/3+1); 
        return v;
    }
};