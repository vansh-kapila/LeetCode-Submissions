/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode head(INT_MIN);
            ListNode *dummy = &head; 
            int carry = 0;
            while (l1 != nullptr and l2 != nullptr)
            {
                dummy->next = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) / 10;
                dummy = dummy->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            while (l1 != nullptr)
            {
                dummy->next = new ListNode((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
                dummy = dummy->next;
                l1 = l1->next;
            }
            while (l2 != nullptr)
            {
                dummy->next = new ListNode((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
                dummy = dummy->next;
                l2 = l2->next;
            }
            if (carry != 0)
            {
                dummy->next = new ListNode((carry) % 10);
            }
            return head.next;
        }
};