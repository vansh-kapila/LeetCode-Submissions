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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* dummy1=headA;
        while(dummy1!=nullptr)
        {
            dummy1 = dummy1->next;
            len1++;
        }
        ListNode* dummy2=headB;
        while(dummy2!=nullptr)
        {
            dummy2 = dummy2->next;
            len2++;
        }
        
        while(len1<len2)
        {
            headB=headB->next;
            len2--;
        }
        while(len1>len2)
        {
            headA=headA->next;
            len1--;
        }
        while(headA!=headB)
        {
            headB=headB->next;
            headA=headA->next;
        }
        
        return headA;
    }
};