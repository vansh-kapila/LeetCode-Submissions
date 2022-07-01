class Solution {
public:
    int histoarea(vector<int> &height)
    {
        stack<pair<int,int>> st;
        vector<int> nextsmaller(height.size()); 
        for(int i=height.size()-1;i>=0;i--)
        {
            while(!st.empty() and st.top().first>=height[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nextsmaller[i]=height.size();
            }
            else
            {
                nextsmaller[i]=st.top().second;
            }
            st.push({height[i],i});
        }
        while(!st.empty())
        {
            st.pop();
        } 
        vector<int> prevsmaller(height.size()); 
        for(int i=0;i<height.size();i++)
        {
            while(!st.empty() and st.top().first>=height[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                prevsmaller[i]=-1;
            }
            else
            {
                prevsmaller[i]=st.top().second;
            }
            st.push({height[i],i});
        }
        int ans = 0;
        for(int i=0;i<height.size();i++)
        { 
            ans = max(ans,height[i]*(nextsmaller[i]-prevsmaller[i]-1)); 
        } 
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) { 
        vector<int> prev(matrix[0].size(),0);
        int ans = 0;
        for(int i=0;i<matrix.size();i++)
        {
            vector<int> height = prev; 
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                }
                else
                {
                    height[j]+=(matrix[i][j]-'0');
                }
            }
            ans = max(ans,histoarea(height));
            prev = height;
        }
        return ans;
    }
};