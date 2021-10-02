class Solution {
public:
    static bool compare(string x,string y)
    {   if(x.length()!=y.length()){
        return x.length()>y.length();}
     else
     {
         return x>y;
     }
        
        
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }
};