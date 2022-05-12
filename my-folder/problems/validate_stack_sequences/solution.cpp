class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        reverse(popped.begin(),popped.end());
        for(auto i:pushed)
        {
            s.push(i);
            while(!s.empty() and !popped.empty() and popped.back()==s.top())
            {
                s.pop();
                popped.pop_back();
            } 
        }
        return s.empty();
    }
};