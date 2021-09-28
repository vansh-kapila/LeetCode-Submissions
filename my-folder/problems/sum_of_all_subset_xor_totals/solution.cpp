class Solution {
public: 
    
    int subsets(vector<int> v,int n,int xxor,int i)
    {
        if(i==n)
        {
            return xxor;
        }
        
        int include = subsets(v,n,xxor^v[i],i+1);
        int exclude = subsets(v,n,xxor,i+1);
        
        return include+exclude;
        
          
    }
    int subsetXORSum(vector<int>& nums) {
        
        return subsets(nums,nums.size(),0,0);
    }
};