class Solution {
public:
     

    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        vector<int> div(nums.size()+1,0);
        div[0]=0;
        for(int i=1;i<nums.size()+1;i++)
        {
            div[i]=div[i-1]+!(nums[i-1]%p);
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            { 
                if((div[j+1]-div[i])<=k)
                {   vector<int> v(nums.begin()+i,nums.begin()+j+1); 
                    st.insert(v); 
                }
            }
        }
        return st.size();
    }
};