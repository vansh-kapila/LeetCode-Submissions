/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode *head, int n)
        { 
            ListNode *slow = head;
            ListNode *fast = head;

            while (fast != nullptr)
            {
                if (n >= 0)
                {
                    n--;
                    fast = fast->next;
                    continue;
                }
                fast = fast->next;
                slow = slow->next;
            }
            if(n>=0)
            {   
                return head->next;
            }
            slow->next = slow->next->next;
            return head;
        }
};