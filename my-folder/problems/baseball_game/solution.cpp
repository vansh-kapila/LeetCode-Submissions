class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto i:ops)
        {
            if(i=="+")
            {
                v.push_back(v[v.size()-1]+v[v.size()-2]);
            }
            else if(i=="D")
            {
                v.push_back(2*v[v.size()-1]);
            }
            else if(i=="C")
            {
                v.pop_back();
            }
            else
            {
                v.push_back(stoi(i));
            }
        }
        int sum = 0;
        sum = accumulate(v.begin(),v.end(),sum);
        return sum;
    }
};