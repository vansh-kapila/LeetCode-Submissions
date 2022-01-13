class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> ans; 
        for(int i=1;i<=numRows;i++){
            vector<int> v;
            int k = 0;
            for(int j=1;j<=i;j++){
                if(j==1 or j==i){
                    v.push_back(1);
                }
                else{
                    v.push_back(ans.back()[k]+ans.back()[k+1]);
                    k++;
                }
            }
            ans.push_back(v);
        }
        return ans;

        
    }
};