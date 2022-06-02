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
       	//iteratively
        ListNode* reverseList(ListNode *head)
        {

            ListNode *dummy = head;
            ListNode *curr = nullptr;
            while (head != nullptr)
            {
                ListNode *second = head->next;
                head->next = curr;
                curr = head;
                head = second; 
            }
            return curr;
        }
};