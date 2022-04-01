class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxh = 1; 
        int ans = arr[0];
        int minh = 1;
        for(int i=0;i<arr.size();i++)
        { 
            ans = max({maxh*arr[i],ans,minh*arr[i]});
            int y = minh;
            minh = min({1,maxh*arr[i],minh*arr[i]});
            maxh = max({1,maxh*arr[i],y*arr[i]});
            //cout<<maxh<<' '<<minh<<endl;
        }
        return ans;
    }
};