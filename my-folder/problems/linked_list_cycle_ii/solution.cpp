/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {   
            if(head==nullptr or head->next==nullptr)
            {
                return nullptr;
            }
            ListNode *fast = head->next;
            ListNode *slow = head;

            while (fast != nullptr and fast->next != nullptr and fast != slow)
            {
                fast = fast->next->next;
                slow = slow->next;
            }

            if (fast != slow)
            {
                return nullptr;
            } 
            slow = head;
            fast = fast->next;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
};