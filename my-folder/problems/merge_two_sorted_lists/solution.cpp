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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* anss;
        anss=new ListNode(0);
        ListNode* ans = anss;

        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                ans->next = l1;
                l1=l1->next;
                ans = ans->next;
            }
            else
            {
                ans->next=l2;
                l2=l2->next;
                ans = ans->next;
            }
        }
        
        if(l1!=NULL)
        {
            while(l1!=NULL)
            {
                ans->next = l1;
                l1 = l1->next;
                ans=ans->next;
            }
        }
        
         else if(l2!=NULL)
        {
            while(l2!=NULL)
            {
                ans->next = l2;
                l2 = l2->next;
                ans=ans->next;
            }
        }
        
        return anss->next;
    }
};