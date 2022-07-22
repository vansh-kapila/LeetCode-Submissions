class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);ListNode* head1 = dummy;  
        ListNode* dummy2 = new ListNode(0);ListNode* head2 = dummy2;
        
        while(head!=nullptr)
        {
            if(head->val<x)
            {
                ListNode* node = new ListNode(head->val);
                head1->next = node;
                head1 = head1->next;
            }
            else
            {
                ListNode* node = new ListNode(head->val);
                head2->next = node;
                head2 = head2->next;
            } 
            head = head->next;
        } 
       
        head1->next = dummy2->next;
        return dummy->next;
    }
};