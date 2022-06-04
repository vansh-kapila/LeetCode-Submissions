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

    int sizeoflist(ListNode *head)
    {
            int n = 0;
            ListNode *dum = head;
            while (dum != nullptr)
            {
                dum = dum->next;
                n++;
            }
            return n;
    }

    ListNode* rotateRight(ListNode *head, int k)
    {   
        int n = sizeoflist(head);
        if(n==0)
        {
            return head;
        }
        k = k % n;
        k = n - k;
        k--; 
        ListNode *dum1 = head;
        ListNode *dum2 = head;
        while (k--)
        {
            dum1 = dum1->next;
        }
        while (dum2->next != nullptr)
        {
            dum2 = dum2->next;
        }
        dum2->next = head;
        ListNode *ret = dum1->next;
        dum1->next = nullptr;
        return ret;
    }
};