/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> ans;
        while(head!=nullptr)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        while(ans.size()<=m*n)
        {
            ans.push_back(-1);
        }
        vector<vector<int>> mat(m,vector<int>(n,-1));
        int j = 0;
        int k = 0,l = 0;
        while(k<m and l<n)
        {
            for (int i = l; i < n; ++i)
            mat[k][i] = ans[j++];
 
             k++; 
            
            for (int i = k; i < m; ++i)
            mat[i][n-1] = ans[j++];
            n--; 
        if (k < m)
        {
            for (int i = n-1; i >= l; --i)
                mat[m-1][i] = ans[j++];
            m--;
        } 
        if (l < n)
        {
            for (int i = m-1; i >= k; --i)
                 mat[i][l] = ans[j++];
            l++;
        }
        }
        return mat;
    }
};