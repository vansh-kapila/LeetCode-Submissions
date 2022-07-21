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
    ListNode* reverse(ListNode* head,int sz)
    {
        //1->2->3->4 
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* x = head;
        ListNode* nxt;
        while(sz>0)
        {
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
            sz--;
        } 
        x->next = head;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
        {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* ret = dummy;
        dummy->next = head; 
        int x = left-1;
        while(x>0)
        {
            dummy=dummy->next;
            x--;
        }
        dummy->next = reverse(dummy->next,right-left+1);
        return ret->next;
    }
};