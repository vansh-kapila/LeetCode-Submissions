/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:

        ListNode* reversell(ListNode *head)
        {
            ListNode *prev = nullptr;
            while (head != nullptr)
            {
                ListNode *next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            return prev;
        }
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr and fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast != nullptr)
        {
            slow = slow->next;
        }

        ListNode *rev = reversell(slow);

        while (rev != nullptr)
        {
            if (head->val != rev->val)
            {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};