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
        if(head==nullptr or head->next==nullptr)
        {
            return 0;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=nullptr and fast->next!=nullptr and fast!=slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        } 
        
        return fast == slow;
    }
};