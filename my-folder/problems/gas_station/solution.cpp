class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> v;
        for(int i=0;i<cost.size();i++)
        {
            v.push_back(gas[i]-cost[i]);
        }
        
        int sum = 0;
        sum = accumulate(v.begin(),v.end(),sum);
        if(sum<0)
        {
            return -1;
        }
        
        int start = 0;
        int end = v.size()-1;
        sum = 0;
        int i = v.size()-1;
        while(start<=i)
        {
            sum=sum+v[start++];
            if(sum>=0)
            {
                continue;
            }
            else
            {    
                while(sum<0)
                {
                    sum=sum+v[i];
                    i--; 
                } 
            }
        } 
        return (i+1)%v.size();
    }
};