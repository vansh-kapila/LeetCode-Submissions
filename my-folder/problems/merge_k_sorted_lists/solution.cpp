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
    ListNode* insertbeg(int x,ListNode* ret)
    {
        ListNode* newhead = new ListNode;
        newhead->next = ret;
        newhead->val = x;
        return newhead;
    }
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* head = lists[i];
            while(head!=NULL)
            {
                pq.push(head->val);
                head=head->next;
            }
        } 
        ListNode* ret = NULL;
        while(!pq.empty())
        {
            ret = insertbeg(pq.top(),ret);
            pq.pop();
        }
        
        return ret;
    }
};