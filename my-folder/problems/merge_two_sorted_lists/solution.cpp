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
        ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            ListNode head(INT_MIN);
            ListNode* newList = &head;
            while (list1 != nullptr and list2 != nullptr)
            {
                if (list1->val < list2->val)
                {
                    newList->next = list1;
                    list1 = list1->next;
                    newList = newList->next;
                }
                else
                {
                    newList->next = list2;
                    list2 = list2->next;
                    newList = newList->next;
                }
            }
            while (list1 != nullptr)
            {
                newList->next = list1;
                list1 = list1->next;
                newList = newList->next;
            }
            while (list2 != nullptr)
            {
                newList->next = list2;
                list2 = list2->next;
                newList = newList->next;
            }
            return head.next;
        }
};