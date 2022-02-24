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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode* dummy = temp;
        for(int i=0;i<v.size();i++)
        {
            dummy->val = v[i]; 
            dummy = dummy->next;
        }
        return temp;
    }
};