class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        vector<int> k;
        int e = arr.size();
        int n = arr.size();
        
        while(n--)
        {
             int index = find(arr.begin(),arr.end(),n+1)-arr.begin();
             
             k.push_back(index+1);
             reverse(arr.begin(),arr.begin()+index+1);
             
             k.push_back(n+1);
             reverse(arr.begin(),arr.begin()+n+1);
        }
        
        return k;
    }
};