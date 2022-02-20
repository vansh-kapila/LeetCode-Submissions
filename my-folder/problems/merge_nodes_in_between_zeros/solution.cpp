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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy;
        dummy = new ListNode(0);
        ListNode* head2 = dummy;
        int x = 0;
        ListNode* ptr = head;
        while(head!=nullptr)
        {
            if(head->val==0)
            {   
                ListNode* dummy2 = new ListNode(0);
                dummy2->val = x; 
                dummy->next = dummy2;
                dummy=dummy->next;
                x=0;
            }
            else
            {
                x=x+head->val;
            }
            head=head->next;
        }
        return head2->next->next;
    }
};