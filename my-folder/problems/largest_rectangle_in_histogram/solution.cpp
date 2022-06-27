class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        vector<int> smallernext(heights.size());
        
        st.push({heights[heights.size()-1],heights.size()-1});
        smallernext[heights.size()-1]=-1;
        for(int i=heights.size()-2;i>=0;i--)
        {
            while(!st.empty() and st.top().first>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                smallernext[i]=-1;
            }
            else
            {
                smallernext[i]=st.top().second;
            }
            st.push({heights[i],i});
        }
        stack<pair<int,int>> st2;
        vector<int> smallerback(heights.size());
        
        st2.push({heights[0],0});
        smallerback[0]=-1;
        for(int i=1;i<heights.size();i++)
        {
            while(!st2.empty() and st2.top().first>=heights[i])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                smallerback[i]=-1;
            }
            else
            {
                smallerback[i]=st2.top().second;
            }
            st2.push({heights[i],i});
        }
        int ans = 0;
        for(int i=0;i<heights.size();i++)
        {
            if(smallernext[i]==-1)
            {
                smallernext[i]=heights.size();
            }
            ans = max(ans,heights[i]*(smallernext[i]-smallerback[i]-1));
        }
        return ans; 
    }
};