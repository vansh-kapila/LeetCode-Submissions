class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {   int k = i;
                while(k<nums.size()-1)
                {
                    nums[k]=nums[k+1];
                    k++;
                }
             i--;
               
             nums.pop_back();
                
            }
        }
        
        return nums.size();
        
    
    }
};