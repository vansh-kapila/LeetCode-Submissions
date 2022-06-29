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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        while(list1!=nullptr and list2!=nullptr)
        {
            if(list1->val<list2->val)
            {
                ans->next = list1;
                ans = ans->next;
                list1 = list1->next;
            }
            else
            {
                ans->next = list2;
                ans = ans->next;
                list2 = list2->next;
            }
        }
        
        ListNode *x = list1?list1:list2;
        ans->next = x;
        return dummy->next;
    }
};