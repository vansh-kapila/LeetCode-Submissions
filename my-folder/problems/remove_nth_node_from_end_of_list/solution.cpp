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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        if(head==NULL or head->next==NULL)
        {
            return NULL;
        }
        int count = 0;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            count++;
        }
        if(count==n)
        {
            return head->next;
        }
        count = count-n;
        ListNode* x = head; 
        count--;
        while(count--)
        {
            x = x->next;
        }
        
        x->next = x->next->next;
        
        return head;
    }
};