class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) { 
        
        double ans = 0.0; 
        // for(int i=1;i<brackets.size();i++)
        // {
        //     brackets[i][0]=brackets[i][0]-brackets[i-1][0];
        // } 
        int back = 0;
        for(int i=0;i<brackets.size();i++)
        {
            int x = brackets[i][0];
            int y = min(brackets[i][0],income);
            if(y<back)
            {
                return ans;
            }
            ans=ans+(double)(y-back)*((double)brackets[i][1]/100.0);
            back = x;
        }
        return ans;
    }
};