/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
        {
            return 0;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while((fast!=nullptr and fast->next!=nullptr and fast!=slow))
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow==fast;
    }
};