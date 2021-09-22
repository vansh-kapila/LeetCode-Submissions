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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        {
            return head;
        } 
        ListNode* prev = new ListNode();
        ListNode* dummy = prev;
        prev->next = head; 
        ListNode* curr = head;
        ListNode* nxt = head->next;
        
        while(curr->next!=NULL and curr!=NULL)
        { 
            prev->next = nxt;
            curr->next = nxt->next;
            nxt->next = curr;
           
            prev = prev->next->next;
            curr = curr->next;
            if(curr==NULL)
            {
                break;
            }
            nxt = curr->next;
        }
        
        return dummy->next;
    }
};