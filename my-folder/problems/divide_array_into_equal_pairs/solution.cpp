class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
m[nums[i]]++;}
        for(auto i:m)
        {
            if(i.second%2==1)
            {
                return false;
            }
        }
        return true;
    }
};